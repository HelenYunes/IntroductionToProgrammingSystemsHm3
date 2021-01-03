
all: isort txtfind

isort: isort.c
	gcc -Wall -o isort isort.c

txtfind: txtfind.c
	gcc -Wall -o txtfind txtfind.c

.PHONY: clean all

clean:
	rm  -f txtfind isort