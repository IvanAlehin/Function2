#include <gtest/gtest.h>
#include <Windows.h>
#include <function2/function2.h>
#include <conio.h>
#include <iostream>

using namespace function2;
using namespace std;

int get_key() {
	int key = getch();
	return key;
}

int menu1() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << endl;
	cout << "��������� ��������!" << endl;
	cout << endl;
	cout << "������� ����� ������ - 1" << endl;
	cout << "������� ������������ ������ - 2" << endl;
	cout << "����� - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50)) return key;
	}
}

int menu2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << endl;
	cout << "������������� ������ - 1" << endl;
	cout << "����� �� ������� �������� ������� - 2" << endl;
	cout << "����� �� ������� �������� ����������� �������  - 3" << endl;
	cout << "����� �� ������� �������� ������������� ������� - 4" << endl;
	cout << "����� � ������ ��������� ������� � ������������ ��������� ����������� - 5" << endl;
	cout << "����� - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 50) || (key == 49) || (key == 51) || (key == 52) || (key == 53)) return key;
	}
}

int menu3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << endl;
	cout << "�������� � ����� ������ - 1" << endl;
	cout << "�������� �� ������� - 2" << endl;
	cout << "�������� �� ������� - 3" << endl;
	cout << "������� �� ������� - 4" << endl;
	cout << "����� Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50) || (key == 52) || (key == 51)) return key;
	}
}

void menu_instal(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	cout << endl;
	Function2 *f = nullptr;
	int index;
	float a, b, c;

	cout << "������� �������� ���� ������� k|g (k-��������������, g-�������������):" << endl;
	switch (get_key()) {
	case 107:
		cout << "������� ������������ ������� a,b,c:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_square(a, b, c);
		break;
	case 103:
		cout << "������� ������������ ������� a,w,f:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_garmonic(a, b, c);
		break;
	default:
		break;
	}
	system("cls");
	function.show();
	cout << "������� ������, �� �������� ����� ���������� ������" << endl;
	cin >> index;
	function.Function_Instal(f, index);

}
void menu_insert(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	cout << endl;
	Function2* f = nullptr;
	int index;
	float a, b, c;

	cout << "������� �������� ���� ������� k|g (k-��������������, g-�������������):" << endl;
	switch (get_key()) {
	case 107:
		cout << "������� ������������ ������� a,b,c:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_square(a, b, c);
		break;
	case 103:
		cout << "������� ������������ ������� a,w,f:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_garmonic(a, b, c);
		break;
	default:
		break;
	}
	system("cls");
	function.show();
	cout << "������� ������, �� �������� ����� �������� ����� ������" << endl;
	cin >> index;
	function.Function_Insert(f, index);

}
void menu_add(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	cout << endl;
	Function2* f = nullptr;
	int index;
	float a, b, c;

	cout << "������� �������� ���� ������� k|g (k-��������������, g-�������������):" << endl;
	switch (get_key()) {
	case 107:
		cout << "������� ������������ ������� a,b,c:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_square(a, b, c);
		break;
	case 103:
		cout << "������� ������������ ������� a,w,f:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_garmonic(a, b, c);
		break;
	default:
		break;
	}
	system("cls");
	function.Function_add(f);

}
void menu_delete(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	int index;
	cout << endl;
	function.show();
	cout << "������� ������ �������, ������� ����� �������:" << endl;
	cin >> index;
	function.Function_Delete(index);
}
void menu_function_x(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	int index;
	float x;
	cout << endl;
	function.show();
	cout << "������� ������ i=";
	cin >> index;
	cout << "������� �������� x=";
	cin >> x;
	cout << endl;
	cout << "�������� ������� ��� �������� " << index << " ��� ��������� " << x << " �����: " << function[index]->function_x(x);

}
void menu_proisvod_function_x(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	int index;
	float x;
	cout << endl;
	function.show();
	cout << "������� ������ i=";
	cin >> index;
	cout << "������� �������� x=";
	cin >> x;
	cout << endl;
	cout << "�������� ����������� ������� ��� �������� " << index << " ��� ��������� " << x << " �����: " << function[index]->proizvod()->function_x(x);

}

void menu_pervoobraz_function_x(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	int index;
	float x;
	cout << endl;
	function.show();
	cout << "������� ������ i=";
	cin >> index;
	if (function[index]->get_type() == TypeF::Square)
	{
		cout << "���������� ��������� ������������� ���� �������." << endl;
	}
	else
	{
		cout << "������� �������� x=";
		cin >> x;
		cout << endl;
		cout << "�������� ������������� ������� ��� �������� " << index << " ��� ��������� " << x << " �����: " << function[index]->pervoobraz()->function_x(x);
	}
}
void menu_lastmax(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	float x;
	cout << endl;
	function.show();
	cout << "������� �������� x=";
	cin >> x;
	cout << endl;
	cout << "������ ��������� ������� � ������������ ��������� ����������� ��� ��������� " << x << " �����: " << last_max(function, x);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, " ");
	TypeF type;
	Function2_list function;
	function.Function_add(Function2::create_square(1.517, 2, 3));
	function.Function_add(Function2::create_square(-2, 5.21, 7));
	function.Function_add(Function2::create_square(3, -8.86, 7.3));
	function.Function_add(Function2::create_garmonic(-5, Pi, Pi / 2));
	function.Function_add(Function2::create_garmonic(3.87, 2 * Pi, 3));
	int x, n = 5;
	while (true) {
		system("cls");
		int m1 = menu1();
		if (m1 == 27) break;
		if (m1 == 50 || m1 == 49) {
			while (true) {
				if (m1 == 49)
				{
					Function2_list function2;
					function = function2;
				}
				system("cls");
				function.show();
				int m2 = menu2();

				if (m2 == 50) {
					menu_function_x(function);
					if (get_key() == 27) break;
				}
				if (m2 == 51) {
					menu_proisvod_function_x(function);
					if (get_key() == 27) break;
				}
				if (m2 == 52) {
					menu_pervoobraz_function_x(function);
					if (get_key() == 27) break;
				}
				if (m2 == 53) {
					menu_lastmax(function);
					if (get_key() == 27) break;
				}
				if (m2 == 27) break;
				if (m2 == 49) {
					while (true) {
						system("cls");
						function.show();
						int m3 = menu3();
						if (m3 == 27) break;
						if (m3 == 51) {
							menu_insert(function);
						}
						if (m3 == 49) {
							menu_add(function);
						}
						if (m3 == 52) {
							menu_delete(function);
						}
						if (m3 == 50) {
							menu_instal(function);
						}


					}
				}
			}
		}
	}
	return 0;
}

