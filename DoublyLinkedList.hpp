#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "DoublyNode.hpp"
#include <iostream>
using namespace std;
template <typename T>
class DoublyLinkedList{
    public:
        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList<T>& OTHER);
        ~DoublyLinkedList();
        DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& OTHER);
        T get(const int POS) const;
        DoublyNode<T>* getNode(const int POS) const;
        void set(const int POS, const T VAL);
        void insert(const int POS, const T VAL);
        void remove(const int POS);
        int size() const;
        void print() const;
        void printReverse() const;
        void makeCircular();
        DoublyNode<T>* getHead() const;
        DoublyNode<T>* getTail() const;
        bool destroy = true;
    private:
        
        DoublyNode<T>* head;
        DoublyNode<T>* tail;
        int listSize;
};
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}
template <typename T>
void DoublyLinkedList<T>::makeCircular(){
    head->prev = tail;
    tail->next = head;
}
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& OTHER){
    if (this == &OTHER) return *this;
    while(listSize>0){
        remove(0);
    }
    for(int i = 0; i<OTHER.listSize;i++){
        insert(listSize,OTHER.get(i));
    }
    return *this;
}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& OTHER){
    DoublyNode<T>* thisNode = OTHER.getHead();
    for(int i=0; i<OTHER.size();i++){
        insert(listSize,thisNode->value);
        thisNode = thisNode->next;
    }
}
template <typename T>
void DoublyLinkedList<T>::remove(const int POS){
    //Edge Cases (popfront, popback)
    if(listSize==0) return;
    if(listSize==1){
        delete head;
        head = nullptr;
        tail = nullptr;
        listSize = 0;
        return;
    }
    if(POS <= 0) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        listSize--;
        return;
    }
    if(POS >= listSize){
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        listSize--;
        return;
    }
    //Middle Cases
    DoublyNode<T>* thisNode = head;
    for(int i=0; i<POS; i++){
        thisNode = thisNode->next;
    }
    listSize--;
    thisNode->prev->next = thisNode->next;
    thisNode->next->prev = thisNode->prev;
    delete thisNode;
}
template <typename T>
T DoublyLinkedList<T>::get(const int POS) const{
    if(listSize==0||POS<0||POS>=listSize) return T();
    DoublyNode<T>* thisNode = head; 
    for(int i=0; i<POS;i++){
        thisNode = thisNode->next;
    }
    return thisNode->value;
}
template <typename T>
DoublyNode<T>* DoublyLinkedList<T>::getNode(const int POS) const{
    DoublyNode<T>* thisNode = head; 
    for(int i=0; i<POS;i++){
        thisNode = thisNode->next;
    }
    return thisNode;
}
template <typename T>
void DoublyLinkedList<T>::set(const int POS, const T VAL){
    if(listSize==0||POS<0||POS>=listSize) return;
    DoublyNode<T>* thisNode = head;
    for(int i=0; i<POS;i++){
        thisNode = thisNode->next;
    }
    thisNode->value = VAL;
    return; 
};
template <typename T>
void DoublyLinkedList<T>::insert(const int POS, const T VAL){
    DoublyNode<T>* newNode = new DoublyNode<T>(VAL);
    if(listSize == 0){
        head = newNode;
        tail = newNode;
        listSize++;
        return;
    }
    if(POS <= 0){
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        listSize++;
        return;
    }
    if(POS >= listSize){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        listSize++;
        return;
    }
    DoublyNode<T>* thisNode = head;
    for(int i=0; i<POS; i++){
        
        thisNode = thisNode->next;
    }
    
    newNode->prev = thisNode->prev;
    newNode->next = thisNode;
    thisNode->prev->next = newNode;
    thisNode->prev = newNode;
    listSize++;
    return;
}
template <typename T>
int DoublyLinkedList<T>::size() const{
    return listSize;
};
template <typename T>
DoublyLinkedList<T> merge(DoublyLinkedList<T> &list1, DoublyLinkedList<T> &list2){
    DoublyLinkedList<T> newList;
    for(int i=0; i<list1.size(); i++){
        newList.insert(newList.size(),list1.get(i));
    }
    for(int i=0; i<list2.size(); i++){
        newList.insert(newList.size(),list2.get(i));
    }
    return newList;
}
template <typename T>
DoublyNode<T>* DoublyLinkedList<T>::getHead() const{
    return head;
}
template <typename T>
DoublyNode<T>* DoublyLinkedList<T>::getTail() const{
    return tail;
}
template <typename T>
void DoublyLinkedList<T>::print() const{
    DoublyNode<T>* thisNode = head;
    if(listSize==0) return;
    int counter = 0;
    do{
        cout << counter++ << ": " << thisNode->value.getName() << endl;
        thisNode = thisNode->next;
    }while(thisNode!=nullptr);
}
template <typename T>
void DoublyLinkedList<T>::printReverse() const{
    DoublyNode<T>* thisNode = tail;
    int counter = listSize-1;
    do{
        cout << counter-- << ": " << thisNode->value << endl;
        thisNode = thisNode->prev;
    }while(thisNode!=nullptr);
}
template <typename T>
void mergeSort(DoublyLinkedList<T> &list){
    if(list.size()<=1) return;
    DoublyLinkedList<T> list1;
    DoublyLinkedList<T> list2;
    list.split(list1,list2);
    cout << "Splitting list" << endl;
    list.print();
    cout << "Into" << endl;
    list1.print();
    list2.print();
    mergeSort(list1);
    mergeSort(list2);
    cout << "Lists being analyzed: " << endl;
    list1.print();
    list2.print();
    cout << "List 2 head: " << list2.getHead()->value << endl;
    cout << "List 1 head: " << list1.getHead()->value << endl;
    if(list2.getHead()->value>list1.getHead()->value){
        list = merge(list1,list2);
    }else{
        list = merge(list2,list1);
    }

    cout << "result:" << endl;
    list.print();
    bubbleSort(list);
    cout << "end frame" << endl;
}
template<typename T>
void bubbleSort(DoublyLinkedList<T> &list){
    bool valid = false;
    while(!valid){
        valid = true;
        for(int i=0; i<list.size()-1;i++){
            if(list.get(i)>list.get(i+1)){
                T value = list.get(i);
                list.set(i,list.get(i+1));
                list.set(i+1,value);
                valid = false;
            }
        }
    }
}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    if(!destroy) return;
    while(listSize!=0){
        remove(0);
    }
};
#endif