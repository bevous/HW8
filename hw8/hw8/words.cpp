#include "pch.h"
#include "words.h"


int words::compare_to(const words &other)const
{
	if (this->getWord() < other.getWord()) {
		return -1;
	}
	else if (this->getWord() > other.getWord()) {
		return 1;
	}
	else {
		return 0;
	}
}

words::words()
{
}

words::words(int n = 0, string w= "", string l="")
{
	numberOfTimes = n;
	lineNumbers = l;
	word = w;
}

words::~words()
{
}

void words::setWord(string w)
{
	word = w;
}

void words::setLines(string l)
{
	lineNumbers = l;
}

void words::setCount(int c)
{
	numberOfTimes = c;
}

string words::getWord()const
{
	return word;
}

string words::getLines() const
{
	return lineNumbers;
}

int words::getCount() const
{
	return numberOfTimes;
}


void words::operator=(words &rh)
{
	this->setLines(rh.getLines());
	this->setCount(rh.getCount());
	this->setWord(rh.getWord());
}

bool words::operator<(const words &rh)const
{
	return this->compare_to(rh) < 0;
}

bool words::operator>(const words &rh)const
{
	return this->compare_to(rh) > 0;
}

bool words::operator<=(const words &rh)const
{
	return this->compare_to(rh) <= 0;
}

bool words::operator>=(const words &rh)const
{
	return this->compare_to(rh) >= 0;
}

bool words::operator==(const words &rh)const
{
	return this->compare_to(rh) == 0;
}

bool words::operator!=(const words &rh)const
{
	return this->compare_to(rh) != 0;
}

ostream & operator<<(ostream & out, words &cat)
{
	out << cat.getWord() << "(" << cat.getCount() << ") " << cat.getLines();
	return out;
}
