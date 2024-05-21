#include <iostream>
#include "Math/matrix/matrix.hpp"

int main()
{
	Matrix3f newMtx = Matrix3f::uniform(9.0f);
	std::cout << newMtx;	
}