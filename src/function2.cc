#include <function2/function2.h>
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <string>

using namespace function2;
using namespace std;


/*Function2Ptr Function2::create_square(const float a, const float b, const float c) {
    return new Function2(TypeF::Square, a, b, c);
}

Function2Ptr Function2::create_garmonic(float a, float b, float c) {

    return new Function2(TypeF::Garmonic, a, b, c);
}

Function2::Function2(TypeF type, float a)
{
    throw runtime_error("[Function2::Function2], lack of parameters");
}

Function2::Function2(TypeF type, float a, float b)
{
    throw runtime_error("[Function2::Function2], lack of parameters");
}

Function2::Function2(TypeF type, float a, float b, float c)
{

    _type = type;
    _a = a;
    _b = b;
    _c = c;
}

TypeF function2::Function2::get_type() const
{
    return _type;
}*/

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

FunctionPtr SquareFunction::clone() const {
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
    cout << setiosflags(ios::left) << setw(20) << "Квадратический" << get_a() << "*x^2 + (" << get_b() << ")*x + (" << get_c() << ")		" << > get_a() * 2 << "*x + (" << get_b() << ")			" << setw(20) << "Невозможно получить" << endl;
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

FunctionPtr GarmonicFunction::clone() const {
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

/*float Function2::function_x(float const x) const {
    switch (_type) {
    case TypeF::Square:
        return _a * pow(x, 2) + _b * x + _c;
    case TypeF::Garmonic:
        return _a * cos(_b * x + _c);
    default:
        throw runtime_error("[Function2::function_x], invalid function type");
    }
}

Function2Ptr function2::Function2::proizvod() const {
    switch (_type) {
    case TypeF::Square:
        return create_square(0, _a * 2, _b);
    case TypeF::Garmonic:
        return create_garmonic(_a * _b, _b, _c + Pi / 2);
    default:
        throw runtime_error("[Function2::proizvod], invalid function type");
    }
}
Function2Ptr function2::Function2::pervoobraz() const
{
    switch (_type) {
    case TypeF::Square:
        throw runtime_error("[Function2::pervoobraz],the primitive quadratic function cannot be realized according to the condition of this problem ");
    case TypeF::Garmonic:
        if (_b == 0) {
            throw invalid_argument("[Function2::pervoobraz], division by zero");
        }
        else {
            return create_garmonic((-1) * _a / _b, _b, _c + Pi / 2);
        }
    default:
        throw runtime_error("[Function2::pervoobraz], invalid function type");
    }
}

Function2Ptr Function2::clone() const {
    return new Function2(_type, _a, _b, _c);
}

bool function2::operator==(const Function2& lhs, const Function2& rhs) {
    return
        lhs.get_type() == rhs.get_type() &&
        abs(lhs.get_a() - rhs.get_a()) < Epsilon;
}

bool function2::operator!=(const Function2& lhs, const Function2& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<< (std::ostream& out, Function2& function)
{
    setlocale(LC_ALL, " ");
    cout << " " << setiosflags(ios::left) <<setw(20) << "Тип функции" << setw(33) << "Функция" << setw(32) << "Производная функции" << setw(25) << "Первообразная функции" << endl;
        switch (function.get_type()) {
        case TypeF::Square:
            out << " " << setiosflags(ios::left)<< setw(20) << "Квадратический" << function.get_a() << "*x^2 + (" << function.get_b() << ")*x + (" << function.get_c() << ")		" << function.get_a() * 2 << "*x + (" << function.get_b() << ")			" << setw(20) << "Невозможно получить" << endl;
            break;
        case TypeF::Garmonic:
            out << " " << setiosflags(ios::left)<< setw(20) << "Гармонический" << function.get_a() << "*cos(" << function.get_b() << "*x + (" << function.get_c() << "))	" << -1 * function.get_a() * function.get_b() << "*sin(" << function.get_b() << "*x + (" << function.get_c() << "))	" << function.get_a() / function.get_b() << "*sin(" << function.get_b() << "*x + (" << function.get_c() << "))" << endl;
            break;
        default:
            break;

    }return out;
}*/



