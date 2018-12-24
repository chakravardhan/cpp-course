//in mechanic.cpp
#include<iostream>
#include<cstdlib>
#include<fstream>
#include "mechanic.h"
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
        // for(last_entry=bottom;last_entry->next!=NULL;last_entry=last_entry->next)
         //{
        //second_last_entry=last_entry;
        //}

         if(top==bottom)
        bottom=NULL;

         x=top->data;

         delete(top);

         top=second_last_entry;
         top->next=NULL;

         cout<<"\n\n\n\t *** "<<x<<" is poped from the Stack."<<endl;
      }

}
void Mechanic::pope()
{
	print=bottom;
	 if(print!=NULL)
      cout<<"\n\n\n\n\n\t Values pushed onto Stack are : \n"<<endl;

       else
      cout<<"\n\n\n\n\n\t *** Nothing to show. "<<endl;
	while(print!=NULL)
      {
         cout<<"\t "<<print->data<<endl;

         print=print->next;
      }

	
	
}
