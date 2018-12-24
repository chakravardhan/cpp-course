#include<iostream>
#include<cstdlib>
#include<fstream>
#define size 100
using namespace std;

class Mechanic
{
	private :
		int arr[size];
		int top;
		int item;
	public : 
		Mechanic()
		{
			top=-1;
		}
		void push(int id)
		{
			if(top==size) cout<<"Stack is already full"<<endl;
			else
			{
			    int i;
				arr[++top]=id;
			}
		}
		void pop()
		{
			if(top==-1) cout<<"The stack is empty"<<endl;
			else
			{
				item=arr[top--];int i;
				cout<<"The deleted item was "<<item<<endl;
			}
		}
		void pope()
		{
		    int i;
		    for(i=top;i>=0;i--)
		    {
		        cout<<"The deleted item was "<<arr[i]<<endl;
		    }
        }
};

class FrontDesk
{
	private :
		int CID;
		string Type;

	public :
		void readFile()
		{
			Mechanic obj;
    		int num = 0,j;
    		ifstream fin;
    		fin.open("test");
    		if (!fin.good())
    		{
        		cout << "File not found" << endl;
    		}
    		whil
    		e(!fin.eof())
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
};

int main()
{
    cout << " " << endl;
    cout << "Garage\n" << endl;
    FrontDesk Customers;
    cout << "Reading all customer's data from file" << endl;
    Customers.readFile();
 	return 0;
}
