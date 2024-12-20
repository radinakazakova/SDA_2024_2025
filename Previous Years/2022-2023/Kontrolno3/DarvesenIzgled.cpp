//От Георги
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    int depth = 0;
    
    Node(int val){
        this->value = val;
    }
};

int MIN_INDEX = 0;
int MAX_INDEX = 1999999;
Node* container[2000000] = { nullptr }; //пазим всички изгледи отгоре тук

Node* insert(Node* root, int key){ //изпозваме за да конструираме цялото дърво
    if(!root)
        return new Node(key);
    
    if(root->value > key){
        root->left = insert(root->left, key);
    } else if(root->value < key){
        root->right = insert(root->right, key);
    }
    
    return root;
}

void dfs(Node* current, int number, int depth = 0){ //започваме от root и number = 1 000 000 - демек по средата е
    if(!current)
        return;
    
    dfs(current->left, number - 1, depth + 1);
    dfs(current->right, number + 1, depth + 1);
    
    
    if(!container[number]){ //ако не сме добавили в масива, добавяме
        container[number] = current;
        current->depth = depth;
        if(MIN_INDEX > number){
            MIN_INDEX = number;
        }
        if(MAX_INDEX < number){
            MAX_INDEX = number;
        }
    }
    if(container[number] && container[number]->depth > depth){ //тъй като използваме dfs ще добавяме отдолу нагоре, тоест ако намерим по вертикала(number) че имаме node по-нагоре в дървото (depth), го добавяме вместо текущото
        container[number] = current;
        current->depth = depth;
        if(MIN_INDEX > number){
            MIN_INDEX = number;
        }
        if(MAX_INDEX < number){
            MAX_INDEX = number;
        }
    }
}

void clear(){
    for(int i = MIN_INDEX; i <= MAX_INDEX; i++){
        container[i] = nullptr;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int count;
    cin>>count;
    for(int i = 0; i < count; i++){
        int l;
        cin>>l;
        
        Node* root = nullptr;
        for(int j = 0; j < l; j++){
            int value;
            cin>>value;
                
            if(!root){
                root = new Node(value);
            } else {
                root = insert(root, value);
            }
        }
        
        dfs(root, 1000000);
        
        for(int q = MIN_INDEX; q <= MAX_INDEX; q++){
            if(container[q]){
                cout << container[q]->value << " ";
            }
        }
        cout<<"\n";
        clear(); //изчистваме контейнера

      //Актуализираме индексите за следващото дърво
        MIN_INDEX = 0; 
        MAX_INDEX = 1999999;
    }
    
    return 0;
}
