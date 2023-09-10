#include<iostream>
using namespace std;
int main(){
	int choice;
	float num1, num2;
	cout<<"Enter the first number."<<endl;
	cin>>num1;
	cout<<"Enter the second number."<<endl;
	cin>>num2;
	cout<< "Press the following keys to access the four operations respectively."<<endl;
	cout<<"1 for addition"<<endl;
	cout<<"2 for subtraction"<<endl;
	cout<<"3 for multiplication"<<endl;
	cout<<"4 for division"<<endl;
	cout<<"5 for exiting the calculator"<<endl;
	while (choice != 5){
	cout<<"Enter your choice."<<endl;
	cin>>choice;
	 switch (choice){
	 	case 1:
	 		cout<<"Addition:"<<num1+num2<<endl;
	 		break;
	 	case 2:
	 		cout<<"Subtraction:"<<num1-num2<<endl;
	 		break;
	 	case 3:
	 		cout<<"Multiplication:"<<num1*num2<<endl;
	 		break;	
	 	case 4:
	 		cout<<"Division:"<<num1/num2<<endl;
	 		break;
	 	case 5:
	 		cout<<"Program ended!"<<endl;
	 		break;
	 	default:
	    	cout<<"Invalid Input!"<<endl;
	 }
}
	return 0;
}
