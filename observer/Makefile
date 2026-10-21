CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
DEPFLAGS := -MMD -MP
BUILD    := build
TARGET   := $(BUILD)/weather
SRCS     := main.cpp WeatherData.cpp Displays.cpp
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