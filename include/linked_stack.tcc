/**
 * @file linked_stack.tcc
 * @brief Implementation of linked-list Stack ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

#include <utility>

template <typename T>
LinkedStack<T>::LinkedStack() : top(nullptr), itemCount(0) {}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack& other) : top(nullptr), itemCount(0) {
    copyFrom(other);
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack&& other) noexcept
        : top(other.top), itemCount(other.itemCount) {
    other.top = nullptr;
    other.itemCount = 0;
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& other) {
    if (this != &other) {
        LinkedStack copy(other);
        swap(copy);
    }
    return *this;
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack&& other) noexcept {
    if (this != &other) {
        clear();
        top = other.top;
        itemCount = other.itemCount;
        other.top = nullptr;
        other.itemCount = 0;
    }
    return *this;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template <typename T>
void LinkedStack<T>::clear() noexcept {
    Node<T>* current = top;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    top = nullptr;
    itemCount = 0;
}

template <typename T>
void LinkedStack<T>::copyFrom(const LinkedStack& other) {
    Node<T>* tail = nullptr;
    try {
        for (Node<T>* current = other.top; current != nullptr;
             current = current->getNext()) {
            Node<T>* copy = new Node<T>(current->getData());
            if (top == nullptr) {
                top = copy;
            } else {
                tail->setNext(copy);
            }
            tail = copy;
            itemCount++;
        }
    } catch (...) {
        clear();
        throw;
    }
}

template <typename T>
void LinkedStack<T>::swap(LinkedStack& other) noexcept {
    using std::swap;
    swap(top, other.top);
    swap(itemCount, other.itemCount);
}

template <typename T>
void LinkedStack<T>::push(const T& item) {
    Node<T>* newNode = new Node<T>(item, top);
    top = newNode;
    itemCount++;
}

template <typename T>
bool LinkedStack<T>::pop(T& item) {
    if (isEmpty()) {
        return false;
    }
    item = top->getData();
    Node<T>* temp = top;
    top = top->getNext();
    delete temp;
    itemCount--;
    return true;
}

template <typename T>
bool LinkedStack<T>::peek(T& item) const {
    if (isEmpty()) {
        return false;
    }
    item = top->getData();
    return true;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
int LinkedStack<T>::size() const {
    return itemCount;
}
