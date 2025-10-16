#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.MulMatrix(other);
  return tmp;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix tmp{*this};
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

double &S21Matrix::operator()(int row, int col) & {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_)
    throw std::invalid_argument("Incorrect matrix index");
  return matrix_[row][col];
}

const double &S21Matrix::operator()(int row, int col) const & {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_)
    throw std::invalid_argument("Incorrect matrix index");
  return matrix_[row][col];
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  S21Matrix copy{other};
  kill_matrix();
  *this = std::move(copy);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    kill_matrix();
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }

  return *this;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix tmp{*this};
  tmp.MulNumber(num);
  return tmp;
}

S21Matrix operator*(double number, const S21Matrix &matrix) noexcept {
  return matrix * number;
}