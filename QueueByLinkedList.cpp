#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int _data){
        data = _data;
        prev = next = NULL;
    }
};

class Queue
{
private:
    Node* Front;
    Node* Rear;

public:
    Queue(){
        Front = Rear = NULL;
    }

    //Add element to queue
    void EnQueue(int data){

        Node* newNode = new Node(data);

        if(Front ==NULL && Rear == NULL){
            Front = Rear = newNode;
        }else{
            Rear->next = newNode;
            newNode->prev=Rear;
            Rear = newNode;
        }
    }


    //remove element from queue
    void Dequeue(){
        Node* temp = Front;
        Front = Front->next;
        Front->prev=NULL;
        delete temp;
    }


    void Display(){
        Node* current = Front;
        while(current != NULL){
            cout<<current->data<<endl;
            current = current->next;
        }

    }
    void Display_front(){

        cout<<Front->data<<endl;

    }
    void Display_Reverse(){
        Node* current = Rear;
        while(current != NULL){
            cout<<current->data<<endl;
            current = current->prev;
        }

    }
    void size(){
        Node* current = Rear;
        int cnt=0;
        while(current != NULL){
            cnt++;
            current = current->prev;
        }
        cout<<cnt<<"\n";

    }
};

int main()
{

    Queue Q;

    Q.EnQueue(5);
    Q.EnQueue(3);
    Q.EnQueue(7);
    Q.EnQueue(1);
    Q.Display();
    cout<<"//////////////////////////////////////////////\n";
    Q.Dequeue();
    Q.Display();
    cout<<"//////////////////////////////////////////////\n";
    Q.Display_front();
    cout<<"//////////////////////////////////////////////\n";
    Q.Display_Reverse();
    cout<<"//////////////////////////////////////////////\n";
    Q.size();

    return 0;
}