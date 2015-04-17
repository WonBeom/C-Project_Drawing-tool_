#ifndef CIRCLE_H
#define CIRCLE_H

#include <fstream>
#include"shape.h"
using namespace std;
class Circle : public shape
{
	double xpos, ypos;                    // 중심 좌표
	double size;                          // 반지름
	double red_per,green_per,blue_per;    //  RGB 값

public:
	Circle();
	void set();
	void draw_(ofstream &ofStream);
	void moving(double move,double move2);
	void setSize(double s);

	virtual SHAPE_TYPE type ()
	{
		return SHAPE_CIRCLE_TYPE;
    }
};

#endif