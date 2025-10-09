#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Conditioner {
private:
	string firm_;
	string model_;
	double weight_, temperature_;
	string mode_;
	int year_;
public:
	Conditioner(string firm, string model, double weight, double temperature, string mode, int year) : //для кучи
		firm_(firm), model_(model), weight_(weight), temperature_(temperature), mode_(mode), year_(year) { }
	Conditioner() : firm_(""), model_(""), weight_(0), temperature_(0), mode_(""), year_(0) { } //для стека
	void setFirm(string firm);
	void setModel(string model);
	void setWeight(double weight);
	void setTemperature(double temperature);
	void setMode(string mode);
	void setYear(int year);
	void settings(string mode, double temperature = 0);
	void print();
	double temperatureShow() {
		return temperature_;
	}
	void serialize();                              
	void serialize(const string& filename);        
	void deserialize();                           
	void deserialize(const string& filename);      
};