#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <fstream>
using namespace std;

enum SHAPE_TYPE
{
  SHAPE_CIRCLE_TYPE, SHAPE_TRIANGLE_TYPE, SHAPE_RECTANGLE_TYPE
};
class shape
{
	int id;

public:
	static int tp_id;
	shape(){};
	void set_id()
	{
	id=tp_id;
	tp_id++;

	};
	int get_id()
	{
	return id;
	};
	virtual void moving(double move,double move2)=0;
	virtual void setSize(double s)=0;
	virtual void set()=0;
	virtual void draw_(ofstream &ofStream)=0;

	virtual SHAPE_TYPE type () = 0;
};

#endif