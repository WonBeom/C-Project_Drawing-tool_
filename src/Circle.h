#ifndef CIRCLE_H
#define CIRCLE_H

#include <fstream>
#include"shape.h"
using namespace std;
class Circle : public shape
{
	double xpos, ypos;                    // �߽� ��ǥ
	double size;                          // ������
	double red_per,green_per,blue_per;    //  RGB ��

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