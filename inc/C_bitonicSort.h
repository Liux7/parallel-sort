#include<iostream>
using namespace std;
void bitonicMerge(float* a, int n, bool direction)
{
    if(n > 1)
    {
    for(int i = 0; i < n/2; i++)
    {
        if(direction == (a[i] > a[i + n/2]) )
        {
            swap(a[i], a[i+n/2]);
        }
    }

    bitonicMerge(a, n/2, direction);
    bitonicMerge(a+n/2, n/2, direction);
    }
}



void bitonicSort(float* a, int n, bool direction = true)
{
    if(n > 1)
    {
    bitonicSort(a, n/2, direction);
    bitonicSort(a + n/2, n/2, !direction);
    bitonicMerge(a, n, direction);
    }
}
