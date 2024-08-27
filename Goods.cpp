#include "Goods.h"

void Goods::setPrice(double price)
{
	this->price = price;
}

void Goods::setWeight(double weight)
{
	this->weight = weight;
}

double Goods::getPrice()
{
	return price;
}

double Goods::getWeight()
{
	return weight;
}

int Goods::getQuantitySold()
{
	return quantitySold;
}

void Goods::info()
{
	std::cout << "Name -> " <<  name << "\nWeight -> " <<  weight << 
		"\nPrice -> " <<  price << std::endl << std::endl;
}



