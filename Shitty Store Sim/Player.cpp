#include "Player.h"


Player::Player()
{
	_money = 100;
}

void Player::printInventory()
{
	for (int i = 0; i < _inventory.size(); i++){
		std::cout << i + 1 << " " << _inventory[i]->getName() << std::endl;
	}
}

bool Player::clearSoldItem(int i)
{
	if (_inventory[i]){

		std::vector<Item*>::iterator it;
		for (it = _inventory.begin(); it != _inventory.end();){

			if ((*it) == _inventory[i]){
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
	else{
		return false;
	}

}


bool Player::sellItem(int storeMoney, int itemPlace)
{

	if (storeMoney > _inventory[itemPlace - 1]->getPrice()){
		_money += _inventory[itemPlace - 1]->getPrice();
		//clearSoldItem(itemPlace - 1);
		return true;
	}
	else{
		return false;
	}
}

Item *Player::getItem(int i)
{
	return _inventory[i];
}

void Player::recieveItem(Item *item)
{
	_inventory.push_back(std::move(item));
}

bool Player::buyItem(Item *item)
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

void Player::removeMoney(int itemCost)
{
	_money -= itemCost;
}
