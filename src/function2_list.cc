#include <function2/function2.h>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace function2;
using namespace std;


/*Function2_list::Function2_list() {
	_size = 0;
	_function= nullptr;
}

int Function2_list::get_size() const{
	return _size;
}*/

Function2_list::Function2_list(const Function2_list& other) {
	const auto n = other.size();
	_function.reserve(n);
	for (int i = 0; i < n; ++i) {
		_function.push_back(other[i]->clone());
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
	return _function.at[index];
}


void Function2_list::Function_add( Function2Ptr const f) {
	/*auto new_function = new Function2Ptr[_size + 1];
	for (int i = 0; i < _size; ++i) {
		new_function[i] = _function[i];
	}
	new_function[_size] = _f;
	delete[] _function;
	_function = new_function;
	++_size;*/
	_function.push_back(f);
}


void Function2_list::Function_Instal( Function2Ptr const _f, int index) {
	/*if ((index < 0) || (index >= _size)) {
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
	_function = new_function;*/
	_function.erase(_function.begin() + index);
	_function.emplace(_function.begin() + index, f);
}

void Function2_list::Function_Insert(Function2Ptr const f, int index) {
	/*if ((index < 0) || (index > _size)) {
		throw out_of_range("[Function2_list::Function_Insert] Index is out of range.");
	}
	auto new_function = new Function2Ptr[_size + 1];
	for (int i = 0; i < index; ++i) {
		new_function[i] = _function[i];
	}
	for (int i = _size; i > index; --i) {
		new_function[i] = _function[i-1];
	}
	new_function[index] = _f;
	delete[] _function;
	_function = new_function;
	++_size;*/
	_function.insert(_function.begin() + index, f);
}



void Function2_list::Function_Delete(int index) {
	/*if ((index < 0) || (index >= _size)) {
		throw out_of_range("[Function2_list::Function_Delete] Index is out of range.");
	}
	auto new_function = new Function2Ptr*[_size - 1];
	for (int i = 0; i < index; ++i) {
		new_function[i] = *_function[i];
	}
	for (int i = index; i < _size - 1; ++i) {
		new_function[i] = *_function[i + 1];
	}
	delete[] *_function;
	*_function = new_function;
	--_size;*/
	_function.erase(_function.begin() + index);
}

void Function2_list::swap(Function2_list& other) {
	std::swap(this->_function, other._function);
}

/*Function2_list::~Function2_list() {
	for (int i = 0; i < _size; ++i) {
		delete _function[i];
	}
	delete[] _function;
}*/

int function2::last_max(const Function2_list& function, const float x){
	const auto n = function.size();

	float maxvalue = function[n-1]->function_x(x);
	int maxindex = n-1;

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
	cout << " ������:" << endl;
	cout << " " << setiosflags(ios::left) << setw(10) << "������" << setw(20) << "��� �������" << setw(33) << "�������" << setw(32)  << "����������� �������" << setw(25) << "������������� �������" << endl;
	for (int i(0); i < size(); ++i) {
		cout << " " << setiosflags(ios::left) << setw(10) << i
		_function[i]->print_function();
	}
	/*for (int i = 0; i < _size; ++i) {
		switch (*_function[i]->get_type()) {
		case TypeF::Square:
			cout << " " << setiosflags(ios::left) << setw(10) << i << setw(20) << "��������������"   << _function[i]->get_a() << "*x^2 + (" << _function[i]->get_b() << ")*x + (" <<_function[i]->get_c() <<")		" << _function[i]->get_a() *2 << "*x + (" << _function[i]->get_b() <<")			"<<setw(20) << "���������� ��������" << endl;
			break;
		case TypeF::Garmonic:
			cout << " " << setiosflags(ios::left) << setw(10) << i << setw(20) << "�������������" << _function[i]->get_a()<< "*cos(" << _function[i]->get_b() << "*x + (" << _function[i]->get_c() << "))	"<<-1* _function[i]->get_a()* _function[i]->get_b()<<"*sin("<< _function[i]->get_b()<<"*x + ("<< _function[i]->get_c()<<"))	"<< _function[i]->get_a()/ _function[i]->get_b()<<"*sin("<< _function[i]->get_b()<<"*x + ("<< _function[i]->get_c()<<"))" << endl;
			break;
		default:
			break;
		}
	}*/
}