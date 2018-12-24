#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T = double>
class Point
{
public:
	Point(int d) : dim(d) {
		coords = new T[dim];
	}

	~Point(){
		delete coords;
	}

	T *getCoords() const {
		return coords;
	}

	int dimension() const {
		return dim;
	}

	void setCoords(const T *cvals) {
		for (int i = 0; i < dim;i++)
		coords[i] = cvals[i];
	}

	double distSqrd(const Point<T>& p2) const {
		T *diff = new T[dim];
		for (int i = 0; i < dim; i++)
			diff[i] = coords[i] - p2.coords[i];
		double distSq = inner_product(diff, diff + dim, diff, 0.0);
		delete diff;
		return distSq;
	}

	double dist(const Point<T>& p2) const {
		return sqrt(distSqrd(p2));
	}


	double distOrigin() const {
		return sqrt(inner_product(coords, coords + dim, coords, 0.0));
	}


	// find the point in the given list of points that is closest to this point
	Point<T> *closestPoint(typename vector<Point<T> *>::iterator start, typename vector<Point<T> *>::iterator end) const
	{
	    // since we have to iterate through all the points in the vector to compute the distance, we might as well
	    // keep track of the min dist and therefore the closest point.
		Point<T> *closest = *start;
		double bestDist = distSqrd(*closest);
		start++;
		while (start != end){
			double newds = distSqrd(*(*start));
			if (newds < bestDist) {
				bestDist = newds;
				closest = *start;
			}
			start++;
		}
		return closest;
	}

	ostream& print(ostream& os) const {
		os << "Point: [" << dim << "]: ";
		for (int i = 0; i < dim; i++)
			os << coords[i] << "  ";
		return os;
	}

	static void distSort(typename vector<Point<T> *>::iterator start, typename vector<Point<T> *>::iterator end, const Point<T>& pref) {
		vector<ptDist *> ptds;
		// create a temp vector of (dist, Point *) pairs

		typename vector<Point<T> *>::iterator iter = start;
		while (iter != end) {
			Point<T> *p = *iter;
			ptDist *pd = new ptDist(pref.distSqrd(*p), p);
			ptds.push_back(pd);
			iter++;
		}
  		sort(ptds.begin(), ptds.end(), distCompare);

		// modify the original vector with points in the new order
		typename vector<ptDist *>::iterator piter = ptds.begin();
		iter = start;
		while (iter != end) {
			*iter = (*piter)->pt;
			delete *piter;
			iter++; piter++;
		}
	}

	static void lexSort(typename vector<Point<T> *>::iterator start, typename vector<Point<T> *>::iterator end) {
		sort(start, end, lexCompare);
	}

private:
	const int dim;
	T *coords;

	class ptDist {
	public:
		ptDist(double d, Point<T> *p) : dist(d), pt(p) {}

		const double dist;
		Point<T> *pt;
	};


	static bool distCompare(ptDist *p1, ptDist *p2) {
		return (p1->dist < p2->dist);
	}

	static bool lexCompare(Point<T> *p1, Point<T> *p2) {
		int dim = p1->dim;
		return lexicographical_compare(p1->coords, p1->coords + dim, p2->coords, p2->coords+dim);
	}
};

#endif
