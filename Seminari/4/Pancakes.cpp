//времената на готвачите май са сортирани възходящо
#include <iostream>

using namespace std;

int cookerTime[10000000]{}; //за всеки готвач ще пазим времето тук

size_t calculatePossiblePancakes(size_t cookersCount, size_t time) {
    size_t currentSolutionPancakes = 0;
    for(size_t i = 0; i < cookersCount; i++) {
        currentSolutionPancakes += (time / cookerTime[i]);
    }
    return currentSolutionPancakes;
}

int main() {
    size_t neededPancakes, cookersCount;
    cin >> neededPancakes >> cookersCount;
    
    for(size_t i = 0; i < cookersCount; i++) {
        cin >> cookerTime[i];
    }
    
    size_t left = 0;
    size_t right = cookerTime[0] * neededPancakes; //макс ни е първия готвач за колко време ще направи палачинките, които искаме
    size_t solution = right;
    
    while(left <= right) {
        size_t midTime = left + (right - left) / 2; //избираме време по средата
        size_t currentSolutionPancakes = calculatePossiblePancakes(cookersCount, midTime); //колко палачинки може всеки от готвачите да направи за това време
        
        if(currentSolutionPancakes >= neededPancakes) { //всяко намерено решение, после намаляме интервала и намираме най-малкото време
            solution = midTime;
            right = midTime - 1;
        }
        else {
            left = midTime + 1;
        }
    }
    
    cout << solution;
}
