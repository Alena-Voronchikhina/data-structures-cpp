/**
 * @file array_list.tcc
 * @brief Implementation of array-based List ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

template <typename T>
ArrayList<T>::ArrayList() : itemCount(0), capacity(DEFAULT_CAPACITY) {
    items = new T[DEFAULT_CAPACITY];
}

template <typename T>
ArrayList<T>::ArrayList(int capacity) : itemCount(0), capacity(capacity) {
    items = new T[capacity];
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] items;
}

template <typename T>
bool ArrayList<T>::insert(int position, const T& item) {
    if (position < 1 || position > itemCount + 1 || itemCount >= capacity) {
        return false;
    }
    
    for (int i = itemCount; i >= position; i--) {
        items[i] = items[i - 1];
    }
    
    items[position - 1] = item;
    itemCount++;
    return true;
}

template <typename T>
bool ArrayList<T>::remove(int position) {
    if (position < 1 || position > itemCount) {
        return false;
    }
    
    for (int i = position - 1; i < itemCount - 1; i++) {
        items[i] = items[i + 1];
    }
    
    itemCount--;
    return true;
}

template <typename T>
bool ArrayList<T>::get(int position, T& item) const {
    if (position < 1 || position > itemCount) {
        return false;
    }
    
    item = items[position - 1];
    return true;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return itemCount == 0;
}

template <typename T>
int ArrayList<T>::size() const {
    return itemCount;
}