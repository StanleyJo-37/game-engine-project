#pragma once

#include <iostream>
#include <algorithm>

#include "matrix.hpp"

using std::ostream;

template<size_t NROWS, size_t NCOLS>
Matrix<NROWS, NCOLS>::Matrix(const float data[NROWS][NCOLS])
{
	for (size_t i = 0; i < NROWS; ++i)
		for (size_t j = 0; j < NCOLS; ++j)
			nums[i][j] = data[i][j];
}

template<size_t NROWS, size_t NCOLS>
Matrix<NROWS, NCOLS> Matrix<NROWS, NCOLS>::uniform(float num)
{
	float nums[NROWS][NCOLS];
	std::fill(&nums[0][0], &nums[0][0] + NROWS * NCOLS, num);
	return Matrix(nums);
}

template<size_t NROWS, size_t NCOLS>
float Matrix<NROWS, NCOLS>::operator()(size_t _idx1, size_t _idx2)
{
	return this->nums[_idx1][_idx2];
}

