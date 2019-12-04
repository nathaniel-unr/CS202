TARGET = proj10
CXX = g++ 
CXX_FLAGS = -Wall -std=c++98

all: $(TARGET)

$(TARGET): $(TARGET).cpp ArrayStack.h NodeStack.h
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp -o $(TARGET)

clean:
	rm -f $(TARGET).exe

fmt:
	clang-format -i *.h *.cpp
