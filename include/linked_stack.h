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
    void clear() noexcept;
    void copyFrom(const LinkedStack& other);
    void swap(LinkedStack& other) noexcept;

public:
    LinkedStack();
    LinkedStack(const LinkedStack& other);
    LinkedStack(LinkedStack&& other) noexcept;
    LinkedStack& operator=(const LinkedStack& other);
    LinkedStack& operator=(LinkedStack&& other) noexcept;
    virtual ~LinkedStack();

    virtual void push(const T& item) override;
    virtual bool pop(T& item) override;
    virtual bool peek(T& item) const override;
    virtual bool isEmpty() const override;
    virtual int size() const override;
};

#include "linked_stack.tcc"
#endif  // LINKED_STACK_H
