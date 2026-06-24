#include<iostream>
using namespace std;

class Queue{
public:
    int arr[5];
    int front;
    int rear;

    Queue(){
        front = 0;
        rear = -1;
    }

    void push(int val){
        if(rear == 4){
            cout << "Queue is Full!" << endl;
            return;
        }

        rear++;
        arr[rear] = val;
    }

    int pop(){
        if(front > rear){
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int x = arr[front];
        front++;
        return x;
    }

    int peek(){
        if(front > rear){
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return arr[front];
    }

    int size(){
        return rear - front + 1;
    }

    void display(){
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.display();

    cout << q.pop() << endl;

    q.display();

    cout << q.peek() << endl;
}