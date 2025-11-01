/**
 * @file array_stack.h
 * @brief Array-based implementation of Stack ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "stack.h"

template <typename T>
class ArrayStack : public Stack<T> {
private:
    static const int DEFAULT_CAPACITY = 100;
    T* items;
    int top;
    int capacity;

public:
    ArrayStack();
    ArrayStack(int capacity);
    virtual ~ArrayStack();

    virtual void push(const T& item) override;
    virtual bool pop(T& item) override;
    virtual bool peek(T& item) const override;
    virtual bool isEmpty() const override;
    virtual int size() const override;
};

#include "array_stack.tcc"
#endif  // ARRAY_STACK_H