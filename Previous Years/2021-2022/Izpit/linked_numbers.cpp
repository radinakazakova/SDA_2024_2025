#include <bits/stdc++.h>
using namespace std;

size_t res = 0;

struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    
    Node *head, *tail;
};

void solve(LinkedList& num1, LinkedList& num2){
    
    if(!num1.head && !num2.head)
    {
        cout << 0;
        return;
    }

    Node* iter1 = num1.head;
    Node* iter2 = num2.head;
    
    stack<size_t> result;
    size_t remainder = 0;
    while(iter1 && iter2)
    {
        size_t sum = iter1->data + iter2->data + remainder;
        remainder = sum / 10;
        size_t digit = sum % 10;
        
        result.push(digit);
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    
    while(iter1)
    {
        size_t sum = iter1->data + remainder;
        remainder = sum / 10;
        size_t digit = sum % 10;
        
        result.push(digit);
        iter1 = iter1->next;
    }
    while(iter2)
    {
        size_t sum = iter2->data + remainder;
        remainder = sum / 10;
        size_t digit = sum % 10;
        
        result.push(digit);
        iter2 = iter2->next;
    }
    
    if(remainder)
        result.push(remainder);
    
    while(!result.empty())
    {
        cout << result.top();
        result.pop();
    }
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }
    
    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }
  
    solve(num1, num2);
}
