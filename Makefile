inc = -I./inc
flag = -mavx -o3
avxbs:
	g++ $(inc) $(flag) AVX_bitonicSort.cpp -o avxbs
cbs:
	g++ C_bitonicSort.cpp -o cbs
crs:
	g++ C_radixSort.cpp -o crs
test:
	g++ $(inc) $(flag) test.cpp -o test
clean:
	rm *.exe