#include <stdio.h>
#include <stdlib.h>

const int RADIX = 10, KEYNUM = 8;

int seed = 1;

inline int GetDigitInPos(int num,int pos)  
{  
    int temp = 1;  
    for (int i = 0; i < pos - 1; i++)  
        temp *= 10;  
    return (num / temp) % 10;  
}

inline void RadixSort(int* unorderArray, int dataNum)  
{  
    int *radixArrays[RADIX]; 
    for (int i=0; i<10; i++) 
    {  
        radixArrays[i] = (int *)malloc(sizeof(int)*(dataNum + 1));  
        radixArrays[i][0] = 0;
    }  
    for (int pos=1; pos<=KEYNUM; pos++) 
    {   
        for (int i=0; i<dataNum; i++)   
        {  
            int num = GetDigitInPos(unorderArray[i],pos);  
            int index = ++radixArrays[num][0];  
            radixArrays[num][index] = unorderArray[i];  
        }  
        for (int i=0, j=0; i<RADIX; i++)
        {  
            for (int k = 1; k <= radixArrays[i][0]; k++)  
                unorderArray[j++] = radixArrays[i][k];  
            radixArrays[i][0] = 0;  
        }  
    }  
} 


int main()
{
    int n = 100;
    srand(seed);
    int *array = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }
    RadixSort(array, n);

    int flag = 0;
    for(int i = 1; i < n; i++)
    {
        if(array[i-1] > array[i]) 
        {
            flag  = 1;
            break;
        }
    }
    if(flag) printf("fail\n");
    else printf("success\n");
    
}