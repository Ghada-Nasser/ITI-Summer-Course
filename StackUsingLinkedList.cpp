#include <iostream>
using namespace std;
class Node{
public:

    int data;
    Node* prev;

    Node(int _data){
        data = _data;
        prev = NULL;
    }
};
class StackUsingLinkedList
{
private:
    Node* Top;
public:
    StackUsingLinkedList(){
        Top = NULL;
    }

    // push new element

    void Push(int data){
        Node* newNode = new Node(data);

        if(Top == NULL){
            Top = newNode;
        }else{
            newNode->prev = Top;
            Top = newNode;
        }
    }

    void Pop(){
        if(Top == NULL)
            cout<< "Stack is empty"<<endl;
        else{
            Node* temp = Top;
            Top = Top->prev;
            delete temp;
        }

    }

    void Display(){
        Node* Current = Top;

        while(Current != NULL){
            cout<< Current->data<<endl;
            Current = Current->prev;
        }

    }

};
int main()
{

    StackUsingLinkedList stk;
     stk.Push(4);
    stk.Push(3);
    stk.Push(566);
    stk.Display();
    cout<<"///////////////////////////////////////\n";
    stk.Pop();
     stk.Display();





    return 0;
}
