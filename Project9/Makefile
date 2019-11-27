TARGET = proj9
CXX = g++ 
CXX_FLAGS = -Wall -std=c++98

all: $(TARGET)

$(TARGET): $(TARGET).cpp DataType.h DataType.cpp ArrayQueue.h ArrayQueue.cpp NodeQueue.h NodeQueue.cpp
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp DataType.cpp ArrayQueue.cpp NodeQueue.cpp -o $(TARGET)

clean:
	rm -f $(TARGET).exe

fmt:
	clang-format -i *.h *.cpp
