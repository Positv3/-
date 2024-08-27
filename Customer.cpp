#include "Customer.h"

void Customer::setMoney(int money)
{
	this->money = money;
}

int Customer::getMoney()
{
	return money;
}

void Customer::buy(Stock& st)
{
	system("CLS");

	while (1)
	{
		if (st.buy(money))
		{
			purchaseGoods++;
			std::cout << "Successful!\nPress any key...";
			allGoods.push_back(st.getGoods());
			_getch();
			return;
		}

		else
			return;
	}
}

void Customer::purchasedGoods()
{
	system("CLS");
	setlocale(LC_ALL, "Russian");

	int i = 0;
	for (Goods& gds : allGoods)
	{
		std::cout << "¹" << i + 1 << std::endl;
		gds.info();
		i++;
	}

	_getch();
}


