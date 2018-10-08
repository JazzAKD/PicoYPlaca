#include "Hour.h"
#include <iostream>
#include <string>

using namespace std;

string Hour::ReceiveHour(string Hour)
{
	do
	{
		cout << "\n\nPor favor ingrese la hora, formato: hh:mm. Ejm 07:50 o 16:35: ";
		cin >> Hour;
		Checker = CheckHour(Hour);
		if (Checker == false)
		{
			cout << "\nDatos mal ingresados por favor reintente." << endl;

		}
		else
		{
			cout << "\nDatos ingresados con exito." << endl;
			return Hour;
		}

		system("Pause");
		system("cls");
	} while (Checker == false);

}//end ReceiveHour

bool Hour::CheckHour(string Hour)
{
	int Hour1;
	int Minute;

	if (Hour.length() == 5)
	{
		size_t pos = Hour.find(":");
		if (pos == 2)
		{
			Hour1 = atoi(Hour.substr(0, 2).c_str());
			Minute = atoi(Hour.substr(3, 5).c_str());
			if ((Hour1 >= 00 && Hour1 <= 23) && (Minute >= 00 && Minute <= 59)) {
				return true;
			}
			else {
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}//end CheckHour


