#ifndef REC_H
#define REC_H

#include <fstream>
#include"shape.h"
using namespace std;

class Rectangle : public shape
{
	double leftTop_xpos, leftTop_ypos;            //좌상단 꼭지점
	double rightBot_xpos, rightBot_ypos;          //우하단 꼭지점
	double red_per, green_per, blue_per;          //RGB 값

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