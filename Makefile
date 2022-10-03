avxbs:
	g++ -I./inc -mavx -o3 AVX_bitonicSort.cpp -o avxbs
cbs:
	g++ C_bitonicSort.cpp -o cbs
crs:
	g++ C_radixSort.cpp -o crs
	