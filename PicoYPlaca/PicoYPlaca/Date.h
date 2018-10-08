#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;

class Date
{
	string Date;


public:

	string ReceiveDate(string Date);
	bool CheckDate(string Date);
	string PrintDate(int Day, int Month, int Year);
	bool VerifyDayMonth(int Day, int Month);

private:
	bool Checker = false;
	string CompleteDate;
};

#endif 


