#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>

class Complex
{
private:
	double real;
	double imag;
public:
	// Constructors/Destructors
	Complex(const double real=0,const double imag=0);
	Complex(const Complex& c);
	~Complex();
	
	// setgets
	double get_real() const;
	double get_imag() const;
	void set_real(const double val);
	void set_imag(const double val);

	// Operator Overloads
	// -Uniary
	Complex operator-() const;

	// -casting
	template<typename T> operator T() const;

	// -intra-Class
	Complex operator+(const Complex& other) const;
	Complex operator-(const Complex& other) const;
	Complex operator*(const Complex& other) const;
	Complex operator/(const Complex& other) const;

	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const;
	bool operator<(const Complex& other) const;
	bool operator>(const Complex& other) const;
	bool operator<=(const Complex& other) const;
	bool operator>=(const Complex& other) const;

	// -inter-class
	template<typename T> Complex operator+(const T& other) const;
	template<typename T> Complex operator-(const T& other) const;
	template<typename T> Complex operator*(const T& other) const;
	template<typename T> Complex operator/(const T& other) const;
	template<typename T> Complex operator+=(const T& other);
	template<typename T> Complex operator-=(const T& other);
	template<typename T> Complex operator*=(const T& other);
	template<typename T> Complex operator/=(const T& other);

	// -inter-class friend
	template<typename T> friend Complex operator+(const T& other, const Complex& c);
	template<typename T> friend Complex operator-(const T& other, const Complex& c);
	template<typename T> friend Complex operator*(const T& other, const Complex& c);
	template<typename T> friend Complex operator/(const T& other, const Complex& c);
	
	friend std::ostream& operator<<(std::ostream& other, const Complex& c);
	friend std::istream& operator>>(std::istream& other, Complex& c);

	// Custom
	double magnitude() const;

};

#endif