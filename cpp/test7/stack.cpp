#ifndef __MYSTACK__
#define __MYSTACK__

#include <iostream>

template <typename T>
class MyStack
{
private:
	T* data;
	unsigned int length;
	int tos;

	//static helper methods
	static void init_from
	(MyStack* self, unsigned int size=0, const T * const other=nullptr, int tos=-2);

public:
	
	// constructors/destructors
	MyStack();
	MyStack(int size);
	MyStack(const T * const other, unsigned int size, int tos=-2);
	MyStack(const MyStack& other);
	MyStack(const MyStack&& other);
	~MyStack();

	// setgets
	unsigned int size() const;
	unsigned int get_tos() const;

	// custom
	void push(const T item);
	void pop();
	T top();

	// operators
	MyStack operator=(const MyStack& other);
	MyStack& operator=(const MyStack&& other);
	bool operator==(const MyStack& other) const;
	bool operator!=(const MyStack& other) const;
	MyStack operator+=(const T item);
	T operator[](const unsigned int i) const;

	template<typename U> friend std::ostream& operator<<(std::ostream& stream, const MyStack<U>& mystack);
	template<typename U> friend std::istream& operator>>(std::istream& stream, MyStack<U>& mystack);
};


template <typename T> void MyStack<T>::init_from
(MyStack<T>* self, unsigned int size, const T * const other, int tos){
	if (self->data!=nullptr){
		delete[] self->data;
	}
	if (size==0){
		self->data=nullptr;
	}else{
		// TODO: give error on failure to allocate
		self->data=new T[size];
	}
	self->length=size;
	//TODO: give error when tos > size-1
	if (other==nullptr){
		self->tos = -1;
	}else if ((tos>-1)&&(tos<size)){
		self->tos = tos;
	}
	else{
		self->tos = size-1;
	}
	// fill data
	if (other!=nullptr){
		for (int i=0; i<=self->tos;i++){
			self->data[i]=other[i];
		}
	}

}

// constructors/destructors
template <typename T> MyStack<T>::MyStack(){
	init_from(this);
}

template <typename T> MyStack<T>::MyStack(int size){
	init_from(this,size);
}

template <typename T> MyStack<T>::MyStack(const T * const other, unsigned int size, int tos){
	init_from(this,size,other,tos);
}

template <typename T> MyStack<T>::MyStack(const MyStack& other){
	init_from(this,other.length,other.data,other.tos);
}

template <typename T> MyStack<T>::MyStack(const MyStack&& other){
	this.data = other.data;
	this.size = other.size;
	other.data=nullptr;
	other.size=0;
}

template <typename T> MyStack<T>::~MyStack(){
	if (this->data!=nullptr){
		delete[] data;
	}
}

// setgets
template <typename T> unsigned int MyStack<T>::size() const{return length;}
template <typename T> unsigned int MyStack<T>::get_tos() const{return tos;}

// custom
template <typename T> void MyStack<T>::push(const T item){
	if (tos!=length){ //TODO add error here otherwise
		tos++;
		data[tos]=item;
	}
}

template <typename T> void MyStack<T>::pop(){
	if (tos!=-1){ //TODO add error here otherwise
		tos--;
	}
}

template <typename T> T MyStack<T>::top(){
	return data[tos];
}

// operators
template <typename T> MyStack<T> MyStack<T>::operator=(const MyStack& other){
	init_from(this,other.length,other.data,other.tos);
	return *this;
}

template <typename T> MyStack<T>& MyStack<T>::operator=(const MyStack&& other){
	this->data=other.data;
	this->length=other.length;
	this->tos=other.tos;
	
	other.data=nullptr;
	other.length=0;
	other.tos=0;
	return *this;
}

template <typename T> bool MyStack<T>::operator==(const MyStack& other) const{
	if (this->length!=other->length) return false;
	for (int i=0; i<this->length;i++){
		if (this->data[i]!=other->data[i]) return false;
	}
	return true;
}

template <typename T> bool MyStack<T>::operator!=(const MyStack& other) const{
	return (*this==other);
}

template <typename T> MyStack<T> MyStack<T>::operator+=(const T item){
	push(item);
	return *this;
}

template <typename T> T MyStack<T>::operator[](const unsigned int i) const{
	if (i<=tos){ // add error otherwise
		return data[i];
	}
	return T();
}

template <typename T> std::ostream& operator<<(std::ostream& stream, const MyStack<T>& mystack){
	for (int i=0; i<=mystack.tos; i++){
		stream<<mystack.data[i]<<" ";
	}
	return stream;
}

template <typename T> std::istream& operator>>(std::istream& stream, MyStack<T>& mystack){
	for (int i=0; i<mystack.length; i++){
		stream>>mystack.data[i];
	}
	return stream;
}


#endif