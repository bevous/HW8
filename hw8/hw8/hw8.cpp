// hw8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <locale>
using namespace std;

int main()
{
	set<string> words;
	string buffer;
	bool erased;
	ifstream infile;
	infile.open("MobyDick_W.txt");
	int count = 0;
	while (getline(infile,buffer,' ')) {
		
		//cout << "wordnum " << count << " "<< buffer << '\r';
		count++;
		for (int x = 0; x < buffer.length(); x++) {
			cout << buffer << "  " << x << endl;
			if (ispunct((int)buffer[x])) {
				buffer.erase(x);
				erased = true;
			}
			else { erased = false; }
			if (ispunct((int)buffer[buffer.length()-(x+1)])) {
				buffer.erase(buffer.length() - (x + 1));
				erased = true;
			}
			else
			{
				erased = false;
			}
			if (!erased) {
				break;
			}
		}
		words.insert(buffer);
	}
	cout << words.size() << endl;
	infile.close();

	system("pause");
	return 0;
}
