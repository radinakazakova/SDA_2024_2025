//рекурсивно добавяме по-ниското ниво към по-високото, като намираме неговия head и го свързваме към parent
//ако има нужда свързваме следващия след parent с края на по-ниското ниво
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while(curr)
        {
            if(curr->child)
            {
                Node* next = curr->next;
                Node* toAdd = flatten(curr->child); //рекурсивно взимаме долния ред
                curr->next = toAdd; //svurzvame gi v nachaloto (parent s child)
                curr->child = nullptr;
                toAdd->prev = curr;

                if(next)
                {
                    while(toAdd->next)//da svurjem i v kraq (next s poslednoto ot dolniq level) 
                    {
                        toAdd = toAdd->next;
                    }
                    next->prev = toAdd;
                    toAdd->next = next;
                }
            }
            curr = curr->next;
        }
        //като стигнем последния ред няма да се изпълни нищо ит if-a (няма повече деца) и ще дойдем тук
        return head;
    }
};
