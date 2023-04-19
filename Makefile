CFLAGS = -O3 -std=c++11 -Wall 


run: clean proj.out
	./proj.out

proj.out:
	g++ $(CFLAGS) *.cpp -lm -o proj.out

test1: clean proj.out
	./proj.out < test1.txt

test2: clean proj.out
	./proj.out < test2.txt

clean:
	rm -f *.out
