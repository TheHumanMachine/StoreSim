#pragma once
#include <vector>
#include <iostream>
#include "Item.h"



class Store
{
public:
	Store();

	void setItemsInInventory();
	void updatePrice(float modifier);


	//Selling and Buying functions
	void printInventory();
	bool clearSoldItem(int i);

	Item *getItem(int i);
	void recieveItem(Item *item);
	bool sellItem(int money, int i);
	bool buyItem(Item *item);
	int _sizeOfInventory()const { return _inventory.size(); }

	int getMoney() const { return _money; }
	void addMoney(int m){ _money += m; }
	void removeMoney(int itemCost);

private:
	int _money = 100;
	int _shopsize = 10;
	std::vector<Item*> _inventory;
};

