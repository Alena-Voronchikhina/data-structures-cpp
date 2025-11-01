/**
 * @file array_list.h
 * @brief Array-based implementation of List ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "list.h"

template <typename T>
class ArrayList : public List<T> {
private:
    static const int DEFAULT_CAPACITY = 100;
    T* items;
    int itemCount;
    int capacity;

public:
    ArrayList();
    ArrayList(int capacity);
    virtual ~ArrayList();

    virtual bool insert(int position, const T& item) override;
    virtual bool remove(int position) override;
    virtual bool get(int position, T& item) const override;
    virtual bool isEmpty() const override;
    virtual int size() const override;
};

#include "array_list.tcc"
#endif  // ARRAY_LIST_H