#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int _data){
        data =_data;
        right = left = NULL;
    }
};


class BST
{
private:


    void Display(Node* pdisplay){

        if(pdisplay == NULL)
            return;
        Display(pdisplay->right);
        cout<<pdisplay->data << "\t";
        Display(pdisplay->left);
    }


    Node* Search(int data){
        Node* pSearch = root;

        while(pSearch != NULL){
            if(pSearch-> data == data){
                return pSearch;
            }else if(data > pSearch->data){
                pSearch = pSearch->right;
            }else{
                pSearch = pSearch->left;
            }
        }

        return NULL;

    }

    Node* GetMaxRight(Node* child){

        while(child->right != NULL){
            child = child->right;
        }

        return child;

    }
public:
    Node* root;
    BST(){
        root =NULL;
    }

     Node* GetMaxLeft(Node* child){
        while(child->left != NULL){
            child = child->left;
        }

        return child;

    }

     int GetMaxLeft(){
        Node* child= root;
        while(child->left != NULL){
            child = child->left;
        }

        return child->data;

    }
   void Add(int data){
       Node* newNode = new Node(data);
        if(root == NULL){
            root = newNode;
        }else{

            Node* current = root;
            Node* parent;

            while(current != NULL){

                  parent = current;

                if(data < current->data){
                    current = current->left;
                }else{
                    current = current->right;
                }
            }

            if(data > parent->data){
                parent->right = newNode;
            }else{
                parent->left = newNode;
            }

        }
   }

    void Traverse(){
        Display(root);
        cout<<endl;
    }

    void Traverse(int data){
        Node* node = Search(data);

        Display(node);
        cout<<endl;
    }

Node* Delete(Node* root, int k) {
        if (root == NULL)
            return root;

        if (root->data > k) {
            root->left = Delete(root->left, k);
            return root;
        } else if (root->data < k) {
            root->right = Delete(root->right, k);
            return root;
        }

        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else {

            Node* succParent = root;

            Node* succ = root->right;
            GetMaxLeft(succ)->left=root->left;
            delete succParent;
            return succ;
        }
    }
};


int main()
{
    BST tree;

    tree.Add(50);
    tree.Add(30);
    tree.Add(25);
    tree.Add(45);
    tree.Add(60);
    tree.Add(70);
    tree.Add(10);
    tree.Add(15);
    tree.Add(35);
    tree.Traverse();
    cout << endl<< "------------------" << endl;
    tree.Delete(tree.root,30);
    tree.Traverse();
    cout << endl<< "------------------" << endl;
    tree.Delete(tree.root,10);
    tree.Traverse();
    cout << endl<< "------------------" << endl;
    tree.Delete(tree.root,45);
    tree.Traverse();
    cout << endl<< "------------------" << endl;
    cout << "Minimum Number: "<<tree.GetMaxLeft()<<endl;


    return 0;
}