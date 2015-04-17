#ifndef TRI_H
#define TRI_H

#include<fstream>
#include"shape.h"
using namespace std;

class Triangle : public shape
{
	double xpos01,ypos01;                  // ������ 1
	double xpos02,ypos02;                  // ������ 2
	double xpos03,ypos03;                  // ������ 3
	double red_per, green_per, blue_per;   // RGB ��

public:
	Triangle();
	void set();
	void draw_(ofstream &ofStream);
	void moving(double move,double move2);
	void setSize(double s);
	virtual SHAPE_TYPE type ()
   {
	return SHAPE_TRIANGLE_TYPE;
   }
};

#endif