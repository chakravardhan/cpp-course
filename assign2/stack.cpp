#include<iostream>
#include<cstdlib>
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
		void push()
		{
			if(top==size) cout<<"Stack is already full"<<endl;
			else
			{
				cin>>item;int i;
				arr[++top]=item;
				cout<<"The stack is now"<<endl;
				for(i=top;i>=0;i--) cout<<arr[i]<<endl;
			}
		}
		void pop()
		{
			if(top==-1) cout<<"The stack is empty"<<endl;
			else
			{
				item=arr[top--];int i;
				cout<<"The deleted item was "<<item<<endl;
				cout<<"The stack is now"<<endl;
				for(i=top;i>=0;i--) cout<<arr[i]<<endl;
			}
		}
 
};
 
int main()
{
	Mechanic obj;
	//char ch='y';
	do
	{
		cout<<"Stack array choices : "<<endl;
		cout<<"1.Enter 1 for push"<<endl;
		cout<<"2.Enter 2 for pop"<<endl;
		cout<<"3.Enter 3 for exit"<<endl;
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1 : {obj.push();break;}
			case 2 : {obj.pop();break;}
			case 3 : {cout<<"Bye..."<<endl;exit(0); }
			default : {cout<<"Invalid choice stupid ...."<<endl;exit(0);}
		}
		cout<<"Do u wish to continue(y|n)"<<endl;
		cin>>ch;
	}while(ch=='y'||ch=='Y');
return 0;
}