/**
 * @file array_stack.tcc
 * @brief Implementation of array-based Stack ADT
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
ArrayStack<T>::ArrayStack() : top(0), capacity(DEFAULT_CAPACITY) {
    items = new T[DEFAULT_CAPACITY];
}

template <typename T>
ArrayStack<T>::ArrayStack(int capacity) : items(nullptr), top(0), capacity(capacity) {
    if (capacity < 0) {
        throw std::invalid_argument("capacity must be non-negative");
    }
    items = new T[capacity];
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack& other)
        : items(nullptr), top(other.top), capacity(other.capacity) {
    std::unique_ptr<T[]> copy(new T[capacity]);
    if (top > 0) {
        std::copy(other.items, other.items + top, copy.get());
    }
    items = copy.release();
}

template <typename T>
ArrayStack<T>::ArrayStack(ArrayStack&& other) noexcept
        : items(other.items), top(other.top), capacity(other.capacity) {
    other.items = nullptr;
    other.top = 0;
    other.capacity = 0;
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& other) {
    if (this != &other) {
        ArrayStack copy(other);
        swap(copy);
    }
    return *this;
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack&& other) noexcept {
    if (this != &other) {
        delete[] items;
        items = other.items;
        top = other.top;
        capacity = other.capacity;
        other.items = nullptr;
        other.top = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] items;
}

template <typename T>
void ArrayStack<T>::swap(ArrayStack& other) noexcept {
    using std::swap;
    swap(items, other.items);
    swap(top, other.top);
    swap(capacity, other.capacity);
}

template <typename T>
void ArrayStack<T>::push(const T& item) {
    if (top < capacity) {
        items[top] = item;
        top++;
    }
}

template <typename T>
bool ArrayStack<T>::pop(T& item) {
    if (isEmpty()) {
        return false;
    }
    top--;
    item = items[top];
    return true;
}

template <typename T>
bool ArrayStack<T>::peek(T& item) const {
    if (isEmpty()) {
        return false;
    }
    item = items[top - 1];
    return true;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return top == 0;
}

template <typename T>
int ArrayStack<T>::size() const {
    return top;
}
