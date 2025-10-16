#ifndef VERY_COMPLICATED_LIBRARY_MACRO_NAME_TO_PREVENT_SIMILARITIES_S21_MATRIX_PLUS_PLUS_OOP_H
#define VERY_COMPLICATED_LIBRARY_MACRO_NAME_TO_PREVENT_SIMILARITIES_S21_MATRIX_PLUS_PLUS_OOP_H

#include <iostream>
#include <cmath>

#define eps 1e-7

class S21Matrix
{
private:
    // Attributes
    int rows_, cols_; // Rows and columns
    double **matrix_; // Pointer to the memory where the matrix is allocated

    void allocate_memory() noexcept;

    S21Matrix fill_matrix(int i);

    //double Determinant_further(double &result);

    double fill_calc_complement_cell(int row, int column);

    void kill_matrix();

    double Determinant_real(double &res);

public:
    S21Matrix() noexcept;              // Default constructor
    S21Matrix(int rows, int cols);     // Normal constructor
    S21Matrix(const S21Matrix &other); // Copy
    S21Matrix(S21Matrix &&other);      // Transfer
    ~S21Matrix();                      // Destructor

    int get_rows() const noexcept;

    int get_cols() const noexcept;

    void set_rows(const int rows);

    void set_cols(const int cols);

    void resize_matrix(const int rows, const int cols);

    bool EqMatrix(const S21Matrix &other) const;

    void SumMatrix(const S21Matrix &other);

    void SubMatrix(const S21Matrix &other);

    void MulNumber(const double num);

    void MulMatrix(const S21Matrix &other);

    S21Matrix Transpose();

    S21Matrix CalcComplements();

    double Determinant();

    S21Matrix InverseMatrix();

    double &operator()(int row, int col) &;

    const double &operator()(int row, int col) const &;

    S21Matrix operator+(const S21Matrix &other) const;

    S21Matrix operator-(const S21Matrix &other) const;

    S21Matrix operator*(const S21Matrix &other) const;

    S21Matrix operator*(const double num) const;

    S21Matrix &operator=(const S21Matrix &other);

    S21Matrix &operator+=(const S21Matrix &other);

    S21Matrix &operator*=(const S21Matrix &other);

    S21Matrix &operator-=(const S21Matrix &other);

    bool operator==(const S21Matrix &other) const;

    S21Matrix &operator=(S21Matrix &&other) noexcept;
};

S21Matrix operator*(double number, const S21Matrix &matrix) noexcept;

#endif