//Използваме двоен свързан списък, защото искаме да премахваме с О(1) от всяко място в списъка
//Отделно за да разберем дали в списъка има вече дадено value, ще пазим в масив за всеки пакет дали имаме пойнтър в списъка
//Така намираме дали е вътре за О(1) (като bool counting, но само с пойнтъри, за да го достъпваме, ако е в списъка вече) вместо да търсим линейно за О(n)
#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;
    Node(int v) : value(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), size(0){}
    int getSize()
    {
        return size;
    }
    
    Node* getHead()
    {
        return head;
    }
    
    Node* getTail()
    {
        return tail;
    }
    
    void pop_front()
    {
        if(!head)
            return;
        
        size--;
        
        if(head == tail){
            Node* temp = head;
            head = tail = nullptr;
            delete temp;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    
    void pop_back()
    {
        if(!head)
            return;
        
        size--;
        if(head == tail){
            head = tail = nullptr;

            delete tail;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    
    void push_front(int value)
    {   
        Node* newNode = new Node(value);
               
        size++;
        if(!head){
            head = tail = newNode;
            return;
        }
 
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
    }
    
   void remove(Node* node) //1 ot prichinite da predpochetem doubly, mojem s O(1) da premahvame izvun kraishtata
   {
       if(head == node){
           this->pop_front();
           return;
       }
       if(node == tail)
       {
            this->pop_back();
            return;
       }

       size--;
       Node* temp = node;
       node->prev->next = node->next;
       node->next->prev = node->prev;
       delete temp;
   }
    
};

//dali go ima daden node shte pazim v masiv
Node* nodes[100000];
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int queries, maxPackets;
    cin >> queries >> maxPackets;

    DoublyLinkedList list;
    for (int i = 0; i < queries; i++) {
        int packet;
        cin >> packet;
        
        Node* currNode = nodes[packet];
        
        //veche go ima v spisuka
        if(currNode){ 
            cout << "true" << "\n";
            list.remove(currNode);
            list.push_front(packet);
            continue;
        }
        //nqma go v spisuka
        cout << "false" << "\n";
        if(list.getSize() == maxPackets) //stignali sme maksimalniq broi paketi
        {   //mahame posledniq
            Node* listTail = list.getTail();
            nodes[listTail->value] = nullptr;
            list.pop_back();
        } 
        
        list.push_front(packet);
        Node* listHead = list.getHead();
        nodes[packet] = listHead;
    }

    return 0;
}
