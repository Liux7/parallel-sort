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



void thread2_bitonic_sort(float* array, int size)
{
    int left = 0, right = size - 1;

    
    int middle = left + (right - left) / 2;   
    


    #pragma omp parallel sections
    {
    #pragma omp section
    {
        // simd_small_sort(array, size/2);
        // std::sort(array, array + middle + 1);
        bitonicSort(array, size/2);
    }
    #pragma omp section
    {
        // simd_small_sort(array+size/2, size/2);
        bitonicSort(array + size/2, size/2);
        // std::sort(array + middle + 1, array + size);
    }
    
    }

    merge_arrays(array, left, middle, right);
    
}

void thread4_bitonic_sort(float* array, int size)
{
    int left = 0, right = size - 1;
    int blocksize = size / 4;

    #pragma omp parallel sections
    {
        
    #pragma omp section
    {
        // simd_small_sort(array, size/2);
        // std::sort(array, array + middle + 1);
        bitonicSort(array, blocksize); // [left, middle]
    }
    #pragma omp section
    {
        // simd_small_sort(array+size/2, size/2);
        bitonicSort(array + blocksize, blocksize);
        // std::sort(array + middle + 1, array + size);
    }
    #pragma omp section
    {
        // simd_small_sort(array, size/2);
        // std::sort(array, array + middle + 1);
        bitonicSort(array + 2*blocksize, blocksize);
    }
    #pragma omp section
    {
        // simd_small_sort(array+size/2, size/2);
        bitonicSort(array + 3*blocksize, blocksize);
        // std::sort(array + middle + 1, array + size);
    }
    
    }


    #pragma omp parallel sections
    {
        #pragma omp section
        merge_arrays(array, left, blocksize-1, 2*blocksize-1);

        #pragma omp  section
        merge_arrays(array, 2*blocksize,  3*blocksize - 1, right);
    }

    merge_arrays(array, left, 2*blocksize - 1, right);
    
}

void thread8_bitonic_sort(float* array, int size)
{
    int left = 0, right = size - 1;
    int blocksize = size / 8;

    #pragma omp parallel sections
    {
        
    #pragma omp section
    {
        // simd_small_sort(array, size/2);
        // std::sort(array, array + middle + 1);
        bitonicSort(array , blocksize); // [left, middle]
    }
    #pragma omp section
    {
        // simd_small_sort(array+size/2, size/2);
        bitonicSort(array + blocksize, blocksize);
        // std::sort(array + middle + 1, array + size);
    }
    #pragma omp section
    {
        // simd_small_sort(array, size/2);
        // std::sort(array, array + middle + 1);
        bitonicSort(array + 2*blocksize, blocksize);
    }
    #pragma omp section
    {
        // simd_small_sort(array+size/2, size/2);
        bitonicSort(array + 3*blocksize, blocksize);
        // std::sort(array + middle + 1, array + size);
    }
    #pragma omp section
    {
        // simd_small_sort(array, size/2);
        // std::sort(array, array + middle + 1);
        bitonicSort(array + 4*blocksize, blocksize);
    }
    #pragma omp section
    {
        // simd_small_sort(array+size/2, size/2);
        bitonicSort(array + 5*blocksize, blocksize);
        // std::sort(array + middle + 1, array + size);
    }
    #pragma omp section
    {
        // simd_small_sort(array, size/2);
        // std::sort(array, array + middle + 1);
        bitonicSort(array + 6*blocksize, blocksize);
    }
    #pragma omp section
    {
        // simd_small_sort(array+size/2, size/2);
        bitonicSort(array + 7*blocksize, blocksize);
        // std::sort(array + middle + 1, array + size);
    }
    
    }

    #pragma omp parallel sections
    {
        #pragma omp  section
        merge_arrays(array, left, blocksize-1, 2*blocksize-1);

        #pragma omp  section
        merge_arrays(array, 2*blocksize,  3*blocksize - 1, 4*blocksize-1);
    }

    merge_arrays(array, left, 2*blocksize - 1, 4*blocksize-1);

    #pragma omp parallel sections
    {
        #pragma omp  section
        merge_arrays(array, 4*blocksize, 5*blocksize-1, 6*blocksize-1);

        #pragma omp  section
        merge_arrays(array, 6*blocksize,  7*blocksize - 1, right);

    }
    merge_arrays(array, 4*blocksize, 6*blocksize-1, right);

    merge_arrays(array, left, 4*blocksize-1, right);

    
}