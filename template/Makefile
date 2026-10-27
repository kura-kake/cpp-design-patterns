CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

beverage: main.cpp CaffeineBeverageWithHook.hpp TeaWithHook.hpp CoffeeWithHook.hpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

run: beverage
	./beverage

clean:
	rm -f beverage

.PHONY: run clean
