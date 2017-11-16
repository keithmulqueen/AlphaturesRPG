#include "stdafx.h"
#include "Bag.h"
#include "Item.h"
#include <vector>



Bag::Bag()
{
	
}


Bag::~Bag()
{
}

void Bag::addToBag(Item passed_newItem)
{
	newItem = passed_newItem;

	//adds new Item to the end of the bag list
	myBag.push_back(newItem);

}

void Bag::removeFromBag(int removeIndex)
{
	myBag.erase(myBag.begin() + removeIndex);
}

void Bag::openBag()
{

}
