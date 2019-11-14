TARGET = projX
CXX = g++ 
CXX_FLAGS = -Wall -std=c++98

all: $(TARGET)

$(TARGET): $(TARGET).cpp DataType.h DataType.cpp SmartPtr.h SmartPtr.cpp
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp DataType.cpp SmartPtr.cpp -o $(TARGET)

clean:
	-rm -f $(TARGET)

fmt:
	clang-format -i *.h *.cpp
