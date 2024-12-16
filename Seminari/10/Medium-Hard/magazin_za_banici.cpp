#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Order
{
    int start, time, idx;
    bool operator <(const Order& other)
    {
        return this->start < other.start;
    }
};

struct compareIdx
{   //aко имаме едно и също време за изпълнение, взимаме по-малкия индекс (първата приета поръчка)
    bool operator()(const Order& f, const Order& s)
    {
         if (f.time == s.time)
            return f.idx > s.idx;
        return f.time > s.time; 
    } 
};

struct compareOrders 
{   
    bool operator()(const Order& f, const Order& s)
    {
        return f.start > s.start;
    }  
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int ordersCount;
    cin >> ordersCount;
    priority_queue<Order, vector<Order>, compareOrders> orders; //сортирани поръчки по начално време за изпълнение
    for(int i = 0; i < ordersCount; i++)
    {
        int start, time;
        cin >> start >> time;
        orders.push({start, time, i});
    }
        
    priority_queue<Order, vector<Order>, compareIdx> pending; //слагаме всяка поръчка, която към даден момент може да се обработи според времто за обработка или индекса
    int time = 1; //по условие започваме от време 1
    
    while(!orders.empty())
    {
        while(!orders.empty() && orders.top().start <= time) //добавяме тези, които може да се изпълнят към текущия момент
        {
            pending.push(orders.top());
            orders.pop();
        }

      //нямаме повече поръчки за приемане, следователно изпълняваме по приоритет всички в pending
        if(orders.empty() && !pending.empty())
        {
            while(!pending.empty())
            {
                cout << pending.top().idx << " ";
                pending.pop();
            }
            break;
        }
        //обработваме само 1 поръчка
        if(!pending.empty()){
            auto inProcess = pending.top();
            pending.pop();
            time += inProcess.time;
            cout << inProcess.idx << " ";
        }
        else //ако нямаме поръчки за обработване трябва да увеличим времето
            time++;
    }
        
    return 0;
}
