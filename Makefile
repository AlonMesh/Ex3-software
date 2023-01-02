all: isort txtfind

##try:  isort.o
##	gcc isort.o -o -lm
# This method/command runs a compiled file (spesificly main)
txtfind: txtfind.o
	gcc -Wall txtfind.o -o txtfind -lm

isort: isort.o
	gcc -Wall isort.o -o isort -lm

clean:
	rm -f isort txtfind try *.o