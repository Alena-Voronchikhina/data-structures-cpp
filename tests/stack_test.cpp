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

int main() {
    testArrayStack();
    testLinkedStack();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}