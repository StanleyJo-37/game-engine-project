#include <iostream>
#include "Math/matrix/matrix.hpp"

int main()
{
	Matrix2f newMtx = Matrix2f({ { 1.0f, 2.0f },
								 { 4.0f, 5.0f },
												});
	std::cout << newMtx;	
}