/**
 * @file list.h
 * @brief List ADT interface
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef LIST_H
#define LIST_H

/**
 * @class List
 * @brief An ordered collection with position-based access
 * @tparam T The type of elements in the list
 */
template <typename T>
class List {
public:
    virtual ~List() = default;
    
    /**
     * @brief Inserts an item at a specific position
     * @param position The 1-based position (1 is first)
     * @param item The item to insert
     * @return true if insert succeeded, false if position invalid
     */
    virtual bool insert(int position, const T& item) = 0;
    
    /**
     * @brief Removes an item at a specific position
     * @param position The 1-based position
     * @return true if remove succeeded, false if position invalid
     */
    virtual bool remove(int position) = 0;
    
    /**
     * @brief Gets an item at a specific position
     * @param position The 1-based position
     * @param item Reference to store the item
     * @return true if get succeeded, false if position invalid
     */
    virtual bool get(int position, T& item) const = 0;
    
    /**
     * @brief Checks if the list is empty
     * @return true if empty, false otherwise
     */
    virtual bool isEmpty() const = 0;
    
    /**
     * @brief Gets the number of items in the list
     * @return The size of the list
     */
    virtual int size() const = 0;
};

#endif  // LIST_H