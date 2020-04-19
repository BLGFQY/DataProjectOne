#pragma once
#include <iostream>
#include <string>

using namespace std;

// class to store each individual transaction
class transaction
{
private:
	// amount moved
	double amount;
	// deposit or withdrawal
	bool type;
	// reference number
	int tranNum;
	// account holder's name
	string name;

public:
	// default constructor
	transaction()
	{
		name = "NULL";
		amount = -1;
		type = 0;
		tranNum = -1;
	}

	// specialized constructor
	transaction(string tempName, double tempAm, int tempNum, bool tempType)
	{
		name = tempName;
		amount = tempAm;
		type = tempType;
		tranNum = tempNum;
	}

	// information getters
	string getName() { return name; }
	double getAm() { return amount; }
	bool getType() { return  type; }
	int getTran() { return tranNum; }

	// print function displays transaction
	void print();
	
	// no need for setters, all done in constructor
};

// method to print out an individual transaction
void transaction::print()
{
	cout << "Client Name: " << name << endl;
	cout << "Transfer Type: " << type << endl;
	cout << "Transfer Amount: " << amount << endl;
	cout << "Reference Number: " << tranNum << endl;
	cout << "--------------------------------------" << endl;
}