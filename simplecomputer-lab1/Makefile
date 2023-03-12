LIB_NAME = mySimpleComputer
APP_NAME = binary
CFLAGS = -Wall -I ./lib
LDLIBS = -L ./lib -lmySimpleComputer

.PHONY: all clean

.PATH: project

all: binary

binary: lib$(LIB_NAME).a
	gcc $(CFLAGS) -o project/$(APP_NAME) project/main.c $(LDLIBS) 
	make -C dir clean

lib$(LIB_NAME).a: $(LIB_NAME).o
	ar cr ./lib/lib$(LIB_NAME).a ./lib/$(LIB_NAME).o

$(LIB_NAME).o:
	gcc $(CFLAGS) -c ./lib/$(LIB_NAME).c -o ./lib/$(LIB_NAME).o

run:
	./project/$(APP_NAME);

clean:
	rm -rf ./lib/*.o ./lib/*.a
	rm -rf ./project/*.o ./project/$(APP_NAME)
