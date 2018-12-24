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
			type=0;
		}
		Circle(int t,float a,float b,float c)
		{
			type=t;
			position.x=a;
			position.y=b;
			position.radius=c;
		}
		int getType()
		{
			return type;
		}
		int getX()
		{
			return position.x;
		}
		int getY()
		{
			return position.y;
		}
		int getR()
		{
			return position.radius;
		}
};	

class node
{	
	public:
		Circle c;
  		node *next;
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
    		count=0;
    	}
   		int distance( int x1, int y1, int x2, int y2 )
		{
			return sqrt( pow( x2 - x1, 2 ) + pow( y2 -y1, 2 ) );
		}


		int check_collision(Circle a,Circle b)
		{
			int sumRad= a.getR() + b.getR();
			sumRad= sumRad * sumRad;
			int xDist= (a.getX()- b.getX())*(a.getX()- b.getX());
			int yDist= (a.getY()- b.getY())*(a.getY()- b.getY());
			int totaldist=xDist+yDist;
			if(sumRad<totaldist)
				return 0;
			else
				return 1;
		}

		void addStack(int a,int b,int c)
		{
			node * top1=new node;
    		top1->c.position.x=a;
    		top1->c.position.y=b;
    		top1->c.position.radius=c;
   			count++;
   			if(count%3==0)
   			{
   				top1->c.type=1;
  			}
   			else if(count%10==0)
   			{
   				top1->c.type=2;
   			}
   			else
   			{
   				top1->c.type=0;
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
			int rand2 = rand()%3;
			return rand2;
		}


		void newCircles()
		{
			int random;//random1,random2,random3,random4;
			node * top1=top;
			while(top1!=NULL)
			{
				if(top1->c.getType()==0)
				{
					random=random1();
					top1->c.position.x=random ;//rand()%500;
					random=random1();
					top1->c.position.y=random ;//rand()%500;
				}
				else if(top1->c.getType()==1)
				{
					random=random2();
					top1->c.position.radius += random;
				}

				else if(top1->c.getType()==2)
				{
					addStack(top1->c.getX(),top1->c.getY(),top1->c.getR());
					random=random1();
					top1->c.position.x=random;//rand()%500;
					random=random1();
					top1->c.position.y= random;//rand()%500;
				}
			}
			top1=top1->next;
		}

		int getScore()
		{
			return count;
		}
};

class User
{
	private:
		Game cGame;
	public:
		

		int newCircles1(int d,int e,int f)
		{
			node * top1=cGame.top;
			Circle randomcircle(0,d,e,f);
			while(top1!=NULL)
			{
				if(cGame.check_collision(randomcircle,top1->c)==1)
				{
					return -1;
				}
				top1=top1->next;
			}
			cGame.addStack(d,e,f);
			return 0;

		}

		int getScore1()
		{
			return cGame.getScore();
		}

		void newCircles2()
		{
			cGame.newCircles();
		}
};

int main()
{
	User Gamer;
	int cx,cy,ra,check;
	cin>>cx;
	cin>>cy;
	cin>>ra;
	while(cx!=0 && cy!=0 && ra!=0)
	{
		check=Gamer.newCircles1(cx,cy,ra);
		if(check==-1)
		{
			break;
		}
		else
		{	
			cout<<"circle entered successfully and score is "<<Gamer.getScore1()<<endl;
		}
		Gamer.newCircles2();
		cin>>cx;
		cin>>cy;
		cin>>ra;
	}
	cout<<"Game Over and Score is "<<Gamer.getScore1()<<endl;
}

