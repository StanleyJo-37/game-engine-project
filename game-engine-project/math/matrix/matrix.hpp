#pragma once

#include <iostream>
#include <cmath>
#include <array>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

template<size_t NROWS, size_t NCOLS>
class Matrix
{
private:
	size_t rows = NROWS;
	size_t cols = NCOLS;
	float nums[NROWS][NCOLS];
public:
	Matrix(const float data[NROWS][NCOLS]);
	static Matrix uniform(float num);

	float operator()(size_t _idx1, size_t _idx2);
	friend inline ostream& operator<<(ostream& os, const Matrix<NROWS, NCOLS>& _mtx)
	{
		for (int i = 0; i < NROWS; ++i)
			for (int j = 0; j < NCOLS; ++j)
				os << _mtx.nums[i][j] << (j == NCOLS - 1 ? "\n" : ", ");
		return os;
	}
};

#include "matrix.inl"