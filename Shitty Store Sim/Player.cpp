#include "Player.h"


Player::Player()
{
	_money = 100;
}

void Player::printInventory()
{
	for (int i = 0; i < _inventory.size(); i++){
		std::cout << i + 1 << _inventory[i]->getName() << std::endl;
	}
}

void Player::deleteItemFromInventory(int i)
{
	_inventory.erase(_inventory.begin() + (i - 1));
}

Item *Player::sellItem(int i)
{
	return _inventory[i - 1];
}



bool Player::buyItem(Item *item)
{
	if (_money > item->getPrice()){
		_money -= item->getPrice();
		Item *newItem = item;
		_inventory.push_back(newItem);
		return true;
	}
	else{
		std::cout << "You don't have enough money for" << item->getName() << std::endl;
		return false;
	}
}
