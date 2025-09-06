#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept {
  this->rows_ = 1;
  this->cols_ = 1;
  this->matrix_ = new double* [1] {};
  this->matrix_[0] = new double[1]{};
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument{"Impossible matrix dimensions"};
  }
  this->rows_ = rows;
  this->cols_ = cols;
  this->matrix_ = new double* [rows] {};
  for (int i = 0; i < rows; i++) {
    this->matrix_[i] = new double[cols]{};
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  if (other.matrix_ == nullptr) {
    throw std::invalid_argument{"Impossible matrix dimensions"};
  }
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = new double* [other.rows_] {};
  for (int i = 0; i < other.rows_; i++) {
    this->matrix_[i] = new double[other.cols_]{};
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  if (other.GetRows() < 1 || other.GetCols() < 1 || other.matrix_ == nullptr) {
    throw std::invalid_argument{"Impossible matrix dimensions"};
  }
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
}

S21Matrix::~S21Matrix() noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
    matrix_[i] = nullptr;
  }
  delete[] matrix_;
  this->matrix_ = nullptr;
  this->rows_ = 0;
  this->cols_ = 0;
}

S21Matrix& S21Matrix::operator+=(S21Matrix const& obj) {
  SumMatrix(obj);
  return *this;
}

S21Matrix& S21Matrix::operator-=(S21Matrix const& obj) {
  SubMatrix(obj);
  return *this;
}
bool S21Matrix::operator==(S21Matrix const& obj) const { return EqMatrix(obj); }
S21Matrix& S21Matrix::operator*=(S21Matrix const& obj) {
  MulMatrix(obj);
  return *this;
}
S21Matrix& S21Matrix::operator*=(double obj) noexcept {
  MulNumber(obj);
  return *this;
}
S21Matrix& S21Matrix::operator=(S21Matrix const& obj) {
  CopyMatrix(obj);
  return *this;
}
S21Matrix S21Matrix::operator+(S21Matrix const& obj) {
  S21Matrix result = CopyMatrix(*this);
  result.SumMatrix(obj);
  return result;
}
S21Matrix S21Matrix::operator-(S21Matrix const& obj) {
  S21Matrix result = CopyMatrix(*this);
  result.SubMatrix(obj);
  return result;
}
S21Matrix S21Matrix::operator*(S21Matrix const& obj) {
  S21Matrix result = CopyMatrix(*this);
  result.MulMatrix(obj);
  return result;
}
S21Matrix S21Matrix::operator*(double obj) noexcept {
  S21Matrix result = CopyMatrix(*this);
  result.MulNumber(obj);
  return result;
}
double S21Matrix::operator()(int rows, int cols) const {
  return GetMatrix(rows, cols);
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  bool error = true;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    error = false;
  }
  for (int i = 0; i < this->rows_ && error == true; i++) {
    for (int j = 0; j < this->cols_ && error == true; j++) {
      if (this->matrix_[i][j] != other.matrix_[i][j]) {
        error = false;
      }
    }
  }
  return error;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::invalid_argument{"Different matrix dimensions"};
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::invalid_argument{"Different matrix dimensions"};
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  S21Matrix temp(this->rows_, other.cols_);
  if (this->cols_ != other.rows_) {
    throw std::invalid_argument{"Rows(1) and cols(2) not equal"};
  }
  for (int i = 0; i < temp.rows_; i++) {
    for (int j = 0; j < temp.cols_; j++) {
      for (int p = 0; p < this->cols_; p++) {
        temp.matrix_[i][j] += this->matrix_[i][p] * other.matrix_[p][j];
      }
    }
  }
  double** t_matrix = this->matrix_;
  this->matrix_ = temp.matrix_;
  temp.matrix_ = t_matrix;
  this->cols_ = other.cols_;
  temp.~S21Matrix();
}

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix result(this->cols_, this->rows_);
  for (int m = 0; m < result.rows_; m++) {
    for (int s = 0; s < result.cols_; s++) {
      result.matrix_[m][s] = this->matrix_[s][m];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->cols_ != this->rows_) {
    throw std::invalid_argument{"Rows and cols not equal"};
  }
  double pos_mul = 0, neg_mul = 0;
  S21Matrix result(this->cols_, this->rows_);
  for (int m = 0; m < this->rows_ && (this->rows_ == 3 || this->rows_ == 2);
       m++) {
    for (int s = 0; s < this->cols_; s++) {
      result.matrix_[m][s] =
          s21_third_n_second_grade_minor(*this, m, s) * pow(-1, m + s);
    }
  }
  for (int m = 0; m < this->rows_ && this->rows_ != 3 && this->rows_ != 2;
       m++) {
    for (int s = 0; s < this->cols_; s++) {
      for (int i = 0; i < this->cols_; i++) {
        neg_mul += s21_fourth_minus_grade_minor(*this, m, s, i);
      }
      for (int i = 0; i < this->cols_; i++) {
        pos_mul += s21_fourth_plus_grade_minor(*this, m, s, i);
      }
      result.matrix_[m][s] = (pos_mul - neg_mul) * pow(-1, m + s);
      pos_mul = 0;
      neg_mul = 0;
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw std::invalid_argument{"Rows and cols not equal"};
  }
  double result = 0;
  int plus_minus = 1, temp_row = 0, temp_column = 0;
  if (this->rows_ == 1) {
    result = matrix_[0][0];
  } else if (this->rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else if (this->rows_ == 3) {
    result += matrix_[0][0] * ((matrix_[1][1] * matrix_[2][2]) -
                               (matrix_[2][1] * matrix_[1][2]));
    result -= matrix_[0][1] * ((matrix_[1][0] * matrix_[2][2]) -
                               (matrix_[2][0] * matrix_[1][2]));
    result += matrix_[0][2] * ((matrix_[1][0] * matrix_[2][1]) -
                               (matrix_[2][0] * matrix_[1][1]));
  } else {
    S21Matrix temp_matrix(this->rows_ - 1, this->cols_ - 1);
    for (int i = 0; i < this->rows_; i++) {
      for (int m = 0; m < this->rows_ && temp_row <= temp_matrix.rows_ - 1;
           m++) {
        for (int s = 0; s < this->cols_ && temp_row <= temp_matrix.rows_ - 1;
             s++) {
          if (m != 0 && s != i) {
            temp_matrix.matrix_[temp_row][temp_column] = matrix_[m][s];
            temp_column += 1;
          }
          if (temp_column >= temp_matrix.cols_) {
            temp_column = 0;
            temp_row += 1;
          }
        }
      }
      result += plus_minus * matrix_[0][i] * temp_matrix.Determinant();
      plus_minus *= -1;
      temp_row = 0;
      temp_column = 0;
    }
    temp_matrix.~S21Matrix();
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = this->Determinant();
  if (determinant == 0) {
    throw std::logic_error{"Matrix does not exist"};
  }
  S21Matrix temp_matrix = this->CalcComplements();
  S21Matrix temp_transpose = temp_matrix.Transpose();
  temp_transpose.MulNumber(1.0 / determinant);
  temp_matrix.~S21Matrix();
  return temp_transpose;
}

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

double S21Matrix::GetMatrix(int rows, int cols) const {
  if (rows < 0 || cols < 0) {
    throw std::logic_error{"Rows and cols cant be less than 1"};
  } else if (rows >= rows_ || cols >= cols_) {
    throw std::logic_error{"Rows and cols exceed the matrix border"};
  }
  return this->matrix_[rows][cols];
}

double** S21Matrix::GetAddress() const noexcept { return this->matrix_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 1) {
    throw std::invalid_argument{"Rows cant be less than 1"};
  }
  if (new_rows == this->rows_) {
    return;
  }
  S21Matrix temp(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      temp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
    this->matrix_[i] = nullptr;
  }
  delete[] this->matrix_;
  this->matrix_ = nullptr;
  this->matrix_ = new double* [new_rows] {};
  this->rows_ = new_rows;
  for (int i = 0; i < new_rows; i++) {
    matrix_[i] = new double[this->cols_]{};
  }
  for (int i = 0; i < new_rows && i < temp.GetRows(); i++) {
    for (int j = 0; j < this->cols_; j++) {
      matrix_[i][j] = temp.matrix_[i][j];
    }
  }
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 1) {
    throw std::invalid_argument{"Cols cant be less than 1"};
  }
  if (new_cols == this->cols_) {
    return;
  }
  S21Matrix temp(this->rows_, this->cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      temp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
    this->matrix_[i] = nullptr;
  }
  delete[] this->matrix_;
  this->matrix_ = nullptr;
  this->matrix_ = new double* [rows_] {};
  this->cols_ = new_cols;
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[new_cols]{};
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < new_cols && j < temp.GetCols(); j++) {
      this->matrix_[i][j] = temp.matrix_[i][j];
    }
  }
}

void S21Matrix::SetMatrix(int rows, int cols, double num) {
  if (rows < 0 || cols < 0) {
    throw std::invalid_argument{"Rows and cols cant be less than 1"};
  } else if (rows >= rows_ || cols >= cols_) {
    throw std::out_of_range{"Rows and cols exceed the matrix border"};
  }
  this->matrix_[rows][cols] = num;
}

void S21Matrix::PrintMatrix() const noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      printf("%f ", matrix_[i][j]);
    }
    printf("\n");
  }
}

void S21Matrix::FullfillMatrix() noexcept {
  int count = 1;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = count;
      count += 1;
    }
  }
}

S21Matrix S21Matrix::CopyMatrix(S21Matrix matrix1) noexcept {
  S21Matrix matrix2(matrix1.rows_, matrix1.cols_);
  for (int i = 0; i < matrix1.rows_; i++) {
    for (int j = 0; j < matrix1.cols_; j++) {
      matrix2.matrix_[i][j] = matrix1.matrix_[i][j];
    }
  }
  return matrix2;
}

double S21Matrix::s21_third_n_second_grade_minor(
    S21Matrix matrix, int excluded_row, int excluded_column) const noexcept {
  int counter = 0;
  double result, num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0;
  if (matrix.rows_ == 2) {
    for (int m = 0; m < matrix.rows_; m++) {
      for (int s = 0; s < matrix.cols_; s++) {
        if (m != excluded_row && s != excluded_column) {
          result = matrix.matrix_[m][s];
        }
      }
    }
  }
  if (matrix.rows_ == 3) {
    for (int m = 0; m < matrix.rows_; m++) {
      for (int s = 0; s < matrix.cols_; s++) {
        if (m != excluded_row && s != excluded_column) {
          counter += 1;
          if (counter == 1) {
            num_1 = matrix.matrix_[m][s];
          } else if (counter == 2) {
            num_2 = matrix.matrix_[m][s];
          } else if (counter == 3) {
            num_3 = matrix.matrix_[m][s];
          } else if (counter == 4) {
            num_4 = matrix.matrix_[m][s];
          }
        }
      }
    }
    result = num_1 * num_4 - num_2 * num_3;
  }
  return result;
}

double S21Matrix::s21_fourth_plus_grade_minor(S21Matrix matrix,
                                              int excluded_row,
                                              int excluded_column,
                                              int m) const noexcept {
  double result = 1;
  int start_column = matrix.GetCols() - 1 - m, start_row = 0;
  for (int s = 0; s < matrix.GetCols() - 1; s++) {
    if (start_row == excluded_row && start_column == excluded_column) {
      start_row += 1;
      start_column += 1;
    } else if (start_row == excluded_row) {
      start_row += 1;
    } else if (start_column == excluded_column) {
      start_column += 1;
    }
    if (start_column >= matrix.GetCols()) {
      start_column -= matrix.GetCols();
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
      result *= matrix.GetMatrix(start_row, start_column);
    }
    start_row += 1;
    start_column += 1;
  }
  if (excluded_column == matrix.GetCols() - 1 - m) {
    result = 0;
  }
  return result;
}

double S21Matrix::s21_fourth_minus_grade_minor(S21Matrix matrix,
                                               int excluded_row,
                                               int excluded_column,
                                               int m) const noexcept {
  double result = 1;
  int start_column = matrix.GetCols() - 1 - m, start_row = 0;
  for (int s = 0; s < matrix.GetCols() - 1; s++) {
    if (start_row == excluded_row && start_column == excluded_column) {
      start_row += 1;
      start_column -= 1;
    } else if (start_row == excluded_row) {
      start_row += 1;
    } else if (start_column == excluded_column) {
      start_column -= 1;
    }
    if (start_column < 0) {
      start_column += matrix.GetCols();
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
      result *= matrix.GetMatrix(start_row, start_column);
    }
    start_row += 1;
    start_column -= 1;
  }
  if (excluded_column == matrix.GetCols() - 1 - m) {
    result = 0;
  }
  return result;
}
