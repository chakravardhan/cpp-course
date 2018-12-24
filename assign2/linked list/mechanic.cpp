//in mechanic.cpp
#include<iostream>
#include<cstdlib>
#include<fstream>
#include "mechanic.h"
void Mechanic::push(int id)
{
	if(top==NULL)
	{
		top1=new node;
    	top1->info=id;
    	top1->next=top;
    	top=top1;
    }
    else
    {
    	temp =new node;
        temp->next = top;
        temp->info = id;
        top = temp;
    }
}
void Mechanic::pop()
{
	if(top==NULL)
		cout<<"Stack is empty"<<endl;
	else
	{
		x=top->info;
	    cout<<"The id whose work done is "<<x<<endl;
	    top1=top;
	    top=top->next;
	    delete(top1);
	}

}
void Mechanic::pope()
{
	top1 = top;
    if (top1 == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while (top1 != NULL)
    {
        cout<<"The id whose work done is "<<top1->info<<endl;
        top1 = top1->next;
    }
	
}


