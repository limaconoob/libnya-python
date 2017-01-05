NAME := "nya"
LIB := "libss.so"

.SILENT: all
.PHONY: default all

default: all

all:
	gcc -shared -o $(LIB) -fPIC -I/System/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7 -L/Users/jpepin/Library/Python/2.7/lib -lpython2.7 libss.c 

clean:
	rm $(LIB)

re: clean all
