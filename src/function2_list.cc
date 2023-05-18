#include <function2/function2.h>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace function2;
using namespace std;


Function2_list::Function2_list(const Function2_list& other) {
	const auto n = other.size();
	_function.reserve(n);
	for (const auto& ptr: other._function) {
		_function.push_back(ptr->clone());
	}
}

Function2_list& Function2_list::operator=(const Function2_list& rhs) {
	Function2_list copy(rhs);
	copy.swap(*this);
	return *this;
}

int Function2_list::size() const {
	return static_cast<int>(_function.size());
}

Function2Ptr Function2_list::operator[](const int index) const
{  
	return _function.at(index);
}


void Function2_list::Function_add( Function2Ptr const f) {
	_function.push_back(f);
}


void Function2_list::Function_Instal( Function2Ptr const f, int index) {
	_function.erase(_function.begin() + index);
	_function.emplace(_function.begin() + index, f);
}

void Function2_list::Function_Insert(Function2Ptr const f, int index) {
	_function.insert(_function.begin() + index, f);
}



void Function2_list::Function_Delete(int index) {
	_function.erase(_function.begin() + index);
}

void Function2_list::swap(Function2_list& other) {
	std::swap(this->_function, other._function);
}


int function2::last_max(const Function2_list& function, const float x){
	const auto n = function.size();

	float maxvalue = function[n-1]->function_x(x);
	int maxindex =n-1;

	for (int i = n-1; i >=0; --i) {
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
	cout << " " << setiosflags(ios::left) << setw(10) << "Индекс" << setw(20) << "Тип функции" << setw(33) << "Функция" << setw(32)  << "Производная функции" << setw(25) << "Первообразная функции" << endl;
	for (int i(0); i < size(); ++i) {
		cout << " " << setiosflags(ios::left) << setw(10) << i;
		_function[i]->print_function();
	}
}
