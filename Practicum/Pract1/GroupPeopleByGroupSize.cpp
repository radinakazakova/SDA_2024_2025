
// O(N^2) solution
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>sol;
        for(int i=1;i<=n;i++){ //цикъл за бройката хора
            vector<int> ans;
            for(int j=0;j<n;j++){ //за всяка бройка добавяме човек във вектор, докато не се напълни
                if(ans.size() == i){ //пълни се, добавяме го, изпразваме го
                    sol.push_back(ans);
                    ans.clear();
                }
                if(groupSizes[j]==i){ //събираме група от хора и ги добавяме към вектора
                    ans.push_back(j);
                }
            }
            if(ans.size()) sol.push_back(ans); //ако сме извършвали да го добавим се добавя тук (?)
        }
        return sol;
    }
};
