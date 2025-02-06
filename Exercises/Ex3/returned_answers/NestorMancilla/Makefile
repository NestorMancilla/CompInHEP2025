all:
	g++ -shared -fPIC test_MET.cpp -o libMET.so
	g++ test_MET.cpp -o test_MET -L. -lMET

clean:
	rm -f libMET.so test_MET

