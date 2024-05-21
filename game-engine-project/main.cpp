#include <iostream>
#include "Math/Matrix/matrix.h"

int main()
{
	Matrix<3,3>newMtx = Matrix<3,3>::uniform(9.0f);
	std::cout << newMtx;	
}