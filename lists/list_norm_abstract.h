#ifndef LIST_H
#define LIST_H
struct node{
        int data;
        struct node *next;
};

class list{
        struct node *start;
        int size;
        public:
        list(){
                start = 0;
                size = 0;
        }
        void add( int& );
        int disp_index(int );
        int remove( int& );
        int get_size();
};

#endif
