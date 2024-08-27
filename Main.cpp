#include "Stock.h"
#include "Customer.h"

#include <iostream>
#include <conio.h>
#include <vector>
#include <map>

void Menu();


int main()
{	
	Menu();

	return 0;
}

void Menu()
{
	Stock firstStock;
	Customer cs;

	int choice = 0;

	while (1)
	{
		system("CLS");

		std::cout << "1.User\n2.Customer\n3.Exit\n\n";
		std::cin >> choice;

		if (choice == 1)
		{
			do {

				system("CLS");

				std::cout << "\t\tMenu User\n\n" <<
					"\n1.View all goods\n2.View a specific product" <<
					"\n3.Add a product\n4.Delete a product\n5.Change info\n6.Check profit" <<
					"\n7.Choose user\n\n";

				std::cin >> choice;

				switch (choice)
				{
				case 1:
					firstStock.showGoods();
					break;
				case 2:
					firstStock.specificGoods();
					break;
				case 3:
					firstStock.Add();
					break;
				case 4:
					std::cout << "Enter a number of product that you want to delete: ";
					std::cin >> choice;
					firstStock.Delete(choice); 
					break;
				case 5:
					firstStock.changeInfo();
					break;
				case 6:
					firstStock.analyseSales();
					break;
				case 7:
					break;
				default:
					std::cout << "\n\nTry again";
					break;
				}
			} while (choice != 7);
		}

		else if (choice == 2)
		{
			do
			{
				system("CLS");

				std::cout << "\t\tMenu Customer\n\nSelect one of the option below:" <<
					"\n1.View all goods\n2.Buy goods\n3.Purchased goods\n4.Cash" <<
					"\n5.Choose user\n\n";
				std::cin >> choice;

				switch (choice)
				{
				case 1:
					firstStock.showGoods();
					break;
				case 2:
					cs.buy(firstStock);
					break;
				case 3:
					cs.purchasedGoods();
					break;
				case 4:
					system("CLS");
					std::cout << "Balance is " << cs.getMoney();
					_getch();
					break;
				case 5:
					break;
				default:
					std::cout << "Try again!\n\n";
					break;
				}

			} while (choice != 5);
		}

		else if (choice == 3) return;
	}
}
