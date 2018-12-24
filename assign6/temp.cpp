#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
template <typename T>
class point
{
	private:
	int space;
	T * coord;
	public:
	float distance;
	point()
	{
		space =0;
	}
	point(int n)
	{
		space=n;
		coord= new T[n];
		for (int i = 0; i < n; ++i)
		{
			coord[i]=0;
		}
	}
	int getDim()
	{
		return space;
	}
	T * getCoord()
	{
		return coord;
	}
	void setCoord(T * value)
	{
		for (int i = 0; i < space; ++i)
		{
			coord[i]=value[i];
		}
	}
	void print_coord()
	{
		for (int i = 0; i < space; ++i)
		{
			cout<<coord[i]<<" ";
		}
		cout<<endl;
	}
};
/*namespace traits
{
    template <class P,int D>
    struct access {};
}
namespace traits
{
    template <class T>
    struct access<T, 0>
    {
        static double get(T p)
        {
            return p.x;
        }
    };
    template <class T>
    struct access<T, 1>
    {
        static double get(T p)
        {
            return p.y;
        }
    };
	template <class T>
    struct access<T, 2>
    {
        static double get(T p)
        {
            return p.z;
        }
    };
    template <class T>
    struct access<T, 3>
    {
        static double get(T p)
        {
            return p.t;
        }
    };
}
template <int D, class P>
inline double get(P p)
{
    return traits::access<P, D>::get(p);
}
template <class P1, class P2, int D>
double apply(P1 *a, P2 *b)
{
	int d = get<D-1>(a) - get<D-1>(b);
	return d * d + apply(a, b);
}
template <class P1, class P2>
double distance3(P1 *a, P2 *b,int D)
{
    return sqrt(apply(a, b));
}*/
template <class P, class P1>
float distance4(P a,P b,P1 c)
{
	if(a.getDim()!=b.getDim())
		return 0;
	else
	{
		float result;
		P1 * coordA= a.getCoord();
		P1 * coordB= b.getCoord();
		for (int i = 0; i < a.getDim(); ++i)
		{
			result= result+ (pow((coordA[i]-coordB[i]),2));
		}
		return sqrt(result);
	}
}
template <class P>
P getClosest(P a,vector <P> p)
{
	float min= FindDistance(a,p[0],*(a.getCoord()));
	int j=0;
	for (int i = 1; i < p.size(); ++i)
	{
		if(min>FindDistance(a,p[i],*(a.getCoord())))
			j=i;
		/* code */
	}
	return p[j];
}

template <class T, class T1>
T * getInterval(vector<T> p,T1 a)
{
	T * result=new T[2];
	result[0]=p[0];
	result[1]=p[0];
	T1 * Rmin=p[0].getCoord();
	T1 * Rmax=p[0].getCoord();
	T1* check;
	int dim= p[0].getDim();
	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < p.size(); ++j)
		{
			check= p[j].getCoord();
			if(check[i]<Rmin[i])
				Rmin[i]=check[i];
			if(check[i]>Rmax[i])
				Rmax[i]=check[i];
		}
	}
	result[0].setCoord(Rmin);
	result[1].setCoord(Rmax);
	return result;
}

template <class T, class T1>
bool checkIntersection(T a,T * p,T1 b)
{
	T1 * coords=a.getCoord();
	T1 * Cmin=p[0].getCoord();
	T1 * Cmax=p[1].getCoord();
	int dim = a.getDim();
	for (int i = 0; i < dim; ++i)
	{
		if(coords[i]<Cmin[i] || coords[i]>Cmax[i])
			return true;
	}
	return false;
}

template <class T>
bool checkIntervalIntersection(T * a,T* p)
{
	if(checkIntersection(a[0],p,*(a[0].getCoord())))
		return true;
	else if(checkIntersection(a[1],p,*(a[0].getCoord())))
		return true;
	else if(checkIntersection(p[0],a,*(a[0].getCoord())))
		return true;
	else if(checkIntersection(p[1],a,*(a[0].getCoord())))
		return true;
	return false;
}
template <class T>
bool isCloser(T b,T c)
{
	return (b.distance < c.distance);
}

template <class T>
void DistanceSort(T a,vector<T> &p)
{
	for (int i = 0; i < p.size(); ++i)
	{
		p[i].distance=FindDistance(a,p[i],*(p[i].getCoord()));
		/* code */
	}
	std::sort(p.begin(),p.end(),isCloser);
}

template <class T>
bool isSmaller(T a, T b)
{
	float* acoord=(float *)a.getCoord();
	float* bcoord=(float *)b.getCoord();
	int size=a.getDim();
	for (int i = 0; i < size; ++i)
	{
		if(acoord[i]<bcoord[i])
			return true;
		else if(acoord[i]>bcoord[i])
			return false;
	}
}

template <class T>
void LexiSort(vector<T>&p)
{
	std::sort(p.begin(),p.end(),isSmaller);
}