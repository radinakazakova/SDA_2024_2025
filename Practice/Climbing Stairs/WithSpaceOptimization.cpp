//използва 2 индекса prev и curr (първоначално base cases), за да не пази всички изчисления
//пазим curr(което в края на итерацията вече ще е предното изчисление, тоест prev) в temp и смятаме най-новото изчисление в него (защото е сегашно)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};
