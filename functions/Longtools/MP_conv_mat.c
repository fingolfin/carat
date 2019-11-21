#include "typedef.h"
#include "utils.h"
#include "gmp.h"
#include "matrix.h"
/* #include "gmp-impl.h" */
/**************************************************************************\
@---------------------------------------------------------------------------
@---------------------------------------------------------------------------
@ FILE: MP_conv_mat.c
@---------------------------------------------------------------------------
@---------------------------------------------------------------------------
@
\**************************************************************************/



/**************************************************************************\
@---------------------------------------------------------------------------
@ mpz_t **matrix_to_MP_mat(M)
@ matrix_TYP *M;
@
@  allocated an 2-dimensional array of mpz_t of the size
@  Mat->rows x Mat->cols,
@  converts the entries of Mat->array.SZ to MP_INt and writes 
@  them into the array.
@---------------------------------------------------------------------------
@
\**************************************************************************/
mpz_t **
matrix_to_MP_mat (matrix_TYP *M)
{
  int i,j,m,n;
  mpz_t **erg;

  m = M->cols;
  n = M->rows;
  
  erg = (mpz_t **) xmalloc(n *sizeof(mpz_t *));
  for(i=0;i<n;i++)
  {
    erg[i] = (mpz_t *) xmalloc(m *sizeof(mpz_t));
  }
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
     mpz_init_set_si(&erg[i][j], M->array.SZ[i][j]);
  return(erg);
}


/**************************************************************************\
@---------------------------------------------------------------------------
@ matrix_TYP *MP_mat_to_matrix(M, rows, cols)
@ mpz_t **M;
@ int rows, cols;
@
@ converts the 2-dimensional array M of mpz_t to a matrix_TYP.
@ if the entries in M are to big, the function exits with an error message.
@---------------------------------------------------------------------------
@
\**************************************************************************/
matrix_TYP *
MP_mat_to_matrix (mpz_t **M, int rows, int cols)
{
  int i,j;
  matrix_TYP *erg;

  erg = init_mat(rows, cols, "");

  for(i=0;i<rows;i++){
   for(j=0;j<cols;j++)
   {
     if(abs(M[i][j]._mp_size) > 1)
     {
       printf("Error: Integer overflow in 'MP_mat_to_matrix'\n");
       exit(2);
     }
     erg->array.SZ[i][j] = mpz_get_si(&M[i][j]);
   }
  }

  return(erg);
}



/**************************************************************************\
@---------------------------------------------------------------------------
@ void write_MP_mat_to_matrix(Mat, mp)
@ matrix_TYP *Mat;
@ mpz_t **mp;
@
@ converts the entries of 'mp' and write them to mat->array.SZ
@ If the entries are to big, the programm exits
@---------------------------------------------------------------------------
@
\**************************************************************************/
void 
write_MP_mat_to_matrix (matrix_TYP *Mat, mpz_t **mp)
{
  int i,j;

  for(i=0;i<Mat->rows;i++)
   for(j=0;j<Mat->cols;j++)
   {
     if(abs(mp[i][j]._mp_size) > 1)
     {
       printf("Error: Integer overflow in 'write_MP_mat_to_matrix'\n");
       exit(3);
     }
     Mat->array.SZ[i][j] = mpz_get_si(&mp[i][j]);
   }
}


/**************************************************************************\
@---------------------------------------------------------------------------
@ mpz_t **init_MP_mat(rows, cols)
@ int rows, cols;
@
@ intitializes a 2-dimensional array of mpz_t of size rows x cols
@ and sets all entries 0.
@---------------------------------------------------------------------------
@
\**************************************************************************/
mpz_t **
init_MP_mat (int rows, int cols)
{
   mpz_t **E;
   int i,j;

   E = (mpz_t **)xmalloc(rows *sizeof(mpz_t *));
   for(i=0;i<rows;i++)
   {
     E[i] = (mpz_t *)xmalloc(cols *sizeof(mpz_t));
     for(j=0;j<cols;j++)
        mpz_init(&E[i][j]);
   }
   return(E);
}



/**************************************************************************\
@---------------------------------------------------------------------------
@ void free_MP_mat(M, rows, cols)
@ mpz_t **M;
@ int rows, cols;
@
@ Clears the entries in the 2-dimensional array 'M' and frees
@ M[i] for 0 <= i < rows
@---------------------------------------------------------------------------
@
\**************************************************************************/
void 
free_MP_mat (mpz_t **M, int rows, int cols)
{
 int i,j;
 for(i=0;i<rows;i++)
 {
    for(j=0;j<cols;j++)
      mpz_clear(&M[i][j]);
    free(M[i]);
 }
}
