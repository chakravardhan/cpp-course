//in mechanic1.cpp
#include<iostream>
#include<cstdlib>
#include<fstream>
#include "mechanic1.h"
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