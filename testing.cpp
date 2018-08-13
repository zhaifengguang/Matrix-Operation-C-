#include <iostream>
#include "matrix.h"

using namespace std;
void main()
{
	Matrix mat1(2,3);
	Matrix mat2(3,2);
	Matrix mat3(1,2);

	mat1.setElement();
	mat2 = mat1.transpose();
	mat2.mprint();
	//mat2 = mat1.transpose();


	//mat2 = mat1 * 2;

	cout << mat2;
	//mat2.setElement();
	//mat2.mprint();
	//mat3 = mat1 + mat2;
	//mat2 = mat1 - mat2;
	//mat3.mprint();
	system("pause");

}