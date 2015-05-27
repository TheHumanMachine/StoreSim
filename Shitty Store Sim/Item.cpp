#include "Item.h"


Item::Item(std::string name)
{
	_name = name;

}

void Item::updateItemPrice(float modifier)
{
	_price *= modifier; 
}

