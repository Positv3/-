#pragma once
#include "Stock.h"

class Customer
{
public:

	int  getMoney();
	void setMoney(int);
	void buy(Stock& st);
	void purchasedGoods();
	
private:

	std::vector<Goods>allGoods;

	int ch = 0; 
	int purchaseGoods = 0;
	double money = 2000.0;
};

