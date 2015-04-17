#include "Triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle()
	:xpos01(0),ypos01(0),xpos02(0),ypos02(0),xpos03(0),ypos03(0),
     red_per(0),green_per(0),blue_per(0)
{

}
/*
Set the composition of Triangle from outside.
*/
void Triangle::set()
{
	 cout<<"�ﰢ���� �� ������ ��ǥ (x, y) ���� �ݽð� ���� ������ �Է��ϼ���: ";
	 cin>>xpos01>>ypos01>>xpos02>>ypos02>>xpos03>>ypos03;
	 

	 cout<<"�ﰢ���� ���� (r, g, b) ���� �Է��ϼ���: ";
	 cin>>red_per>>green_per>>blue_per;
	 
	 shape::set_id();

	 cout<<"�ﰢ��(���� ID:"<< shape::get_id()<<")�� �����Ǿ����ϴ�."<<endl;
}




/* 
Put the information of triangle for ps type file.

*/
void Triangle::draw_(ofstream &ofStream)        
{
	ofStream<<"% draw a triangle"<<endl<<endl;
	ofStream<<"newpath"<<endl;
	ofStream<<"\t"<<xpos01<<" "<<ypos01<<" "<<"moveto"<<endl;
	ofStream<<"\t"<<xpos02<<" "<<ypos02<<" "<<"lineto"<<endl;
	ofStream<<"\t"<<xpos03<<" "<<ypos03<<" "<<"lineto"<<endl;
	ofStream<<"closepath"<<endl<<endl;
	ofStream<<red_per<<" "<<green_per<<" "<<blue_per<<" "<<"setrgbcolor";
	ofStream<<"\t % r g b"<<endl;
	ofStream<<"fill"<<"\t\t"<<"%draw a shape by filling with the current color"<<endl<<endl;

}

void Triangle::moving(double move,double move2)
{
	xpos01+=move;
	ypos01+=move2;
	xpos02+=move;
	ypos02+=move2;
	xpos03+=move;
	ypos03+=move2;
}



void Triangle:: setSize(double s)
{
}