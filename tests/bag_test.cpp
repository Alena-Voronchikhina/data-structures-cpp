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

int main() {
    testArrayBag();
    testLinkedBag();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}