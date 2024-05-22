#pragma once

#include <iostream>
#include <algorithm>

#include "matrix.hpp"

using std::ostream;

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>::Matrix(const float data[NROWS][NCOLS])
{
	for (size_t i = 0; i < NROWS; ++i)
		for (size_t j = 0; j < NCOLS; ++j)
			nums[i][j] = data[i][j];

	size[0] = NROWS;
	size[1] = NCOLS;
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>::Matrix(Matrix&& other) noexcept
{
	for (size_t i = 0; i < NROWS; ++i)
		for (size_t j = 0; j < NCOLS; ++j)
			nums[i][j] = std::move(other.nums[i][j]);

	size[0] = NROWS;
	size[1] = NCOLS;
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>::Matrix(float(&& data)[NROWS][NCOLS]) noexcept
{
	for (size_t i = 0; i < NROWS; ++i)
		for (size_t j = 0; j < NCOLS; ++j)
			nums[i][j] = std::move(data[i][j]);

	size[0] = NROWS;
	size[1] = NCOLS;
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>::Matrix(const Matrix& other)
{
	for (size_t i = 0; i < NROWS; ++i)
		for (size_t j = 0; j < NCOLS; ++j)
			nums[i][j] = other.nums[i][j];

	size[0] = NROWS;
	size[1] = NCOLS;
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>& Matrix<NROWS, NCOLS>::operator=(const Matrix& other)
{
		if (this == &other) return *this;

		for (size_t i = 0; i < NROWS; ++i)
			for (size_t j = 0; j < NCOLS; ++j)
				nums[i][j] = other.nums[i][j];

		size[0] = NROWS;
		size[1] = NCOLS;

		return *this;
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS> Matrix<NROWS, NCOLS>::uniform(float num)
{
	float nums[NROWS][NCOLS];
	std::fill(&nums[0][0], &nums[0][0] + NROWS * NCOLS, num);
	return Matrix(nums);
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>& Matrix<NROWS, NCOLS>::operator+(const Matrix& other)
{
	try
	{
		if (this->size[0] != other.size[0] || this->size[1] != other.size[1]) throw std::runtime_error("Matrices's sizes don't match up.");

		float newData[NROWS][NCOLS];
		for (size_t i = 0; i < NROWS; ++i)
			for (size_t j = 0; j < NCOLS; ++j)
				newData[i][j] = this->nums[i][j] + other.nums[i][j];

		return Matrix(newData);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return nullptr;
	}
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>& Matrix<NROWS, NCOLS>::operator-(const Matrix& other)
{
	try
	{
		if (this->size[0] != other.size[0] || this->size[1] != other.size[1]) throw std::runtime_error("Matrices's sizes don't match up.");

		float newData[NROWS][NCOLS];
		for (size_t i = 0; i < NROWS; ++i)
			for (size_t j = 0; j < NCOLS; ++j)
				newData[i][j] = this->nums[i][j] - other.nums[i][j];

		return Matrix(newData);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return nullptr;
	}
}

template<size_t NROWS, size_t NCOLS>
inline Matrix<NROWS, NCOLS>& Matrix<NROWS, NCOLS>::operator*(const Matrix& other)
{
	return Matrix();
}
