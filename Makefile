inc = -I./inc
avxflag = -mavx -o3
ompflag = -fopenmp
avxbs:
	g++ $(inc) $(avxflag) AVX_bitonicSort.cpp -o avxbs
cbs:
	g++ C_bitonicSort.cpp -o cbs
crs:
	g++ C_radixSort.cpp -o crs
test:
	g++ $(inc) $(avxflag) test.cpp -o test
omptest:
	g++ $(inc) $(avxflag) $(ompflag) test.cpp -o omptest
clean:
	rm *.exe