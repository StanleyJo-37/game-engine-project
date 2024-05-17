#pragma once

#include <iostream>
#include <cmath>

class Matrix3f
{
public:
	Matrix3f(float num1, float num2, float num3);
	static Matrix3f* uniform(float num);
	const void print() const;
private:
	float _num1, _num2, _num3;
};