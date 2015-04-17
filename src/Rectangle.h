#ifndef REC_H
#define REC_H

#include <fstream>
#include"shape.h"
using namespace std;

class Rectangle : public shape
{
	double leftTop_xpos, leftTop_ypos;            //�»�� ������
	double rightBot_xpos, rightBot_ypos;          //���ϴ� ������
	double red_per, green_per, blue_per;          //RGB ��

public:
	Rectangle();
	void set();
	void draw_(ofstream &ofStream);
	void moving(double move,double move2);
	void setSize(double s);
	
	virtual SHAPE_TYPE type ()
  {
	return SHAPE_RECTANGLE_TYPE;
  }
};

#endif