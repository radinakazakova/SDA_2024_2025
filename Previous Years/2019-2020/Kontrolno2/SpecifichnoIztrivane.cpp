#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    Node * next;
    int data;
    Node(Node* _next,int _data){
        next = _next;
        data = _data;
    }
};
class LinkedList{
    public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* tmp;
        while(head!=NULL){
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void add(int number){
        Node *tmp = new Node(head,number);
        head = tmp;
    }
    void print(){
        Node* curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    
    void remove(Node* toRemove, Node* prev)
    {
        if(!prev)//znachi toRemove e head 
        {
            head = head->next;
            delete toRemove;
            return;
        }
        
        prev->next = toRemove->next;
        delete toRemove;
    }
    
    void removeComplex(int devidedBy)
    {
        //  TODO: write your code here 
        
        Node* iter = head;
        if(!head)
            return;
        Node* prev = nullptr;
        
        while(iter)
        {
            if(iter->data % devidedBy == 0)
            {
                Node* toDelete = iter; //важно е да запазим текущия тук
                iter = iter->next; //за да може да преминем на следващия, тъй като ще го изтрием и няма да може да достъпим следващия
                remove(toDelete, prev);

            }
            else
            {
                prev = iter;
                iter = iter->next;
            }
        }
      
    }
    // end removeComplex
    private:
    Node* head;
};
int main(){
    LinkedList l;

    int n;
    cin >> n;
    int number;
    for(int i = 0 ; i < n ; i++){
        cin >>number;
        l.add(number);
    }
    int devidedBy;
    cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();
}
