#include<iostream>
using namespace std;
void bitonicMerge(int* a, int n, bool direction)
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


void bitonicSort(int* a, int n, bool direction)
{
    if(n > 1)
    {
    bitonicSort(a, n/2, direction);
    bitonicSort(a + n/2, n/2, !direction);
    bitonicMerge(a, n, direction);
    }
}

int main()
{
    int n = 16;
    int a[16] = {10, 20, 9, 5, 3, 8, 12, 14, 90, 0, 60, 40, 23, 35, 95, 18};
    
    bitonicSort(a, n, true);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] <<" ";
    }
    

}