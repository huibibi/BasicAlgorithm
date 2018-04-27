#define BLACK 1
#define RED 0
#include <iostream>

using namespace std;

class bst {
public:

    struct Node {
        int value;
        bool color;
        Node *leftTree, *rightTree, *parent;

        Node() : value(0), color(RED), leftTree(NULL), rightTree(NULL), parent(NULL) { }        

        Node* grandparent() {
            if(parent == NULL){
                return NULL;
            }
            return parent->parent;
        }

        Node* uncle() {
            if(grandparent() == NULL) {
                return NULL;
            }
            if(parent == grandparent()->rightTree)
                return grandparent()->leftTree;
            else
                return grandparent()->rightTree;
        }

        Node* sibling() {
            if(parent->leftTree == this)
                return parent->rightTree;
            else
                return parent->leftTree;
        }
    };

    void rotate_left(Node* p){
        Node* par = p->parent; 
        if(par!=NULL){
            if(par->leftTree==p)par->leftTree=p->rightTree;
            else par->rightTree=p->rightTree;
            p->rightTree->parent=par;
        }
        else {
            root = p;
            p->rightTree->parent=NULL;
        }

        Node* rl = p->rightTree->leftTree;
        rl->parent=p;

        p->rightTree->leftTree=p;
        p->parent=p->rightTree;

        p->rightTree=rl;
    }

    void insert(int n){
        if(root==NULL){
            root = new Node();
            root->value = n;
            root->color = BLACK;
            root->leftTree = NIL;
            root->rightTree = NIL;
            
        }
        else{
            Node* p = root;
            Node* par = NULL;
            bool LeftOrRight = 0;
            while(p!=NIL){
                if(n<p->value){
                    par = p;
                    LeftOrRight = 0;
                    p = p->leftTree;
                }
                else{
                    par = p;
                    LeftOrRight = 1;
                    p = p->rightTree;
                }
            }

            p = new Node();
            p->value = n;
            p->leftTree = NIL;
            p->rightTree = NIL;
            p->parent = par;
            if(LeftOrRight)par->rightTree = p;
            else par->leftTree = p;
        }
        return;
    }
public:
    bst(){
        NIL = new Node();
        NIL->color = BLACK;
        root = NULL;
    }

    void inOrder(Node* node){
        if(node->leftTree&&node)inOrder(node->leftTree);
        cout<<node->value<<' ';
        if(node->rightTree&&node)inOrder(node->rightTree);
    }
    Node *root, *NIL;
};



int main(int argc, char const *argv[])
{
    bst b;
    b.insert(5);
    b.insert(2);
    b.insert(4);
    b.inOrder(b.root);
    return 0;
}