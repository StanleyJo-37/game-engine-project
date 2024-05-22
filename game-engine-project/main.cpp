#include <iostream>
#include "Math/matrix/matrix.hpp"

int main()
{
	Matrix3f newMtx = Matrix3f({ { 1.0f, 2.0f, 3.0f },
								 { 4.0f, 5.0f, 6.0f },
								 { 7.0f, 8.0f, 9.0f }
													   });
	std::cout << newMtx;	
}