//пазим си пойнтър mid заради команда milen - като е важно да внимаваме как пресмятаме къде ще се намира той
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
   size_t value = 0;
   Node* prev = nullptr; 
   Node* next = nullptr;  
    
    Node(size_t val): value(val), prev(nullptr), next(nullptr){}
};

struct List
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;

    size_t count = 0;
public:
    
    void print()
    {
        cout << count << '\n';
        Node* iter = head;
        while(iter)
        {
            cout << iter->value << ' ';
            iter=iter->next;
        }
        cout << '\n';
    }
    void pop_back()
    {
        if(count == 0)
            return;
        if(count == 1)
        {
            head = tail = mid = nullptr;
            count--;
            return;
        }
        
        Node* prev = tail->prev;
        prev->next = nullptr;
        tail = prev;
        count--;
         if(count%2==1 && count!=1)
        {
           mid = mid->prev; 
        }
    }
    
    void push_back(size_t val)
    {
        if(count == 0)
        {
            Node* newNode = new Node(val);
            head = tail = newNode;
            mid = head;
            count++;
            return;
        }
        Node* newNode = new Node(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        count++;
        
        //ako e cheten se otmestva nalqvo. pri necheten e s edin po-malko v lqvata chast(demek ne go otmetvame)
        if(count%2==0 && count!=2)
        {
            mid = mid->next;
        }
    }
    void moveHalf()
    {
        if(count == 0 || count == 1)
            return;
        if(count==2) //разменяме head и tail
        {
             Node* temp = head;
             head = tail;
             tail = temp;
             head->prev = nullptr;
             head->next = tail;
             tail->prev = head;
             tail->next = nullptr;
             mid=head;
             return;
        }
        //иначе правим нова глава - началото на втората половина, опашка - края на първата половина (mid)
        //свързваме предишните глава и опашка, за да са последователни
        //зануляваме новите
        //пресмятаме mid - промяна само при нечетен брой (по-големия брой са били отдясно, но отиват отляво - трябва да се мръднем назад)
        Node* newHead = mid->next;
        Node* newTail = mid;
        tail->next = head;
        head->prev = tail;
        newHead->prev = nullptr; 
        newTail->next = nullptr;
        mid = tail;
        if(count%2==1)
        {
            mid=mid->prev;
        }
        head = newHead;
        tail = newTail;

    }
};

char input[10];

int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int queries;
    cin>>queries;
    List list;
    for(int i = 0; i < queries;i++)
    {
        cin >> input;
        if(input[0] == 'a')
        {
            size_t val;
            cin >> val;
            list.push_back(val);
        }
        else if(input[0] == 'g')
        {
            list.pop_back();
        }
        else if(input[0] == 'm')
        {
            list.moveHalf();
        }
    }
    list.print();
    return 0;
}
