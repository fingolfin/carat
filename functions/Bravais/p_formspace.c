#include"typedef.h"
#include"matrix.h"
#include"longtools.h"

/**************************************************************************\
@---------------------------------------------------------------------------
@---------------------------------------------------------------------------
@ FILE: p_formspace.c
@---------------------------------------------------------------------------
@---------------------------------------------------------------------------
@
\**************************************************************************/


/**************************************************************************\
@---------------------------------------------------------------------------
@ matrix_TYP **p_formspace(B, Banz, prime, sym_opt, fdim)
@ matrix_TYP **B;
@ int Banz, prime, sym_opt, *fdim;
@
@ The same as formspace, just module the prime.
@---------------------------------------------------------------------------
@
\**************************************************************************/
matrix_TYP **p_formspace(B, Banz, prime, sym_opt, fdim)
matrix_TYP **B;
int Banz, prime, sym_opt, *fdim;
{
  int i,j,k,l,m, no, p;
  int dim, dd, anz;
  matrix_TYP *X, **Xk, **E;
  int **XX, **Bi;
  int **pos, **sign;

  
  p = prime;
  dim = B[0]->cols;
  if(B[0]->rows != dim)
  {
    printf("error in formspace: non-square matrix in group 'B'\n");
    exit(3);
  }
  for(i=1;i<Banz;i++)
  {
     if(B[i]->rows != dim || B[i]->cols != dim)
     {
       printf("error in formspace: different dimesion of group elements\n");
       exit(3);
     }
  }
  if(sym_opt == 1)
    dd = (dim *(dim+1))/2;
  if(sym_opt == -1)
    dd = (dim *(dim-1))/2;
  if(sym_opt == 0)
    dd = dim * dim;
  if( (pos = (int **)malloc(dim *sizeof(int *))) == NULL)
  {
     printf("malloc of 'pos' in 'formspace' failed\n");
     exit(2);
  }
  for(i=0;i<dim;i++)
  {
    if( (pos[i] = (int *)malloc(dim *sizeof(int))) == NULL)
    {
       printf("malloc of 'pos[%d]' in 'formspace' failed\n", i);
       exit(2);
    }
  }
  if( (sign = (int **)malloc(dim *sizeof(int *))) == NULL)
  {
     printf("malloc of 'sign' in 'formspace' failed\n");
     exit(2);
  }
  for(i=0;i<dim;i++)
  {
    if( (sign[i] = (int *)malloc(dim *sizeof(int))) == NULL)
    {
       printf("malloc of 'sign[%d]' in 'formspace' failed\n", i);
       exit(2);
    }
  }
  if(sym_opt == 0)
  {
     no = 0;
     for(i=0;i<dim;i++)
       for(j=0;j<dim;j++)
       { pos[i][j] = no; sign[i][j] = 1; no++;}
  }
  if(sym_opt == 1)
  {
     no = 0;
     for(i=0;i<dim;i++)
       for(j=0;j<=i;j++)
       { pos[i][j] = no; sign[i][j] = 1; no++;}
     no = 0;
     for(i=0;i<dim;i++)
       for(j=0;j<=i;j++)
       { pos[j][i] = no; sign[j][i] = 1; no++;}
  }
  if(sym_opt == -1)
  {
     no = 0;
     for(i=0;i<dim;i++)
       for(j=0;j<i;j++)
       { pos[i][j] = no; sign[i][j] = 1; no++;}
     no = 0;
     for(i=0;i<dim;i++)
       for(j=0;j<i;j++)
       { pos[j][i] = no; sign[j][i] = -1; no++;}
     for(i=0;i<dim;i++)
     { pos[i][i] = 0; sign[i][i] = 0;}
  }

  X = init_mat(dd * Banz, dd, "");
  XX = X->array.SZ;
  no = 0;
  if(sym_opt == 0)
  {
    no = 0;
    for(i=0;i<Banz;i++)
    {
       Bi = B[i]->array.SZ;
       for(j=0;j<dim;j++)
         for(k=0;k<dim;k++)
         {
           for(l=0;l<dim;l++)
             for(m=0;m<dim;m++)
             {
               XX[no][pos[l][m]] += sign[l][m] * (Bi[l][j]%p) * (Bi[m][k]%p);
               XX[no][pos[l][m]] %= p;
             }
           XX[no][pos[j][k]]--;
           no++;
         }
    }
  }
  if(sym_opt == 1)
  {
     no = 0;
     for(i=0;i<Banz;i++)
     {
       Bi = B[i]->array.SZ;
       for(j=0;j<dim;j++)
         for(k=0;k<=j;k++)
         {
           for(l=0;l<dim;l++)
             for(m=0;m<dim;m++)
             {
               XX[no][pos[l][m]] += sign[l][m] * (Bi[l][j]%p) * (Bi[m][k]%p);
               XX[no][pos[l][m]] %= p;
             }
           XX[no][pos[j][k]]--;
           no++;
         }
     }
  }
  if(sym_opt == -1)
  {
     no = 0;
     for(i=0;i<Banz;i++)
     {
       Bi = B[i]->array.SZ;
       for(j=0;j<dim;j++)
         for(k=0;k<j;k++)
         {
           for(l=0;l<dim;l++)
             for(m=0;m<dim;m++)
             {
               XX[no][pos[l][m]] += sign[l][m] * (Bi[l][j]%p) * (Bi[m][k]%p);
               XX[no][pos[l][m]] %= p;
             }
           XX[no][pos[j][k]]--;
           no++;
         }
     }
  }
  for(i=0;i<X->rows;i++)
    for(j=0;j<X->cols;j++)
      X->array.SZ[i][j] %=p;
  Xk = p_lse_solve(X, NULL, &anz, p);
  free_mat(X);
    anz--;
  if(Xk[0] != NULL)
    free_mat(Xk[0]);
  if(anz != 0)
  {
    if( (E = (matrix_TYP **)malloc(anz *sizeof(matrix_TYP *))) == NULL)
    {
      printf("malloc of 'E' in 'formspace' failed\n");
      exit(2);
    }
  }
  else
     E = NULL;
  for(i=0;i<anz;i++)
  {
    E[i] = init_mat(dim, dim, "");
    if(sym_opt == 0)
    {
       for(j=0;j<dim;j++)
         for(k=0;k<dim;k++)
            E[i]->array.SZ[j][k] = Xk[i+1]->array.SZ[0][pos[j][k]];
    }
    if(sym_opt == 1)
    {
       for(j=0;j<dim;j++)
         for(k=0;k<=j;k++)
         {
            E[i]->array.SZ[j][k] = Xk[i+1]->array.SZ[0][pos[j][k]];
            if(j != k)
              E[i]->array.SZ[k][j] = E[i]->array.SZ[j][k];
         }
    }
    if(sym_opt == -1)
    {
       for(j=0;j<dim;j++)
         for(k=0;k<j;k++)
         {
            E[i]->array.SZ[j][k] = Xk[i+1]->array.SZ[0][pos[j][k]];
              E[i]->array.SZ[k][j] = -E[i]->array.SZ[j][k];
         }
       for(j=0;j<dim;j++)
        E[i]->array.SZ[j][j] = 0;
    }
  }
  for(i=0;i<anz;i++)
    Check_mat(E[i]);
  for(i=0;i<anz;i++)
    free_mat(Xk[i+1]);
  for(i=0;i<dim;i++)
  { free(pos[i]); free(sign[i]);}
  free(pos); free(sign);
  *fdim = anz;
  return(E);
}
