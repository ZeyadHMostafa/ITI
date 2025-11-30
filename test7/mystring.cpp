#include "mystring.h"
using namespace std;

void MyString::init_from(MyString* self, const char * const text){
    int new_length=0;
    if (self->data!=nullptr){
        delete [] self->data;
    }
    while (text[new_length]!=0){new_length++;}
    self->data=new char[new_length+1];
    //TODO add check for allocation
    self->length=new_length;
    for (int i=0; i<self->length; i++){
        self->data[i]=text[i];
    }
    self->data[self->length]=0; // null terminator
}
void MyString::init_from(MyString* self, const MyString& other){
    int new_length=other.length;
    if (self->data!=nullptr){
        delete[] self->data;
    }
    self->data=new char[new_length+1];
    //TODO add check for allocation
    self->length=new_length;
    for (int i=0; i<self->length; i++){
        self->data[i]=other.data[i];
    }
    self->data[self->length]=0; // null terminator
}


MyString::MyString()
{
    length=0;
    data=nullptr;
}

MyString::MyString(const char* const text)
{
    data=nullptr;
    MyString::init_from(this,text);
}

MyString::MyString(const MyString& other)
{
    data=nullptr;
    MyString::init_from(this,other);
}

MyString::~MyString()
{
    delete[] data;
}

unsigned int MyString::size() const{
    return length;
}

MyString MyString::operator=(const MyString& other){
    MyString::init_from(this,other);
    return MyString(other);
}

MyString MyString::operator=(const char* const text){
    MyString::init_from(this,text);
    return MyString(text);
}
bool MyString::operator==(const MyString& other){
    if (other.length!=length) return false;
    for (int i=0; i<length; i++){
        if (other.data[i]!=data[i]) return false;
    }
    return true;
}
bool MyString::operator==(const char * const text){
    int i;
    for (i=0; i<length; i++){
        if (text[i]==0) return false;
        if (text[i]!=data[i]) return false;
    }
    if (text[i]!=0) return false;
    return true;
}
bool MyString::operator!=(const MyString& other){
    return !(*this == other);
}
bool MyString::operator!=(const char * const text){
    return !(*this == text);
}
MyString MyString::operator+(const MyString& other){
    MyString str;
    str.length = length+other.length;
    str.data = new char[str.length+1];
    int index =0;
    for (int i=0; i<length; i++){
        str.data[index]=data[i];
        index++;
    }
    for (int i=0; i<other.length; i++){
        str.data[index]=other.data[i];
        index++;
    }
    str.data[index]=0;
    return str;
}
MyString MyString::operator+(const char * const text){
    MyString str;
    int other_length=0;
    while (text[other_length]!=0){other_length++;}
    str.length = length+other_length;
    str.data = new char[str.length+1];
    int index =0;
    for (int i=0; i<length; i++){
        str.data[index]=data[i];
        index++;
    }
    for (int i=0; i<other_length; i++){
        str.data[index]=text[i];
        index++;
    }
    str.data[index]=0;
    return str;
}
MyString MyString::operator+=(const MyString& other){
    *this=(*this)+other;
    return *this;
}
MyString MyString::operator+=(const char * const text){
    *this=(*this)+text;
    return *this;
}

char MyString::operator[](const unsigned int i) const{
    // TODO add check for OOB errors
    return data[i];
}

MyString::operator char*() const{
    return data;
}

ostream& operator<<(ostream& stream, const MyString& mystr){
    for (int i=0; i<mystr.length; i++){
        stream<<mystr.data[i];
    }
    return stream;
}
istream& operator>>(istream& stream, MyString& mystr){
    const int BUFFER_HOP=20;
    int buffer_size=BUFFER_HOP;
    char* buffer;
    buffer= new char[buffer_size];
    int index=0;
    char c;
    while (stream.get(c) && (c!='\n'||index==0) /*&& c!=' '*/){
        // ignore enters until suitable data is detected
        if (c!='\n'){
            // buffer overflow -> resize
            if (index>=buffer_size-1){
                char* new_buffer = new char[buffer_size+BUFFER_HOP];
                for (int i=0; i<buffer_size; i++){
                    new_buffer[i]=buffer[i];
                }
                delete[] buffer;
                buffer = new_buffer;
                buffer_size = buffer_size+BUFFER_HOP;
            }
    
            // append to buffer
            buffer[index]=c;
            index++;
        }
    }
    buffer[index]=0; // null terminator

    MyString::init_from(&mystr,buffer);

    delete[] buffer;
    return stream;
}