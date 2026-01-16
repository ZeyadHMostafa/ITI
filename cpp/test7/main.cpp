// TODO switch to headers
# include "complex.cpp"
# include "mystring.cpp"
# include "stack.cpp"
# include "mylist.cpp"

using namespace std;
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

void test_stack(){
	static const int values[]= {10,20,30,40,50,60,70,80,90,100};
	MyStack<int> stack1;
	MyStack<int> stack2(5);
	MyStack<int> stack3(values,3);
	MyStack<int> stack4(&values[3],4,2);
	MyStack<int> stack5=stack4;
	MyStack<int> stack6(5);
	stack6 = stack4;
	cout<<"stack 1: "<< stack1 << endl;
	cout<<"stack 2: "<< stack2 << endl;
	cout<<"stack 3: "<< stack3 << endl;
	cout<<"stack 4: "<< stack4 << endl;
	cout<<"stack 5: "<< stack5 << endl;
	cout<<"stack 6: "<< stack6 << endl;
	cout << "-------" << endl;
	stack2.push(7);
	stack2.push(8);
	stack5.pop();
	cout<<"stack 2 push(7), push(8): "<< stack2 << endl;
	cout<<"stack 2 tos: "<< stack2.get_tos() << endl;
	cout<<"stack 3 size: "<< stack3.size() << endl;
	cout<<"stack 4 [1]: "<< stack4[1] << endl;
	cout<<"stack 5 pop: "<< stack5 << endl;
	cout<<"stack 6 top: "<< stack6.top() << endl;
	
}

class randomClass{
	public:
	int val;
	randomClass(){
		this->val=0;
	}
	randomClass(int val){
		this->val=val;
	}
	randomClass(randomClass& other){
		this->val=other.val;
	}
};

void test_list(){
	MyList list(10); // size specified
	randomClass b(7);
	char c_arr[5] ="momo";

	list.push(5);
	list.push(5.5f);
	list.push(b);
	// list.push(1.1.1);
	list.push(1-4);
	list.push("hello");
	list.push(c_arr);
	// list.push(1.1/);
	// list.push(min123);
	// list.push(1.1.1);
	int x;
	float y;
	randomClass z;
	char *c_arr2;
	string s="intitial";
	
	list.get_at(x,0);
	list.get_at(y,1);
	list.get_at(z,2);
	list.get_at(x,3);
	list.get_at(s,4);
	list.get_at(c_arr2,5);
	cout << "x=" << x << "\ny=" << y << "\nz.val=" << z.val << endl << x << endl;
	cout << s <<endl;
	cout << c_arr2 << endl;
}

int main(){
    //test_complex();
    //test_string();
	//test_stack();
	test_list();
	return 0;
}