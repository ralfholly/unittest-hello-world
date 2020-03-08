TARGET:=hello_world

.PHONY: all clean

all: $(TARGET)
	./$^

hello_world.o: hello_world.c hello_world.h

$(TARGET): main.o hello_world.o

clean:
	rm -rf *.o $(TARGET) *.gch
