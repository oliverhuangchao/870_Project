main_filename = main
exe_filename = test
run:
	clang++ -c -Wall -g $(main_filename).cpp
	clang++ -o $(exe_filename) $(main_filename).o
clean:
	rm -f *.o
	rm -f $(exe_filename)
