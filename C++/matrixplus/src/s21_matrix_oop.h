#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H
#include <math.h>
#include <stdio.h>

#include <iostream>

class S21Matrix {
 public:
  // Constructors & destructor
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix() noexcept;
  S21Matrix& operator=(S21Matrix const& obj);
  S21Matrix& operator=(S21Matrix&& obj);

  // Accesors & mutators
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  double GetMatrix(int rows, int cols) const;
  double** GetAddress() const noexcept;
  void SetRows(int rows);
  void SetCols(int cols);
  void SetMatrix(int rows, int cols, double num);

  // Owerloaded operators
  S21Matrix& operator+=(S21Matrix const& obj);
  S21Matrix& operator-=(S21Matrix const& obj);
  bool operator==(S21Matrix const& obj) const;
  S21Matrix& operator*=(S21Matrix const& obj);
  S21Matrix& operator*=(double obj) noexcept;
  S21Matrix operator+(S21Matrix const& obj);
  S21Matrix operator-(S21Matrix const& obj);
  S21Matrix operator*(S21Matrix const& obj);
  S21Matrix operator*(double obj) noexcept;
  double operator()(int rows, int cols) const;

  // Main functions
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Other functions
  void PrintMatrix() const noexcept;
  void FullfillMatrix() noexcept;
  S21Matrix CopyMatrix(S21Matrix matrix1) noexcept;
  double s21_third_n_second_grade_minor(S21Matrix matrix, int excluded_row,
                                        int excluded_column) const noexcept;
  double s21_fourth_plus_grade_minor(S21Matrix matrix, int excluded_row,
                                     int excluded_column, int m) const noexcept;
  double s21_fourth_minus_grade_minor(S21Matrix matrix, int excluded_row,
                                      int excluded_column,
                                      int m) const noexcept;

 private:
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
};

#endif
