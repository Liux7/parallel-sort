#define __SIMD_BITONIC_IMPLEMENTATION__
#include "simd_bitonic.h"

#define SOKOL_IMPL
#include "sokol_time.h"

#include "C_bitonicSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "random.h"
int seed = 0x12345678;

#define NUMBER_OF_SORTS (100000)
#define MAX_ARRAY_SIZE (SIMD_VECTOR_WIDTH * 32)
void initArray(float* array, int array_size)
{
    for(int j=0; j<array_size; ++j)
    {
        array[j] = (iq_random_float(&seed) - 0.5f) * 10000.f;
         
    }
}

bool verify(float* array, int size)
{
    for (int i = 1; i < size; i++)
    {
        if(array[i-1] > array[i]) return false;
    }
    return true;
    
}


int main(int argc, char** argv)
{
    int array_size = atoi(argv[1]);
    if(array_size == 0) 
    {
        printf("test.exe array_size\n");
        return 0;
    }
    stm_setup();
    float* array = (float*)malloc(sizeof(float) * array_size);

    uint64_t start_time, diff = 0;


    for (int i = 0; i < NUMBER_OF_SORTS; i++)
    {
        for(int j=0; j<array_size; ++j)
            array[j] = iq_random_float(&seed);
        start_time = stm_now();
        std::sort(array, array + array_size);
        diff += stm_diff(stm_now(), start_time);    
    }
    float stl_duration = (float)stm_sec(diff);
    
    
    diff = 0;
    seed = 0x12345678;
    for (int i = 0; i < NUMBER_OF_SORTS; i++)
    {
        for(int j=0; j<array_size; ++j)
            array[j] = iq_random_float(&seed);
        start_time = stm_now();
        simd_merge_sort(array, array_size);
        // simd_small_sort(array, array_size);
        diff += stm_diff(stm_now(), start_time);    
    }
    float simd_duration = (float)stm_sec(diff); 

    
    
    diff = 0;
    seed = 0x12345678;
    for (int i = 0; i < NUMBER_OF_SORTS; i++)
    {
        for(int j=0; j<array_size; ++j)
            array[j] = iq_random_float(&seed);
        start_time = stm_now();
        bitonicSort(array, array_size, true);
        // simd_small_sort(array, array_size);
        diff += stm_diff(stm_now(), start_time);    
    }
    float bitonic_duration = (float)stm_sec(diff); 
    
    
    
    printf("%f ",bitonic_duration/stl_duration);
    printf("%f ",bitonic_duration/simd_duration);
    printf("%f ",bitonic_duration/bitonic_duration);
    

    if(!verify(array, array_size)) printf("fail\n");
    




    free(array);

    return 0;
}