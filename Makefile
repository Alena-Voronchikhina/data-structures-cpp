CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Wpedantic -I./include
BUILD_DIR := build
TEST_DIR := tests
TESTS := bag_test stack_test list_test
TEST_TARGETS := $(patsubst %, $(BUILD_DIR)/%, $(TESTS))
SANITIZER_DIR := $(BUILD_DIR)/sanitizers
SANITIZER_TARGETS := $(patsubst %, $(SANITIZER_DIR)/%, $(TESTS))
SANITIZER_FLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer

all: $(TEST_TARGETS)

$(BUILD_DIR)/%: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(SANITIZER_DIR)/%: $(TEST_DIR)/%.cpp | $(SANITIZER_DIR)
	$(CXX) $(CXXFLAGS) $(SANITIZER_FLAGS) -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(SANITIZER_DIR):
	mkdir -p $(SANITIZER_DIR)

test: $(TEST_TARGETS)
	@for test in $(TEST_TARGETS); do ./$$test; done

sanitize: $(SANITIZER_TARGETS)
	@for test in $(SANITIZER_TARGETS); do ./$$test; done

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean sanitize test
