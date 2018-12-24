#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "distance.cpp"
using namespace std;
template <typename T>
class mypoint
{
	private:
		int Dim;
		T * coordinate;
	public:
		float dist;
		mypoint()
		{
			Dim =0;
		}
		mypoint(int n)
		{
			Dim=n;
			coordinate= new T[n];
			for (int i = 0; i < n; ++i)
			{
				coordinate[i]=0;
			}
		}
		int dim()
		{
			return Dim;
		}
		T * getcoordinate()
		{
			return coordinate;
		}
		static bool DistanceComp(mypoint <T> a,mypoint <T> b)
		{
			return (a.dist < b.dist);
		}
		static void DistanceSort(mypoint <T> a,vector<mypoint <T> >&p)
		{
			for (int i = 0; i < p.size(); ++i)
			{
				p[i].dist=distance4(a,p[i],*(p[i].getcoordinate()));
			}
			sort(p.begin(),p.end(),DistanceComp);
		}
		static bool LexicComp(mypoint <T> a,mypoint <T> b)
		{
			float* acoord=(float *)a.getcoordinate();
			float* bcoord=(float *)b.getcoordinate();
			int size=a.dim();
			for (int i = 0; i < size; ++i)
			{
				if(acoord[i]<bcoord[i])
					return true;
				else if(acoord[i]>bcoord[i])
					return false;
			}
			return false;
		}
		static void LexicSort(vector<mypoint <T> >&p)
		{
			sort(p.begin(),p.end(),LexicComp);
		}
		void setcoordinate(T * value)
		{
			for (int i = 0; i < Dim; ++i)
			{
				coordinate[i]=value[i];
			}
		}
		void print_coordinate()
		{
			for (int i = 0; i < Dim; ++i)
			{
				cout<<coordinate[i];
			}
			cout<<endl;
		}
		
};
