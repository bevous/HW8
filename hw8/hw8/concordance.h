#pragma once
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
using namespace std;
class concordance
{
private:
	string fileName[5] = { "ModestProposal_W.txt","Apology_W.txt","WizardOfOz_W.txt",
"MobyDick_W.txt","ShortHistory_W.txt" };
	set<words> book;
public:
	concordance();
	~concordance();
bool checkAscii(char c);

string removeNonAscii(string w);

string removePunct(string w);

vector<string> myText(int select);

set<words> getInfo(set<words> book, int select);

set<words> makeSet(int select);

void output(int select);


};


