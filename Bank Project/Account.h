#pragma once
#include "Transaction.h"
#include <iostream>
#include <list>
#include <set>

using namespace std;

// base class for storing individual information for each account holder
class account
{
private:
	// string for storing account holder's name
	string name;

	// double for storing amount of money in account
	double balance; 

	// list to hold all previous transactions
	list<transaction> transfers;

public:
	// default constructor
	account()
	{
		name = "NULL";
		balance = 0;
	}

	// specialized constructor
	account(pair<string, string> tempName, double val)
	{
		name = tempName.first + ' ' + tempName.second;
		balance = val;
	}
	
	// getter for account holder's name
	string getName() { return name; }
	
	// getter and setter for account balance
	int getBal() { return balance; }
	void setBal(double newBal) { balance = newBal; }

	// setter to add a transaction to list of previous
	void setTran(transaction newTran) { transfers.push_back(newTran); }

};
