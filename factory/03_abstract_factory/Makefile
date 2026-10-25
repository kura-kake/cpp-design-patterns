CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
DEPFLAGS := -MMD -MP
BUILD    := build
TARGET   := $(BUILD)/pizza
SRCS     := main.cpp PizzaStore.cpp NYPizzaStore.cpp ChicagoPizzaStore.cpp \
            NYPizzaIngredientFactory.cpp ChicagoPizzaIngredientFactory.cpp
OBJS     := $(SRCS:%.cpp=$(BUILD)/%.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD)/%.o: %.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c -o $@ $<

$(BUILD):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD)

-include $(OBJS:.o=.d)

.PHONY: run clean