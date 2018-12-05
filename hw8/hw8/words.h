#pragma once
#include <string>
#include <vector>
using namespace std;
class words
{
private:
	string word="";
	int numberOfTimes = 0;
	string lineNumbers = "";
	int compare_to(const words&)const;
public:
	words();
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
	bool operator< (const words&)const;
	bool operator> (const words&)const;
	bool operator<= (const words&)const;
	bool operator>= (const words&)const;
	bool operator== (const words&)const;
	bool operator!= (const words&)const;


	//output operator overload
	friend ostream& operator<< (ostream& out, words &cat);

};

