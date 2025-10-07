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
	data_ = new int[size_];   // �������� ������
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
	Vector temp(size_);                // ������ ��������� ������
	for (int i = 0; i < size_; i++) {
		temp.data_[i] = data_[i];      // �������� ������ ��������
	}
	for (int i = 0; i < size_; i++) {
		++data_[i];                    // ����������� �������
	}
	return temp;                       // ���������� ������ ������
}
// v--
Vector Vector::operator--(int) {		
	Vector temp(size_);					// ������ ��������� �����
	for (int i = 0; i < size_; i++) {
		temp.data_[i] = data_[i];		// �������� ������ ��������
	}										
	for (int i = 0; i < size_; i++) {
		--data_[i];						// ��������� �������
	}
	return temp;						// ���������� ������ ������
}
// --v
Vector& Vector::operator--() {
	for (int i = 0; i < size_; i++)
		--data_[i];
	return *this;
}
Vector::~Vector() {
	delete[] data_; //������������ ������
}