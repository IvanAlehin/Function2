#include <function2/function2.h>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace function2;
using namespace std;


Function2_list::Function2_list() {
	_size = 0;
	_function = nullptr;
}

int Function2_list::get_size() const {
	return _size;
}

Function2_list::Function2_list(const Function2_list& other) :
	_function(new Function2Ptr[other._size]),
	_size(other._size)
{
	for (int i = 0; i < _size; ++i) {
		_function[i] = other[i]->clone();
	}
}

Function2_list& Function2_list::operator=(const Function2_list& rhs) {
	Function2_list copy(rhs);
	copy.swap(*this);
	return *this;
}

Function2Ptr Function2_list::operator[](const int index) const
{
	if (index < 0 || index >= _size) {
		throw out_of_range("[Function2_list::operator[]] Index is out of range.");
	}
	return _function[index];
}


void Function2_list::Function_add(Function2Ptr const _f) {
	auto new_function = new Function2Ptr[_size + 1];
	for (int i = 0; i < _size; ++i) {
		new_function[i] = _function[i];
	}
	new_function[_size] = _f;
	delete[] _function;
	_function = new_function;
	++_size;
}


void Function2_list::Function_Instal(Function2Ptr const _f, int index) {
	if ((index < 0) || (index >= _size)) {
		throw out_of_range("[Function2_list::Function_Instal] Index is out of range.");
	}
	auto new_function = new Function2Ptr[_size];

	for (int i = 0; i < index; ++i) {
		new_function[i] = _function[i];
	}
	for (int i = index; i < _size; ++i) {
		new_function[i] = _function[i];
	}

	new_function[index] = _f;
	delete[] _function;
	_function = new_function;
}

void Function2_list::Function_Insert(Function2Ptr const _f, int index) {
	if ((index < 0) || (index > _size)) {
		throw out_of_range("[Function2_list::Function_Insert] Index is out of range.");
	}
	auto new_function = new Function2Ptr[_size + 1];
	for (int i = 0; i < index; ++i) {
		new_function[i] = _function[i];
	}
	for (int i = _size; i > index; --i) {
		new_function[i] = _function[i - 1];
	}
	new_function[index] = _f;
	delete[] _function;
	_function = new_function;
	++_size;
}



void Function2_list::Function_Delete(int index) {
	if ((index < 0) || (index >= _size)) {
		throw out_of_range("[Function2_list::Function_Delete] Index is out of range.");
	}
	auto new_function = new Function2Ptr [_size - 1];
	for (int i = 0; i < index; ++i) {
		new_function[i] = _function[i];
	}
	for (int i = index; i < _size - 1; ++i) {
		new_function[i] = _function[i + 1];
	}
	delete[]  _function;
	_function = new_function;
	--_size;
}

void Function2_list::swap(Function2_list& other) {
	std::swap(this->_function, other._function);
	std::swap(this->_size, other._size);
}

Function2_list::~Function2_list() {
	for (int i = 0; i < _size; ++i) {
		delete _function[i];
	}
	delete[] _function;
}

int function2::last_max(const Function2_list& function, const float x) {
	const auto n = function.get_size();

	if (n == 0) {
		throw out_of_range("Function2_list is empty");
	}

	float maxvalue = function[n - 1]->function_x(x);
	int maxindex = n - 1;

	for (int i = n - 1; i >= 0; --i) {
		const auto value = function[i]->function_x(x);
		if (maxvalue < value) {
			maxindex = i;
			maxvalue = value;
		}
	}
	return maxindex;
}

void Function2_list::show() {

	setlocale(LC_ALL, " ");
	cout << " Список:" << endl;
	cout << " " << setiosflags(ios::left) << setw(10) << "Индекс" << setw(20) << "Тип функции" << setw(33) << "Функция" << setw(32) << "Производная функции" << setw(25) << "Первообразная функции" << endl;
	for (int i = 0; i < _size; ++i) {
		switch (_function[i]->get_type()) {
		case TypeF::Square:
			cout << " " << setiosflags(ios::left) << setw(10) << i << setw(20) << "Квадратический" << _function[i]->get_a() << "*x^2 + (" << _function[i]->get_b() << ")*x + (" << _function[i]->get_c() << ")		" << _function[i]->get_a() * 2 << "*x + (" << _function[i]->get_b() << ")			" << setw(20) << "Невозможно получить" << endl;
			break;
		case TypeF::Garmonic:
			cout << " " << setiosflags(ios::left) << setw(10) << i << setw(20) << "Гармонический" << _function[i]->get_a() << "*cos(" << _function[i]->get_b() << "*x + (" << _function[i]->get_c() << "))	" << -1 * _function[i]->get_a() * _function[i]->get_b() << "*sin(" << _function[i]->get_b() << "*x + (" << _function[i]->get_c() << "))	" << _function[i]->get_a() / _function[i]->get_b() << "*sin(" << _function[i]->get_b() << "*x + (" << _function[i]->get_c() << "))" << endl;
			break;
		default:
			break;
		}
	}
}
