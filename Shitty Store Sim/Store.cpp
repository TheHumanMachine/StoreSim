#include "Store.h"


Store::Store()
{
	_money = 50;
	for (int i = 0; i < _shopsize; i++){
		_inventory.push_back(new Item("Test Name"));
	}
}

void Store::getInventory()
{
	std::cout << "*** Welcome to the Store ***\n\n" << std::endl;
	for (int i = 0; i < _inventory.size(); i++)
	{
		std::cout <<  i+1 << " Item: " << _inventory[i]->getName() << ", Cost: " << _inventory[i]->getPrice() << std::endl;
	}
	std::cout << "\nWhat would you like to buy?[Enter 1 - " << _sizeOfInventory() << "]" << std::endl;
}

void Store::getItemInInventory(int i)
{
	 _inventory[i]->getName();
}

void Store::updatePrice(float modifier)
{
	for (int i = 0; i < _inventory.size(); i++)
	{
		_inventory[i]->updateItemPrice(modifier);
	}
}

void Store::deleteItemFromInventory(int i)
{
	_inventory.erase(_inventory.begin() + (i - 1));
}

bool Store::buyItem(Item *item)
{
	if (_money >= item->getPrice()){

		_money -= item->getPrice();

		Item *newItem = item;
		_inventory.push_back(newItem);
		return true;
	}
	else{
		std::cout << "The Store does not have enough money for" << item->getName() << std::endl;
		return false;
	}
}

Item *Store::sellItem(int i)
{
	return _inventory[i-1];
}
