#include "PicoYPlacaVerficator.h"
#include <iostream>
#include <string>

using namespace std;

int LastDigit;
string Day;
int Hours;
int Minutes;
int Counter = 0;

string PicoYPlacaVerficator::PicoYPlacaValidator(string PlateNumber, string Date, string Hour)
{
	LastDigit = atoi(PlateNumber.substr(7, 1).c_str());
	size_t pos = Date.find(" ");
	Day = Date.substr(0, pos);
	Hours = atoi(Hour.substr(0, 2).c_str());
	Minutes = atoi(Hour.substr(3, 5).c_str());

	if ((LastDigit == 1 || LastDigit == 2) && (Day == "Lunes"))
	{
		Counter = Counter + 1;
	}
	else if ((LastDigit == 3 || LastDigit == 4) && (Day == "Martes"))
	{
		Counter = Counter + 1;
	}
	else if ((LastDigit == 5 || LastDigit == 6) && (Day == "Miercoles"))
	{
		Counter = Counter + 1;
	}
	else if ((LastDigit == 7 || LastDigit == 8) && (Day == "Jueves"))
	{
		Counter = Counter + 1;
	}
	else if ((LastDigit == 9 || LastDigit == 0) && (Day == "Viernes"))
	{
		Counter = Counter + 1;
	}

	if ((Hours >= 7 && Hours <= 8) && (Minutes >= 00 && Minutes <= 59) || (Hours >= 16 && Hours <= 18) && (Minutes >= 00 && Minutes <= 59))
	{
		Counter = Counter + 1;
	}

	if ((Hours >= 9 && Hours < 8) && (Minutes >= 00 && Minutes <= 30) || (Hours >= 19 && Hours < 20) && (Minutes >= 00 && Minutes <= 30))
	{
		Counter = Counter + 1;
	}

	if (Counter == 2)
	{
		return "No puede transitar, tiene pico y placa.";
	}
	else
	{
		return "Puede transitar libremente.";
	}

	system("Pause");
	system("cls");

}//end PicoYPlacaValidator


