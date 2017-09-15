#include "list_abstract.h"
template <class T>
void list<T>::add( T& value){
        node<T> *p = new(node<T>);
        p->data = value;
        p->next = 0;
        if(start==0){
                start = p;
        }else{
                p->next = start;
                start = p;
        }
        size++;
}

template <class T>
T list<T>::remove( T& value){
        node<T> *cur = start;
        node<T> *prev;
        while(cur != 0){
                if(cur->data == value){
                        prev->next = cur->next;
                        delete cur;
                        size--;
                        return 0;
                }
                prev = cur;
        }
        return 0;
}
template <class T>
T list<T>::disp_index(T i){
        if(i<= size){
                T count = 0;
                node<T> *temp = start;
                while(temp!= 0){
                        if(count == i){
                                //cout<<"element at index = "<< temp->data <<endl;
                                //not yet printing and printing is not cool
                                return 0;
                        }
                        count++;
                }
        }else{
                return -1;
        }
}
template <class T>
T list<T>::get_size(){
        return size;
}
