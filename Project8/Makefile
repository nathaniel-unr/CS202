TARGET = proj8
CXX = g++ 
CXX_FLAGS = -Wall -std=c++98

all: $(TARGET)

$(TARGET): $(TARGET).cpp DataType.h DataType.cpp ArrayList.h ArrayList.cpp NodeList.h NodeList.cpp
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp DataType.cpp ArrayList.cpp NodeList.cpp -o $(TARGET)

clean:
	rm -f $(TARGET).exe

fmt:
	clang-format -i *.h *.cpp
