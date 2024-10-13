# Семинар №2 по СДА Деси- Определяне на сложност на алгоритми. Решаване на задачи.

Определете сложността:
<details>
<summary> 
  
```c++
void f(vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[0];
    }
}
```
</summary>    
О(1)
</details> 

<details>
<summary>
  
```c++
void f(vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[0];
    }
}
```
</summary> 
О(N) (? векторът се копира)
</details> 
<details>
<summary> 
  
```c++
void f(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = n + i - 5; j <= n; j++)
            cout << 1;
    }
}
```
</summary>    

О(N) + O(21) = О(N)- вътрешния цикъл се върти константен брой пъти
</details> 

<details>
<summary> 
  
```c++
void f(vector<int>& arr) {
    int n = arr.size();
    for (int i = n - 1; i >= 0; i /= 7) {
        cout << 1;
    }
}
```
</summary>    

O(logN)
</details> 

<details>
<summary> 
  
```c++
void f(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << 1;
    }
    for (int i = 1; i > n; i *= 2) {
        cout << 1;
    }
}
```
</summary>    

O(N)
</details> 

<details>
<summary> 
  
```c++
int f(int n) {
    if (n <= 0)
        return 0;
    return 1 + f(n - 1);
}
```
</summary>    

O(N)
</details> 

<details>
<summary> 
  
```c++
int f(int n) {
    if (n <= 0)
        return 0;
    return 1 + f(n/2);
}
```
</summary>    

O(logN)
</details> 
