#pragma once
#ifndef PLATENUMBER_H
#define PLATENUMBER_H
#include <iostream>

using namespace std;

class PlateNumber
{
	string PlateNumber;

public:

	string ReceivePlateNumber(string PlateNumber);
	bool CheckPlateNumber(string CheckPlate);

private:

	bool Checker = false;
};

#endif
