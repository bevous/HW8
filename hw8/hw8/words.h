#pragma once
#include <string>
#include <vector>
using namespace std;
class words
{
private:
	string word="";
	int numberOfTimes;
	string lineNumbers;
	int compare_to(const words&)const;
public:
	words();
	words(int n,string w,string l);
	~words();

	//set
	void setWord(string w);
	void setLines(string l);
	void setCount(int c);
	//get
	string getWord()const;
	string getLines()const;
	int getCount()const;
	//compare operators
	void operator=(words&);
	bool operator< (const words&)const;
	bool operator> (const words&)const;
	bool operator<= (const words&)const;
	bool operator>= (const words&)const;
	bool operator== (const words&)const;
	bool operator!= (const words&)const;


	//output operator overload
	friend ostream& operator<< (ostream& out, words &cat);

};

