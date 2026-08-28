/**
 * @file linked_bag.tcc
 * @brief Implementation of linked-list Bag ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

#include <utility>

template <typename T>
LinkedBag<T>::LinkedBag() : head(nullptr), itemCount(0) {}

template <typename T>
LinkedBag<T>::LinkedBag(const LinkedBag& other) : head(nullptr), itemCount(0) {
    copyFrom(other);
}

template <typename T>
LinkedBag<T>::LinkedBag(LinkedBag&& other) noexcept
        : head(other.head), itemCount(other.itemCount) {
    other.head = nullptr;
    other.itemCount = 0;
}

template <typename T>
LinkedBag<T>& LinkedBag<T>::operator=(const LinkedBag& other) {
    if (this != &other) {
        LinkedBag copy(other);
        swap(copy);
    }
    return *this;
}

template <typename T>
LinkedBag<T>& LinkedBag<T>::operator=(LinkedBag&& other) noexcept {
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
LinkedBag<T>::~LinkedBag() {
    clear();
}

template <typename T>
void LinkedBag<T>::clear() noexcept {
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
void LinkedBag<T>::copyFrom(const LinkedBag& other) {
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
void LinkedBag<T>::swap(LinkedBag& other) noexcept {
    using std::swap;
    swap(head, other.head);
    swap(itemCount, other.itemCount);
}

template <typename T>
void LinkedBag<T>::add(const T& item) {
    Node<T>* newNode = new Node<T>(item, head);
    head = newNode;
    itemCount++;
}

template <typename T>
bool LinkedBag<T>::remove(const T& item) {
    Node<T>* target = getPointerTo(item);
    if (target == nullptr) {
        return false;
    }
    
    target->setData(head->getData());
    Node<T>* temp = head;
    head = head->getNext();
    delete temp;
    itemCount--;
    return true;
}

template <typename T>
int LinkedBag<T>::size() const {
    return itemCount;
}

template <typename T>
bool LinkedBag<T>::isEmpty() const {
    return itemCount == 0;
}

template <typename T>
bool LinkedBag<T>::contains(const T& item) const {
    return getPointerTo(item) != nullptr;
}

template <typename T>
Node<T>* LinkedBag<T>::getPointerTo(const T& item) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->getData() == item) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}
