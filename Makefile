inc = -I./inc
bin = ./bin
src = ./src
avxflag = -mavx2 
ompflag = -fopenmp

avxbs:
	g++ $(inc) $(avxflag) $(src)/AVX_bitonicSort.cpp -o $(bin)/avxbs
cbs:
	g++ $(src)/C_bitonicSort.cpp -o $(bin)/cbs
crs:
	g++ $(src)/C_radixSort.cpp -o $(bin)/crs
test:
	g++ $(inc) $(avxflag) $(src)/test.cpp -o $(bin)/test
omptest:
	g++ $(inc) $(avxflag) $(ompflag) $(src)/test.cpp -o $(bin)/omptest

avxtest:
	g++ $(avxflag) $(src)/avx.c -o $(bin)/test


clean:
	rm *.exe