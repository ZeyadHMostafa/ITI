#ifndef __MY_QUEUE__
#define __MY_QUEUE__

#include <stdexcept>
#include <iostream>

#include "MyStructure.h"

//used to avoid long names
namespace MyStructure{
template <typename T>
class Queue
{
protected:
	DataStructure<T>* dataStructure;

public:
	
    Queue(DataStructure<T> *dataStructure){ this->dataStructure = dataStructure; }

	Queue(Queue<T>& other){
		dataStructure = other.dataStructure->createNew();
		*this = other;
	}

	Queue<T>& operator=(Queue<T>& other){
		this->dataStructure->copyFrom(other.dataStructure);
		return *this;
	}// = is intended here

    ~Queue(){ delete dataStructure; }// not sure if this is a good idea

	bool isEmpty(){ return dataStructure->getCount()==0; }
	
	void add(T value){ dataStructure->addEnd(value); }

	T remove(){ return dataStructure->removeStart(); }

	void display(std::ostream& stream){ stream<<*dataStructure; }

    friend std::ostream& operator<<(std::ostream& stream, Queue<T>& queue){
		queue.display(stream);
		return stream;
	}
};

}

#endif