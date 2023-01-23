#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <cstring>


// SMVCGC set SVR 3 clocks
// VMVCCG 2 clocks
// AND 1 clocks
// SLD 7 clocks
// SMOV 1 clocks
// SSHFLL 1 clocks
// VST 4 clocks  VR to AM
// scalar base AR8`AR15 offset OR8~OR15


//33 clocks


VST VR0, *AR0
SMOV control, R63
AND R63, 0b11, OR8
AND R63, 0b1100, OR9
AND R63, 0b110000, OR10
AND R63, 0b11000000, OR11
SSHFLL 2, OR8, OR8
SSHFLL 2, OR9, OR9
SSHFLL 2, OR10, OR10
SSHFLL 2, OR11, OR11
SLD AR0, OR8, R0
SLD AR0, OR9, R1
SLD AR0, OR10, R2
SLD AR0, OR11, R3
ADD OR8, 32
ADD OR9, 32
ADD OR10, 32
ADD OR11, 32
SLD AR0, OR8, R4
SLD AR0, OR9, R5
SLD AR0, OR10, R6
SLD AR0, OR11, R7
SMVCGC R0, SVR0
SMVCGC R1, SVR1
SMVCGC R2, SVR2
SMVCGC R3, SVR3
SMVCGC R4, SVR4
SMVCGC R5, SVR5
SMVCGC R6, SVR6
SMVCGC R7, SVR7
SNOP 2
VMVCCG SVR, VR0
SNOP 1


// 22 clocks

VST VR0, *AR0
SMOV control, R63
AND R63, 0b11, OR8 | AND R63, 0b1100, OR9 | AND R63, 0b110000, OR10 | AND R63, 0b11000000, OR11
SSHFLL 2, OR8, OR8 | SSHFLL 2, OR9, OR9 | SSHFLL 2, OR10, OR10 | SSHFLL 2, OR11, OR11
SLD AR0, OR8, R0 | SLD AR0, OR9, R1 | SLD AR0, OR10, R2
SLD AR0, OR11, R3
ADD OR8, 32 | ADD OR9, 32 | ADD OR10, 32 | ADD OR11, 32
SLD AR0, OR8, R4
SLD AR0, OR9, R5
SLD AR0, OR10, R6
SLD AR0, OR11, R7
SMVCGC R0, SVR0 | SMVCGC R1, SVR1
SMVCGC R2, SVR2
SMVCGC R3, SVR3
SMVCGC R4, SVR4
SMVCGC R5, SVR5
SMVCGC R6, SVR6
SMVCGC R7, SVR7
SNOP 2
VMVCCG SVR, VR0
SNOP 1



// __256m _mm256_permute_ps(__256m src, int control)
// {
//     int idx0 = control & (0b11);
//     int idx1 = control & (0b1100);
//     int idx2 = control & (0b110000);
//     int idx3 = control & (0b11000000);

//     int size = sizeof(float);
//     mov_to_svr0(*( DATATYPE *)(src + size*idx0));
//     mov_to_svr1(*( DATATYPE *)(src + size*idx1));
//     mov_to_svr2(*( DATATYPE *)(src + size*idx2));
//     mov_to_svr3(*( DATATYPE *)(src + size*idx3));

//     idx0 += SIMD_VECTOR_WIDTH/2;
//     idx1 += SIMD_VECTOR_WIDTH/2;
//     idx2 += SIMD_VECTOR_WIDTH/2;
//     idx3 += SIMD_VECTOR_WIDTH/2;

//     mov_to_svr4(*( DATATYPE *)(src + size*idx0));
//     mov_to_svr5(*( DATATYPE *)(src + size*idx1));
//     mov_to_svr6(*( DATATYPE *)(src + size*idx2));
//     mov_to_svr7(*( DATATYPE *)(src + size*idx3));

//     return mov_from_srv_v32sf();

// }  


unsigned long long int begin,end,total=0;	
static inline unsigned long long rdtsc(void)	 
{	 
	unsigned hi, lo; 	
	__asm__ __volatile__ ("rdtsc" : "=a"(lo),"=d"(hi));	 
	return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );	 
} 


int main()
{
    float *src, *dest;
    src = (float*)malloc(sizeof(float) * 8);
    dest = (float*)malloc(sizeof(float) * 8);

    for(int i = 0; i < 8; i++) src[i] =1.0* i;

    __m256 vec = _mm256_loadu_ps(src);

    begin=rdtsc(); 
    // vec = _mm256_permute_ps(vec, 0b00011011);
    _mm256_permute_ps(vec, 0b00011011);
    end=rdtsc();    

    _mm256_storeu_ps(dest, vec);
    for(int i = 0; i < 8; i++) printf("%.1f ", dest[i]);

    total = end - begin;
    printf("%llu\n", total);
}