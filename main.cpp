#include <iostream>
#include <Windows.h>
#include "fraction.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num, denom;
	cout << "Введите числитель дроби 1: ";
	cin >> num;
	cout << "Введите знаменатель  дроби 1: ";
	cin >> denom;
	Fraction f1(num, denom);
	cout << "Введите числитель дроби 2: ";
	cin >> num;
	cout << "Введите знаменатель  дроби 2: ";
	cin >> denom;
	Fraction f2(num, denom);

	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
	cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	cout << "++" << f1 << " * " << f2 << " = ";
	cout << ++f1 * f2 << endl;
	cout << "Значение дроби 1: " << f1 << endl;
	cout << f1 << "-- * " << f2 << " = ";
	cout << f1-- * f2 << endl;
	cout << "Значение дроби 1: " << f1 << endl;
	
	system("pause");
}
