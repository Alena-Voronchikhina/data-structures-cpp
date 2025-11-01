/**
 * @file linked_stack.h
 * @brief Linked-list implementation of Stack ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "stack.h"
#include "node.h"

template <typename T>
class LinkedStack : public Stack<T> {
private:
    Node<T>* top;
    int itemCount;

public:
    LinkedStack();
    virtual ~LinkedStack();

    virtual void push(const T& item) override;
    virtual bool pop(T& item) override;
    virtual bool peek(T& item) const override;
    virtual bool isEmpty() const override;
    virtual int size() const override;
};

#include "linked_stack.tcc"
#endif  // LINKED_STACK_H