//решение с дърво

class Tree { //това е node
    public:
    int start;
    int end;
    Tree* left;
    Tree* right;

    Tree(int s, int e) {
        start = s;
        end = e;
        left = NULL;
        right = NULL;
    }

    bool insert(int s, int e) {
        Tree* curr = this; //започваме винаги от root
        while(1) {
            if(s >= curr -> end) { //ако интервалът е след текущия, добавяме го в дясно (ако в дясно няма друг, ако има правим същите проверки)
                if(!curr -> right) {
                    Tree* node = new Tree(s, e);
                    curr -> right = node;
                    return true;
                }
                curr = curr -> right;
            }
            else if(e <= curr -> start) { //ако е преди текущия, добавяме го в ляво
                if(!curr -> left) {
                    Tree* node = new Tree(s, e);
                    curr -> left = node;
                    return true;
                }
                curr = curr -> left;
            }
            else{
                return false; //препокрива се
            }
        }
    }
};

class MyCalendar {
public:
    Tree* root;
    MyCalendar() {
        root = NULL;
    }
    
    bool book(int start, int end) {
        if(!root) {
            root = new Tree(start, end);
            return true;
        }
        return root -> insert(start, end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
