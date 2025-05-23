# Семинар №1 по СДА Деси - Сложност на алгоритми.
## Алгоритъм
Алгоритъм ще наричаме последователност от стъпки за решаването на даден проблем. 

![image](https://github.com/user-attachments/assets/d10b77cd-ba84-42aa-a240-9e9c27f0e7bd)

## Структура от данни
Структура от данни ще наричаме начин за организирането на данните в удобен за употреба формат. 

![1707338627247](https://github.com/user-attachments/assets/e194fdd1-9feb-4bb2-bef3-72d45593b8a2)


## Сложност
Сложността на алгоритмите е ключов аспект в компютърните науки, който определя ефективността на алгоритъма по отношение на времето и паметта, които използва. 
Определянето на сложността помага при избора на най-добрия алгоритъм за дадена задача, като се има предвид времевите ограничения и наличните ресурси. 
Основните видове сложност са сложност по време и сложност по памет.

### Сложност по време
Сложността по време се определя от **броя стъпки**, необходими за изпълнението на алгоритъма. Тя описва как броят на стъпките нараства с увеличаване на размера на входните данни. 
При анализа на времевата сложност на алгоритмите е важно да се разглеждат различни сценарии, които могат да се случат по време на изпълнението на алгоритъма. Най-често използваните типове времева сложност са:
- `Best-Case`
- `Worst-Case`
- `Average-Case`
- `Амортизирана сложност`

Амортизираната сложност разглежда средното време за изпълнение на операция, когато тя се изпълнява многократно в поредица. Това е полезно при анализиране на операции, при които една скъпа операция се компенсира от множество евтини операции.
Например при добавяне на елемент в динамичен масив (vector) в C++, ако масивът е пълен, размерът му се удвоява, което е скъпа операция. Обаче, тази скъпа операция се случва рядко. Затова амортизираната сложност за *push_back* в `std::vector` е O(1), въпреки че в най-лошия случай е O(n).

#### Примери за времева сложност в контекста на броя стъпки

- O(1) - константна сложност

```c++
void printFirstElement(const int* arr, size_t size) {
    std::cout << arr[0] << std::endl;  // 1 стъпка
}
```

- O(n) - линейна сложност

```c++
void printAllElements(const int* arr, size_t size) {
    for (int i = 0; i < size; i++) {   // n стъпки
        std::cout << arr[i] << std::endl;
    }
}
```

- O(log n) - логаритмична сложност

```c++
int binarySearch(const int* arr, size_t size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {   // Логаритмичен брой стъпки
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
```

- O(n*log n) - линейно-логаритмична сложност

```c++
void printIndexes(const int* arr, size_t size) {
    for (int i = 0; i < size; i++) {   // n стъпки
        std::cout << binarySearch(arr, size, arr[i]) << std::endl; //log n стъпки на всяка итерация
    }
}
```

- O(n^2) - квадратична сложност

```c++
void printAllPairs(const int* arr, size_t size) {
    for (int i = 0; i < size; i++) {       // n стъпки
        for (int j = 0; j < size; j++) {   // n стъпки за всяка от n стъпките
            std::cout << arr[i] << " " << arr[j] << std::endl;  // Общо n * n = n^2 стъпки
        }
    }
}
```

### Сложност по Памет
Сложността по памет измерва количеството памет, необходимо за изпълнението на алгоритъма в зависимост от размера на входните данни.

#### Примери
- O(1) - Константна сложност по памет - алгоритъмът използва фиксирано количество памет, независимо от размера на входа.

```c++
int sumArray(const int* arr, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
```

- O(n) - Линейна сложност по памет - паметта, необходима за алгоритъма, нараства линейно с размера на входа.

```c++
int* createArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin >>arr[i];
    }
    return arr;
}
```


-------------------------------------------------------------------------------------
❗За задачите ще са ви необходими структурите `std::string`, `std::pair` и `std::vector`, като повече за техните методи ще намерите тук:
- [**string**](https://en.cppreference.com/w/cpp/string/basic_string)
- [**pair**](https://en.cppreference.com/w/cpp/utility/pair)
- [**vector**](https://en.cppreference.com/w/cpp/container/vector)
