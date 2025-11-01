/**
 * @file node.tcc
 * @brief Node implementation
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */

template <typename T>
Node<T>::Node() : next(nullptr) {}

template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr) {}

template <typename T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next) {}

template <typename T>
T Node<T>::getData() const {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
void Node<T>::setData(const T& data) {
    this->data = data;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}
