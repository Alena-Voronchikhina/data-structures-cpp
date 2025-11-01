/**
 * @file array_bag.h
 * @brief Array-based implementation of Bag ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#include "bag.h"

template <typename T>
class ArrayBag : public Bag<T> {
    private:
        static const int DEFAULT_CAPACITY = 100;
        T* items;
        int itemCount;
        int capacity;
        int getIndexOf(const T& item) const;

    public:
        ArrayBag();
        ArrayBag(int capacity);
        virtual ~ArrayBag();

        virtual void add(const T& item) override;
        virtual bool remove(const T& item) override;
        virtual int size() const override;
        virtual bool isEmpty() const override;
        virtual bool contains(const T& item) const override;
};

#include "array_bag.tcc"
#endif  // ARRAY_BAG_H
