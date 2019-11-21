#ifndef CARAT_LONGTOOLS_H
#define CARAT_LONGTOOLS_H

#include "typedef.h"

#include "gmp.h"

/*-------------------------------------------------------------*\
| FILE: MP_conv_mat.c
\*-------------------------------------------------------------*/
extern mpz_t **matrix_to_MP_mat(matrix_TYP *M);
extern matrix_TYP *MP_mat_to_matrix(mpz_t **M, int rows, int cols);
extern void write_MP_mat_to_matrix(matrix_TYP *Mat, mpz_t **mp);
extern mpz_t **init_MP_mat(int rows, int cols);
extern void free_MP_mat(mpz_t **M, int rows, int cols);

/*-------------------------------------------------------------*\
| FILE: MP_gauss.c
\*-------------------------------------------------------------*/
extern int MP_trf_gauss(mpz_t **M, mpz_t **Trf, int rows, int cols);
extern int MP_row_gauss(mpz_t **M, int rows, int cols);
extern int MP_row_gauss_simultaneous(mpz_t **M, int rows, int cols,
     mpz_t **B, int Bcols);
extern void MP_row_gauss_reverse(mpz_t **A,int rows,int cols,int option);

/*-------------------------------------------------------------*\
| FILE: MP_hnf.c
\*-------------------------------------------------------------*/
extern int MP_trf_hnf(mpz_t **M, mpz_t **Trf, int rows, int cols);
extern int MP_hnf(mpz_t **M, int rows, int cols);
extern int MP_hnf_simultaneous(mpz_t **M, int rows, int cols, mpz_t **B,
     int Bcols);

/*-------------------------------------------------------------*\
| FILE: MP_pair_red.c
\*-------------------------------------------------------------*/
extern void MP_pair_red(mpz_t **G, mpz_t **T, int n);

/*-------------------------------------------------------------*\
| FILE: MP_red_sort.c
\*-------------------------------------------------------------*/
extern void MP_reduction_sort(mpz_t **G,mpz_t **T,int n);

/*-------------------------------------------------------------*\
| FILE: MP_solve.c
\*-------------------------------------------------------------*/
extern mpz_t ***MP_solve_mat(mpz_t **M, int rows, int cols, mpz_t **B,
     int Bcols, int *X1cols, mpz_t *X0kgv);

/*-------------------------------------------------------------*\
| FILE: long_elt.c
\*-------------------------------------------------------------*/
extern matrix_TYP *long_elt_mat(matrix_TYP *left_trans,
                                matrix_TYP *Mat,
                                matrix_TYP *right_trans);

/*-------------------------------------------------------------------*\
|  FILE: long_gauss.c
\*-------------------------------------------------------------------*/
extern int long_row_gauss(matrix_TYP *Mat);
extern int long_row_basis(matrix_TYP *Mat,int flag);
extern int long_row_trf_gauss(matrix_TYP *M, matrix_TYP *T);
extern int long_row_gauss_simultaneous(matrix_TYP *A, matrix_TYP *B);

/*-------------------------------------------------------------------*\
|  FILE: long_hnf.c
\*-------------------------------------------------------------------*/
extern int long_row_hnf(matrix_TYP *Mat);
extern int long_col_hnf(matrix_TYP *Mat);
extern int long_row_trf_hnf(matrix_TYP *M, matrix_TYP *T);
extern int long_row_hnf_simultaneous(matrix_TYP *A, matrix_TYP *B);

/*-------------------------------------------------------------*\
| FILE: long_kernel_mat.c
\*-------------------------------------------------------------*/
extern matrix_TYP *long_kernel_mat(matrix_TYP *A);

/*-------------------------------------------------------------*\
| FILE: long_mat_inv.c
\*-------------------------------------------------------------*/
extern matrix_TYP *long_mat_inv(matrix_TYP *A);

/*-------------------------------------------------------------*\
| FILE: long_qbase.c
\*-------------------------------------------------------------*/
extern matrix_TYP *long_qbase(matrix_TYP *Mat);

/*-------------------------------------------------------------*\
| FILE: long_rein_mat.c
\*-------------------------------------------------------------*/
extern matrix_TYP *long_rein_mat(matrix_TYP *M);
extern int long_rein_formspace(matrix_TYP **forms,int number,int option);

/*-------------------------------------------------------------*\
| FILE: long_solve_mat.c
\*-------------------------------------------------------------*/
extern matrix_TYP **long_solve_mat(matrix_TYP *A, matrix_TYP *B);

/*-------------------------------------------------------------*\
| FILE: dump_MP_mat.c
\*-------------------------------------------------------------*/
extern void dump_MP_mat(mpz_t **Mat, int rows, int cols, const char *comment);

#endif
