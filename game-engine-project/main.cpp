#include <iostream>
#include "math\Math.h"

int main()
{
	Math::Matrix3f* newMtx = Math::Matrix3f::uniform(9.0f);
	newMtx->print();
}