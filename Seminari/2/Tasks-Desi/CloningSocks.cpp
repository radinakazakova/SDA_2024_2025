#include <iostream>

int myAbs(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    int T, cpy, norm;std::cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        std::cin >> cpy >> norm; // induction by count of normal socks
        if (norm <= 0)
        {
            std::cout << "no\n";
        }
        if (norm == 1)
        {
            if (cpy == 0)
            {
                std::cout << "yes\n";
            }
            else
            {
                std::cout << "no\n";
            }
        }
        if (norm >= 2)
        {
            if (norm-cpy>=2) //нормалните не може да са с 2 повече щото в най-добрия случай, като добавяме нормален добавяме и копие (а започваме с 1 копие и 2 нормални)
            {
                std::cout << "no\n";
            }
            else //при четен брой нормални, копията са нечетни. при нечетен брой нормални, копията са четни
            {
                if (myAbs(cpy - norm) & 1)
                {
                    std::cout << "yes\n";
                }
                else
                {
                    std::cout << "no\n";
                }
            }
        }
    }
    return 0;
}
