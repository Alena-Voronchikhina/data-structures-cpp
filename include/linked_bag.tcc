/**
 * @file linked_bag.tcc
 * @brief Implementation of linked-list Bag ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

template <typename T>
LinkedBag<T>::LinkedBag() : head(nullptr), itemCount(0) {}

template <typename T>
LinkedBag<T>::~LinkedBag() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
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