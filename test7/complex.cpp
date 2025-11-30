#include "complex.h"
using namespace std;

// Constructors/Destructors

Complex::Complex(const double real,const double imag)
{
	this->real=real;
	this->imag=imag;
}

Complex::Complex(const Complex& c)
{
	this->real=c.real;
	this->imag=c.imag;
}

Complex::~Complex()
{
}

// setgets

double Complex::get_real() const{
	return this->real;
}
double Complex::get_imag() const{
	return this->imag;
}
void Complex::set_real(const double val){
	this->real=val;
}
void Complex::set_imag(const double val){
	this->imag=val;
}

// Operators

Complex Complex::operator-() const{
	return Complex(-real,-imag);
}

template<typename T> Complex::operator T() const{
	return T(real);
}

Complex Complex::operator+(const Complex& other) const{
	return Complex(
		other.real + this->real,
		other.imag + this->imag
	);
}

Complex Complex::operator-(const Complex& other) const{
	return Complex(
		other.real - this->real,
		other.imag - this->imag
	);
}

Complex Complex::operator*(const Complex& other) const{
	return Complex(
		other.real*this->real - other.imag*this->imag,
		other.real*this->imag + other.imag*this->real
	);
}
Complex Complex::operator/(const Complex& other) const{
	//(Xr+Xi)/(Yr+Yi) = (Xr+Xi)(Yr-Yi)/mag(Y)
	double mag = other.magnitude();
	return Complex(
		(other.real*this->real + other.imag*this->imag)/mag,
		(other.real*this->imag - other.imag*this->real)/mag
	);
}

bool Complex::operator==(const Complex& other) const{
	return (this->real==other.real)&&(this->imag==other.imag);
}
bool Complex::operator!=(const Complex& other) const{
	return !(*this == other);
}
bool Complex::operator<(const Complex& other) const{
	return (this->magnitude()<other.magnitude());
}
bool Complex::operator>(const Complex& other) const{
	return (this->magnitude()>other.magnitude());
}
bool Complex::operator<=(const Complex& other) const{
	return !(*this > other);
}
bool Complex::operator>=(const Complex& other) const{
	return !(*this < other);
}

template<typename T> Complex Complex::operator+(const T& other) const{
	return Complex(real+other,imag);
}

template<typename T> Complex Complex::operator-(const T& other) const{
	return Complex(real-other,imag);
}

template<typename T> Complex Complex::operator*(const T& other) const{
	return Complex(real*other,imag*other);
}

template<typename T> Complex Complex::operator/(const T& other) const{
	return Complex(real/other,imag/other);
}

template<typename T> Complex Complex::operator+=(const T& other){
	(*this)=(*this)+other;
	return (*this);
}

template<typename T> Complex Complex::operator-=(const T& other){
	(*this)=(*this)-other;
	return (*this);
}

template<typename T> Complex Complex::operator*=(const T& other){
	*this=(*this)*other;
	return *this;
}

template<typename T> Complex Complex::operator/=(const T& other){
	*this=(*this)/other;
	return *this;
}

template<typename T> Complex operator+(const T& other, const Complex& c){
	return Complex(other+c.real,c.imag);
}
template<typename T> Complex operator-(const T& other, const Complex& c){
	return Complex(other-c.real,-c.imag);
}
template<typename T> Complex operator*(const T& other, const Complex& c){
	return Complex(c.real*other,c.imag*other);
}
template<typename T> Complex operator/(const T& other, const Complex& c){
	//(Xr)/(Yr+Yi) = (Xr)(Yr-Yi)/mag(Y)
	double mag = c.magnitude();
	return Complex(
		(other*+c.real)/mag,
		(other*-c.imag)/mag
	);
}

ostream& operator<<(ostream& other, const Complex& c){
	other << c.real << "\t";
	if (c.get_imag()>=0) other << "+";
	other << c.imag << "i";
	return other;
}

istream& operator>>(istream& other, Complex& c){
	other >> c.real;
	other >> c.imag;
	return other;
}

// custom

double Complex::magnitude() const {
	return real*real+imag*imag;
}
