#include "matrix.h"

Matrix::Matrix(const float** nums)
{

}

Matrix3f::Matrix3f(const float (&nums)[rows][cols]) 
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			this->nums[i][j] = nums[i][j];
}

Matrix3f Matrix3f::uniform(float num)
{
	float nums[rows][cols];
	std::fill(&nums[0][0], &nums[rows - 1][cols - 1], num);
	return Matrix3f(nums);
}

void Matrix3f::print() const
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			cout << nums[i][j] << (j == cols - 1 ? std::endl : ' ');
}

