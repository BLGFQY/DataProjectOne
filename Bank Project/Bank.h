#pragma once
#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <iomanip>
#include <list>
#include <stack>
#include <string>
#include <random>
#include <fstream>

using namespace std;

class bank : public account
{
private:
	// list stores all accounts at bank
	list<account> people;
	// stack stores all people waiting to be served
	stack<transaction> waiting;

public:
	void createBank();
	void createLine();
	void printPeople();
	void printWaiting();
	void process();
};

// method to be called in main that reads in from "Text.txt" and creates the list of accounts
void bank::createBank()
{
	fstream fin;
	fin.open("text.txt");
	double amount;
	pair<string, string> name;
	for (int i = 0; i < 10; i++)
	{
		fin >> name.first >> name.second >> amount;
		account temp(name, amount);
		people.push_back(temp);
		//cin.clear(); cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
}

// method that prints all accounts
void bank::printPeople()
{
	list<account>::iterator ptr;
	string name;
	cout << setfill('-') << "Account Holder's Name" << setw(2) << '|' << setw(20) << "Account Value" << endl;
	cout.width(43); cout << setfill('=') << '=' << endl;
	for (ptr = people.begin(); ptr != people.end(); ptr++)
	{
		name = ptr->getName();
		cout.width(22);
		cout << setfill(' ') << name << '|';
		cout.width(20);
		cout << ptr->getBal() << endl;
	}
	cout << endl;
}

 // method to randomly generate line of people waiting
void bank::createLine()
{
	int tempTran; int tempAm;
	string tempName;
	bool tempType;
	list<account>::iterator ptr;

	for (int i = 0; i < 40; i++)
	{
		ptr = people.begin();
		tempTran = rand();
		tempAm = rand() % 10000;
		advance(ptr, rand() % people.size());
		tempName = ptr->getName();
		tempType = rand() % 2;
		transaction temp(tempName, tempAm, tempTran, tempType);
		waiting.push(temp);
	}
}

// method that prints number of people waiting and next person up
void bank::printWaiting()
{
	transaction temp = waiting.top();
	cout << "The number of people currently waiting is " << waiting.size() << endl;
	cout << "Next up is " << temp.getName() << endl;
	cout << "--------------------------------------" << endl;
}

// method to call that processes wait line
void bank::process()
{
	transaction current;
	list<account>::iterator ptr;
	int temp;
	cout << endl;
	while (waiting.size() != 0)
	{
		current = waiting.top();
		waiting.pop();
		for (ptr = people.begin(); ptr != people.end(); ptr++)
		{
			if (ptr->getName() == current.getName())
			{
				ptr->setTran(current);
				//current.print();
				if (current.getType() == false)
				{
					temp = ptr->getBal() - current.getAm();
					ptr->setBal(temp);
				}
				else
				{
					temp = ptr->getBal() + current.getAm();
					ptr->setBal(temp);
				}
				break;
			}
		}
		if (waiting.size() % 5 == 0 && waiting.size() != 0)
		{
			printWaiting();
		}
	}
}