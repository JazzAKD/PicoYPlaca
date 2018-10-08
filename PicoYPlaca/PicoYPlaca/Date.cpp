#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

string Date::ReceiveDate(string Date)
{
	do
	{
		cout << "\n\nPor favor ingrese la fecha, formato: dd/mm/aaaa. Ejm 05/01/2018: ";
		cin >> Date;
		Checker = CheckDate(Date);
		if (Checker == false)
		{
			cout << "\nDatos mal ingresados por favor reintente." << endl;
		}
		else
		{
			cout << "\nDatos ingresados con exito." << endl;
			return CompleteDate;
		}

		system("Pause");
		system("cls");
	} while (Checker == false);

}//end ReceiveDate

bool Date::CheckDate(string Date)
{
	int Day;
	int Month;
	int Year;
	int Validation = 0;
	bool DayMonth = false;
	string aux;
	string DayWeek;

	if (Date.length() == 10)
	{
		size_t pos = Date.find("/");
		if (pos == 2)
		{
			Day = atoi(Date.substr(0, 2).c_str());
			aux = Date.substr(pos);
		}
		else
		{
			return false;
		}
		pos = aux.find("/");
		if (pos == 0)
		{
			Month = atoi(aux.substr(1, 2).c_str());
			aux = aux.substr(pos + 1);
		}
		else
		{
			return false;
		}

		if ((Day >= 1 && Day <= 31) && (Month >= 1 && Month <= 12))
		{
			if (Day == 30 || Day == 31)
			{
				DayMonth = VerifyDayMonth(Day, Month);
				if (DayMonth == true)
				{
					Validation = Validation + 1;
				}
				else
				{
					return false;
				}
			}
			Validation = Validation + 1;
		}
		else
		{
			return false;
		}

		pos = aux.find("/");
		if (pos == 2)
		{
			Year = atoi(aux.substr(3, 4).c_str());
			if (Year >= 0000 || Year <= 9999)
			{
				DayWeek = PrintDate(Day, Month, Year);
				Validation = Validation + 1;
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
	if (Validation == 2 || Validation == 3)
	{
		return true;
	}

}//end CheckDate

bool Date::VerifyDayMonth(int Day, int Month)
{
	int MonthThirtyOne[] = { 1,3,5,7,8,10,12 };
	int MonthThirty[] = { 2,4,6,9,11 };

	for (int i = 1; i <= 12; i++)
	{
		if (Day == 31 && (MonthThirtyOne[i] == Month))
		{
			return true;
		}
		else if (Day == 30 && MonthThirty[i] == Month)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}//end VerifyDayMonth

string Date::PrintDate(int Day, int Month, int Year)
{

	int RegularYear[] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
	int LeapYear[] = { 0,3,4,0,2,5,0,3,6,1,4,6 };
	string NameOfDay[] = { "Domingo","Lunes","Martes","Miercoles","Jueves","Viernes",
						 "Sabado"
	};
	string NameOfMonth[] = { "enero","febrero","marzo","abril","mayo","junio",
						   "julio","agosto","septiembre","octubre","noviembre","diciembre"
	};
	int Result, Result2, Result3, DayWeek;
	int Aux = Month;
	string NameDay;
	string NameMonth;
	
	if ((Year % 4 == 0) && (Year % 100 != 0) || (Year % 400 == 0))
	{
		Aux = LeapYear[Month - 1];
	}
	else
	{
		Aux = RegularYear[Month - 1];
	}
	Result = (Year - 1) % 7;
	Result2 = ((Year - 1) / 4 - ((3 * (((Year - 1) / 100) + 1)) / 4)) % 7;
	DayWeek = (Result + Result2 + Aux + (Day % 7)) % 7;

	NameMonth = NameOfMonth[Month - 1];
	NameDay = NameOfDay[DayWeek];
	CompleteDate = NameDay + " " + to_string(Day) + " de " + NameMonth + " de " + to_string(Year);

	return CompleteDate;
}//end PrintDate
