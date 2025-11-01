CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -I./include
BUILD_DIR := build
TEST_DIR := tests
TESTS := bag_test stack_test list_test
TEST_TARGETS := $(patsubst %, $(BUILD_DIR)/%, $(TESTS))

all: $(TEST_TARGETS)

$(BUILD_DIR)/%: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean