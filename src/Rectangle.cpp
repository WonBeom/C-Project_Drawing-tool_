#include "Rectangle.h"
#include <iostream>

using namespace std;


Rectangle::Rectangle()
	: leftTop_xpos(0), leftTop_ypos(0),rightBot_xpos(0), rightBot_ypos(0),
	  red_per(0), green_per(0), blue_per(0)
{

}
/*
Set the composition of Rectangle from outside.
*/
void Rectangle::set()
{
	cout<<"�簢���� �»�� ��ǥ (x, y) ���� �Է��ϼ���: ";
	cin>>leftTop_xpos>>leftTop_ypos;
	

	cout<<"�簢���� ���ϴ� ��ǥ (x, y) ���� �Է��ϼ���: ";
	cin>>rightBot_xpos>>rightBot_ypos;
	

	cout<<"�簢���� ���� (r, g, b) ���� �Է��ϼ���: ";
	cin>>red_per>>green_per>>blue_per;
	
	shape::set_id();

	cout<<"�簢��(���� ID:"<< shape::get_id()<<")�� �����Ǿ����ϴ�."<<endl;
}

/* 
Put the information of Rectangle for ps type file.

*/

void Rectangle::draw_(ofstream &ofStream)
{
	ofStream<<"%drau a rectangle"<<endl<<endl;
	ofStream<<"newpath"<<endl;
	ofStream<<"\t"<<leftTop_xpos<<" "<<leftTop_ypos<<" "<<"moveto"<<endl;
	ofStream<<"\t"<<leftTop_xpos<<" "<<rightBot_ypos<<" "<<"lineto"<<endl;
	ofStream<<"\t"<<rightBot_xpos<<" "<<rightBot_ypos<<" "<<"lineto"<<endl;
	ofStream<<"\t"<<rightBot_xpos<<" "<<leftTop_ypos<<" "<<"lineto"<<endl;
	ofStream<<"closepath"<<endl<<endl;
	ofStream<<red_per<<" "<<green_per<<" "<<blue_per<<" "<<"setrgbcolor";
	ofStream<<"\t\t % r g b"<<endl;
	ofStream<<"fill"<<"\t\t % draw a shape by filling with the current color"<<endl<<endl;
}

void Rectangle::moving(double move,double move2)
{
	leftTop_xpos+=move;
	leftTop_ypos+=move2;
	rightBot_xpos+=move;
	rightBot_ypos+=move2;

}



void Rectangle:: setSize(double s)
{
}