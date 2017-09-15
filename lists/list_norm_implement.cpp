#include "list_abstract.h"

 void list::add( int& value){
        struct node *p = (node*)new(node);
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

 int list::remove( int& value){
        struct node *cur = start;
        struct node *prev;
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

 int list::disp_index(int i){
        if(i<= size){
                int count = 0;
                struct node* temp = start;
                while(temp!= 0){
                        if(count == i){
                                cout<<"element at index = "<< temp->data <<endl;
                        }
                        count++;
                }
        }else{
                return -1;
        }
}

 int list::get_size(){
        return size;
}
