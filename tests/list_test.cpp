/**
 * @file list_test.cpp
 * @brief Test driver for List implementations
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include <cassert>
#include "array_list.h"
#include "linked_list.h"

void testArrayList() {
    ArrayList<int> list;

    assert(list.isEmpty());
    assert(list.size() == 0);

    assert(list.insert(1, 10));
    assert(list.insert(2, 20));
    assert(list.insert(3, 30));

    assert(!list.isEmpty());
    assert(list.size() == 3);

    int value;
    assert(list.get(1, value));
    assert(value == 10);
    assert(list.get(2, value));
    assert(value == 20);
    assert(list.get(3, value));
    assert(value == 30);

    assert(list.insert(2, 15));
    assert(list.size() == 4);
    assert(list.get(2, value));
    assert(value == 15);
    assert(list.get(3, value));
    assert(value == 20);

    assert(list.remove(2));
    assert(list.size() == 3);
    assert(list.get(2, value));
    assert(value == 20);

    assert(!list.get(0, value));
    assert(!list.get(10, value));
    assert(!list.insert(0, 99));
    assert(!list.remove(0));

    list.insert(1, 0);
    list.insert(2, -5);
    assert(list.get(1, value));
    assert(value == 0);
    assert(list.get(2, value));
    assert(value == -5);

    std::cout << "ArrayList tests passed!" << std::endl;
}

void testLinkedList() {
    LinkedList<int> list;

    assert(list.isEmpty());
    assert(list.size() == 0);

    assert(list.insert(1, 10));
    assert(list.insert(2, 20));
    assert(list.insert(3, 30));

    assert(!list.isEmpty());
    assert(list.size() == 3);

    int value;
    assert(list.get(1, value));
    assert(value == 10);
    assert(list.get(2, value));
    assert(value == 20);
    assert(list.get(3, value));
    assert(value == 30);

    assert(list.insert(2, 15));
    assert(list.size() == 4);
    assert(list.get(2, value));
    assert(value == 15);
    assert(list.get(3, value));
    assert(value == 20);

    assert(list.remove(2));
    assert(list.size() == 3);
    assert(list.get(2, value));
    assert(value == 20);

    assert(!list.get(0, value));
    assert(!list.get(10, value));
    assert(!list.insert(0, 99));
    assert(!list.remove(0));

    list.insert(1, 0);
    list.insert(2, -5);
    assert(list.get(1, value));
    assert(value == 0);
    assert(list.get(2, value));
    assert(value == -5);

    std::cout << "LinkedList tests passed!" << std::endl;
}

int main() {
    testArrayList();
    testLinkedList();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}