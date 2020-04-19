#include <iostream>
#include "Bank.h"

using namespace std;

int main()
{
	bank grubbers;

	grubbers.createBank();
	grubbers.createLine();

	grubbers.printPeople();

	grubbers.process();

	grubbers.printPeople();

	return 0;
}