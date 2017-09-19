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
	node<T> *last;
	int size;
	public:
	list(){
		start = 0;
		size = 0;
	}
	void add( T& );
	//int size() const;
	T disp_index(T);
	void insert_index(int ,T& val);
	T remove( T& );
	T get_size(); 
	list& remove_index(int pos);
	void push_back(const T& val);
	void push_front(const T& val);
	void pop_back();
	void pop_front();
	bool empty() const;
	void clear();
	T get_index(T i);
	
	void resize(int n,T  = 0);

	class  iterator{
		list* li; 
		int pos;
		public:
			iterator():li(new(list)),pos(0){}
			iterator(list& li):li(li),pos(0){}
			iterator& remove_pos(){
				return li = li->remove_pos(pos);
			}
			int get_pos(){ return pos; } 
			int get_val(int pos){ return li->get_index(pos); } 
	};
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	iterator insert(iterator position,const T& val);
	void insert(iterator position,int n,const T& val);
	template<class InputIterator>
	void insert(iterator position,iterator first, iterator last);
/*	
	template<class InputIterator>
	void assign(InputIterator  first,InputIterator last);
	void assign(int n,const T& val);
	reference_back();
	const_reference_back() const;
	iterator begin();
	const_iterator begin() const;
	const_iterator cbegin() const noexcept;
	const_iterator crend() const noexcept;
	const_reverse_iterator crbegin() const noexcept;
	const_reverse_iterator crend() const noexcept;
	template <class... Args>
	iterator emplace(const_iterator, Args&&... args);
	template <class... Args>
	void emplace_back(Args&&... args);
	template <class... Args>
	void emplace_front(Args&&... args);
	iterator end();
	const_iterator end() const;
	reference front();
	const_reference front() const;
	allocator_type get_allocator() const;
	int max_size() const;
	void merge(list& x);
	template <class compare>
	void merge(list& x, compare comp);
	list& operator= (const list& x);
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	template <class predicate>
	void remove_if(predicate pred);
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	void resize(int n, T& val );
	void reverse();
	void sort();
	template <class compare>
	void sort(compare comp);
	void splice(iterator position, list& x);
	void splice (iterator position, list& x, iterator i);
	void splice (iterator position, list& x, iterator i);
	void splice (iterator position, list& x, iterator first, iterator last);
	void swap(list& x );
	void unique();
	template <class binarypredicate>
	void unique(binarypredicate binary_pred);
*/
};
#include "list_implementaion.cpp"
#endif
