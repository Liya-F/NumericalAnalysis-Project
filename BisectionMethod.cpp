#include <iostream>
#include <cmath>
using namespace std;

//a function that calculates the corresponding value of y for a given x

float f(float x){
	float y = (x*x*x) - (5*x) + 3;
	return y;
}
int main(int argc, char** argv) {
	float range[2],e,m1,parameter;
	int i = 0;               //iterator-used to count the number of iterations 
	cout<<"Solve the root of the equation: X^3 - 5X + 3"<<endl;
	cout<<"Enter values:"<<endl<<"a => f(a) > 0, "<<endl<<"b => f(b) < 0 and"<<endl<<"e => error of tolerance"<<endl<<"-------------------------------------"<<endl;
	start:cout<<"Enter a: ";                             
	cin>>range[0];
	cout<<"Enter b: ";                                   
	cin>>range[1];
	cout<<"Enter the error of tolerance: ";              //accept a,b,e           
	cin>>e;
	parameter = f(range[0])*f(range[1]);
	cout<<"Parameter: "<<parameter<<endl;                //parameter: used to check whether the inputs are valid or not
	
	if(parameter>=0){
		cout<<"The inputs aren't valid! Try again..."<<endl;
		cout<<"-------------------------------------"<<endl;
		goto start;
	}else{
		cout<<"The inputs are valid."<<endl<<"-------------------------------------"<<endl;
	
	
while(fabs((range[1] - range[0]))>= e){                               //the code block loops as long as the difference of between range[0] and range[1] is >= e
    i++;
	m1 = (range[0] + range[1])/2;
	cout<<"*"<<"Mid"<<"["<<i<<"]="<<m1<<endl;
	cout<<"f("<<m1<<")="<<f(m1)<<endl;

	if(f(m1) == 0){
		cout<<"The root is " << m1;
	}else if(f(m1)>0){
		range[0] = m1;
		cout<<"range ["<<range[0]<<","<<range[1]<<"]"<<endl;
	}else {
		range[1] = m1;
		cout<<"range ["<<range[0]<<","<<range[1]<<"]"<<endl;
	}
   cout<<"Difference: "<<fabs(range[1] - range[0])<<endl;                  //it gets out of the loop when the root is found
   cout<<"-------------------------------------"<<endl;
}
cout<<"The root is: " <<m1<<endl;
cout<<"PROOF: f("<<m1<<")"<<" = "<<f(m1)<<" appr. = 0";                   
}
	return 0;
}
