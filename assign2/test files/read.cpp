#include <iostream>
#include <fstream>
using namespace std;
class FrontDesk
{
    public:
        
        void setFields(int,int);
        void DisplayCustomer(int);
        static int numIds;
            
    private:

        int CusID[10];
};

	       

int FrontDesk::numIds = 0;

void FrontDesk::setFields(int ID,int index)
{
    CusID[index] = ID;
}
	 

void FrontDesk::DisplayCustomer(int index)
{
    cout << "ID:" << CusID[index] << endl;
}

	 

void readFile(FrontDesk &c);
void displayClass(FrontDesk c);

	 

int main()

{

    cout << " " << endl;
    cout << "Garage\n" << endl;
    FrontDesk Customers;
    cout << "Reading all customer's data from file" << endl;
    //cout << " \n" << endl;
    readFile(Customers);
    displayClass(Customers);


	return 0;

}

	 

void readFile(FrontDesk &c)
{
    int CID, num = 0;
    ifstream fin;
    fin.open("customers.txt");

    if (!fin.good())
    {
        cout << "File not found" << endl;
        
    }
    while(!fin.eof())
    {                     
        fin >> CID ; 
        c.setFields(CID,num);
        num++;        
        FrontDesk::numIds++;
    }	     
    fin.close();
}

	 

void displayClass(FrontDesk c)
{

    int num = FrontDesk::numIds;
    cout << "Total number of students: " << num << endl;
	    for (int i = 0; i < num; i++)
	    {
	        c.DisplayCustomer(i);
            cout << endl;
	    }
}