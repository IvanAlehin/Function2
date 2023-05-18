#include <function2/function2.h>
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <string>

using namespace function2;
using namespace std;


Function2Ptr Function2::create_square(const float a, const float b, const float c) {
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
}

float function2::Function2::get_a() const
{
    return _a;
}

float function2::Function2::get_b() const
{
    return _b;
}

float function2::Function2::get_c() const
{
    return _c;
}


float Function2::function_x(float const x) const {
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
    cout << " " << setiosflags(ios::left) << setw(20) << "Тип функции" << setw(33) << "Функция" << setw(32) << "Производная функции" << setw(25) << "Первообразная функции" << endl;
    switch (function.get_type()) {
    case TypeF::Square:
        out << " " << setiosflags(ios::left) << setw(20) << "Квадратический" << function.get_a() << "*x^2 + (" << function.get_b() << ")*x + (" << function.get_c() << ")		" << function.get_a() * 2 << "*x + (" << function.get_b() << ")			" << setw(20) << "Невозможно получить" << endl;
        break;
    case TypeF::Garmonic:
        out << " " << setiosflags(ios::left) << setw(20) << "Гармонический" << function.get_a() << "*cos(" << function.get_b() << "*x + (" << function.get_c() << "))	" << -1 * function.get_a() * function.get_b() << "*sin(" << function.get_b() << "*x + (" << function.get_c() << "))	" << function.get_a() / function.get_b() << "*sin(" << function.get_b() << "*x + (" << function.get_c() << "))" << endl;
        break;
    default:
        break;

    }return out;
}




