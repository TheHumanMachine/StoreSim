#include "Store.h"
#include "Player.h"


void printMenu();

int main()
{
	int menuResp, buyResp, sellResp;
	Player player1;
	Store store1;
	
	bool isDone = false;

	while (!isDone){

		std::cout << "\n" << std::endl;
		printMenu();

		std::cout << "\nbefore cin >> menuResp" << std::endl;
		std::cin >> menuResp;
		std::cout << "\n";

		switch (menuResp)
		{
		case 1: //Buy Item
			store1.printInventory();
			std::cout << "\nWhat do you want to buy?: ";

			std::cin >> buyResp;
			if (player1.buyItem(store1.getItem(buyResp - 1))){
				std::cout << "if statement, before print item->getName()" << std::endl;
				std::cout << store1.getItem(buyResp - 1)->getName() << " was bought" << std::endl;
				store1.clearSoldItem(buyResp - 1);
			}
			else{
				std::cout << "You failed to purchase the item." << std::endl;
			}
			break;

		case 2: //Sell Item
			std::cout << "Your inventory:" << std::endl;
			player1.printInventory();
			std::cout << "\nWhat item of yours do you want to sell? ";

			std::cin >> sellResp;

			if (player1.sellItem(store1.getMoney(), sellResp)){

				store1.recieveItem(player1.getItem(sellResp - 1));
				player1.clearSoldItem(sellResp - 1);
			}
			else{
				std::cout << "The store could not buy that item!" << std::endl;
			}

			break;
		case 3://Leave game
			std::cout << "You have quit the game" << std::endl;
			isDone = true;
		}


		menuResp = 0;
	}

	system("PAUSE");
	return 0;
}

void printMenu()
{
	std::cout << "[1] Buy an item" << std::endl;
	std::cout << "[2] Sell an item" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "What do you want to do?: ";


}