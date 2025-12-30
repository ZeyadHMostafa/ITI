#ifndef __MY_DEQUEUE__
#define __My_DEQUEUE__

#include <stdexcept>
#include <iostream>

#include "MyStructure.h"
#include "MyQueue.cpp"

//used to avoid long names
namespace MyStructure{
template <typename T>
class DEQueue: public Queue<T>
{

public:
    DEQueue(DataStructure<T> *dataStructure):Queue<T>(dataStructure){}
	
	void addEnd(T value){ this->dataStructure->addEnd(value); }

	void addStart(T value){ this->dataStructure->addStart(value); }

	T removeStart(){ return this->dataStructure->removeStart(); }

	T removeEnd(){ return this->dataStructure->removeEnd(); }
};

}

#endif