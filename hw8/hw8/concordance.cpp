#include "pch.h"
#include "concordance.h"


concordance::concordance()
{
}


concordance::~concordance()
{
}
bool concordance::checkAscii(char c) {
	const int lowerAscii = 0;
	const int upperAscii = 128;
	if (c >= lowerAscii && c <= upperAscii) {
		return false;
	}
	else {
		return true;
	}

}
//removes all non ascii chars
string concordance::removeNonAscii(string w) {
	for (int x = 0; x < w.length(); x++) {
		if (checkAscii(w[x])) {
			w.erase(x);
			x--;
		}
	}
	return w;
}
//removes all punctuation
string concordance::removePunct(string w) {
	bool erased = true;
	w = removeNonAscii(w);
	for (unsigned int x = 0; x < w.length(); x++) {
		if (erased) {
			if (ispunct(w[x])) {
				w.erase(x);
				x = 0;
				erased = true;
			}
			else {
				erased = false;
			}
		}
		else { x = w.length(); }

	}
	erased = true;
	for (int x = w.length() - 1; x >= 0; x--) {
		if (erased) {
			if (ispunct(w[x])) {
				w.erase(x);
				x = w.length();
				erased = true;
			}
			else {
				erased = false;
			}
		}
		else {
			x = -1;
		}
	}

	return w;
}
//copies the file into a vector for faster parsing
vector<string> concordance::myText(int select) {
	vector<string> mybook;
	string buffer = "";
	string temp = "";
	int line = 0;
	fstream infile;
	infile.open(fileName[select]);
	while (getline(infile, buffer)) {
		removeNonAscii(buffer);
		istringstream s(buffer);
		string buff2;
		while (getline(s, buff2, ' ')) {

			buff2 = removePunct(buff2);
			temp += buff2 + " ";
		}
		mybook.push_back(temp);
		line++;
		temp = "";
	}

	infile.close();
	return mybook;
}
//gets the line numbers and number of times each word appears
set<words> concordance::getInfo(set<words> book, int select) {
	string lineNums = "";
	string buffer = "";
	int totalCount = 0;
	int worddone = 0;
	set<words> bookv2;
	vector<string> text = myText(select);
	for (auto word : book) {
		cout << "getting data %" << /*(int)*/(100 * ((float)worddone / book.size())) << '\r';
		for (int linenum = 0; linenum < text.size(); linenum++) {
			istringstream thistext(text[linenum]);
			getline(thistext, buffer);

			string buff2 = "";
			istringstream s(buffer);
			while (getline(s, buff2, ' ')) {
				if (buff2 == word.getWord()) {
					totalCount++;
					if (lineNums == "") {
						lineNums += to_string(linenum);
					}
					else {
						lineNums += "," + to_string(linenum);
					}
				}
			}
		}
		bookv2.insert(words(totalCount, word.getWord(), lineNums));
		//word.setLines(lineNums);
		//word.setCount(totalCount);
		lineNums = "";
		totalCount = 0;
		worddone++;
	}
	return bookv2;
}
//gathers all the unique words in the file
set<words> concordance::makeSet(int select) {
	cout << "collecting words." << endl;
	set<words> book;
	string buffer;
	ifstream infile;
	int lineNum = 0;
	words w;
	infile.open(fileName[select]);
	while (getline(infile, buffer)) {
		//cout << buffer << endl;
		istringstream s(buffer);
		string buff2;
		lineNum++;
		while (getline(s, buff2, ' ')) {
			buff2 = removePunct(buff2);
			if (buff2 != "") {
				w.setWord(buff2);
				book.insert(w);
			}
		}
	}
	infile.close();
	return getInfo(book, select);

}
//prints to screen and saves into a file the entire concordance
void concordance::output(int select) {
	string name = fileName[select];
	name.erase((name.length() - 5), (name.length()-1));
	name += "concordance.txt";
	ofstream outf;
	outf.open(name);
	for (auto word : book) {
		outf << word << endl;
		cout << word << endl;
	}
}
