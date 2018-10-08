#include "PlateNumber.h"
#include <iostream>
#include <string>

using namespace std;

string PlateNumber::ReceivePlateNumber(string PlateNumber)
{
	do
	{
		cout << "\nPor favor ingrese la placa. Ejm ABC-0000 o abc-0000: ";
		cin >> PlateNumber;
		Checker = CheckPlateNumber(PlateNumber);
		if (Checker == false)
		{
			cout << "\nDatos mal ingresados por favor reintente." << endl;

		}
		else
		{
			cout << "\nDatos ingresados con exito." << endl;
			return PlateNumber;
		}
		system("Pause");
		system("cls");
	} while (Checker == false);

}//end ReceivePlateNumber

bool PlateNumber::CheckPlateNumber(string CheckPlate)
{
	string letter;
	int number;
	int Validation = 0;
	int LetterWrong = 0;


	if (CheckPlate.length() == 8)
	{
		size_t pos = CheckPlate.find("-");
		if (pos == 3)
		{
			letter = CheckPlate.substr(0, 3);
			string aux = CheckPlate.substr(pos + 1);
			number = atoi(aux.c_str());

			if (number >= 0000 && number <= 9999)
			{
				Validation = Validation + 1;
			}
			for (int i = 0; i < letter.length(); i++)
			{
				if ((letter[i]) < 65 || ((letter[i]) > 90 && (letter[i]) < 97) || (letter[i]) > 122)
				{
					LetterWrong = 1;
				}
				else
				{
					Validation = Validation + 1;
				}
			}

			if (LetterWrong != 1 && Validation == 4)
			{
				return true;
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
	}
	else
	{
		return false;
	}
}//end CheckPlateNumber








