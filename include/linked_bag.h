/**
 * @file linked_bag.h
 * @brief Linked-list implementation of Bag ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef LINKED_BAG_H
#define LINKED_BAG_H

#include "bag.h"
#include "node.h"

template <typename T>
class LinkedBag : public Bag<T> {
private:
    Node<T>* head;
    int itemCount;
    
    Node<T>* getPointerTo(const T& item) const;
    void clear() noexcept;
    void copyFrom(const LinkedBag& other);
    void swap(LinkedBag& other) noexcept;

public:
    LinkedBag();
    LinkedBag(const LinkedBag& other);
    LinkedBag(LinkedBag&& other) noexcept;
    LinkedBag& operator=(const LinkedBag& other);
    LinkedBag& operator=(LinkedBag&& other) noexcept;
    virtual ~LinkedBag();
    
    virtual void add(const T& item) override;
    virtual bool remove(const T& item) override;
    virtual int size() const override;
    virtual bool isEmpty() const override;
    virtual bool contains(const T& item) const override;
};

#include "linked_bag.tcc"
#endif  // LINKED_BAG_H
