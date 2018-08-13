#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
using namespace std;

class Matrix
{
private:
	int numRows;
	int numCols;
	float * start;
public:
	Matrix(int m, int n);
	Matrix::Matrix(const Matrix & mat);
	Matrix(int n);

	~Matrix();

	void   setElement();
	Matrix operator+(const Matrix & mat);
	Matrix operator-(const Matrix & mat);
	Matrix operator*(const Matrix & mat);
	Matrix operator*(const float scale);
	Matrix operator[](int row);// 取出一行
	Matrix operator()(int col);
	Matrix transpose();
	void   operator=(const Matrix & mat);
	void   mprint();

	float getElement(int i ,int j) const;
	void  setElement(int i, int j, float val);
	void  setDiagI(float num);//将矩阵对角线元素设置为num
	int   getnumRows() const;
	int   getnumCols() const ;
	void  setElementZero();


	void setRows(int rows);
	void setCols(int cols);
};

ostream & operator << (ostream &,const Matrix &);//为什么省略参数？？？？

#endif
