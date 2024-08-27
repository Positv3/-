#pragma once
#include "Goods.h"

#include <iostream>
#include <vector>


class Stock
{
public:


	void Add();
	bool buy(double&);
	void Delete(int);
	void showGoods();
	void changeInfo();
	void analyseSales();
	void specificGoods();
	double getPrice() const;
	Goods  getGoods() const;


private:

	Goods* gds;

	std::vector<Goods*>arr;

	std::string nameOfGoods;

	double price  = 0.0;
	double weight = 0.0;
	double profit = 0.0;

	int choice = 0;
	int goal = 5000;
	int quantityOfAllGoodsSold = 0;
};

