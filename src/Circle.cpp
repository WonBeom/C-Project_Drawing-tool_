#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle()
	:xpos(0),ypos(0),size(0),red_per(0),green_per(0),blue_per(0)
{
	
	
}
/*
Set the composition of Circle from outside.
*/
void Circle::set()
{

	
	cout<<"���� �߽� ��ǥ(x,y) ���� �Է��ϼ��� :";
	cin>>xpos>>ypos;
	

	cout<<"���� ������ R ���� �Է��ϼ���: ";
	cin>>size;
	

	cout<<"���� ���� (r, g, b) ���� �Է��ϼ��� :";
	cin>>red_per>>green_per>>blue_per;
	
	shape::set_id();

	cout<<"��(���� ID:"<< shape::get_id()<<")�� �����Ǿ����ϴ�."<<endl;
}


/* 
Put the information of Circle for ps type file.

*/
void Circle::draw_(ofstream &ofStream)
{
	ofStream<<"% draw a circle"<<endl<<endl;
	ofStream<<"newpath"<<endl<<"\t\t"<<xpos<<" "<<ypos<<" "<<size<<" ";
	ofStream<<0<<" "<<360<<" "<<"arc\t"<<"% x y r start_angle end_angle"<<endl;
	ofStream<<"closepath"<<endl<<endl;
	ofStream<<red_per<<" "<<green_per<<" "<<blue_per<<" "<<"setrgbcolor\t"<<"% r g b"<<endl;
	ofStream<<"fill\t\t"<<"%draw a shape by filling with the current color";

}

void Circle::moving(double move,double move2)
{
	xpos+=move;
	ypos+=move2;
	
}

void Circle::setSize(double s)
{
	size*=s;
}


