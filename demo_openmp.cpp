#include <iostream>
#include <omp.h>   // NEW ADD

using namespace std;

int main()
{

        #pragma omp parallel for num_threads(16) // NEW ADD
        for(int i=0; i<10; i++)
        {
        cout << i << " ";
        cout << omp_get_num_threads() <<endl;
        }
        return 0;
}