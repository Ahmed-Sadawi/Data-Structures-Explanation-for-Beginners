#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class simpleQu 
{
private:
  int* arr;
  int size;
  int front =-1;
  int rear = -1;
public:
   simpleQu(int n ) : size(n){
    arr = new int[size];
   }

   ~simpleQu() {
       delete[] arr;
   }
   bool empty(){
     return (front ==-1 || front > rear );
   }

   void Enqu(int val){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        arr[rear] = val;
    }
    else if(rear < size-1){
        rear++;
        arr [rear] = val;
    }else cout<<" The Queue is full "<<endl;
   }

   int Dequ(){
    if(empty()) {
        cout<<"The queue is empty!"<<endl;
        return -1;
    }
    else {
        return arr[front++];
    }
   }

   void displ(){
    if(!empty()){
        for(int i =front; i<=rear; i++){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
   }
};

int main (){
    int n;
    cout<<"What size do you need for the Queue?"<<endl;
    cin>>n;
    simpleQu q1(n);
    q1.Enqu(2);
    q1.Enqu(5);
    q1.Enqu(9);
    q1.displ();
    q1.Dequ();
    q1.displ();
  //Try each possibility yourself.
}


