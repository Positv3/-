#pragma once
#include <iostream>
#include <conio.h>

class Goods
{
public:

	Goods() {};
	Goods(std::string name, double weight, double price): name(name), weight(weight), 
		price(price) {};

	void setPrice(double);
	void setWeight(double);

	double getPrice();
	double getWeight();
	int getQuantitySold();

	void info();

private:

	double price = 0.0;
	double weight = 0.0;
	int quantitySold = 0;

	std::string name;
};

