#include <function2/function2.h>
#include <cassert>
#include <cmath>
#include <stdexcept>

using namespace function2;
using namespace std;


Function2_list::Function2_list() {
	_size = 0;
	for (int i = 0; i < COUNTER; ++i)
	{
		_function[i] = Function2();
	}
}

int Function2_list::get_size() {
	return _size;
}

Function2 Function2_list::operator[](const int index) const
{
	if (index < 0 || index >= _size) {
		throw out_of_range("[Function2_list::operator[]] Index is out of range.");
	}
	return _function[index];
}

void Function2_list::Function_add(const Function2& _f) {
	if (_size == COUNTER) {
		throw runtime_error("[FunctionList::Function_add] Counter is reached.");
	}
	_function[_size] = _f;
	++_size;
}
void Function2_list::Function_Instal(const Function2& _f, int index) {
	if ((index < 0) || (index >= _size)) {
		throw out_of_range("[Function2_list::Function_Insert] Index is out of range.");
	}
	_function[index] = _f;
}
void Function2_list::Function_Insert(const Function2& _f, int index) {
	if ((index < 0) || (index >= _size)) {
		throw out_of_range("[Function2_list::Function_Insert] Index is out of range.");
	}
	if (_size == COUNTER) {
		throw runtime_error("[FunctionList::Function_Insert] Counter is reached.");
	}
	Function2 last = _function[_size - 1];
	for (int i = _size - 1; i >= index; --i) { _function[i] = _function[i - 1]; }
	_function[index] = _f;
	++_size;
	_function[_size - 1] = last;
}

void Function2_list::Function_Delete(int index) {
	if ((index < 0) || (index >= _size)) {
		throw out_of_range("[Function2_list::Function_Delete] Index is out of range.");
	}
	for (int i = index; i < _size - 1; ++i)
	{
		_function[i] = _function[i + 1];
	}
	--_size;
}



int Function2_list::last_max(const Function2_list& function, const float x) {
	if (_size == 0) {
		throw out_of_range("Function2_list is empty");
	}
	Function2 time1 = function[_size - 1];
	Function2 time2 = time1.proizvod();
	float maxvalue = time2.function_x(x);
	int maxindex = _size - 1;
	for (int i = _size - 1; i >= 0; --i) {
		time1 = function[i];
		time2 = time1.proizvod();
		if (maxvalue < time2.function_x(x)) {
			maxindex = i;
			maxvalue = time2.function_x(x);
		}
	}
	return maxindex;
}
