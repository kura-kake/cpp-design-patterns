CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
TARGET   := gumball
SRCS     := main.cpp GumballMachine.cpp States.cpp
OBJS     := $(SRCS:.cpp=.o)
HEADERS  := State.hpp States.hpp GumballMachine.hpp

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run clean
