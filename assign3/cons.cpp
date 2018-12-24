#include<iostream>
using namespace std;
class X 
{
	private:
		int a;
		int b;
	public:
		X();
		int return1(void);
		int return2(void);
		X(int,int);
		X(const X &x);
		~X();
};

X::X()
{
	a=0;
	b=0;
}

X::X(int v,int w)
{
	a=v;
	b=w;
}

X::X(const X &x)
{
	a=x.a;
	b=x.b;
}

X::~X()
{
	cout<<"Destructing"<<a<<b<<endl;
	//delete *a;
	//delete *b;
}

int X::return1(void)
{
	return a;
	//return b;
}

int X::return2(void)
{
	return b;
	//return b;
}

void display(X x)
{

   cout << "a is : " << x.return1() <<endl;
   cout << "b is : " << x.return2() <<endl;
}

int main( )
{
   X value(10,10);

   display(value);

   return 0;
}