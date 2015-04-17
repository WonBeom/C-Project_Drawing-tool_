/*********************************************************************
*     project_02                                                     *
*                                 전자정보통신대학   컴퓨터공학부    *
*											      20103389 최원범    *
*********************************************************************/

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "shape.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>           // STL이 제공하는 linked list
#include <algorithm>      // STL이 제공하는 각종 알고리즘

using namespace std;
int shape::tp_id(0);

void main()
{
	ofstream ofStream;
	ofStream.open("Mypolygons.ps"); // ps 파일 생성
	
	char choice;             
	char what;
	int howmany;
	int ID[300];
	char work;
	double movex;
	double movey;
	double sizeMn;

	

	list<shape*>          ll;                            //shape* 자료형을 저장하는 linked list 생성
	shape* ptr;                                          //shape*형 포인터                           
	list<shape*>::iterator  it;                          //shape* 자료형  방문자 생성


	char name[101];       // ps파일 이름 (100자 내로)
	char psfile[4]={'.','p','s'};
	
	ofStream<<"%!"<<endl;
	ofStream<<"50 50 scale\t\t"<<"% just scale the coordinate. DO NOT TOUCH THIS LINE."<<endl<<endl;

	
	cout<<"도형 드로잉 툴을 구동합니다."<<endl;

	while(1)
	{
		
		

		
		cout<<"모드를 선택하십시오.:"<<endl;
		cout<<"(1) 도형그리기, (2) 도형 선택, (x) 프로그램 종료: ";
		cin>>choice;
		
		if(choice=='1')                            // 도형그리기
		{
			cout<<"다음 중 그리고 싶은 도형 하나를 선택하십시오."<<endl;
			cout<<"(a)원, (b)삼각형, (c)사각형:"<<endl;
			cin>>what;
			

			if(what=='a')                            // 원선택
			{
				Circle* circle=new Circle;
				ptr=circle;
				circle->set();
				
				ll.push_back(ptr);

				
				
				
		
			}
			
			else if(what== 'b')                     // 삼각형 선택
			{
				Triangle* triangle=new Triangle;
				ptr=triangle;
				triangle->set();
				
				ll.push_back(ptr);

				
				
				
			}
		
			else if(what=='c')                      // 사각형 선택
			{
				Rectangle* rectangle=new Rectangle;
				ptr=rectangle;
				rectangle->set();
				
				ll.push_back(ptr);

				
				
				
			}
		


		}
		else if(choice=='2')
		{
			cout<<"선택할 도형의 개수와 ID를 입력하세요:"<<endl;
			cin>>howmany;
			for(int a=0;a<howmany;a++)
			{
				cin>>ID[a];
			}

			cout<<"선택된 도형에 할 작업을 선택하세요."<<endl;
			cout<<"(a) 복사 및 붙여넣기, (b) 맨 앞으로 가져오기, (c) 맨 뒤로 보내기, (t) 이동, (s) 확대축소 (d) 삭제:"<<endl;
			
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
				list<shape*>::iterator  loc, prev_loc;    // 링크트 리스트에서 각 요소의 위치를 저장할 수 있는 변수 loc, prev_loc 선언
				for(int a=0;a<howmany;a++)
				{
					for(it = ll.begin(); it!= ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
					
							while(1)
							{
								loc = find(ll.begin(), ll.end(), *it);      // 링크트 리스트 ls의 처음(begin())부터 끝(end()) 검색하며 *it가 들어있는 곳의 위치를 loc에 대입
								if (loc != ll.begin())                      // loc가 링크트 리스트의 최초 요소의 위치가 아니라면...
								{
									prev_loc = loc; --prev_loc;             // loc의 앞인 prev_loc 계산
									ll.splice(prev_loc, ll, loc);           // loc에 있는 값을 때내어 prev_loc의 앞에 삽입
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
				list<shape*>::iterator  loc,next_loc;         // 링크트 리스트에서 각 요소의 위치를 저장할 수 있는 변수 loc, next_loc 선언
				for(int a=0;a<howmany;a++)
				{
					for(it = ll.begin(); it!= ll.end(); ++it)
					{
						if ((*it)->get_id() == ID[a])
						{
						
							while(1)
							{
								loc = find(ll.begin(), ll.end(), *it);      // 링크트 리스트 ls의 처음(begin())부터 끝(end()) 검색하며 *it가 들어있는 곳의 위치를 loc에 대입
								next_loc = loc;     ++next_loc;
								if (next_loc != ll.end())                   // loc가 링크트 리스트의 마지막 요소의 위치가 아니라면... (next_loc가 end와 같지 않으면...)
								 {  
									 
									 ll.splice(loc, ll, next_loc);           // next_loc에 있는 값을 때내어 loc의 앞에 삽입
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
				cout<<"이동량 (dx, dy) 값을 입력하세요:"<<endl;
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
				cout<<"확대축소량을 입력하세요:"<<endl;
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
			 각 객체의 주소로 접근해서  id  변수의 값 확인하여 
			 입력받은 ID 와 같을 경우  링크드 리스트 ll 에 저장된 주소값 삭제

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
		
		
		else if(choice=='x')                     //프로그램 종료
		{
			/*
			일괄적으로  링크드리스트에 저장되있는 주소를 틍해 도형 draw

			*/

			for (it = ll.begin(); it != ll.end(); ++it)
				{
					
					(*it)->draw_(ofStream);
						
					
				}
			/*

			그리고 남아있는 나머지 도형 메모리 해제

			*/
			for (it = ll.begin(); it != ll.end(); ++it)
				{
						
					delete *it;
					
				}


			ofStream<<"showpage"<<endl;
			ofStream.close();
			
			cout<<"지금까지 그린 도형을 저장할 파일 이름을 입력하세요: ";
			cout<<endl;
			
			cin>>name;

			

			strcat(name,psfile);
			
			rename("Mypolygons.ps",name);
			
			
			cout<<"현재 디렉토리에 "<<name<<"파일이 생성되었습니다."<<endl<<endl;
			
			cout<<"도형 드로잉 툴을 종료합니다."<<endl;

			
			exit(1);

			break;
		}
			
		
			
	}
		

}

