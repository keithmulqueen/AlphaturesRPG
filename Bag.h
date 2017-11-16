#pragma once
#include "Item.h"
#include <vector>

class Bag
{
public:
	Bag();
	~Bag();

	void addToBag(Item passed_newItem);
	void removeFromBag(int removeIndex);
	void openBag();

	std::vector< Item > myBag;

private:

	Item newItem;
	

};

