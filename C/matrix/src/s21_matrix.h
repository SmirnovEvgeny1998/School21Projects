#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-8
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
//-----------
void s21_print_matrix(matrix_t matrix);
double s21_third_n_second_grade_minor(matrix_t matrix, int excluded_row,
                                      int excluded_column);
double s21_fourth_plus_grade_minor(matrix_t matrix, int excluded_row,
                                   int excluded_column, int m);
double s21_fourth_minus_grade_minor(matrix_t matrix, int excluded_row,
                                    int excluded_column, int m);
double s21_two_or_three_determinant(matrix_t matrix);
double s21_four_plus_determinant(matrix_t matrix);
int s21_inf_nan_check(matrix_t A);

#endif
