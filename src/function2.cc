#include <function2/function2.h>
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

using namespace function2;
using namespace std;

function2::Function2::Function2()
{
    _type = TypeF::Square;
    _a = 0;
    _b = 0;
    _c = 0;
}

function2::Function2::Function2(TypeF type, float a)
{
    throw runtime_error("[Function2::Function2], lack of parameters");

}

function2::Function2::Function2(TypeF type, float a, float b)
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

TypeF function2::Function2::get_type()
{
    return _type;
}

float function2::Function2::get_a()
{
    return _a;
}

float function2::Function2::get_b()
{
    return _b;
}

float function2::Function2::get_c()
{
    return _c;
}

float Square_pervoobraz(float x, float a, float b, float c) {
    if (a == 0)
    {
        throw runtime_error("[Function2::Function2], invalid value");
    }
    return ((a / 3) * pow(x, 3) + (b / 2) * pow(x, 2) + c * x);
}

float Function2::function_x(float const x) {
    switch (_type) {
    case TypeF::Square:
        return _a * pow(x, 2) + _b * x + _c;
    case TypeF::Garmonic:
        return _a * cos(_b * x + _c);
    default:
        throw runtime_error("[Function2::function_x], invalid function type");
    }
}

Function2 function2::Function2::proizvod() {
    switch (_type) {
    case TypeF::Square:
        return Function2(TypeF::Square, 0, _a * 2, _b);
    case TypeF::Garmonic:
        return Function2(TypeF::Garmonic, _a * _b, _b, _c + Pi / 2);
    default:
        throw runtime_error("[Function2::proizvod], invalid function type");
    }
}
Function2 function2::Function2::pervoobraz()
{
    switch (_type) {
    case TypeF::Square:
        throw runtime_error("[Function2::pervoobraz],the primitive quadratic function cannot be realized according to the condition of this problem ");
    case TypeF::Garmonic:
        if (_b == 0) {
            throw invalid_argument("[Function2::pervoobraz], division by zero");
        }
        else {
            return Function2(TypeF::Garmonic, (-1) * _a / _b, _b, _c + Pi / 2);
        }
    default:
        throw runtime_error("[Function2::pervoobraz], invalid function type");
    }
}