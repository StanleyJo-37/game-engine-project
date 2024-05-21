#include "matrix.h"

template<size_t NROWS, size_t NCOLS>
Matrix<NROWS, NCOLS>::Matrix(const float data[NROWS][NCOLS])
{
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			nums[i][j] = data[i][j];
}

template<size_t NROWS, size_t NCOLS>
Matrix<NROWS, NCOLS> Matrix<NROWS, NCOLS>::uniform(float num)
{
	float nums[NROWS][NCOLS];
	std::fill(&nums[0][0], &nums[rows - 1][cols], num);
	return Matrix(nums);	
}

template<size_t NROWS, size_t NCOLS>
float Matrix<NROWS, NCOLS>::operator()(size_t _idx1, size_t _idx2)
{
	return this->nums[_idx1][_idx2];
}

/*
float Matrix<NROWS, NCOLS>::operator()(size_t _idx1, size_t _idx2)
{
	return this->nums[_idx1][_idx2];
}
ostream& operator<<(ostream& os, const Matrix& _mtx)
{
	for (int i = 0; i < _mtx.rows; ++i)
	{
		for (int j = 0; j < _mtx.cols; ++j)
			os << _mtx.nums[i][j];
		os << (i == _mtx.rows - 1 ? "\n" : ", ");
	}
	return os;
}*/