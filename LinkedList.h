//
// Created by Paolo Octoman on 1/16/23.
//

#ifndef WHATEVER_LINKEDLIST_H
#define WHATEVER_LINKEDLIST_H


#include "Node.h"
#include <iostream>


template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* createNode(T dataPar);
    void addFirstNode(T dataPar);
    Node<T>* search(T item);
    Node<T>* searchPrev(T item);
    int size;
public:
    LinkedList<T>();
    LinkedList<T>(const LinkedList<T>& listPar);
    ~LinkedList();
    void push_front(T dataPar);
    void push_back(T dataPar);
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    void pop_front();
    void pop_back();
    int getSize() const;
    bool empty();
    void insertBefore(T thisItem, T beforeThisItem);
    void insertAfter(T thisItem, T afterThisItem);
    void remove(T item);
    LinkedList<T>& operator=(const LinkedList<T>& listPar);

    T& operator[] (unsigned int index);
    const T& operator[] (unsigned int index) const;

    template<class U>
    friend std::ostream& operator<<(std::ostream &os, const LinkedList<U>& list );




};

#include "LinkedList.cpp"

#endif //WHATEVER_LINKEDLIST_H
