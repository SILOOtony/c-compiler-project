exec = c+
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -Wall -lm -ldl -fPIC -rdynamic


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c includes/%.h
	gcc -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o

lint:
	clang-tidy src/*.c src/includes/*.h
