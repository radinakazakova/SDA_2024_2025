#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>

//копиран клас от предните задачи
class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

//с рекурсия ще се местим в списъка и ще обръщаме, като ще подаваме и последния преместен отзад node - 'lastlastNode', в началото няма такъв следователно подаваме nullptr
SinglyLinkedListNode* reverseK(SinglyLinkedListNode* head, int k, SinglyLinkedListNode* lastLastNode)//prev e beforeLeft
{
    if(!head) //ако е nullptr, значи сме стигнали място, при което няма повече елементи нататък след 'head'
    {
        return head;
    }
    if(k == 1)
        return head;
    
    SinglyLinkedListNode* headCopy = head; //копие, за да не го изгубим, тъй като то винаги ще бъде последния преместен отзад node
    SinglyLinkedListNode* left = head;
    SinglyLinkedListNode* afterRight = head;
    int kCopy = k;
    while(kCopy && afterRight)
    {
        afterRight = afterRight->next;
        kCopy--;
    }
    
    if(kCopy && !afterRight) //ако не сме изчерпали итерациите на к, но сме излезли от цикъла, следователно елементите не са кратни на к
    {
        return head;
    }
    
    SinglyLinkedListNode* prev = afterRight;
    while(left != afterRight) // reverse-ваме
    {
        SinglyLinkedListNode* next = left->next;
        left->next = prev;
        prev = left;
        left = next;
    }
    if(lastLastNode) //ако сме имали reverse преди този, който сме направили сега, свързваме края му с текущото начало на този reverse
    {
        lastLastNode->next = prev; //prev is new first node after reversing - just in the current recursion step
    }
    reverseK(afterRight, k, headCopy); //продължааваме нататък
    return prev; //при първия reverse новия head ще бъде prev, затова го връшаме след изпълнение на всички стъпки от рекурсията надолу
}

int main() {
    int N;
    cin >> N;
    SinglyLinkedList* list = new SinglyLinkedList();

    for(int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        list->insert_node(val);
    }
    
    int k;
    cin >> k;
    
    list->head = reverseK(list->head, k, nullptr); //ще върнем само head-a от първото извикване след изпълнение на цялата рекурсия
    
    print_singly_linked_list(list->head, " ", cout);
    
    return 0;
}
