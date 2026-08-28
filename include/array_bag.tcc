/**
 * @file array_bag.tcc
 * @brief Implementation of array-based Bag ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <utility>

template <typename T>
ArrayBag<T>::ArrayBag() : itemCount(0), capacity(DEFAULT_CAPACITY) {
    items = new T[DEFAULT_CAPACITY];
}

template <typename T>
ArrayBag<T>::ArrayBag(int capacity) : items(nullptr), itemCount(0), capacity(capacity) {
    if (capacity < 0) {
        throw std::invalid_argument("capacity must be non-negative");
    }
    items = new T[capacity];
}

template <typename T>
ArrayBag<T>::ArrayBag(const ArrayBag& other)
        : items(nullptr), itemCount(other.itemCount), capacity(other.capacity) {
    std::unique_ptr<T[]> copy(new T[capacity]);
    if (itemCount > 0) {
        std::copy(other.items, other.items + itemCount, copy.get());
    }
    items = copy.release();
}

template <typename T>
ArrayBag<T>::ArrayBag(ArrayBag&& other) noexcept
        : items(other.items), itemCount(other.itemCount), capacity(other.capacity) {
    other.items = nullptr;
    other.itemCount = 0;
    other.capacity = 0;
}

template <typename T>
ArrayBag<T>& ArrayBag<T>::operator=(const ArrayBag& other) {
    if (this != &other) {
        ArrayBag copy(other);
        swap(copy);
    }
    return *this;
}

template <typename T>
ArrayBag<T>& ArrayBag<T>::operator=(ArrayBag&& other) noexcept {
    if (this != &other) {
        delete[] items;
        items = other.items;
        itemCount = other.itemCount;
        capacity = other.capacity;
        other.items = nullptr;
        other.itemCount = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
ArrayBag<T>::~ArrayBag() {
    delete[] items;
}

template <typename T>
void ArrayBag<T>::swap(ArrayBag& other) noexcept {
    using std::swap;
    swap(items, other.items);
    swap(itemCount, other.itemCount);
    swap(capacity, other.capacity);
}

template <typename T>
void ArrayBag<T>::add(const T& item) {
    if (itemCount < capacity) {
        items[itemCount] = item;
        itemCount++;
    }
}

template <typename T>
bool ArrayBag<T>::remove(const T& item) {
    int index = getIndexOf(item);
    if (index > -1) {
        items[index] = items[itemCount - 1];
        itemCount--;
        return true;
    }
    else
        return false;
}

template <typename T>
int ArrayBag<T>::size() const {
    return itemCount;
}

template <typename T>
bool ArrayBag<T>::isEmpty() const {
    return itemCount == 0;
}

template <typename T>
bool ArrayBag<T>::contains(const T& item) const {
    return getIndexOf(item) > -1;
}

template <typename T>
int ArrayBag<T>::getIndexOf(const T& item) const {
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == item) {
            return i;
        }
    }
    return -1;
}
