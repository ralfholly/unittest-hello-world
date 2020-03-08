TARGET:=test_hello_world
CPPFLAGS:= -I ..

.PHONY: test clean

test: $(TARGET)
	./$^

#
# This is the SUT.
#
hello_world.o: ../hello_world.c ../hello_world.h
	$(CC) -Dprintf=mock_printf -c $^

$(TARGET).o: $(TARGET).c

$(TARGET):	$(TARGET).o hello_world.o

clean:
	rm -rf *.o $(TARGET) core
