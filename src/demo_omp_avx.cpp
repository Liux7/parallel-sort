#include <stdio.h>
#include <omp.h>
#include <immintrin.h>

int main()
{
    double c[4] = {0,0,0,0},b[4]={1,1,1,1},a[4]={2,2,2,2};
    __m256d c0 = _mm256_load_pd(c), a0 = _mm256_load_pd(a), b0 = _mm256_load_pd(b); 

    for(int i = 0; i < 10000; i++)
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            c0 = _mm256_add_pd(a0, b0);
        }
        #pragma omp section
        {
            c0 = _mm256_add_pd(a0, b0);
        }
    }
    _mm256_store_pd(c, c0);

    for(int i = 0; i < 4; i++)
    {
        printf("%lf ", c[i]);
    }
    
}
