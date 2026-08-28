/**
 * @file stack_test.cpp
 * @brief Test driver for Stack implementations
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <utility>
#include "array_stack.h"
#include "linked_stack.h"

void testArrayStack() {
    ArrayStack<int> stack;

    assert(stack.isEmpty());
    assert(stack.size() == 0);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(!stack.isEmpty());
    assert(stack.size() == 3);

    int value;
    assert(stack.peek(value));
    assert(value == 30);
    assert(stack.size() == 3);

    assert(stack.pop(value));
    assert(value == 30);
    assert(stack.size() == 2);

    assert(stack.pop(value));
    assert(value == 20);

    assert(stack.pop(value));
    assert(value == 10);

    assert(stack.isEmpty());
    assert(!stack.pop(value));
    assert(!stack.peek(value));

    stack.push(0);
    stack.push(-5);
    assert(stack.pop(value));
    assert(value == -5);

    std::cout << "ArrayStack tests passed!" << std::endl;
}

void testLinkedStack() {
    LinkedStack<int> stack;

    assert(stack.isEmpty());
    assert(stack.size() == 0);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(!stack.isEmpty());
    assert(stack.size() == 3);

    int value;
    assert(stack.peek(value));
    assert(value == 30);
    assert(stack.size() == 3);

    assert(stack.pop(value));
    assert(value == 30);
    assert(stack.size() == 2);

    assert(stack.pop(value));
    assert(value == 20);

    assert(stack.pop(value));
    assert(value == 10);

    assert(stack.isEmpty());
    assert(!stack.pop(value));
    assert(!stack.peek(value));

    stack.push(0);
    stack.push(-5);
    assert(stack.pop(value));
    assert(value == -5);

    std::cout << "LinkedStack tests passed!" << std::endl;
}

template <typename StackType>
void testStackValueSemantics() {
    StackType original;
    original.push(10);
    original.push(20);

    StackType copy(original);
    int value = 0;
    assert(original.pop(value));
    assert(copy.peek(value));
    assert(value == 20);

    StackType assigned;
    assigned = copy;
    assert(copy.pop(value));
    assert(assigned.peek(value));
    assert(value == 20);

    StackType moved(std::move(assigned));
    assert(assigned.isEmpty());
    assert(moved.size() == 2);

    StackType moveAssigned;
    moveAssigned.push(99);
    moveAssigned = std::move(moved);
    assert(moved.isEmpty());
    assert(moveAssigned.peek(value));
    assert(value == 20);
}

void testArrayStackRejectsNegativeCapacity() {
    bool rejected = false;
    try {
        ArrayStack<int> invalid(-1);
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    assert(rejected);
}

int main() {
    testArrayStack();
    testLinkedStack();
    testArrayStackRejectsNegativeCapacity();
    testStackValueSemantics<ArrayStack<int> >();
    testStackValueSemantics<LinkedStack<int> >();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
