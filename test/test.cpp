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
    }else cout<<" The Queue is fill ";
   }

   int Dequ(){
    if(empty()) {
        cout<<"The queue is empty!";
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

class CirQu 
{
  private:
    int* arr;
    int size;
    int front = -1;
    int rear = -1;
  public:
    CirQu(int n) : size(n){
        arr = new int[size];
    } 
    ~CirQu(){
        delete[] arr;
    }
    bool empty(){
        if(front == -1 && rear == -1) return true;
        return false;
    }
    bool full(){
        if((rear == size-1 && front == 0) || (front == rear+1)) return true;
        return false;
    }
    void Enqu(int val){
        if(full()){
            cout<<"Queue is full";
            return;
        }
        else if(empty()){
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else {
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
    }
    int Dequ(){
        if(empty()){
            cout<<"Queue is empty";
            return -1;
        }
        int x = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        return x;
    }
    int peek(){
       if(empty()){
           cout <<"Empty";
           return -1;
       }
       return arr[front];
    }
    void disp(){
        if(empty()){
            cout <<"Empty";
            return;
        }
        if(front <= rear){
            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<" ";
            }
        }
        else {
            for(int i = front; i < size; i++){ cout<<arr[i]<<" "; }
            for(int i = 0; i <= rear; i++){ cout<<arr[i]<<" "; }
        }
    }
};


int main (){
    simpleQu q1(5);
    q1.Enqu(2);
    q1.Enqu(5);
    q1.Enqu(9);
    q1.displ();
    q1.Dequ();
    q1.displ();
    
}