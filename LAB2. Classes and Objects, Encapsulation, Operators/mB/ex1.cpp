#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include "forEX1.h"

using namespace std;

Vector::Vector(int n) {
	size_ = n;
	data_ = new int[size_]; 
}
void Vector::initArray() {
	for (int i = 0; i < size_; i++) {
		data_[i] = i * i + 1;
		if (i % 2 != 0) {
			data_[i] *= -1;
		}
	}
}
void Vector::print1D() {
	cout << "[";
	for (int i = 0; i < size_; i++) {
		cout << setw(5) << data_[i];
	}
	cout << setw(5) << ']';
	cout << '\n' << endl;
}
int& Vector::operator[](int index) {
	return data_[index];
}
// ++v
Vector& Vector::operator++() {
	for (int i = 0; i < size_; i++) {
		++data_[i];
	}
	return *this;
}
// v++
Vector Vector::operator++(int) {
	Vector temp(size_);                // создаём временный вектор
	for (int i = 0; i < size_; i++) {
		temp.data_[i] = data_[i];      // копируем старые значения
	}
	for (int i = 0; i < size_; i++) {
		++data_[i];                    // увеличиваем текущие
	}
	return temp;                       // возвращаем старую версию
}
// v--
Vector Vector::operator--(int) {		
	Vector temp(size_);					// создаём временный векто
	for (int i = 0; i < size_; i++) {
		temp.data_[i] = data_[i];		// копируем старые значения
	}										
	for (int i = 0; i < size_; i++) {
		--data_[i];						// уменьшаем текущие
	}
	return temp;						// возвращаем старую версию
}
// --v
Vector& Vector::operator--() {
	for (int i = 0; i < size_; i++)
		--data_[i];
	return *this;
}
Vector::~Vector() {
	delete[] data_; 
}
Matrix::Matrix(int r, int c) {
	rows_ = r;
	cols_ = c;
	data_ = new int* [rows_];
	for (int i = 0; i < rows_; i++)
		data_[i] = new int[cols_];
}
void Matrix::convert1Dto2D(const int* arr, int totalSize) {
	int k = 0;
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			if (k < totalSize)
				data_[i][j] = arr[k++];
			else
				data_[i][j] = 0;
		}
	}
}

void Matrix::print2D() {
	cout << "=>" << endl;
	for (int i = 0; i < rows_; i++) {
		if (i == 0) cout << "[ ";
		else cout << "  ";
		for (int j = 0; j < cols_; j++) {
			cout << setw(5) << data_[i][j];
		}
		if (i == rows_ - 1) cout << " ]";
		cout << endl;
	}
	cout << endl;
}
int Matrix::at(int i, int j) const {
	return data_[i][j];
}
void Matrix::setAt(int i, int j, int val) {
	data_[i][j] = val;
}
Matrix& Matrix::operator++() {
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			++data_[i][j];
	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix temp(rows_, cols_);
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			temp.data_[i][j] = data_[i][j];
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			++data_[i][j];
	return temp;
}

Matrix& Matrix::operator--() {
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			--data_[i][j];
	return *this;
}

Matrix Matrix::operator--(int) {
	Matrix temp(rows_, cols_);
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			temp.data_[i][j] = data_[i][j];
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			--data_[i][j];
	return temp;
}

Matrix::~Matrix() {
	for (int i = 0; i < rows_; i++)
		delete[] data_[i];
	delete[] data_;
}