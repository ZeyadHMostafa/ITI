#ifndef __MYLISVagueBox__
#define __MYLISVagueBox__

#include <iostream>
using namespace std;

class VagueBox
{
public:
	virtual void inject(const void *const object)=0;
	virtual void extract(void * object) const=0;
};

template <typename U>
class TypedBox: public VagueBox{
	public:
	U value;

	void inject(const void *const object){
		value = *static_cast<const U*>(object);
	}
	void extract(void * object) const{
		*static_cast<U*>(object)=value;
	}
};


class MyList
{
private:
	VagueBox** data;
	unsigned int length;
	int tos;

	//static helper methods
	static void init_from
	(MyList* self, unsigned int size=0, VagueBox ** const other=nullptr, int tos=-2);

public:
	
	// constructors/destructors
	MyList();
	MyList(int size);
	MyList(VagueBox ** other, unsigned int size, int tos=-2);
	MyList(const MyList& other);
	~MyList();

	// setgets
	unsigned int size() const;
	unsigned int get_tos() const;

	// custom
	void push(const char* item);
	template <typename U>
	void push(const U item);
	void pop();
	template <typename U>
	void get_at(U& object,int index);
};

template <typename U>
void MyList::get_at(U& object,int index){
	data[index]->extract((void*)(&object));
}

 void MyList::init_from
(MyList* self, unsigned int size, VagueBox ** const other, int tos){
	if (self->data!=nullptr){
		delete[] self->data;
	}
	if (size==0){
		self->data=nullptr;
	}else{
		// VagueBoxODO: give error on failure to allocate
		self->data=new VagueBox*[size];
	}
	self->length=size;
	//VagueBoxODO: give error when tos > size-1
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
 MyList::MyList(){
	init_from(this);
}

 MyList::MyList(int size){
	init_from(this,size);
}

 MyList::MyList(VagueBox ** other, unsigned int size, int tos){
	init_from(this,size,other,tos);
}

 MyList::MyList(const MyList& other){
	init_from(this,other.length,other.data,other.tos);
}

 MyList::~MyList(){
	if (this->data!=nullptr){
		for (int i=0; i<tos; i++){
			delete data[i];
		}
		delete[] data;
	}
}

// setgets
 unsigned int MyList::size() const{return length;}
 unsigned int MyList::get_tos() const{return tos;}

// custom
void MyList::push(const char* item){
	if (tos!=length){ 
		tos++;
		TypedBox<string> *container = new TypedBox<string>;
		container->value=item;
		data[tos]=container;
	}
}
template <typename U> void MyList::push(const U item){
	if (tos!=length){ 
		tos++;
		TypedBox<U> *container = new TypedBox<U>;
		container->value=item;
		data[tos]=container;
	}
}

void MyList::pop(){
	if (tos!=-1){ //VagueBoxODO add error here otherwise
		delete data[tos];
		tos--;
	}
}

/*
// operators
 MyList MyList::operator=(const MyList& other){
	init_from(this,other.length,other.data,other.tos);
	return *this;
}

 bool MyList::operator==(const MyList& other) const{
	if (this->length!=other->length) return false;
	for (int i=0; i<this->length;i++){
		if (this->data[i]!=other->data[i]) return false;
	}
	return true;
}

 bool MyList::operator!=(const MyList& other) const{
	return (*this==other);
}

 MyList MyList::operator+=(const VagueBox item){
	push(item);
	return *this;
}

 VagueBox MyList::operator[](const unsigned int i) const{
	if (i<=tos){ // add error otherwise
		return data[i];
	}
	return VagueBox();
}

 std::ostream& operator<<(std::ostream& stream, const MyList& MyList){
	for (int i=0; i<=MyList.tos; i++){
		stream<<MyList.data[i]<<" ";
	}
	return stream;
}

 std::istream& operator>>(std::istream& stream, MyList& MyList){
	for (int i=0; i<MyList.length; i++){
		stream>>MyList.data[i];
	}
	return stream;
}

*/
#endif