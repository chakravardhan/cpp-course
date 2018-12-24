
#include <iostream>
using namespace std;

#include "Point.h"
#include "Range.h"


int icoords[] =
{
	0, 3, 5, 73,
	50, 7, 34, 52,
	43, 92, 8, 1,
	4, 5, 6, 90,
	45, 31, 14, 55,
	15, 92, 64, 16,
	11, 44, 22, 72,
	34, 82, 9, 23,
	8, 7, 72, 17,
	82, 11, 7, 11
};

double dcoords[] =
{
	0.0, 3.1, 5.2, 73.1,
	50.1, 7.8, 34.2, 52.1,
	43.4, 92.2, 8.1, 1.7,
	4.0, 5.9, 6.2, 90.4,
	45.1, 31.2, 14.3, 55.4,
	15.7, 92.7, 64.6, 16.5,
	11.1, 44.4, 22.2, 72.2,
	34.4, 82.8, 9.1, 23.5,
	8.3, 7.5, 72.1, 17.9,
	82.1, 11.6, 7.7, 11.9
};


template<class T, int dim>
void testFunc(T* coordsData)
{
	// 1. Create 10 points , using the first 10*n coordinate values from the coords array
		vector<Point<T> *> points;
		for (int i = 0; i < 10; i++) {
			Point<T> *pt = new Point<T>(dim);
			pt->setCoords(coordsData + i*dim);
			points.push_back(pt);
		}

		// 2. Print out the distance of the 0'th point from the origin
		double dist = points[0]->distOrigin();
		cout << "Distance to origin: " << dist << " from " << endl;
		points[0]->print(cout);
		cout << endl;
		cout << endl;

		// 3. Print out the distance between the 4th and 6th points, (first point in the list is point 0)
		dist = points[3]->dist(*points[5]);
		cout << "Distance between points 4 and 6: " << dist << endl;
		cout << "Points: \n";
		points[3]->print(cout);
		cout << endl;
		points[5]->print(cout);
		cout << endl;
		cout << endl;

		// 4. Print the coordinates of the closest point in the first 6 points from the 8th point
		Point<T> *cp = points[7]->closestPoint(points.begin(), points.begin() + 6);
		cout << "Closest Point to 8th point:\n";
		cp->print(cout);
		cout << endl;
		cout << endl;

		// 5. For each of the points from 6 to 8, print out if this point intersects the bounding interval of the first 5 points
		Range<T> r1(dim);
		Range<T>::findRange(points.begin(), points.begin() + 5, r1);
		for (int i = 5; i < 8; i++){
			cout << "Point " << i << " ";
			if (r1.intersects(*points[i]))
				cout << "intersects\n";
			else
				cout << "does not intersect \n";
		}
		r1.print(cout);
		cout << endl;
		cout << endl;

		// 6. Check if the bounding interval of the first 5 points intersects the bounding interval of the last 5 points
		Range<T> r2(dim);
		Range<T>::findRange(points.begin() + 5, points.begin() + 10, r2);
		bool boom = r1.intersects(r2);
		if (boom)
			cout << "Ranges intersect" << endl;
		else
			cout << "Ranges do not intersect" << endl;
		cout << endl;

		// 7. Print out the coordinates of the first 6 points in order of increasing distance from the 9th point
		Point<T>::distSort(points.begin(), points.begin() + 6, *points[8]);
		cout << "Points sorted based on distance from 9th point\n";
		for (int i = 0; i < 6; i++) {
			points[i]->print(cout);
			cout << endl;
		}
		cout << endl;

		// 8. Print out the coordinates of the first 7 points in lexicographic order
		Point<T>::lexSort(points.begin(), points.begin() + 7);
		cout << "Points sorted based on lex order\n";
		for (int i = 0; i < 7; i++) {
			points[i]->print(cout);
			cout << endl;
		}
		cout << endl;
		cout << endl;

   	for (int i = 0; i < 10; i++) {
   	    delete points[i];
   	}
}

int main(int argc, char* argv[])
{
	// Run the sequence of tests for each dimension n = 1, 2, 3, 4 with double coords space

    testFunc<double, 1>(dcoords);
    testFunc<double, 2>(dcoords);
    testFunc<double, 3>(dcoords);
    testFunc<double, 4>(dcoords);

	// repeat for int space, dim = 2
	testFunc<int, 2>(icoords);
}

