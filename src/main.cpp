/*********************************************************************
*     project_02                                                     *
*                                 ����������Ŵ���   ��ǻ�Ͱ��к�    *
*											      20103389 �ֿ���    *
*********************************************************************/

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "shape.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>           // STL�� �����ϴ� linked list
#include <algorithm>      // STL�� �����ϴ� ���� �˰���

using namespace std;
int shape::tp_id(0);

void main()
{
	ofstream ofStream;
	ofStream.open("Mypolygons.ps"); // ps ���� ����
	
	char choice;             
	char what;
	int howmany;
	int ID[300];
	char work;
	double movex;
	double movey;
	double sizeMn;

	

	list<shape*>          ll;                            //shape* �ڷ����� �����ϴ� linked list ����
	shape* ptr;                                          //shape*�� ������                           
	list<shape*>::iterator  it;                          //shape* �ڷ���  �湮�� ����


	char name[101];       // ps���� �̸� (100�� ����)
	char psfile[4]={'.','p','s'};
	
	ofStream<<"%!"<<endl;
	ofStream<<"50 50 scale\t\t"<<"% just scale the coordinate. DO NOT TOUCH THIS LINE."<<endl<<endl;

	
	cout<<"���� ����� ���� �����մϴ�."<<endl;

	while(1)
	{
		
		

		
		cout<<"��带 �����Ͻʽÿ�.:"<<endl;
		cout<<"(1) �����׸���, (2) ���� ����, (x) ���α׷� ����: ";
		cin>>choice;
		
		if(choice=='1')                            // �����׸���
		{
			cout<<"���� �� �׸��� ���� ���� �ϳ��� �����Ͻʽÿ�."<<endl;
			cout<<"(a)��, (b)�ﰢ��, (c)�簢��:"<<endl;
			cin>>what;
			

			if(what=='a')                            // ������
			{
				Circle* circle=new Circle;
				ptr=circle;
				circle->set();
				
				ll.push_back(ptr);

				
				
				
		
			}
			
			else if(what== 'b')                     // �ﰢ�� ����
			{
				Triangle* triangle=new Triangle;
				ptr=triangle;
				triangle->set();
				
				ll.push_back(ptr);

				
				
				
			}
		
			else if(what=='c')                      // �簢�� ����
			{
				Rectangle* rectangle=new Rectangle;
				ptr=rectangle;
				rectangle->set();
				
				ll.push_back(ptr);

				
				
				
			}
		


		}
		else if(choice=='2')
		{
			cout<<"������ ������ ������ ID�� �Է��ϼ���:"<<endl;
			cin>>howmany;
			for(int a=0;a<howmany;a++)
			{
				cin>>ID[a];
			}

			cout<<"���õ� ������ �� �۾��� �����ϼ���."<<endl;
			cout<<"(a) ���� �� �ٿ��ֱ�, (b) �� ������ ��������, (c) �� �ڷ� ������, (t) �̵�, (s) Ȯ����� (d) ����:"<<endl;
			
			cin>>work;
			
			if(work=='a')
			{
				for(int a=0;a<howmany;a++)
				{
					std::list<shape*>::iterator pos;
					for (it = ll.begin(); it != ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
							
							 pos = it;
							 break;
						}
					}
					shape* new_fig;
					switch( (*pos)->type() )
					 {
						  case SHAPE_CIRCLE_TYPE:
						  new_fig = new Circle( *((Circle*)(*pos)));
						  new_fig->set_id();
		                  break;
						  case SHAPE_TRIANGLE_TYPE:
		                  new_fig = new Triangle( *((Triangle*)(*pos)));
						  new_fig->set_id();
		                  break;
	                      case SHAPE_RECTANGLE_TYPE:
		                  new_fig = new Rectangle(*((Rectangle*)(*pos)));
						  new_fig->set_id();
		                  break;
	                 }
	                  ll.push_back(new_fig);
					  
				}

			}
			else if(work=='b')
			{ 
				list<shape*>::iterator  loc, prev_loc;    // ��ũƮ ����Ʈ���� �� ����� ��ġ�� ������ �� �ִ� ���� loc, prev_loc ����
				for(int a=0;a<howmany;a++)
				{
					for(it = ll.begin(); it!= ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
					
							while(1)
							{
								loc = find(ll.begin(), ll.end(), *it);      // ��ũƮ ����Ʈ ls�� ó��(begin())���� ��(end()) �˻��ϸ� *it�� ����ִ� ���� ��ġ�� loc�� ����
								if (loc != ll.begin())                      // loc�� ��ũƮ ����Ʈ�� ���� ����� ��ġ�� �ƴ϶��...
								{
									prev_loc = loc; --prev_loc;             // loc�� ���� prev_loc ���
									ll.splice(prev_loc, ll, loc);           // loc�� �ִ� ���� ������ prev_loc�� �տ� ����
								}
								else if(loc == ll.begin())
									break;
							}
						}
					}
				}
			}
			else if(work=='c')
			{
				list<shape*>::iterator  loc,next_loc;         // ��ũƮ ����Ʈ���� �� ����� ��ġ�� ������ �� �ִ� ���� loc, next_loc ����
				for(int a=0;a<howmany;a++)
				{
					for(it = ll.begin(); it!= ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
						
							while(1)
							{
								loc = find(ll.begin(), ll.end(), *it);      // ��ũƮ ����Ʈ ls�� ó��(begin())���� ��(end()) �˻��ϸ� *it�� ����ִ� ���� ��ġ�� loc�� ����
								next_loc = loc;     ++next_loc;
								if (next_loc != ll.end())                   // loc�� ��ũƮ ����Ʈ�� ������ ����� ��ġ�� �ƴ϶��... (next_loc�� end�� ���� ������...)
								 {  
									 
									 ll.splice(loc, ll, next_loc);           // next_loc�� �ִ� ���� ������ loc�� �տ� ����
								 }
								else if(next_loc == ll.end())
									break;
							}
						}
					}
				}
			}
			else if(work=='t')
			{
				cout<<"�̵��� (dx, dy) ���� �Է��ϼ���:"<<endl;
				cin>>movex;
				cin>>movey;

				for(int a=0;a<howmany;a++)
				{
					for (it = ll.begin(); it != ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
							(*it)->moving(movex,movey);
							
						}
					}
				}
			}
			else if(work=='s')
			{
				cout<<"Ȯ����ҷ��� �Է��ϼ���:"<<endl;
				cin>>sizeMn;
				for(int a=0;a<howmany;a++)
				{
					for (it = ll.begin(); it != ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
							(*it)->setSize(sizeMn);
							
						}
					}
				}
			}
			/*
			 �� ��ü�� �ּҷ� �����ؼ�  id  ������ �� Ȯ���Ͽ� 
			 �Է¹��� ID �� ���� ���  ��ũ�� ����Ʈ ll �� ����� �ּҰ� ����

			*/
			else if(work=='d')
			{
				for(int a=0;a<howmany;a++)
				{
					for (it = ll.begin(); it != ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
							
							delete *it;
							ll.erase(it);
							
							break;
						}
					}
				}
			}

		}
		
		
		else if(choice=='x')                     //���α׷� ����
		{
			/*
			�ϰ�������  ��ũ�帮��Ʈ�� ������ִ� �ּҸ� �v�� ���� draw

			*/

			for (it = ll.begin(); it != ll.end(); ++it)
				{
					
					(*it)->draw_(ofStream);
						
					
				}
			/*

			�׸��� �����ִ� ������ ���� �޸� ����

			*/
			for (it = ll.begin(); it != ll.end(); ++it)
				{
						
					delete *it;
					
				}


			ofStream<<"showpage"<<endl;
			ofStream.close();
			
			cout<<"���ݱ��� �׸� ������ ������ ���� �̸��� �Է��ϼ���: ";
			cout<<endl;
			
			cin>>name;

			

			strcat(name,psfile);
			
			rename("Mypolygons.ps",name);
			
			
			cout<<"���� ���丮�� "<<name<<"������ �����Ǿ����ϴ�."<<endl<<endl;
			
			cout<<"���� ����� ���� �����մϴ�."<<endl;

			
			exit(1);

			break;
		}
			
		
			
	}
		

}

