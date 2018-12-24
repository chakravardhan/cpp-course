//in mechanic.h
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
      node *entry;
      node *print;
      node *bottom;
      node *last_entry;
      node *second_last_entry;
      int x;

       public:
      Mechanic( )
      {
      top=NULL;
      bottom=NULL;
      }

      void pop();
      void push(int);
      void pope( );
	
};
