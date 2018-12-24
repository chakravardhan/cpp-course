#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
template <typename T>
class point
{
	public:
    	double x, y, z;
    	T * coord;
    	int D;
    	point(int n)
		{	
			D=n;
			coord= new T[n];
			for (int i = 0; i < n; ++i)
			{
				coord[i]=0;
			}
		}
		int getDim()
		{	
			return D;
		}
		T * getCoord()
		{
			return coord;
		}
		void setCoord(T * value)
		{
			for (int i = 0; i < D; i++)
			{
				coord[i]=value[i];
			}
		}
};
namespace traits
{
    template <class P,int D>
    struct access {};
}
namespace traits
{
    template <class T>
    struct access<T, 0>
    {
        static double get(T const& p)
        {
            return p.x;
        }
    };
    template <class T>
    struct access<T, 1>
    {
        static double get(T const& p)
        {
            return p.y;
        }
    };
	template <class T>
    struct access<T, 2>
    {
        static double get(T const& p)
        {
            return p.z;
        }
    };
}
template <int D, class P>
inline double get(P const& p)
{
    return traits::access<P, D>::get(p);
}
template <class P1, class P2, int D>
class p
{
	public :
		int apply(P1 const& a, P2 const& b)
    	{
       		int d = get<D-1>(a) - get<D-1>(b);
       		return d * d + p<P1, P2, D-1> ::apply(a, b);
    	}
};
template <class P1, class P2 >
class p<P1, P2, 0>
{
    int apply(P1 const&, P2 const&)
    {
        return 0;
    }
};
template <class P1, class P2,int D>
double distance3(P1 const& a, P2 const& b)
{
    return sqrt(p<P1, P2, D>::apply(a, b));
}
template <class P1>
P1 getClosest(P1 a,P1 const& b, int size)
{
	float min= distance3(a,b[0]);
	int j=0;
	for (int i = 1; i < size; ++i)
	{
		if(min>distance3(a,b[i]))
			j=i;
	}
	return b[j];
}
template <class P1, class P2>
P1 * getInterval(P1 const& a,int size)
{
	P1 const& result=new P1[2];
	result[0]=a[0];
	result[1]=a[0];
	P2 const& min=a[0];
	P2 const& max=a[0];
	P2* check;
	int dim= a[0].getDim();
	for (int i=0;i<dim;i++)
	{
		for (int j=0;j<size;j++)
		{
			check=a[j].getCoord();
			if(get<i>(check)<get<i>(min))
			{
				min[i]=check[i];
			}
			if(get<i>(check)>get<i>(max))
			{
				max[i]=check[i];
			}
		}
	}
	result[0].setCoord(min);
	result[1].setCoord(max);
	return result;
}
template <class P1, class P2>
bool checkIntersection(P1 a,P2 const& p)
{
	P2 const& coord = a.getCoord();
	P2 const& Cmin=a[0].getCoord();
	P2 const& Cmax=a[1].getCoord();
	int dim=a.getDim();
	for (int i = 0; i < dim; i++)
	{
			if((a[i]<Cmin[i]) || (a[i]>Cmax[i]))
				return true;
	}
	return false;
}
template <class P1, class P2>
bool checkInterval(P1 a,P2 const& p)
{
	if(checkIntersection(a[0],p))
		return true;
	else if(checkIntersection(a[1],p))
		return true;
	else if(checkIntersection(p[0],a))
		return true;
	else if(checkIntersection(p[1],a))
		return true;
	return false;
}
template <class P1,class P2>
P1* isCloser(const P2& lhs,const P2& rhs)
{
	P2 P;
	return distance3(P,lhs)<distance3(P,rhs);
}

template <class P2,class P1>
void DistanceSort(vector <P1> &p)
{
	P2 P;
	sort(begin(p),end(p),isCloser);
}

template <class P1,class P2>
P1* isSmaller(P1 const& a,P1 const& b)
{
	P2 P;
	b=a[0];
	for (int i=0;i<P.getDim();i++)
	{
		for (int j=0;j<4;j++)
		{
			b=a[j];
			if(get<i>(a) > get<i>(b))
			{
				return a;
			}
			if(get<i>(a) > get<i>(b))
			{
				return b;
			}
		}
	}
}
template <class P1, class P2>
void LexicSort(P1 const& a,vector <P1> &p)
{
	sort(p.begin(),p.end(),isSmaller);
}

