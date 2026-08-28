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

# Data Structures in C++

Array-backed and linked-node implementations of Bag, Stack, and List abstract
data types. The owning containers implement deep-copy and move semantics so
copies remain independent and destruction is safe.

## Implemented ADTs

- Bag: array and linked implementations
- Stack: array and linked implementations
- List: array and linked implementations
- Rule-of-Five ownership for all six concrete containers

## Project Structure

```
data-structures-cpp/
├── include/           # Headers and template implementations
├── tests/             # Test drivers
├── .github/workflows/ # Linux/macOS CI and sanitizer job
├── Makefile
└── README.md
```

## Building

```bash
make           # Build all test executables
make test      # Build and run the test suite
make sanitize  # Run the suite with ASan and UBSan
make clean     # Remove build artifacts
```

Or compile manually:
```bash
g++ -std=c++11 -I./include -o build/bag_test tests/bag_test.cpp
g++ -std=c++11 -I./include -o build/stack_test tests/stack_test.cpp
g++ -std=c++11 -I./include -o build/list_test tests/list_test.cpp
```

## Implementation Notes

Each ADT is implemented with both array-based and linked-list-based backends.
Template implementations are included directly from the headers. Array-backed
containers own dynamic arrays; linked containers own their node chains. Copy
construction and copy assignment perform deep copies, while move operations
transfer ownership and leave the source empty.

Tests cover core operations, invalid positions, copy independence, move
construction, and move assignment. CI runs the tests on Linux and macOS, plus
an Ubuntu ASan/UBSan job.
