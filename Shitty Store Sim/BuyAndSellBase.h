#pragma once
#include <vector>

#include <iostream>
#include "Item.h"
#include "Player.h"
#include "Store.h"


class BuyAndSellBase
{
public:
	BuyAndSellBase();
	~BuyAndSellBase();

	void printInventory();
	int getMoney() const { return _money; }
	void deleteItemFromInventory(int i);
	bool deletePointerInInventory(int i);

	Item *getItem(int i);

	bool sellItem(int money, int i);
	bool buyItem(Item *item);
	int _sizeOfInventory()const { return _inventory.size(); }
	void addMoney(int m){ _money += m; }
	void removeMoney(int itemCost);


	int _money;
	int _inventoryLimit = 10;
	std::vector<Item*> _inventory;
};

	