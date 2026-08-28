/**
 * @file bag_test.cpp
 * @brief Test driver for Bag implementations
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <utility>
#include "array_bag.h"
#include "linked_bag.h"

void testArrayBag() {
    ArrayBag<int> bag;

    assert(bag.isEmpty());
    assert(bag.size() == 0);

    bag.add(10);
    bag.add(20);
    bag.add(30);

    assert(!bag.isEmpty());
    assert(bag.size() == 3);
    assert(bag.contains(20));
    assert(!bag.contains(40));

    assert(bag.remove(20));
    assert(!bag.contains(20));
    assert(bag.size() == 2);

    assert(!bag.remove(40));

    bag.add(0);
    bag.add(-5);
    bag.add(-100);
    
    assert(bag.contains(0));
    assert(bag.contains(-5));
    assert(bag.contains(-100));
    assert(bag.size() == 5);
    
    assert(bag.remove(0));
    assert(!bag.contains(0));
    assert(bag.remove(-5));
    assert(bag.size() == 3);

    std::cout << "ArrayBag tests passed!" << std::endl;
}

void testLinkedBag() {
    LinkedBag<int> bag;

    assert(bag.isEmpty());
    assert(bag.size() == 0);

    bag.add(10);
    bag.add(20);
    bag.add(30);

    assert(!bag.isEmpty());
    assert(bag.size() == 3);
    assert(bag.contains(20));
    assert(!bag.contains(40));

    assert(bag.remove(20));
    assert(!bag.contains(20));
    assert(bag.size() == 2);

    assert(!bag.remove(40));

    bag.add(0);
    bag.add(-5);
    bag.add(-100);
    
    assert(bag.contains(0));
    assert(bag.contains(-5));
    assert(bag.contains(-100));
    assert(bag.size() == 5);
    
    assert(bag.remove(0));
    assert(!bag.contains(0));
    assert(bag.remove(-5));
    assert(bag.size() == 3);

    std::cout << "LinkedBag tests passed!" << std::endl;
}

void testArrayBagValueSemantics() {
    bool rejectedNegativeCapacity = false;
    try {
        ArrayBag<int> invalid(-1);
    } catch (const std::invalid_argument&) {
        rejectedNegativeCapacity = true;
    }
    assert(rejectedNegativeCapacity);

    ArrayBag<int> original;
    original.add(10);
    original.add(20);

    ArrayBag<int> copy(original);
    assert(original.remove(10));
    assert(copy.contains(10));

    ArrayBag<int> assigned;
    assigned = copy;
    assert(copy.remove(20));
    assert(assigned.contains(20));

    ArrayBag<int> moved(std::move(assigned));
    assert(assigned.isEmpty());
    assert(moved.contains(10));
    assert(moved.contains(20));

    ArrayBag<int> moveAssigned;
    moveAssigned.add(99);
    moveAssigned = std::move(moved);
    assert(moved.isEmpty());
    assert(moveAssigned.contains(10));
    assert(!moveAssigned.contains(99));
}

void testLinkedBagValueSemantics() {
    LinkedBag<int> original;
    original.add(10);
    original.add(20);

    LinkedBag<int> copy(original);
    assert(original.remove(10));
    assert(copy.contains(10));

    LinkedBag<int> assigned;
    assigned = copy;
    assert(copy.remove(20));
    assert(assigned.contains(20));

    LinkedBag<int> moved(std::move(assigned));
    assert(assigned.isEmpty());
    assert(moved.contains(10));
    assert(moved.contains(20));

    LinkedBag<int> moveAssigned;
    moveAssigned.add(99);
    moveAssigned = std::move(moved);
    assert(moved.isEmpty());
    assert(moveAssigned.contains(10));
    assert(!moveAssigned.contains(99));
}

int main() {
    testArrayBag();
    testLinkedBag();
    testArrayBagValueSemantics();
    testLinkedBagValueSemantics();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
