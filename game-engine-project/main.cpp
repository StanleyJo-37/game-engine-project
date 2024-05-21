#include <iostream>
#include "Math/matrix/matrix.hpp"

int main()
{
	Matrix<3, 3>newMtx = Matrix<3, 3>::uniform(9.0f);
	std::cout << newMtx;	
}