#include <stdexcept>
#include <iostream>
#include "MyStructure.h"

#ifndef __MY_CIR_ARRAY__
#define __My_CIR_ARRAY__

//used to avoid long names
namespace MyStructure{
template <typename T>
class CirArray : public DataStructure<T>
{
private:
    T *data;
	unsigned int size;
	unsigned int front;
	unsigned int count;

	void fromCirArray(CirArray& other, unsigned int size=0){
		// note, the front isn't the same for both,because
		// front is an arbitrary position and shouldn't affect functionality

		if (size==0) size = other.size;

		if (data!=nullptr) delete[] data;
		this->size=size;
		this->data = new T[size];
		this->front = 0;
		this->count = other.count;

		//note, if down sizing data is lost
		for (unsigned i=0; i < count && i<size; i++){
			data[i]=other.data[other.trueIndex(i)];
		}
	}

	unsigned int trueIndex(unsigned int i){return (front+i)%size;}

public:

	virtual DataStructure<T>* createNew(){return new CirArray(0);}

	void copyFrom(DataStructure<T>* other){
        fromCirArray(*static_cast<CirArray<T>*>(other));
    }

    CirArray(int size){
		this->size=size;
		this->front=0;
		this->count=0;
		this->data = new T[size];
	}

	CirArray(CirArray<T>& other){
		fromCirArray(other);
	}

	CirArray<T>& operator=(CirArray<T>& other){
		fromCirArray(other);
		return *this;
	}

    ~CirArray(){
		delete[] data; 
	}

	bool isEmpty(){
		return count==0;
	}

	bool isFull(){
		return count==size;
	}

	void clear(){
        while(!isEmpty()){
            removeEnd();
        }
    }

    void addStart(T value){
        if (isFull()){throw std::length_error("attempt to add to a full queue");}
		front=(front-1+size)%size;
        data[front] = value;
        count++;
    }

	void addEnd(T value){
		if (isFull()){throw std::length_error("attempt to add to a full queue");}
		data[trueIndex(count)] = value;
		count++;
	}

	T removeStart(){
        if (isEmpty()){throw std::range_error("attempt to remove from empty queue");}
		T value = data[front];
		front=(front+1)%size;
		count--;
		return value;
	}
    
    T removeEnd(){
        if (isEmpty()){throw std::range_error("attempt to remove from empty queue");}
		T value = data[trueIndex(count-1)];
		count--;
		return value;
	}

	unsigned int getCount() {return count;}

    void display(std::ostream& stream){
		stream<<"[";
		for (int i=0; i<count; i++){
			stream<< data[trueIndex(i)] <<", ";
		}
		stream<<"]";
	}
};

}

#endif