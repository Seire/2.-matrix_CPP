#include "s21_matrix_oop.h"

void S21Matrix::set_rows(const int rows) {
  if (rows <= 0) {
    throw std::invalid_argument("Matrix size must be greater than 0");
  }
  resize_matrix(rows, cols_);
}

void S21Matrix::set_cols(const int cols) {
  if (cols <= 0) {
    throw std::invalid_argument("Matrix size must be greater than 0");
  }
  resize_matrix(rows_, cols);
}

int S21Matrix::get_rows() const noexcept { return rows_; }

int S21Matrix::get_cols() const noexcept { return cols_; }