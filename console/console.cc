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
	cout << "Программа запущена!" << endl;
	cout << endl;
	cout << "Создать новый список - 1" << endl;
	cout << "Выбрать существующий список - 2" << endl;
	cout << "Выход - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 49) || (key == 50)) return key;
	}
}

int menu2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << endl;
	cout << "Редактировать список - 1" << endl;
	cout << "Найти по индексу значение функции - 2" << endl;
	cout << "Найти по индексу значение производной функции  - 3" << endl;
	cout << "Найти по индексу значение первообразной функции - 4" << endl;
	cout << "Найти в списке последнюю функцию с максимальным значением производной - 5" << endl;
	cout << "Выход - Esc" << endl;
	while (true) {
		int key = get_key();
		if ((key == 27) || (key == 50) || (key == 49) || (key == 51) || (key == 52) || (key == 53)) return key;
	}
}

int menu3() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << endl;
	cout << "Добавить в конец списка - 1" << endl;
	cout << "Заменить по индексу - 2" << endl;
	cout << "Вставить по индексу - 3" << endl;
	cout << "Удалить по индексу - 4" << endl;
	cout << "Выход Esc" << endl;
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

	cout << "Введите название типа функции k|g (k-Квадратический, g-Гармонический):" << endl;
	switch (get_key()) {
	case 107:
		cout << "Введите коэффициенты функции a,b,c:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_square(a, b, c);
		break;
	case 103:
		cout << "Введите коэффициенты функции a,w,f:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_garmonic(a, b, c);
		break;
	default:
		break;
	}
	system("cls");
	function.show();
	cout << "Введите индекс, по которому нужно произвести замену" << endl;
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

	cout << "Введите название типа функции k|g (k-Квадратический, g-Гармонический):" << endl;
	switch (get_key()) {
	case 107:
		cout << "Введите коэффициенты функции a,b,c:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_square(a, b, c);
		break;
	case 103:
		cout << "Введите коэффициенты функции a,w,f:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_garmonic(a, b, c);
		break;
	default:
		break;
	}
	system("cls");
	function.show();
	cout << "Введите индекс, по которому нужно вставить новый объект" << endl;
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

	cout << "Введите название типа функции k|g (k-Квадратический, g-Гармонический):" << endl;
	switch (get_key()) {
	case 107:
		cout << "Введите коэффициенты функции a,b,c:" << endl;
		cin >> a >> b >> c;
		f = Function2::create_square(a, b, c);
		break;
	case 103:
		cout << "Введите коэффициенты функции a,w,f:" << endl;
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
	cout << "Введите индекс объекта, который нужно удалить:" << endl;
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
	cout << "Введите индекс i=";
	cin >> index;
	cout << "Введите значение x=";
	cin >> x;
	cout << endl;
	cout << "Значение функции под индексом " << index << " при аргументе " << x << " равно: " << function[index]->function_x(x);

}
void menu_proisvod_function_x(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	int index;
	float x;
	cout << endl;
	function.show();
	cout << "Введите индекс i=";
	cin >> index;
	cout << "Введите значение x=";
	cin >> x;
	cout << endl;
	cout << "Значение производной функции под индексом " << index << " при аргументе " << x << " равно: " << function[index]->proizvod()->function_x(x);

}

void menu_pervoobraz_function_x(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	int index;
	float x;
	cout << endl;
	function.show();
	cout << "Введите индекс i=";
	cin >> index;
	if (function[index]->get_type() == TypeF::Square)
	{
		cout << "Невозможно посчитать первообразную этой функции." << endl;
	}
	else
	{
		cout << "Введите значение x=";
		cin >> x;
		cout << endl;
		cout << "Значение первообразной функции под индексом " << index << " при аргументе " << x << " равно: " << function[index]->pervoobraz()->function_x(x);
	}
}
void menu_lastmax(Function2_list& function) {
	setlocale(LC_ALL, " ");
	system("cls");
	float x;
	cout << endl;
	function.show();
	cout << "Введите значение x=";
	cin >> x;
	cout << endl;
	cout << "Индекс последней функции с максимальным значением производной при аргументе " << x << " равен: " << last_max(function, x);
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

