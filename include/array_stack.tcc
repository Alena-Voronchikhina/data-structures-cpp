/**
 * @file array_stack.tcc
 * @brief Implementation of array-based Stack ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

template <typename T>
ArrayStack<T>::ArrayStack() : top(0), capacity(DEFAULT_CAPACITY) {
    items = new T[DEFAULT_CAPACITY];
}

template <typename T>
ArrayStack<T>::ArrayStack(int capacity) : top(0), capacity(capacity) {
    items = new T[capacity];
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] items;
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