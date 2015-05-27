#include <iostream>
#include "Interaction.h"


int main()
{
	int num;
	Store *store1;
	Player *player;
	Interaction gameInteration;

	store1->getInventory();
	std::cin >> num;
	gameInteration.playerBuyFromStore(store1, player, num);

	player->printInventory();
	

	system("PAUSE");
	return 0;
}