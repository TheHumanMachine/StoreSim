#include "Interaction.h"


Interaction::Interaction()
{
}


bool Interaction::playerBuyFromStore(Store *store, Player *player, int i)
{
	if (player->buyItem(store->sellItem(i))){
		store->addStoreMoney(store->sellItem(i)->getPrice());
		store->deleteItemFromInventory(i);

		return true;
	}
	else{
		std::cout << "You do not have enough money to purchase" << store->sellItem(i)->getName() << std::endl;
		return false;
	}
}

bool Interaction::playerSellToStore(Store *store, Player *player, int i)
{
	if (store->buyItem(player->sellItem(i))){
		player->addPlayerMoney(player->sellItem(i)->getPrice());
		return true;
	}
	else{
		std::cout << "The Store did not have enough money to buy your item." << std::endl;
		return false;
	}
}

bool Interaction::storeBuyFromPlayer(Store *store, Player *player, int i)
{
	if (store->buyItem(player->sellItem(i))){
		player->addPlayerMoney(player->sellItem(i)->getPrice());
		player->deleteItemFromInventory(i);

		return true;
	}
	else{
		std::cout << "The store does not have enough money to purchase" << player->sellItem(i)->getName() << std::endl;
		return false;
	}
}
bool Interaction::storeSellToPlayer(Store *store, Player *player, int i)
{
	if (player->buyItem(store->sellItem(i))){
		store->addStoreMoney(player->sellItem(i)->getPrice());
		return true;
	}
	else{
		std::cout << "The Store did not have enough money to buy your item." << std::endl;
		return false;
	}
}