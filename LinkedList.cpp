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

class LinledList{
    Node* Head;
    Node* Tail;

    Node* Search(int data){
        Node* current = Head;

        while(current != NULL){
            if(current->data == data){
                return current;
            }
            else{
                current = current->next;
            }
        }

        return NULL;
    }
public:
    LinledList(){
        Head = Tail = NULL;
    }

    //Add node

    void Add(int data){
        Node* newNode = new Node(data);

        if(Head == NULL && Tail == NULL){
            Head = Tail = newNode;
        }else{

            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    //Display node
    void Display(){
        Node* current = Head;

        while(current !=NULL){
            cout<< current->data<<endl;
            current = current->next;
        }
    }

    void Delete(int data){
        Node* pdelete = Search(data);

        if(pdelete != NULL){
            //deleted node is the head
            if(pdelete == Head){
                if(pdelete == Tail){
                    Head = Tail =NULL;
                }else{
                    Head = Head->next;
                    Head->prev = NULL;

                }
            }

                // deleted node is tail
            else if( pdelete == Tail)
            {

                Tail = Tail->prev;
                Tail->next = NULL;

            }

                // deleted node is not head or tail
            else{
                pdelete->prev->next = pdelete->next;
                pdelete->next->prev = pdelete->prev;

            }
        }
    }

    void insertAftar(int prevData , int newData){
        Node* prevNode = Search(prevData);

        if(prevNode == Tail || prevNode == NULL){
            Add(newData);
        }else{
            Node* newNode = new Node(newData);

            newNode->prev = prevNode;
            newNode->next = prevNode->next;
            prevNode->next = newNode;
            newNode->next->prev = newNode;
        }
    }
};

int main(){
    LinledList li;
    li.Add(4);
    li.Add(5);
    li.Add(3);
    li.Display();
    cout<<"////////////////////////////////////////\n";
    li.Delete(5);
    li.insertAftar(4,6);
    li.Display();

    return 0;
}
