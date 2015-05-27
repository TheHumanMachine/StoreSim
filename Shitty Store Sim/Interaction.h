#pragma once
#include <iostream>
#include "Store.h"
#include "Player.h"
#include "Item.h"

class Interaction
{
public:
	Interaction();
	bool playerBuyFromStore(Store *store, Player *player, int i);
	bool playerSellToStore(Store *store, Player *player, int i);

	bool storeBuyFromPlayer(Store *store, Player *player, int i);
	bool storeSellToPlayer(Store *store, Player *player, int i);


};

