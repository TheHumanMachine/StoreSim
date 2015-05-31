#include "Store.h"

Store::Store()
{
	_money = 50;
	setItemsInInventory();
}


void Store::setItemsInInventory()
{
	for (int i = 0; i < _shopsize; i++){
		_inventory.push_back(new Item("Test name"));
	}
}


void Store::updatePrice(float modifier)
{
	for (int i = 0; i < _inventory.size(); i++)
	{
		_inventory[i]->updateItemPrice(modifier);
	}
}

void Store::printInventory()
{
	if (_inventory.size() != 0){
		std::cout << _inventory.size() << std::endl;
		for (int i = 0; i < _inventory.size(); i++){
			std::cout << i + 1 << " " << _inventory[i]->getName() << std::endl;
		}
	}
	else{
		std::cout << "Store Inventory is empty" << std::endl;
	}
}


bool Store::clearSoldItem(int i)
{

		std::vector<Item*>::iterator it;
		for (it = _inventory.begin(); it != _inventory.end();){

			if ( (*it) == _inventory[i]){
				//delete *it;
				it = _inventory.erase(it);
				return true;
			}
			else{
				it++;
			}

		}
		return false;

}


bool Store::sellItem(int money, int i)
{

	if (money > _inventory[i - 1]->getPrice()){
		_money += _inventory[i - 1]->getPrice();
		return true;
	}
	else{
		return false;
	}
}

Item *Store::getItem(int i)
{
	return _inventory[i];
}

void Store::recieveItem(Item *item)
{
	std::cout << "inside the recieveItem function!" << std::endl;
	_inventory.push_back(std::move(item));
}

bool Store::buyItem(Item *item)
{
	if (_money > item->getPrice()){
		_money -= item->getPrice();
		_inventory.push_back(std::move(item));
		return true;
	}
	else{
		return false;
	}
}

void Store::removeMoney(int itemCost)
{
	_money -= itemCost;
}

