//
// Created by Paolo Octoman on 1/16/23.
//

#ifndef WHATEVER_LINKEDLIST_CPP
#define WHATEVER_LINKEDLIST_CPP

#include "LinkedList.h"
#include "Node.h"
template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size =0;
}


template <typename T>
void LinkedList<T>::push_front(T dataPar){
    if (head == nullptr && tail == nullptr) {
        addFirstNode(dataPar);
    }
    else {
        Node<T>* n = createNode(dataPar);
        n->next = head;
        head = n;
        size+=1;
    }

}


template <typename T>
void LinkedList<T>::push_back(T dataPar){
    if ((head == nullptr) && (tail == nullptr)) {
        addFirstNode(dataPar);
    }
    else {
        Node<T>* n = createNode(dataPar);
        tail->next = n;
        tail = n;
        size+=1;
    }
}


template <typename T>
Node<T>* LinkedList<T>::createNode(T dataPar){
    Node<T>* n = new Node<T>;
    n->data = dataPar;
    return n;
}

template<typename T>
void LinkedList<T>::addFirstNode(T dataPar) {
    Node<T>* n = createNode(dataPar);
    head = n;
    tail = n;
    size+=1;

}

template<typename T>
Node<T> *LinkedList<T>::search(T item) {
    Node<T>* walker = head;
    while(walker!= nullptr && walker->data!=item){
        walker = walker->next;
    }
    return walker;
}

template<typename T>
Node<T> *LinkedList<T>::searchPrev(T item) {
    Node<T>* walker = head;
    while(walker->next!= nullptr && walker->next->data!=item){
        walker = walker->next;
    }
    return walker;
}

template<typename T>
T &LinkedList<T>::front() {
    return head->data;
}

template<typename T>
const T &LinkedList<T>::front() const {
    return head->data;
}

template<typename T>
T &LinkedList<T>::back() {
    return tail->data;
}

template<typename T>
const T &LinkedList<T>::back() const {
    return tail->data;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (size==0){
        //if there are no nodes, do nothing

    }
    else if (size==1){
        //if theres only one, delete it and point head/tail to nothing
        Node<T>* temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
        size-=1;
    }
    else {
        Node<T> *temp = head;
        head = head->next;// add more cases if there less than 2
        delete temp;
        size-=1;
    }
}

template<typename T>
void LinkedList<T>::pop_back() {
    if (size==0){
        //if there are no nodes, do nothing

    }
    else if (size==1){
        //if theres only one, delete it and point head/tail to nothing
        Node<T>* temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
        size-=1;
    }
    else {
        //pops the back
        Node<T> *temp = tail;
        Node<T> *walker = head;
        while (walker != nullptr && walker->next != tail) {
            walker = walker->next;
        }
        tail = walker;
        delete temp;
        tail->next = nullptr;
        size -= 1;
    }
}

template<typename T>
int LinkedList<T>::getSize() const{
    return size;
}

template<typename T>
bool LinkedList<T>::empty() {
    if(head == nullptr && tail== nullptr){
        return true;
    } else{
        return false;
    }
}

template<typename T>
void LinkedList<T>::insertBefore(T thisItem, T beforeThisItem) {

    if(head->data == beforeThisItem){
        Node<T>* n = createNode(thisItem);
        n->next = head;
        head = n;
        size+=1;
    }
    else if(tail->data== beforeThisItem){
        Node<T>* n = createNode(thisItem);
        Node<T>* pN = searchPrev(tail->data);
        pN->next=n;
        n->next =tail;
        size+=1;

    }
    else {
        Node<T> *n = createNode(thisItem);
        Node<T> *pN = searchPrev(beforeThisItem); //pn means previous node
        Node<T> *nN = search(beforeThisItem); //nN means Next node

        n->next = nN;
        pN->next = n;
        size += 1;
    }



}

template<typename T>
void LinkedList<T>::insertAfter(T thisItem, T afterThisItem) {

    if(head->data==afterThisItem){
        Node<T>* n = createNode(thisItem);
        n->next=head->next;
        head->next=n;
        size+=1;

    }
    else if(tail->data==afterThisItem){
        Node<T>* n = createNode(thisItem);
        tail->next = n;
        tail = n;
        n->next= nullptr;
        size+=1;
    }
    Node<T>* n = createNode(thisItem);
    Node<T>* pN = searchPrev(afterThisItem); //pn means previous node
    n = pN->next;
    pN->next = n;
    size+=1;


}

template<typename T>
void LinkedList<T>::remove(T item) {
    if (head->data == item){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size-=1;
    }
    else if (tail->data = item){
        Node<T>* temp = tail;
        tail = searchPrev(item);
        delete temp;
        tail->next = nullptr;
        size-=1;
    }
    else
    {
        Node<T>* target = search(item);
        Node<T>* pN = searchPrev(item);
        pN->next = target->next;
        delete target;

    }
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T>& list ) {
    os << "[ ";
    Node<T>* walker = list.head;
    while(walker!= nullptr){
        os << walker->data << ", ";
        walker = walker->next;
    }
    os << "]";
    return os;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &listPar) {
    if(&listPar == this) {
        return *this;
    }

    this->~LinkedList();
    Node<T>* walker = listPar.head;
    while(walker!= nullptr){
        push_back(walker->data);
        walker = walker->next;
    }
    size = listPar.size;

    return *this;

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &listPar) {//copy CONSTRUCTOR
    *this = listPar;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while(empty() == false){
        pop_front();
    }
}

template<typename T>
T &LinkedList<T>::operator[](unsigned int index) {
    Node<T>* walker = head;
    for (int i = 0; i < getSize(); ++i) {
        if (index == i){
            return walker->data;
        }
        walker = walker->next;
    }
}


#endif