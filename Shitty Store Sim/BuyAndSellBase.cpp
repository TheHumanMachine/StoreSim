#include "BuyAndSellBase.h"


BuyAndSellBase::BuyAndSellBase()
{
}

void BuyAndSellBase::printInventory()
{
	for (int i = 0; i < _inventory.size(); i++){
		std::cout << i + 1 << _inventory[i]->getName() << std::endl;
	}
}

void BuyAndSellBase::deleteItemFromInventory(int i)
{
	_inventory.erase(_inventory.begin() + (i - 1));
	
	
}

bool BuyAndSellBase::deletePointerInInventory(int i)
{
	if (_inventory[i]){
		delete _inventory[i];
		return true;
	}

}


bool BuyAndSellBase::sellItem(int money, int i)
{

	if (money > _inventory[i - 1]->getPrice()){
		_money += _inventory[i - 1]->getPrice();
		deleteItemFromInventory(i - 1);
		return true;
	}
	else{
		return false;
	}
}

Item *BuyAndSellBase::getItem(int i)
{
	return _inventory[i];
}

bool BuyAndSellBase::buyItem(Item *item)
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

void BuyAndSellBase::removeMoney(int itemCost)
{
	_money -= itemCost;
}

BuyAndSellBase::~BuyAndSellBase()
{
}
