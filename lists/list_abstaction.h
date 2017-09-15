#ifndef LIST_H
#define LIST_H
template<class T>
struct node{
        T data;
        node<T> *next;
};

template<class T>
class list{
        node<T> *start;
        T size;
        public:
        list(){
                start = 0;
                size = 0;
        }
        void add( T& );
        T disp_index(T);
        T remove( T& );
        T get_size();
};
#include "list_implementaion.cpp"
#endif
