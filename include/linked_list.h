/**
 * @file linked_list.h
 * @brief Linked-list implementation of List ADT
 * @author Alena Voronchikhina
 * @date October 2025
 * 
 * @copyright Copyright (c) 2025
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "list.h"
#include "node.h"

template <typename T>
class LinkedList : public List<T> {
private:
    Node<T>* head;
    int itemCount;
    
    Node<T>* getNodeAt(int position) const;

public:
    LinkedList();
    virtual ~LinkedList();

    virtual bool insert(int position, const T& item) override;
    virtual bool remove(int position) override;
    virtual bool get(int position, T& item) const override;
    virtual bool isEmpty() const override;
    virtual int size() const override;
};

#include "linked_list.tcc"
#endif  // LINKED_LIST_H