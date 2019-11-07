TARGET = proj7
CXX = g++ 
CXX_FLAGS = -Wall -std=c++98

all: $(TARGET)

$(TARGET): $(TARGET).cpp MyString.h MyString.cpp
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp MyString.h MyString.cpp -o $(TARGET)

clean:
	-rm -f $(TARGET)

fmt:
	clang-format -i *.h *.cpp
