/**
 * @file README.md
 * @brief Data structures implementation
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 * 
 * Implementation with array-based and
 * linked-list-based backends.
 */

# Data Structures Implementation

## Implemented ADTs

- Bag (Array and Linked implementations)
- Stack (Array and Linked implementations)
- List (Array and Linked implementations)

## Project Structure

```
data-structures-cpp/
├── include/           # Headers and template implementations
├── tests/             # Test drivers
├── build/             # Compiled binaries
├── Makefile
└── README.md
```

## Building

```bash
make              # Build all tests
make clean        # Clean build artifacts
```

Or compile manually:
```bash
g++ -std=c++11 -I./include -o build/bag_test tests/bag_test.cpp
g++ -std=c++11 -I./include -o build/stack_test tests/stack_test.cpp
g++ -std=c++11 -I./include -o build/list_test tests/list_test.cpp
```

## Running Tests

```bash
./build/bag_test
./build/stack_test
./build/list_test
```

## Implementation Notes

Each ADT is implemented with both array-based and linked-list-based backends.
Template implementations are included directly in the `include/` directory.