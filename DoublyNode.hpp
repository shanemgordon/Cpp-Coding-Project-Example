#ifndef DOUBLYNODE_HPP
#define DOUBLYNODE_HPP
#include <iostream>
using namespace std;
template <typename T>
struct DoublyNode{
    DoublyNode<T>* next;
    DoublyNode<T>* prev;
    T value;
    bool operator>(DoublyNode<T>* that);
    DoublyNode<T>(const T value);
};
template <typename T>
bool DoublyNode<T>::operator>(DoublyNode<T>* that){
        return (this->value > that->value);
}
template <typename T>
DoublyNode<T>::DoublyNode(const T val){
    value = val;
    next = nullptr;
    prev = nullptr;
}

#endif