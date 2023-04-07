#include <iostream>
#include <cmath>
using namespace std;

//a function that calculates the corresponding value of y for a given x

float f(float x){
	float y = (x*x*x) - (3*x) + 1;
	return y;
}
int main(int argc, char** argv) {
	float a,b,e,m1,parameter,diff[50],difference;
	int i = 1;            
	cout<<"Solve the root of the equation: X^3 - 3X + 1"<<endl;
	cout<<"Enter values:"<<endl<<"a => f(a) < 0, "<<endl<<"b => f(b) > 0 and"<<endl<<"e => error of tolerance"<<endl<<"-------------------------------------"<<endl;
	start:cout<<"Enter a: ";                             
	cin>>a;
	cout<<"Enter b: ";                                   
	cin>>b;
	cout<<"Enter the error of tolerance: ";                       
	cin>>e;
	parameter = f(a)*f(b);
	cout<<"Parameter: "<<parameter<<endl;               
	
	if(parameter>=0){
		cout<<"The inputs aren't valid! Try again..."<<endl;
		cout<<"-------------------------------------"<<endl;
		goto start;
	}else{
		cout<<"The inputs are valid."<<endl<<"-------------------------------------"<<endl;
	diff[0] = a; 
	m1 = b - ((f(b)*(b-a))/(f(b) - f(a))); 
	difference = m1 - a;
	
while(difference >= e){                            
	diff[i] = m1;
	cout<<"*"<<"C"<<"["<<i<<"]="<<m1<<endl;
	cout<<"f("<<m1<<")="<<f(m1)<<endl;

	if(f(m1) == 0){
		cout<<"The root is " << m1;
	}else if(f(m1)*f(a)<0){
		b = m1;
		cout<<"range ["<<a<<","<<b<<"]"<<endl;
	}else {
		a = m1;
		cout<<"range ["<<a<<","<<b<<"]"<<endl;
	}
   cout<<"Difference: "<<difference<<endl;                 
   cout<<"-------------------------------------"<<endl;
   i++;
   m1 = b - ((f(b)*(b-a))/(f(b) - f(a)));
   diff[i] = m1;
   difference = fabs(diff[i] - diff[i-1]);
}
cout<<"*"<<"C"<<"["<<i<<"]="<<m1<<endl;
cout<<"f("<<m1<<")="<<f(m1)<<endl;
cout<<"*** DIFFERENCE : "<<difference<<" < "<<e<<endl;
cout<<"*** THE ROOT IS : " <<m1<<endl;
cout<<"PROOF: f("<<m1<<")"<<" = "<<f(m1)<<" appr. = 0";                   
}
	return 0;
}
