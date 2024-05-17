#pragma once

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

template<size_t NROWS, size_t NCOLS>
class Matrix
{
public:
	Matrix(const float** nums);
	static Matrix uniform(float num);
private:
	const size_t rows = 3;
    const size_t cols = 3;
}

class Matrix3f
{
public:
	Matrix3f(const float(&nums)[rows][cols]);
	static Matrix3f uniform(float num);

	const;
private:
	static constexpr uint8_t rows = 3;
	static constexpr uint8_t cols = 3;
	float nums[rows][cols];
};