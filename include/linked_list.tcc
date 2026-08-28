/**
 * @file linked_list.tcc
 * @brief Implementation of linked-list List ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

#include <utility>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), itemCount(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(nullptr), itemCount(0) {
    copyFrom(other);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& other) noexcept
        : head(other.head), itemCount(other.itemCount) {
    other.head = nullptr;
    other.itemCount = 0;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        LinkedList copy(other);
        swap(copy);
    }
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        itemCount = other.itemCount;
        other.head = nullptr;
        other.itemCount = 0;
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::clear() noexcept {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
    itemCount = 0;
}

template <typename T>
void LinkedList<T>::copyFrom(const LinkedList& other) {
    Node<T>* tail = nullptr;
    try {
        for (Node<T>* current = other.head; current != nullptr;
             current = current->getNext()) {
            Node<T>* copy = new Node<T>(current->getData());
            if (head == nullptr) {
                head = copy;
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
void LinkedList<T>::swap(LinkedList& other) noexcept {
    using std::swap;
    swap(head, other.head);
    swap(itemCount, other.itemCount);
}

template <typename T>
Node<T>* LinkedList<T>::getNodeAt(int position) const {
    if (position < 1 || position > itemCount) {
        return nullptr;
    }
    
    Node<T>* current = head;
    for (int i = 1; i < position; i++) {
        current = current->getNext();
    }
    return current;
}

template <typename T>
bool LinkedList<T>::insert(int position, const T& item) {
    if (position < 1 || position > itemCount + 1) {
        return false;
    }
    
    Node<T>* newNode = new Node<T>(item);
    
    if (position == 1) {
        newNode->setNext(head);
        head = newNode;
    } else {
        Node<T>* prev = getNodeAt(position - 1);
        newNode->setNext(prev->getNext());
        prev->setNext(newNode);
    }
    
    itemCount++;
    return true;
}

template <typename T>
bool LinkedList<T>::remove(int position) {
    if (position < 1 || position > itemCount) {
        return false;
    }
    
    Node<T>* toDelete;
    
    if (position == 1) {
        toDelete = head;
        head = head->getNext();
    } else {
        Node<T>* prev = getNodeAt(position - 1);
        toDelete = prev->getNext();
        prev->setNext(toDelete->getNext());
    }
    
    delete toDelete;
    itemCount--;
    return true;
}

template <typename T>
bool LinkedList<T>::get(int position, T& item) const {
    Node<T>* node = getNodeAt(position);
    if (node == nullptr) {
        return false;
    }
    
    item = node->getData();
    return true;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return itemCount == 0;
}

template <typename T>
int LinkedList<T>::size() const {
    return itemCount;
}
