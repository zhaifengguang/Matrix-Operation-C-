//利用操作符重载实现常见的矩阵运算功能，将C++prime plus全都实现一遍，
//最好的学习就是使用
#include <iostream>
#include <cmath>
#include "matrix.h"

void Matrix::setRows(int rows)
{
	numRows = rows;
}
 void Matrix::setCols(int cols)
{
	numCols = cols;
}

 void Matrix::mprint()
 {
	 for(int i = 0; i < numRows * numCols; i++)
	 {
		 printf("%f  ",start[i]);
		 if(((i+1) % numCols) == 0)
			 printf("\n");
	 }
	 printf("\n");
 }
 void Matrix::setElement()
 {
	 int total = numRows * numCols;
	 for(int i = 0; i < total; i++)
		 cin >> start[i]; 
 }

 float Matrix::getElement(int i,int j) const
 {
	 if( i > numRows || j > numCols || i <= 0 || j <= 0)
	 {
		 cout << "ERROR  " << endl;
	     return 0.0;
	 }
	 return start[(i - 1) * numCols + j - 1];

 }

 void Matrix::setElement(int i, int j, float val)
 {
	 if(i > numRows || j > numCols || i <= 0 || j <= 0)
	 {
		 cout << "ERROR "<< endl;
		 return;
	 }
	 start[(i - 1) * numRows + j - 1] = val;
 }
Matrix::Matrix(int m_numRwos, int m_numCols)//构造函数，赋给私有数据部分初值，赋值给数组为0
{
	setRows(m_numRwos);
	setCols(m_numCols);
	start = new float[m_numRwos * m_numCols];

	int total = m_numRwos * m_numCols;

	for(int i = 0; i < total; i++)
		start[i] = 0.0;
}

Matrix::Matrix(const Matrix & mat)
{
	numRows = mat.numRows;
	numCols = mat.numCols;
	start = new float[numRows * numCols];

	int total = numRows * numCols;
	for(int i = 0; i < total; i++)
		start[i] = mat.start[i];
}

Matrix::~Matrix()
{
	delete [] start;
}

Matrix Matrix::operator+(const Matrix & mat)
{
	if(numRows != mat.numRows || numCols != mat.numCols)
		cout << "ERROR: matrix wrong dismention when add"<<endl;

	Matrix result(numRows,numCols);
	result.start = new float[numRows * numCols];
	for(int i = 0; i < numRows * numCols; i++)
		result.start[i] = start[i] + mat.start[i];

	return result;
}

Matrix Matrix::operator-(const Matrix & mat)
{
	if(numRows != mat.numRows || numCols != mat.numCols)
		cout << "ERROR: matrix wrong dismension when sub"<<endl;

	Matrix result(numRows,numCols);
	result.start = new float[numRows * numCols];

	for (int i = 0; i < numRows * numCols;i++)
		result.start[i] = start[i] - mat.start[i];

	return result;
}

Matrix Matrix::operator*(const Matrix & mat)
{
	if(numCols != mat.numRows)
		cout << "ERROR: matrix wrong dismension when mul"<<endl;	
	Matrix result(numRows,mat.numCols);
	result.start = new float[numRows * mat.numCols];
	result.setElementZero();
	for(int i = 0; i < numRows; i++ )
		for(int j = 0; j < mat.numCols; j++)
			for(int k = 0; k < numCols;k++)
				result.start[i * mat.numCols + j] += start[k + i * numCols] * mat.start[k * mat.numCols + j];

	return result;
}

Matrix Matrix::operator*(const float scale)
{
	Matrix result(numRows,numCols);
	result.start = new float[numRows * numCols];
	for(int i = 0; i < numRows * numCols; i++)
		result.start[i] = start[i] * scale;

	return result;
}

void Matrix::operator=(const Matrix & mat)
{
	for(int i = 0; i < numRows * numCols; i++)
		start[i] = mat.start[i];
}

Matrix Matrix::operator[](int row)
{
	Matrix result(1,numCols);
	result.start = new float[numCols];

	for(int i = 0; i < numCols; i++)
		result.start[i] = start[row * numCols + i];

	return result;

}
Matrix Matrix::operator()(int col)
{
	Matrix result(numRows,1);
	result.start = new float[numRows];
	for(int i = 0; i < numRows; i++)
		result.start[i] = start[col + i * numRows];

	return result;
}

Matrix Matrix::transpose()
{
	Matrix result(numCols,numRows);
	for(int i = 0; i < numRows;i++)
		for(int j = 0; j < numCols; j++)
		{
			result.start[j * numRows + i] = start[i * numCols + j];
			//printf("%d ",(j * numRows + i));

		}


	return result;
}

void Matrix::setDiagI(float num)
{
	if( numRows != numCols &&  numRows < 0 )
	{
		cout << "ERROR " << endl;
		return;
	}
	for(int i = 0; i < numRows; i++)
		setElement(i+1,i+1,num);
}

int Matrix::getnumRows() const
{
	return numRows;
}

int Matrix::getnumCols() const
{
	return numCols;
}
ostream & operator << (ostream & os, const Matrix & mat)//如果矩阵是const类型，必须getnumRows getnumCols必须是const类型
{
	int rows = mat.getnumRows();
	int cols = mat.getnumCols();
	int i,j,k=0;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
			os << mat.getElement(i+1,j+1) << "    ";
		os << endl;
	}
	os << " \n";
	return os;
}

void Matrix::setElementZero()
{
	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols;j++)
			start[i * numCols + j] = 0.0f;
}