#include "s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols())
    throw std::invalid_argument("Incorrect matrix sizes(SumMatrix)");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + other(i, j);
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool res = true;
  if (rows_ != other.get_rows() || cols_ != other.get_cols())
    throw std::invalid_argument("Incorrect matrix size(EqMatrix)");

  for (int i = 0; i < rows_ && res; i++) {
    for (int j = 0; j < cols_ && res; j++) {
      if (std::round(matrix_[i][j] * std::pow(10, 7)) !=
          std::round(other(i, j) * std::pow(10, 7)))
        res = false;
    }
  }
  return res;
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols())
    throw std::invalid_argument("Incorrect matrix size(SubMatrix)");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - other(i, j);
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.get_rows()) {
    throw std::invalid_argument(
        "Incorrect matrix sizes for the multiplication (MulMatrix)");
  }

  int cols_2 = other.get_cols();

  S21Matrix result(rows_, cols_2);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_2; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = std::move(result);
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] =
          std::pow(-1, i + j) * fill_calc_complement_cell(i, j);
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect matrix size for Inverse");
  }

  double det = Determinant();

  if (std::abs(det) < eps) {
    throw std::invalid_argument(
        "Determinant must be non-zero to calculate Inverse");
  }

  return (1.0 / det) * Transpose().CalcComplements();
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Matrix size incorrect, rows_ must be == cols_ (Determinant)");
  }

  double res = 0;
  return Determinant_real(res);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }

  return result;
}
