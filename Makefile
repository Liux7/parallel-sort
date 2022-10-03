avx:
	g++ -I./inc -mavx -o3 AVX_bitonicSort.cpp -o avxbs
c:
	g++ C_bitonicSort.cpp -o cbs