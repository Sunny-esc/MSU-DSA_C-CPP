//3. Reimplement Q-1 in C++ using a class-based approach.
//program to implement a stack using an array with the following operations:
//1. push()
//2. pop()
//3. peek()
//4. display()

#include<iostream>
using namespace std; 

class Stack{
public:
  //fuctions delcareation 
  void push(int );
  void pop();
  void peek();
  void display();

private:
  //delcareation of stack and top
  static const int max =11;
  int top =-1;
  int stack[max];
   
};

void Stack::push(int data){
  if (top == max) {
    cout <<"The stack is Full ";
    return;
    
  }
  top++;
  stack[top]=data;


}
void Stack::pop(){
 if (top == -1) {
   cout<<"The stack is empty";
   return;
    
  } 
 top--;
}

void Stack::peek(){
  
   if (top == -1) {
   cout<<"The stack is empty";
    return;
  } 
  cout<<"The top is = "<<stack[top];

}
void Stack::display(){
  
   if (top == -1) {
   cout<<"The stack is empty";
   return;
    
  } 
  cout<<"The Stack is = "<<endl;
  for (int i = 0; i <= top; i++) {
    cout<<stack[i]<<"->";
    
  }

}


int main(){
  int choice,data;
  Stack opp;
  do {
    cout<<"1.Push"<<endl;
    cout<<"2.pop"<<endl;
    cout<<"3.peek"<<endl;
    cout<<"4.abort"<<endl;


    cout<<"Enter the choice"<<endl;
    cin>>choice;
    switch (choice) {
      case 1:
        cout<<"Enter the data=";
        cin>>data;
        opp.push(data);
        cout<<"Done"<<endl;
        break;
      case 2:
        cout<<"POPING element";
        opp.pop();
        break;
      case 3:
        cout<<"peek";
        opp.peek();
        break;

      case 4:
        cout<<"exit";
        break;
      case 5:
        cout<<"display ="<<endl;
        opp.display();
        break;
      
    }
  } while(choice !=4);
return 0;

}
