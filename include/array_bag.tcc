/**
 * @file array_bag.tcc
 * @brief Implementation of array-based Bag ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

template <typename T>
ArrayBag<T>::ArrayBag() : itemCount(0), capacity(DEFAULT_CAPACITY) {
    items = new T[DEFAULT_CAPACITY];
}

template <typename T>
ArrayBag<T>::ArrayBag(int capacity) : itemCount(0), capacity(capacity) {
    items = new T[capacity];
}

template <typename T>
ArrayBag<T>::~ArrayBag() {
    delete[] items;
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


