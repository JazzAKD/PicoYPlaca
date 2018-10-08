#pragma once
#ifndef HOUR_H
#define HOUR_H
#include <iostream>

using namespace std;

class Hour
{
public:
	string ReceiveHour(string Hour);
	bool CheckHour(string Hour);

private:
	bool Checker = false;
};

#endif 
