// TODO switch to headers
# include "complex.cpp"
# include "mystring.cpp"

// ---------------- Complex ----------------
// ---------------- String -----------------
// ----------------- List ------------------

void displayComplex(Complex c){
	cout << c.get_real() << "\t";
	if (c.get_imag()>=0) cout << "+";
	cout << c.get_imag() << "i"; 
}

void test_complex(){
Complex c1;
	Complex c2(25);
	Complex c3(-3,4);
    cout << "plese enter complex number"<<endl;
    cin >> c3;
	cout << "c1:\t"		; displayComplex(c1)	; cout <<endl;
	cout << "c2:\t"		; displayComplex(c2)	; cout <<endl;
	cout << "c3:\t"		; displayComplex(c3)	; cout <<endl;
	cout << "c2+c3:\t"	; displayComplex(c2+c3)	; cout <<endl;
	cout << "c2-c3:\t"	; displayComplex(c2-c3)	; cout <<endl;
	cout << "c2*c3:\t"	; displayComplex(c2*c3)	; cout <<endl;
	cout << "c2/c3:\t"	; displayComplex(c2/c3)	; cout <<endl;
	cout << "c3+5:\t"	; displayComplex(c3+5)	; cout <<endl;
	cout << "c3-5:\t"	; displayComplex(c3-5)	; cout <<endl;
	cout << "c3*5:\t"	; displayComplex(c3*5)	; cout <<endl;
	cout << "c3/5:\t"	; displayComplex(c3/5)	; cout <<endl;
	cout << "5+c3:\t"	<< (5+c3)				<< 		endl;
	cout << "5-c3:\t"	<< (5-c3)				<< 		endl;
	cout << "5*c3:\t"	<< (5*c3)				<< 		endl;
	cout << "5/c3:\t"	<< (5/c3)				<< 		endl;
	cout << "c2==c2:\t"	<< (c2==c2)				<< 		endl;
	cout << "c2!=c3:\t"	<< (c2!=c3)				<< 		endl;
	cout << "c2< c3:\t"	<< (c2< c3)				<< 		endl;
	cout << "c2> c3:\t"	<< (c2> c3)				<< 		endl;
	cout << "c2<=c3:\t"	<< (c2<=c3)				<< 		endl;
	cout << "c2>=c3:\t"	<< (c2>=c3)				<< 		endl;
	cout << "c2+= 5:\t"	<< (c2+=5)				<< 		endl;
	cout << "c2-= 5:\t"	<< (c2-=5)				<< 		endl;
	cout << "c2*= 5:\t"	<< (c2*=5)				<< 		endl;
	cout << "c2/= 5:\t"	<< (c2/=5)				<< 		endl;
	cout << "int(c2):\t"<< (int(c2))			<< 		endl;
}

void test_string(){
    MyString s1("hello ");
    MyString s2("what?????");

    cout << "enter string:"<<endl;
    cin >> s2;
    cout << s1 << s2 << endl;
    
    s2 = s1;
    cout << "s2=s1: " << s2 <<endl;

    s2 = "him";
    cout << "s2='him': " << s2 <<endl;

    s1 = s1+s2;
    cout << "s1=s1+s2: " << s1 <<endl;

    s1 = s1+" nice";
    cout << "s1=s1+ ' nice': " << s1 <<endl;

    s1 += " nice";
    cout << "s1+= ' nice': " << s1 <<endl;
}

int main(){
    test_complex();
    test_string();
	return 0;
}