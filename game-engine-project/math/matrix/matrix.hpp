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
	float nums[NROWS][NCOLS];
	size_t size[2];
public:
	Matrix(const float data[NROWS][NCOLS]);
	Matrix(Matrix&& other) noexcept;
	Matrix(float (&&data)[NROWS][NCOLS]) noexcept;
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix() = default;

	static Matrix uniform(float num);

	float** get2DArray() const { return nums; }
	std::array<std::array<float, NCOLS>, NROWS> getSTDArray() const { return std::array<std::array<float, NCOLS>, NROWS>(nums); }
	std::vector<std::vector<float>> getSTDVector() const { return std::vector<std::vector<float>>(nums); }
	const size_t* getSize() const { return size; }

	float operator()(size_t _idx1, size_t _idx2) const { return this->nums[_idx1][_idx2]; }
	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);

	friend inline ostream& operator<<(ostream& os, const Matrix<NROWS, NCOLS>& _mtx)
	{
		for (int i = 0; i < NROWS; ++i)
			for (int j = 0; j < NCOLS; ++j)
				os << _mtx.nums[i][j] << (j == NCOLS - 1 ? "\n" : ", ");
		return os;
	}
};

using Matrix4f = Matrix<4, 4>;
using Matrix3f = Matrix<3, 3>;
using Matrix2f = Matrix<2, 2>;

#include "matrix.inl"