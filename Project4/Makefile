TARGET = proj4
CXX = g++ 
CXX_FLAGS = -Wall -std=c++98

all: $(TARGET)

$(TARGET): $(TARGET).h $(TARGET).cpp Sensor.h Sensor.cpp Car.h Car.cpp Agency.h Agency.cpp
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp Sensor.cpp Car.cpp Agency.cpp -o $(TARGET)

clean:
	-rm -f *.o
	-rm -f $(TARGET)

fmt:
	clang-format -i *.h *.cpp
