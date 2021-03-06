#include "PlateNumber.h"
#include "Date.h"
#include "Hour.h"
#include "PicoYPlacaVerficator.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

	PlateNumber Plate;
	Date Date;
	Hour Hour;
	PicoYPlacaVerficator Verificator;
	string Plate1;
	string Date1;
	string Hour1;
	string PicoYPlaca;

	cout << setw(40) << "BIENVENIDO/A" << endl << endl;
	Plate1 = Plate.ReceivePlateNumber(Plate1);
	Date1 = Date.ReceiveDate(Date1);
	Hour1 = Hour.ReceiveHour(Hour1);
	PicoYPlaca = Verificator.PicoYPlacaValidator(Plate1, Date1, Hour1);

	system("cls");
	cout << setw(40) << "RESULTADOS" << endl << endl;
	cout << setw(30) << "Placa: " << Plate1 << endl;
	cout << setw(30) << "Fecha: " << Date1 << endl;
	cout << setw(30) << "Hora:  " << Hour1 << endl;
	cout << endl << setw(20) << PicoYPlaca << endl;
	
	return 0;
}
