#include <function2/function2.h>
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <string>

using namespace function2;
using namespace std;



SquareFunction::SquareFunction(const float a, const float b, const float c) : _a(a), _b(b), _c(c) {}
float SquareFunction::get_a() const { return _a; }
float SquareFunction::get_b() const { return _b; }
float SquareFunction::get_c() const { return _c; }

float SquareFunction::function_x(const float x) const {
    return _a * pow(x, 2) + _b * x + _c;
}

Function2Ptr SquareFunction::proizvod() const {
    return make_shared<SquareFunction>(0, _a * 2, _b);
}

Function2Ptr SquareFunction::pervoobraz() const {
    throw runtime_error("[Function2::pervoobraz],the primitive quadratic function cannot be realized according to the condition of this problem ");
}

Function2Ptr SquareFunction::clone() const {
    return make_shared<SquareFunction>(_a, _b, _c);
}

bool SquareFunction::equals(Function2Ptr other) const {
    const auto downcasted_other = dynamic_pointer_cast<SquareFunction>(other);
    if (downcasted_other == nullptr) {
        return false;
    }
    return (_a == downcasted_other->_a) && (_b == downcasted_other->_b) && (_c == downcasted_other->_c);
}
void SquareFunction::print_function() const
{
    cout << setiosflags(ios::left) << setw(20) << "Квадратический" << get_a() << "*x^2 + (" << get_b() << ")*x + (" << get_c() << ")		" << get_a() * 2 << "*x + (" << get_b() << ")			" << setw(20) << "Невозможно получить" << endl;
}
//
GarmonicFunction::GarmonicFunction(const float a, const float b, const float c) : _a(a), _b(b), _c(c) {}
float GarmonicFunction::get_a() const { return _a; }
float GarmonicFunction::get_b() const { return _b; }
float GarmonicFunction::get_c() const { return _c; }

float GarmonicFunction::function_x(const float x) const {
    return _a * cos(_b * x + _c);
}

Function2Ptr GarmonicFunction::proizvod() const {
    return make_shared<GarmonicFunction>(_a * _b, _b, _c + Pi / 2);
}

Function2Ptr GarmonicFunction::pervoobraz() const {
    if (_b == 0) {
        throw invalid_argument("[Function2::pervoobraz], division by zero");
    }
    else {
        return make_shared<GarmonicFunction>((-1) * _a / _b, _b, _c + Pi / 2);
    }
}

Function2Ptr GarmonicFunction::clone() const {
    return make_shared<GarmonicFunction>(_a, _b, _c);
}

bool GarmonicFunction::equals(Function2Ptr other) const {
    const auto downcasted_other = dynamic_pointer_cast<GarmonicFunction>(other);
    if (downcasted_other == nullptr) {
        return false;
    }
    return (_a == downcasted_other->_a) && (_b == downcasted_other->_b) && (_c == downcasted_other->_c);
}
void GarmonicFunction::print_function() const
{
    cout << setiosflags(ios::left) << setw(20) << "Гармонический" << get_a() << "*cos(" << get_b() << "*x + (" << get_c() << "))	" << -1 * get_a() * get_b() << "*sin(" << get_b() << "*x + (" << get_c() << "))	" << get_a() / get_b() << "*sin(" << get_b() << "*x + (" << get_c() << "))" << endl;
}




