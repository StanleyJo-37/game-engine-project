#include "matrix.h"

Matrix3f::Matrix3f(float num1, float num2, float num3)
	: _num1(num1), _num2(num2), _num3(num3) {}

Matrix3f* Matrix3f::uniform(float num)
{
	return new Matrix3f(num, num, num);
}

const void Matrix3f::print() const
{
	std::cout << _num1 << ' ' << _num2 << ' ' << _num3 << '\n';
}