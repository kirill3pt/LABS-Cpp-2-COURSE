#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "forEX3.h"

void Conditioner::settings(string mode, double temperature) {
	mode_ = mode;
	if (mode == "Охлаждение") {
		temperature_ -= temperature;
	}
	else if (mode == "Нагрев") {
		temperature_ += temperature; 
	}
}

void Conditioner::print() {
	cout << "Фирма: " << firm_
		<< "\nМодель: " << model_
		<< "\nВес: " << weight_
		<< "\nТемпература: " << temperature_
		<< "\nРежим: " << mode_
		<< "\nГод выпуска: " << year_ << "\n\n";
}

void Conditioner::setFirm(string firm) {
	firm_ = firm;
}

void Conditioner::setMode(string mode) {
	mode_ = mode;
}

void Conditioner::setModel(string model) {
	model_ = model;
}

void Conditioner::setTemperature(double temperature) {
	temperature_ = temperature;
}

void Conditioner::setWeight(double weight) {
	weight_ = weight;
}

void Conditioner::setYear(int year) {
	year_ = year;
}
void Conditioner::serialize() {
	serialize("conditioner.txt");
}
void Conditioner::serialize(const string& filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Ошибка открытия файла для записи!\n";
		return;
	}
	file << firm_ << '\n'
		<< model_ << '\n'
		<< weight_ << '\n'
		<< temperature_ << '\n'
		<< mode_ << '\n'
		<< year_ << '\n';
	file.close();
}
void Conditioner::deserialize() {
	deserialize("conditioner.txt");
}

void Conditioner::deserialize(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Ошибка открытия файла для чтения!\n";
		return;
	}
	getline(file, firm_);
	getline(file, model_);
	file >> weight_ >> temperature_;
	file.ignore();
	getline(file, mode_);
	file >> year_;
	file.close();
}