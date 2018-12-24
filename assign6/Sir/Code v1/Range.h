#ifndef RANGE_H
#define RANGE_H

#include "Point.h"

template <class T = double>
class Range
{
public:
	Range(int d) : minP(d), maxP(d) {}
	~Range() {
	}

	bool intersects(T val, int dim) const  // checks if a given value intersects the range interval in a given dimension
	{
		return (val >= minP.getCoords()[dim]) && (val <= maxP.getCoords()[dim]);
	}

	bool intersects(const Point<T>& pt) const     // checks if a point intersects (is contained in) this range
	{
		bool hits = true;
		T* coords = pt.getCoords();
		int dim = minP.dimension();

		for (int i = 0; hits && (i < dim); i++){
			hits &= intersects(coords[i], i);
		}
		return hits;
	}


	bool intersects(const Range<T>& r2) const   // checks if this range intersects another range
	{
		int dim = minP.dimension();
		bool overlaps = true;
		T *minc = r2.minP.getCoords();
		T *maxc = r2.maxP.getCoords();
		for (int i = 0; overlaps && (i < dim); i++){
			overlaps &= (intersects(minc[i], i) || intersects(maxc[i], i)
							|| r2.intersects(minP.getCoords()[i], i) || intersects(maxP.getCoords()[i], i));

		}
		return overlaps;
	}

	static Range<T>& findRange(typename vector<Point<T> *>::iterator start, typename vector<Point<T> *>::iterator end, Range<T>& range) {
		Point<T> *pi = *start;
		int dim = pi->dimension();
		T *mincv = new T[dim];
		T *maxcv = new T[dim];

		for (int i = 0; i < dim; i++){
			mincv[i] = maxcv[i] = pi->getCoords()[i];
		}
		typename vector<Point<T> *>::iterator iter = start + 1;

		while (iter != end) {
			T *coords = (*iter)->getCoords();
			for (int i = 0; i < dim; i++) {
				if (coords[i] < mincv[i])
					mincv[i] = coords[i];
				else if (coords[i] > maxcv[i])
					maxcv[i] = coords[i];
			}
			iter++;
		}

		range.minP.setCoords(mincv);
		range.maxP.setCoords(maxcv);

		delete mincv;
		delete maxcv;

		return range;
	}

	ostream& print(ostream& os)
	{
		os << "Range: " << "Min: ";
		minP.print(os);
		os << "Max: ";
		maxP.print(os);

		return os;
	}

private:
	Point<T> minP;
	Point<T> maxP;
};

#endif
