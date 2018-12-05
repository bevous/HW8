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
using namespace std;

const string fileName[] = { "ModestProposal_W.txt","Apology_W.txt","WizardOfOz_W.txt",
"MobyDick_W.txt","ShortHistory_W.txt" };
string removePunct(string w) {
	bool erased = false;
	for (unsigned int x = 0; x < w.length(); x++) {
		if (ispunct(w[x])) {
			w.erase(x);
			erased = true;
		}
		else {
			erased = false;
		}
		if (w.length() >= (x + 1)) {
			if (ispunct(w[w.length() - (x + 1)])) {
				w.erase(w.length() - (x + 1));
				erased = true;
			}
			else {
				erased = false;
			}
		}
		if (!erased) {
			break;
		}
	}
	return w;
}

vector<string> myText() {
	vector<string> mybook;
	string buffer = "";
	string temp = "";
	int line = 0;
	fstream infile;
	infile.open(fileName[0]);
	while (getline(infile, buffer)) {
		istringstream s(buffer);
		string buff2;
		while (getline(s, buff2, ' ')) {
			//run through twice to ensure all punctuation was removed
			buff2 = removePunct(removePunct(buff2));
			temp += buff2 + " ";
		}
		mybook.push_back(temp);
		line++;
		temp = "";
	}

	infile.close();
	return mybook;
}

set<words> makeSet() {
	set<words> book;
	string buffer;
	ifstream infile;
	int lineNum = 0;
	words w;
	infile.open(fileName[0]);
	while (getline(infile, buffer)) {
		istringstream s(buffer);
		string buff2;
		lineNum++;
		while (getline(s, buff2,' ')) {
			//run through twice to ensure all punctuation was removed
			buff2 = removePunct(removePunct(buff2));
			if (buff2 != "") {
				w.setWord(buff2);
				book.insert(w);
			}
		}
	}
	infile.close();
	return book;
}

vector<string> getLines(vector<string>& lines, set<words>& book) {
	string lineNums = "";
	string buffer = "";
	vector<int> totalCount;
	int wordnum = 0;
	vector<string> text = myText();
	for (auto word : book) {
		cout << word.getWord() << endl;
		totalCount.push_back(0);
		for (int linenum = 0; linenum < text.size(); linenum++) {
			istringstream thistext(text[linenum]);
			getline(thistext, buffer);

			string buff2 = "";
			istringstream s(buffer);
			while (getline(s, buff2, ' ')) {
				if (buff2 == word.getWord()) {
					if (lineNums == "") {
						lineNums += to_string(linenum);
						totalCount[wordnum]++;
					}
					else {
						lineNums += "," + to_string(linenum);
						totalCount[wordnum]++;
					}
				}
			}
		}
		word.setLines(lineNums);
		word.setCount(totalCount[wordnum]);
		lineNums = "";
		wordnum++;
	}
	
	return lines;
}

void bleh() {
	set<words> book;
	vector<string> lines;
	book = makeSet();
	lines = getLines(lines, book);
	ofstream outf;
	outf.open("mywords.csv");
	int x = 0;
	for (auto word : book) {
		outf << word <<endl;
		cout << word <<endl;
		x++;
	}
}

int main()
{
	bleh();

	system("pause");
	return 0;
}
