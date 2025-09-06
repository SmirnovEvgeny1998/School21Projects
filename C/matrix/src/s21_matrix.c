#include "s21_matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows <= 0 || columns <= 0) {
    error = 1;
  }
  if (error == 0) {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      error = 2;
    } else {
      result->rows = rows;
      result->columns = columns;
      for (int i = 0; i < rows && error == 0; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          error = 2;
        }
      }
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i] != NULL) {
          free(A->matrix[i]);
        }
      }
      free(A->matrix);
      A->rows = 0;
      A->columns = 0;
      A->matrix = NULL;
    }
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (A == NULL || B == NULL) {
    error = FAILURE;
  } else if (A->matrix == NULL || B->matrix == NULL) {
    error = FAILURE;
  }
  if (error == SUCCESS) {
    if (A->rows != B->rows || A->columns != B->columns || A->columns <= 0 ||
        B->rows <= 0) {
      error = FAILURE;
    }
    for (int i = 0; i < A->rows && error == SUCCESS; i++) {
      for (int j = 0; j < A->columns && error == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
          error = FAILURE;
        }
      }
    }
  }
  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A == NULL || B == NULL) {
    error = 1;
  } else if (A->matrix == NULL || B->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    for (int i = 0; i < B->rows && error == 0; i++) {
      if (B->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || B->rows <= 0 || A->columns <= 0 || B->columns <= 0) {
      error = 1;
    }
  }
  if (error == 0) {
    if (A->rows != B->rows || A->columns != B->columns) {
      error = 2;
    }
    if (error == 0 && s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows && error == 0; i++) {
        for (int j = 0; j < A->columns && error == 0; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A == NULL || B == NULL) {
    error = 1;
  } else if (A->matrix == NULL || B->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    for (int i = 0; i < B->rows && error == 0; i++) {
      if (B->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || B->rows <= 0 || A->columns <= 0 || B->columns <= 0) {
      error = 1;
    }
  }
  if (error == 0) {
    if (A->rows != B->rows || A->columns != B->columns) {
      error = 2;
    }
    if (error == 0 && s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows && error == 0; i++) {
        for (int j = 0; j < A->columns && error == 0; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if (A == NULL) {
    error = 1;
  } else if (A->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || A->columns <= 0 || isinf(number) != 0 ||
        isnan(number) != 0) {
      error = 1;
    }
  }
  if (error == 0) {
    if (error == 0 && s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows && error == 0; i++) {
        for (int j = 0; j < A->columns && error == 0; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A == NULL || B == NULL) {
    error = 1;
  } else if (A->matrix == NULL || B->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    for (int i = 0; i < B->rows && error == 0; i++) {
      if (B->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || B->rows <= 0 || A->columns <= 0 || B->columns <= 0) {
      error = 1;
    }
  }
  if (error == 0) {
    if (A->rows != B->columns || A->columns != B->rows) {
      error = 2;
    }
    if (error == 0 && s21_create_matrix(A->rows, B->columns, result) == 0) {
      for (int i = 0; i < result->rows && error == 0; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = 0;
        }
      }
      for (int i = 0; i < result->rows && error == 0; i++) {
        for (int j = 0; j < result->columns && error == 0; j++) {
          for (int p = 0; p < A->columns && error == 0; p++) {
            result->matrix[i][j] += A->matrix[i][p] * B->matrix[p][j];
          }
        }
      }
    }
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A == NULL) {
    error = 1;
  } else if (A->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || A->columns <= 0) {
      error = 1;
    }
  }
  if (error == 0 && s21_create_matrix(A->columns, A->rows, result) == 0) {
    for (int m = 0; m < result->rows && error == 0; m++) {
      for (int s = 0; s < result->columns && error == 0; s++) {
        result->matrix[m][s] = A->matrix[s][m];
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  double pos_mul = 0, neg_mul = 0;
  if (A == NULL) {
    error = 1;
  } else if (A->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || A->columns <= 0) {
      error = 1;
    }
  }
  if (error == 0 && A->columns != A->rows) {
    error = 2;
  }
  if (error == 0 && s21_create_matrix(A->columns, A->rows, result) == 0) {
    for (int m = 0; m < result->rows && error == 0 &&
                    (result->rows == 3 || result->rows == 2);
         m++) {
      for (int s = 0; s < result->columns && error == 0; s++) {
        result->matrix[m][s] =
            s21_third_n_second_grade_minor(*A, m, s) * pow(-1, m + s);
      }
    }
    for (int m = 0; m < result->rows && error == 0 && result->rows != 3 &&
                    result->rows != 2;
         m++) {
      for (int s = 0; s < result->columns && error == 0; s++) {
        for (int i = 0; i < A->columns; i++) {
          neg_mul += s21_fourth_minus_grade_minor(*A, m, s, i);
        }
        for (int i = 0; i < A->columns; i++) {
          pos_mul += s21_fourth_plus_grade_minor(*A, m, s, i);
        }
        result->matrix[m][s] = (pos_mul - neg_mul) * pow(-1, m + s);
        pos_mul = 0;
        neg_mul = 0;
      }
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (A == NULL || result == NULL) {
    error = 1;
  } else if (A->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || A->columns <= 0) {
      error = 1;
    }
  }
  if (error == 0 && A->rows != A->columns) {
    error = 2;
  }
  if (error == 0) {
    *result = s21_four_plus_determinant(*A);
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  double determinant = 0;
  if (A == NULL) {
    error = 1;
  } else if (A->matrix == NULL) {
    error = 1;
  } else {
    for (int i = 0; i < A->rows && error == 0; i++) {
      if (A->matrix[i] == NULL) {
        error = 1;
      }
    }
    if (A->rows <= 0 || A->columns <= 0) {
      error = 1;
    }
  }
  if (error == 0 && A->rows != A->columns) {
    error = 2;
  }
  if (error == 0) {
    if (error == 0) {
      s21_determinant(A, &determinant);
      if (determinant == 0) {
        error = 2;
      }
    }
    if (error == 0) {
      matrix_t temp_matrix = {0}, temp_transpose = {0};
      s21_calc_complements(A, &temp_matrix);
      s21_transpose(&temp_matrix, &temp_transpose);
      s21_mult_number(&temp_transpose, 1.0 / determinant, result);
      s21_remove_matrix(&temp_matrix);
      s21_remove_matrix(&temp_transpose);
    }
  }
  return error;
}

double s21_third_n_second_grade_minor(matrix_t matrix, int excluded_row,
                                      int excluded_column) {
  int counter = 0;
  double result, num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0;
  if (matrix.rows == 2) {
    for (int m = 0; m < matrix.rows; m++) {
      for (int s = 0; s < matrix.columns; s++) {
        if (m != excluded_row && s != excluded_column) {
          result = matrix.matrix[m][s];
        }
      }
    }
  }
  if (matrix.rows == 3) {
    for (int m = 0; m < matrix.rows; m++) {
      for (int s = 0; s < matrix.columns; s++) {
        if (m != excluded_row && s != excluded_column) {
          counter += 1;
          if (counter == 1) {
            num_1 = matrix.matrix[m][s];
          } else if (counter == 2) {
            num_2 = matrix.matrix[m][s];
          } else if (counter == 3) {
            num_3 = matrix.matrix[m][s];
          } else if (counter == 4) {
            num_4 = matrix.matrix[m][s];
          }
        }
      }
    }
    result = num_1 * num_4 - num_2 * num_3;
  }
  return result;
}

double s21_fourth_plus_grade_minor(matrix_t matrix, int excluded_row,
                                   int excluded_column, int m) {
  double result = 1;
  int start_column = matrix.columns - 1 - m, start_row = 0;
  for (int s = 0; s < matrix.columns - 1; s++) {
    if (start_row == excluded_row && start_column == excluded_column) {
      start_row += 1;
      start_column += 1;
    } else if (start_row == excluded_row) {
      start_row += 1;
    } else if (start_column == excluded_column) {
      start_column += 1;
    }
    if (start_column >= matrix.columns) {
      start_column -= matrix.columns;
    }
    if (start_row == excluded_row && start_column == excluded_column) {
      start_row += 1;
      start_column += 1;
    } else if (start_row == excluded_row) {
      start_row += 1;
    } else if (start_column == excluded_column) {
      start_column += 1;
    }
    if (start_row != excluded_row) {
      result *= matrix.matrix[start_row][start_column];
    }
    start_row += 1;
    start_column += 1;
  }
  if (excluded_column == matrix.columns - 1 - m) {
    result = 0;
  }
  return result;
}

double s21_fourth_minus_grade_minor(matrix_t matrix, int excluded_row,
                                    int excluded_column, int m) {
  double result = 1;
  int start_column = matrix.columns - 1 - m, start_row = 0;
  for (int s = 0; s < matrix.columns - 1; s++) {
    if (start_row == excluded_row && start_column == excluded_column) {
      start_row += 1;
      start_column -= 1;
    } else if (start_row == excluded_row) {
      start_row += 1;
    } else if (start_column == excluded_column) {
      start_column -= 1;
    }
    if (start_column < 0) {
      start_column += matrix.columns;
    }
    if (start_row == excluded_row && start_column == excluded_column) {
      start_row += 1;
      start_column -= 1;
    } else if (start_row == excluded_row) {
      start_row += 1;
    } else if (start_column == excluded_column) {
      start_column -= 1;
    }
    if (start_row != excluded_row) {
      result *= matrix.matrix[start_row][start_column];
    }
    start_row += 1;
    start_column -= 1;
  }
  if (excluded_column == matrix.columns - 1 - m) {
    result = 0;
  }
  return result;
}

double s21_four_plus_determinant(matrix_t matrix) {
  matrix_t temp_matrix = {0};
  double result = 0;
  int plus_minus = 1, temp_row = 0, temp_column = 0;
  if (matrix.rows == 1) {
    result = matrix.matrix[0][0];
  } else if (matrix.rows == 2) {
    result = matrix.matrix[0][0] * matrix.matrix[1][1] -
             matrix.matrix[0][1] * matrix.matrix[1][0];
  } else if (matrix.rows == 3) {
    result +=
        matrix.matrix[0][0] * ((matrix.matrix[1][1] * matrix.matrix[2][2]) -
                               (matrix.matrix[2][1] * matrix.matrix[1][2]));
    result -=
        matrix.matrix[0][1] * ((matrix.matrix[1][0] * matrix.matrix[2][2]) -
                               (matrix.matrix[2][0] * matrix.matrix[1][2]));
    result +=
        matrix.matrix[0][2] * ((matrix.matrix[1][0] * matrix.matrix[2][1]) -
                               (matrix.matrix[2][0] * matrix.matrix[1][1]));
  } else {
    s21_create_matrix(matrix.rows - 1, matrix.columns - 1, &temp_matrix);
    for (int i = 0; i < matrix.rows; i++) {
      for (int m = 0; m < matrix.rows && temp_row <= temp_matrix.rows - 1;
           m++) {
        for (int s = 0; s < matrix.columns && temp_row <= temp_matrix.rows - 1;
             s++) {
          if (m != 0 && s != i) {
            temp_matrix.matrix[temp_row][temp_column] = matrix.matrix[m][s];
            temp_column += 1;
          }
          if (temp_column >= temp_matrix.columns) {
            temp_column = 0;
            temp_row += 1;
          }
        }
      }
      result += plus_minus * matrix.matrix[0][i] *
                s21_four_plus_determinant(temp_matrix);
      plus_minus *= -1;
      temp_row = 0;
      temp_column = 0;
    }
    s21_remove_matrix(&temp_matrix);
  }
  return result;
}
