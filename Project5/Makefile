TARGET = proj5
CXX = g++ 
CXX_FLAGS = -Wall -std=c++98

all: $(TARGET)

$(TARGET): $(TARGET).h $(TARGET).cpp Vehicle.h Car.h Vehicle.cpp Car.cpp
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp Vehicle.cpp Car.cpp -o $(TARGET)

clean:
	-rm -f $(TARGET)

fmt:
	clang-format -i *.h *.cpp
