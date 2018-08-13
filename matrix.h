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
	Matrix operator[](int row);// ȡ��һ��
	Matrix operator()(int col);
	Matrix transpose();
	void   operator=(const Matrix & mat);
	void   mprint();

	float getElement(int i ,int j) const;
	void  setElement(int i, int j, float val);
	void  setDiagI(float num);//������Խ���Ԫ������Ϊnum
	int   getnumRows() const;
	int   getnumCols() const ;
	void  setElementZero();


	void setRows(int rows);
	void setCols(int cols);
};

ostream & operator << (ostream &,const Matrix &);//Ϊʲôʡ�Բ�����������

#endif
