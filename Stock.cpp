#include "Stock.h"


void Stock::Add()
{
	system("CLS");

	std::cout << "Enter the number of products you want: ";
	std::cin >> choice;

	for (int i = 0; i < choice; ++i)
	{
		std::cout << "\nEnter name, weight, price\n";
		std::cin >> nameOfGoods >> weight >> price;

		gds = new Goods(nameOfGoods, weight, price);
	}
}


void Stock::Delete(int index)
{
	system("CLS");

	if ((index < 0) || (index > arr.size()))
	{
		std::cout << "There's no such goods! Press any key...\n";
		_getch();
		return;
	}
	else
		arr.erase(arr.begin() + index);
}


void Stock::changeInfo()
{
	system("CLS");

	if (arr.empty())
	{
		std::cout << "There's no goods! Press any key...\n";
		_getch();
		return;
	}
	else 
	{
		std::cout << "What the goods do you want to change?\n";
		std::cin >> choice;

		gds = std::move(arr.at(choice - 1));

		std::cout << "\n\nWhat do you want to change in the goods? " <<
			"\n1.Weight\n2.Price\n";
		std::cin >> choice;

		if (choice == 1)
		{
			std::cout << "Write weight -> ";
			std::cin >> choice;
			gds->setWeight(choice);
		}
		else if (choice == 2)
		{
			std::cout << "Write price -> ";
			std::cin >> choice;
			gds->setPrice(choice);
		}
	}
	
	_getch();
}


void Stock::analyseSales()
{
	system("CLS");

	if (quantityOfAllGoodsSold == 0)
	{
		std::cout << "No goods sold!\n";
		_getch();
		return;
	}

	std::cout << "Goods sold -> " << quantityOfAllGoodsSold << std::endl;
	std::cout << "Goal is " << goal << "$\n\n";
	
	if (profit >= 5000)
		std::cout << "We've achieved our goal!\n";

	else
		std::cout << "Our sales is low than we expected!\n";


	std::cout << "Profit -> " << profit << "\nPress any key...";

	_getch();
}


void Stock::showGoods()
{
	system("CLS");
	setlocale(LC_ALL, "Russian");

	if (arr.empty())
	{
		std::cout << "There's no goods! Press any key...\n";
		_getch();
		return;
	}

	else
	{
		int i = 0;
		for (const auto& gds : arr)
		{
			std::cout << "¹" << i + 1 << std::endl;
			gds->info();
			i++;
		}
	}

	_getch();
}


bool Stock::buy(double& cash)
{
	if (arr.empty())
	{
		std::cout << "There's no goods! Press any key...\n";
		_getch();
		return false;
	}
	else
	{
		while (1)
		{
			std::cout << "Enter a number goods what you want to buy: ";
			std::cin >> choice;

			if (choice < 1 || choice > arr.size())
			{
				std::cout << "Invalid index! Try it again\n";
				_getch();
				continue;
			}
			else
			{
				gds = arr.at(choice-1);
				
				if (cash < gds->getPrice())
				{
					std::cout << "\nYou don't have money enough! Choose another goods.\n\n";
					std::cin.get();
					continue;
				}

				else
				{
					profit += gds->getPrice();
					cash -= gds->getPrice();
					quantityOfAllGoodsSold += 1; 

					Delete(choice-1);
					return true;
				}
			}
		}
	}
} 


void Stock::specificGoods()
{
	system("CLS");

	if (arr.empty())
	{
		std::cout << "There's no goods! Press any key...\n";
		_getch();
		return;
	}
	else
	{
		std::cout << "Enter a number of specific number: ";
		std::cin >> choice;
		std::cout << std::endl;

		gds = arr.at(choice - 1);
		gds->info();
	}

	_getch();
}

Goods Stock::getGoods() const
{
	return *gds;
}

double Stock::getPrice() const
{
	return price;
}

