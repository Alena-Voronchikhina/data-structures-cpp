/**
 * @file node.h
 * @brief Node class for linked structures
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef NODE_H
#define NODE_H

/**
 * @class Node
 * @brief A node in a linked structure
 * @tparam T The type of data stored in the node
 */
template <typename T>
class Node {
    private:
        T data;
        Node<T>* next;

    public:
        Node();
        Node(const T& data);
        Node(const T& data, Node<T>* next);

        T getData() const;
        Node<T>* getNext() const;

        void setData(const T& data);
        void setNext(Node<T>* next);
};

#include "node.tcc"
#endif // NODE_H
