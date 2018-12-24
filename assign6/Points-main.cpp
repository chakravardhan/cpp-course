#include <iostream>
#include <vector>
#include <fstream>
#include "temp.cpp"
using namespace std;
int main()
{

    int icoords[] ={0,3,5, 73,50, 7, 34, 52,43, 92, 8, 1,4, 5, 6, 90,45, 31, 14, 55,15, 92, 64, 16,11, 44, 22, 72,34, 82, 9, 23,8, 7, 72, 17,82, 11, 7, 11};
    float dcoords[] ={0.0, 3.1, 5.2, 73.1,50.1, 7.8, 34.2, 52.1,43.4, 92.2, 8.1, 1.7,4.0, 5.9, 6.2, 90.4,45.1, 31.2, 14.3, 55.4,15.7, 92.7, 64.6, 16.5,11.1, 44.4, 22.2, 72.2,34.4, 82.8, 9.1, 23.5,8.3, 7.5, 72.1, 17.9,82.1, 11.6, 7.7, 11.9};
    cout<<"Doing for Integer Space"<<endl;
    vector <point <int> > ipoint;
    for (int i = 1; i < 5; ++i)
    {
        for(int j=0;j<10;j++)
        {
            int * temp1= new int[i];
            for(int k=0;k<i;k++)
            {
                 temp1[k]=icoords[(j*i)+k];
            }
            ipoint.push_back(point<int> (i));
            ipoint[j].setCoord(temp1);
        }
        int * temp1= new int[i];
        for(int k=0;k<i;k++)
        {
             temp1[k]=0;
        }
        point <int> origin (i);
        origin.setCoord(temp1);
        cout<<FindDistance(ipoint[0],origin,1)<<endl;
        cout<<FindDistance(ipoint[3],ipoint[5],1)<<endl;

        vector <point <int> > test(ipoint.begin(),ipoint.begin()+6);
        (getClosest(ipoint[7],test)).print_coord();

        point <int> * temp4 = getInterval(vector <point <int> > (ipoint.begin(),ipoint.begin()+5),1);
        if(checkIntersection(ipoint[5],temp4,1))
            cout<<"6 th point has intersection"<<endl;
        if(checkIntersection(ipoint[6],temp4,1))
            cout<<"7 th point has intersection"<<endl;
        if(checkIntersection(ipoint[7],temp4,1))
            cout<<"8 th point has intersection"<<endl;

        point <int> * temp5= getInterval(vector <point <int> > (ipoint.begin(),ipoint.begin()+5),1);
        point <int> * temp6= getInterval(vector <point <int> > (ipoint.begin()+6,ipoint.end()),1);
        if(checkIntervalIntersection(temp5,temp6))
            cout<<"Yes there is an intersection"<<endl;

        cout<<"printing using distanceSort"<<endl;
        vector <point <int> > test1 (ipoint.begin(),ipoint.begin()+6);
        /*DistanceSort(ipoint[8],test1);
        for (int k = 0; k < 6; ++k)
        {
            test1[k].print_coord();
        }*/
        cout<<"printing using Lexisort"<<endl;
        vector <point <int> > test2 (ipoint.begin(),ipoint.begin()+7);
        /*LexiSort(test2);
        for (int k = 0; k < 6; ++k)
        {
            test2[k].print_coord();
        }*/
        cout<<endl;
        cout<<endl;
        delete temp1;
        ipoint.erase(ipoint.begin(),ipoint.end());
    }
    cout<<"Doing for Float space"<<endl;
    vector <point <float> > dpoint;
    for (int i = 1; i < 5; ++i)
    {
        for(int j=0;j<10;j++)
        {
            float * temp1= new float[i];
            for(int k=0;k<i;k++)
            {
                 temp1[k]=dcoords[(j*i)+k];
            }
            dpoint.push_back(point<float> (i));
            dpoint[j].setCoord(temp1);
        }
        float * temp1= new float[i];
        for(int k=0;k<i;k++)
        {
             temp1[k]=0;
        }
        point <float> origin (i);
        origin.setCoord(temp1);
        cout<<FindDistance(dpoint[0],origin,(float)0.0)<<endl;
        cout<<FindDistance(dpoint[3],dpoint[5],(float)0.0)<<endl;
        vector <point <float> > test(dpoint.begin(),dpoint.begin()+6);
        (getClosest(dpoint[7],test)).print_coord();

        point <float> * temp4=getInterval(vector <point <float> > (dpoint.begin(),dpoint.begin()+5),(float)1.1);
        if(checkIntersection(dpoint[5],temp4,(float)1.1))
            cout<<"6 th point has intersection"<<endl;
        if(checkIntersection(dpoint[6],temp4,(float)1.1))
            cout<<"7 th point has intersection"<<endl;
        if(checkIntersection(dpoint[7],temp4,(float)1.1))
            cout<<"8 th point has intersection"<<endl;

        point <float> * temp5= getInterval(vector <point <float> > (dpoint.begin(),dpoint.begin()+5),(float)1.1);
        point <float> * temp6= getInterval(vector <point <float> > (dpoint.begin()+6,dpoint.end()),(float)1.1);
        if(checkIntervalIntersection(temp5,temp6))
            cout<<"Yes there is an intersection"<<endl;

        cout<<"printing using distanceSort"<<endl;
        vector <point <float> > test1 (dpoint.begin(),dpoint.begin()+6);
        /*DistanceSort(dpoint[8],test1);
        for (int k = 0; k < 6; ++k)
        {
            test1[k].print_coord();
        }*/

        cout<<"printing using Lexisort"<<endl;
        vector <point <float> > test2 (dpoint.begin(),dpoint.begin()+7);
        //LexiSort(test2);
        //for (int k = 0; k < 6; ++k)
        //{
            //test2[k].print_coord();
            /* code */
        //}
        cout<<endl;
        cout<<endl;
        delete temp1;
        dpoint.erase(dpoint.begin(),dpoint.end());
    }

}