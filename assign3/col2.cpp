#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

class Pos
{
	public:
		int x,y;
		int radius;
};

class Circle
{	
public:
	int type;
	Pos position;
	Circle()
	{
		position.x=0;
		position.y=0;
		position.radius=0;
	}

	Circle(int t,int a,int b,int c)
	{
		type=t;
		position.x=a;
		position.y=b;
		position.radius=c;
		
	}

	int Type()
	{
		return type;
	}
	int R()
	{
		return position.radius;
	}
	int X()
	{
		return position.x;
	}
	int Y()
	{
		return position.y;
	}
};


class node
{
	public:
		Circle C;
		node * next;
};


class Game
{
	private:
		int count;
	public:
		node * top;
		Game()
		{
			top=NULL;
			count = 0;
		}

		int distance( int x1, int y1, int x2, int y2 )
		{
			return sqrt( pow( x2 - x1, 2 ) + pow( y2 -y1, 2 ) );
		}

		int checkcollision(Circle A , Circle B)
		{
			if( distance( A.X(), A.Y(), B.X(), B.Y() ) < ( A.R() + B.R() ) )
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		
		void LL(int a,int b,int c)
		{
			node * top1= new node;
			top1->C.position.x= a;
			top1->C.position.y= b;
			top1->C.position.radius= c;

			count++;
			if (count%3==0)
			{
				top1->C.type=1;
			}
			else if(count%6==0)
			{
				top1->C.type=2;
			}
			else if(count%10==0)
			{	
				top1->C.type=3;
			}
			else
			{
				top1->C.type=0;
			}

			top1->next=top;
			top=top1;
		}


		int random1()
		{
			int rand1 = rand()%500 ;
    		return rand1;
		}

		int random2()
		{
			int rand2 = rand()% 2;
			return rand2;
		}


		void NewCircles()
		{
			int random;
			node * top1 = top;
			while(top1!=NULL)
			{
				if(top1->C.Type()==0)
				{
					random=random1();
					top1->C.position.x=random ;
					random=random1();
					top1->C.position.y=random ;
				}
				else if(top1->C.Type()==1)
				{
					random=random2();
					top1->C.position.radius += random;
				}

				else if(top1->C.Type()==2)
				{
					random=random2();
					top1->C.position.radius -= random;
				}

				else if(top1->C.Type()==3)
				{
					LL(top1->C.X(),top1->C.Y(),top1->C.R());
					random=random1();
					top1->C.position.x=random;
					random=random1();
					top1->C.position.y= random;
				}
				top1=top1->next;

			}
		}

		int Score()
		{
			return count;
		}
};


class Player
{
	private:
		Game MovingCircles;
	public:
		int Main(int a,int b,int c)
		{
			node * top1= MovingCircles.top;
			Circle randomcircle(0,a,b,c);
			while(top1!=NULL)
			{
				if(MovingCircles.checkcollision(randomcircle,top1->C)==1)
				{
					break;
				}
				else
					top1=top1->next;

			}
			MovingCircles.LL(a,b,c);
			return 0;
		}
		int Score1()
		{
			return MovingCircles.Score();
		}
		void setcircles()
		{
			MovingCircles.NewCircles();
		}
};
int main()
{
	Player Gamer;
	int cx,cy,rad,score;
	cout<<"Let The Game Begin"<<endl;
	cin>>cx;
	cin>>cy;
	cin>>rad;
	
	while((cx!=0 && cy!=0 && rad!=0) && ((cx<500) && (cy<500)))
	{
		Gamer.Main(cx,cy,rad);
		cout<<"Score is "<<Gamer.Score1()<<endl;
		Gamer.setcircles();
		cin>>cx;
		cin>>cy;
		cin>>rad;
	}
	score=Gamer.Score1();
	cout<<"Score is "<<score<<endl;
}
