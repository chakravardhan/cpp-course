#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class Pos
{
	public:
		int x;
		int y;
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
	Circle(int a,int b,int c,int t)
	{
		position.x=a;
		position.y=b;
		position.radius=c;
		type=t;
	}
	int getType()
	{
		return type;
	}
	int getR()
	{
		return position.radius;
	}
	int getX()
	{
		return position.x;
	}
	int getY()
	{
		return position.y;
	}
};
class 
{
	public:
		circle C;
		stack * next;
};
class game
{
	private:
		int count;
	public:
		stack * list;
		game()
		{
			list=NULL;
			count = 0;
		}
		int checkCollision(circle a,circle b)
		{
			int sumRad= a.getRad() + b.getRad();
			sumRad= sumRad * sumRad;
			int xDist= (a.getx()- b.getx())*(a.getx()- b.getx());
			int yDist= (a.gety()- b.gety())*(a.gety()- b.gety());
			int totaldist=xDist+yDist;
			if(sumRad<totaldist)
				return 0;
			else
				return 1;
		}
		void addCircle(int a,int b,int c)
		{
			stack * temp= new stack;
			temp->C.pos.x= a;
			temp->C.pos.y= b;
			temp->C.pos.rad= c;
			count++;
			if (count%3==0)
				temp->C.type=1;
			else if(count%10==0)
				temp->C.type=2;
			else
				temp->C.type=0;
			temp->next=list;
			list=temp;
		}
		void setNewValues()
		{
			stack * temp = list;
			stack temp1;
			while(temp!=NULL)
			{
				if(temp->C.getType()==0)
				{
					temp->C.pos.x= rand()%500;
					temp->C.pos.y= rand()%500;
				}
				else if(temp->C.getType()==1)
				{
					temp->C.pos.y += rand()% 3;
				}
				else if(temp->C.getType()==2)
				{
					addCircle(temp->C.getx(),temp->C.gety(),temp->C.getRad());
					temp->C.pos.x= rand()%500;
					temp->C.pos.y= rand()%500;
				}
				temp=temp->next;
			}
		}
		int getScore()
		{
			return count;
		}
};
class user
{
	private:
		game Cgame;
	public:
		int enterNewCircle(int a,int b,int c)
		{
			stack * temp= Cgame.list;
			circle newcircle(a,b,c,0);
			while(temp!=NULL)
			{
				if(Cgame.checkCollision(newcircle,temp->C)==1)
					return -1;
				temp=temp->next;

			}
			Cgame.addCircle(a,b,c);
			return 0;
		}
		int getMyScore()
		{
			return Cgame.getScore();
		}
		void setvalues()
		{
			Cgame.setNewValues();
		}
};
int main()
{
	user Lakshay;
	int centrex,centrey,radius,check;
	cin>>centrex;
	cin>>centrey;
	cin>>radius;
	while(centrex!=0 && centrey!=0 && radius!=0)
	{
		check=Lakshay.enterNewCircle(centrex,centrey,radius);
		if(check==-1)
			break;
		else
			cout<<"circle entered successfully and score is "<<Lakshay.getMyScore()<<endl;
		Lakshay.setvalues();
		cin>>centrex;
		cin>>centrey;
		cin>>radius;
	}
	cout<<"Game Over and Score is "<<Lakshay.getMyScore()<<endl;
}
