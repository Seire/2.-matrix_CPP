#include "s21_matrix_oop.h"

void S21Matrix::allocate_memory() noexcept {
  matrix_ = new double *[rows_] {};
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

void S21Matrix::kill_matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    matrix_ = nullptr;
  }
}

double S21Matrix::Determinant_real(double &result) {
  if (rows_ == 1) {
    result += matrix_[0][0];
  } else if (rows_ == 2) {
    result += matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    int imaginary_unit = 1;
    for (int i = 0; i < cols_; i++) {
      double det = 0;
      S21Matrix B = fill_matrix(i);
      B.Determinant_real(det);
      result += imaginary_unit * matrix_[0][i] * det;
      imaginary_unit *= -1;
    }
  }
  return result;
}

S21Matrix S21Matrix::fill_matrix(int skip) {
  S21Matrix B(cols_ - 1, cols_ - 1);
  double *data = new double[(cols_ - 1) * (cols_ - 1)];
  int data_i = 0;
  for (int i = 1; i < cols_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (j == skip) continue;
      data[data_i++] = matrix_[i][j];
    }
  }

  data_i = 0;

  for (int i = 0; i < B.get_rows(); i++) {
    for (int j = 0; j < B.get_cols(); j++) {
      B.matrix_[i][j] = data[data_i++];
    }
  }
  delete[] data;
  return B;
}

void S21Matrix::resize_matrix(const int rows, const int cols) {
  S21Matrix res(rows, cols);
  for (int i = 0; i < rows && i < rows_; i++) {
    for (int j = 0; j < cols && j < cols_; j++) {
      res.matrix_[i][j] = matrix_[i][j];
    }
  }
  (*this) = res;
}

double S21Matrix::fill_calc_complement_cell(int row, int column) {
  int row_offset = 0;
  int column_offset = 0;
  double res = 0;
  S21Matrix B(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    if (i == row) {
      row_offset = 1;
      continue;
    }
    for (int j = 0; j < cols_; j++) {
      if (j == column) {
        column_offset = 1;
        continue;
      }
      B.matrix_[i - row_offset][j - column_offset] = matrix_[i][j];
    }
    column_offset = 0;
  }
  res = B.Determinant();
  return res;
}
