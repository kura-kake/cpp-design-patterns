CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

remote: main.cpp Command.hpp Devices.hpp Commands.hpp RemoteControl.hpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

run: remote
	./remote

clean:
	rm -f remote

.PHONY: run clean
