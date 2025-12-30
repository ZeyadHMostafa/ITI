#include <stdexcept>
#include <iostream>
#include <iterator>

#ifndef __MY_Structure__
#define __MY_Structure__

//used to avoid long names
namespace MyStructure{

template <typename T>
class DataStructure
{
public:

	virtual DataStructure<T>* createNew() = 0; // important when containers try copying data
	virtual void copyFrom(DataStructure<T>* other) = 0;
    
    virtual void addStart(T data) = 0;
    virtual void addEnd(T data) = 0;
	virtual T removeStart() = 0;
    virtual T removeEnd() = 0;
    
	virtual void clear() = 0;
	virtual unsigned int getCount() = 0;
	virtual void display(std::ostream& stream) = 0;

    friend std::ostream& operator<<(std::ostream& stream, DataStructure<T>& structure){
		structure.display(stream);
		return stream;
	}
};


}

#endif