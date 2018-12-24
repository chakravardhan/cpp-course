
//in mechanic1.h
using namespace std;


class Mechanic
{
	private:
		struct node
		{
			int data;
			node *next;
		};
		node *top;
		node *bottom;
		node *entry;
		node *print;
      	node *last_entry;
      	node *second_last_entry;

	public:
		Mechanic()
		{
			top=NULL;
			bottom=NULL;
		}
		void push(int);
		void pop();
		void pope();

};

