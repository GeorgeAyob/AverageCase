// George Ayob Lab 2
#include <iostream>
#include <iomanip>
#include <limits.h>

using namespace std;

int Find(int x, int A[], int n) // array of size n
{
    int j;
    for (j = 0; j < n; j++)
    {
        if (x == A[j]) {
            return (j + 1); //the position is 1 more than the index
        }
    }
    return 0; // x is not an element of the array
}

void findAvg(int bound, int num)
{
    int n = 50;
    int sequence[n] ;
    float hits=0.0, totalSteps=0;
    
    for(int i=0; i<100000; i++)
    {
        for(int j=0; j<n; j++)
            sequence[j]= rand() % bound;
        
        if(Find(num, sequence, n))
        {
            hits++;
            totalSteps+=Find(num, sequence, n);
        }
        
        else
            totalSteps+=50;
    }
    
    float q = hits/100000;
    float calcAverage= n + (q/2) - (q*n)/2;
    float realAverage=totalSteps/100000;
    
    cout<<bound<<"\t\t\t"<<calcAverage<<"\t\t\t"<<realAverage<<endl;
}


int main()
{
    cout<<"Bound\t"<< "Calculated Average\t" << "Real Average"<<endl;
    cout<<"-----------------------------------------"<<endl;
    findAvg(30, 15);
    findAvg(50, 10);
    findAvg(80, 5);
    findAvg(100, 20);
    findAvg(1000, 25);
    findAvg(10000, 30);
    findAvg(INT_MAX, 35);
}

/*
 Bound    Calculated Average    Real Average
 -----------------------------------------
 30            30.0153            24.5005
 50            34.467            31.7874
 80            38.6002            37.3157
 100            40.5136            39.7955
 1000            48.8019            48.8008
 10000            49.8677            49.8556
 2147483647            50            50
 Program ended with exit code: 0
 */
