

CXX     = g++
CFLAGS  = -v  -fPIC  -Wall -Wshadow -Wunused -Wunused-value -Wextra  -Waddress -Wno-implicit-fallthrough 
LDFLAGS =
INCLUDE = 
LIBS    =
HEADERS = my_string.hh
OBJS    = my_string.o test_my_string.o
TARGET  = test_my_string
CLEAN   = *.o

.PHONY: all clean

all:  run

%.o : %.cpp $(HEADERS)
	$(CXX) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) $(FLAGS) $(LIBS) -o $@


run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(CLEAN) $(TARGET)