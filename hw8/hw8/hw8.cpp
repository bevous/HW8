// hw8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <locale>
#include "words.h"
#include "concordance.h"

using namespace std;



const string fileName[] = { "ModestProposal_W.txt","Apology_W.txt","WizardOfOz_W.txt",
"MobyDick_W.txt","ShortHistory_W.txt" };


void bleh() {
	concordance myconcordance;
	int select = 0;
	//print the file names
	for (int x = 0; x < 5;x++) {
		cout << x <<" "<< fileName[x] << ", ";
	}
	cout << "enter the coresponding number." << endl;
	//validate user selection
	do{
		if (cin.fail() || (select < 0 || select > 4)){
			cout << "try again." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cin >> select;
	} while (cin.fail() || (select < 0 || select > 4));
	myconcordance.makeSet(select);
	// call the output function
	myconcordance.output(select);
}

int main()
{
	bleh();
	return 0;
}
