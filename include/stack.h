/**
 * @file stack.h
 * @brief Stack ADT interface
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef STACK_H
#define STACK_H

/**
 * @class Stack
 * @brief A LIFO (Last In First Out) collection
 * @tparam T The type of elements in the stack
 */
template <typename T>
class Stack {
public:
    virtual ~Stack() = default;
    
    /**
     * @brief Adds an item to the top of the stack
     * @param item The item to push
     */
    virtual void push(const T& item) = 0;
    
    /**
     * @brief Removes and returns the top item
     * @param item Reference to store the popped item
     * @return true if pop succeeded, false if stack was empty
     */
    virtual bool pop(T& item) = 0;
    
    /**
     * @brief Views the top item without removing it
     * @param item Reference to store the top item
     * @return true if peek succeeded, false if stack was empty
     */
    virtual bool peek(T& item) const = 0;
    
    /**
     * @brief Checks if the stack is empty
     * @return true if empty, false otherwise
     */
    virtual bool isEmpty() const = 0;
    
    /**
     * @brief Gets the number of items in the stack
     * @return The size of the stack
     */
    virtual int size() const = 0;
};

#endif  // STACK_H