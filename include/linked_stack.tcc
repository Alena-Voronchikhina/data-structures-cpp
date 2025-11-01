/**
 * @file linked_stack.tcc
 * @brief Implementation of linked-list Stack ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

template <typename T>
LinkedStack<T>::LinkedStack() : top(nullptr), itemCount(0) {}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    Node<T>* current = top;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
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