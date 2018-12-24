//in mechanic.h
using namespace std;
class node
{	
	public:
		int info;
  		node *next;
};
class Mechanic
{
	private:		
		node *top;
		node *top1;
		node *temp;
		int x;
	public:
		Mechanic()
		{
			top=NULL;
		}
 		void push(int);
		void pop();
		void pope();
};
