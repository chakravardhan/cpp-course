#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;


class FrontDesk
{
	private :
		int CID;
		string Type;

	public :
		void readFile();
		    
};

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

void Mechanic::push(int id)
{
	entry=new node;

    if(bottom==NULL)
    {
    	entry->data=id;
    	entry->next=NULL;
    	bottom=entry;
    	top=entry;
    }

    else
    {
        entry->data=id;
        entry->next=NULL;
        top->next=entry;
        top=entry;
    }
    
}

void Mechanic::pop()
{
	if(bottom==NULL)
      cout<<"\n\n\n\t ***  Error : Stack is empty. \n"<<endl;

    else
    {
    	for(last_entry=bottom;last_entry->next!=NULL;
             last_entry=last_entry->next)
        second_last_entry=last_entry;

         if(top==bottom)
        bottom=NULL;

         int poped_element=top->data;

         delete top;

         top=second_last_entry;
         top->next=NULL;

        
      }

       
       
}
void Mechanic::pope()
{
	print=bottom;

    while(print!=NULL)
    {
        cout<<"\t "<<print->data<<endl;

        print=print->next;
    }
    

}

void FrontDesk::readFile()
{
	Mechanic obj;
	int num = 0,j;
	ifstream fin;
	fin.open("sample");
	if (!fin.good())
	{
   		cout << "File not found" << endl;
	}
  		while(!fin.eof())
	{
		fin >> Type;
		if(Type=="R")
		{                     
   			fin >> CID ;
   			obj.push(CID);
   			num++;        
		}	     
		else if(Type=="N")
		{
			obj.pop();
		}
		else if(Type=="E")
		{
       		obj.pope();
    		break;    		
		}
	}
	fin.close();
}    
int main()
{
    cout << " " << endl;
    cout << "Garage\n" << endl;
    FrontDesk Customers;
    cout << "Reading all customer's data from file" << endl;
    Customers.readFile();
 	return 0;
}
