#include "list_abstract.h"
template <class T>
void list<T>::add( T& value){
	node<T> *p = new(node<T>);
	p->data = value;
	p->next = 0;
	if(start==0){
		start = p;
		last = p;
	}else{
		p->next = start;
		start = p;
	}
	size++;
}

template <class T>
void list<T>::push_front( const T& value){
	node<T> *p = new(node<T>);
	p->data = value;
	p->next = 0;
	if(start==0){
		start = p;
		last = p;
	}else{
		p->next = start;
		start = p;
	}
	size++;
}

template <class T>
void list<T>::push_back( const T& value){
	node<T> *p = new(node<T>);
	p->data = value;
	p->next = 0;
	if(start==0){
		start = p;
		last = p;
	}else{
		last->next = p;
		last = p;
	}
	size++;
}

template <class T>
void list<T>::insert_index(int pos,T& val){
	if(pos ==  0){
		push_front(val);
	}else if(pos == size){
		push_back(val);
	}else if(pos > 0 and pos <size){
		node<T> *temp = new node<T>;
		temp->next = 0; 
		node<T> *p = start;
		int count = 0;
		while(count != pos-1){
			p = p->next;
			count++;
		}
		temp->next = p->next;
		p->next = temp;
	}
}

template <class T>
void list<T>::pop_front(){
	if(size>0){
		node<T> *cur = start;
		node<T> *start = start->next;
		size--; 
		delete cur;
	}
}

template <class T>
bool list<T>::empty() const{
	return size == 0;
}

template <class T>
void list<T>::resize(int re_size,T def_val ){
	while(re_size != 0){	
		push_front(def_val);
		re_size--;
	}
}

template <class T>
void list<T>::clear(){
	while(size!=0)
		pop_front();
}

template <class T>
list<T>::iterator list<T>::insert(list<T>::iterator position,const T& val){
	position.insert_index(pos,val);
	return position;
}

template<class T>
void list<T>::insert(list<T>::iterator position,int n,const T& val){
	for(int i = 0;i<n;i++)
		position.insert_index(pos,val);
}

template<class T>
void list<T>::insert(list<T>::iterator position,list<T>::iterator first,list<T>::iterator last){
	while(first != last){
		position.insert_index(first.get_pos(),first.get_index());
		first++;
	}	
	position.insert_index(first.get_pos(),first.get_index());
}

template <class T>
void list<T>::pop_back(){
	if(size > 0){
		node<T> *cur = start;
		node<T> *prev = start;
		while(cur->next != 0 ){
			prev = cur;
			cur = cur->next;
		}
		prev->next = 0;
		delete cur;
		size--; 
	}
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
list<T>& list<T>::remove_index(int i){
	if(i<= size){
		T count = 0;
		node<T> *temp = start;
		while(temp!= 0){
			if(count == i){
				list<T> rm = temp;
				temp = temp->next;
				return temp;
				size--;
			}
			count++;
		}
	}else{
		return -1;
	}
}

template <class T>
T list<T>::get_index(T i){
	if(i<= size){
		T count = 0;
		node<T> *temp = start;
		while(temp!= 0){
			if(count == i){
				//cout<<"element at index = "<< temp->data <<endl;
				//not yet printing and printing is not cool
				return temp->data;;
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

template <class T>
list<T>::iterator list<T>::erase(list<T>::iterator position){
	position.remove_pos(pos);
}

list<T>::iterator list<T>::erase(list<T>::iterator first, list<T>::iterator second){
	int count = first.get_pos() - second_pos();
	for(int i = first.pos();i< count;i++)
		position.remove_pos(pos);
}

