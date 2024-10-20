#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    cin>>N;
    vector<int> nums1;
    vector<int> nums2;
    
    for(int i = 0; i < N; i++)
    {
        int num;
        cin>>num;
        nums1.push_back(num);
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int num;
        cin>>num;
        nums2.push_back(num);
    }
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int sum = 0;
    int index1 =0;
    int index2 = 0;
    
    while(index1 < N && index2 < M)
    {
        if(nums1[index1] == nums2[index2])
        {
            int curr = nums1[index1];
            sum += nums1[index1];    
            
            //propuskame duplicates
           while (index1 < N && nums1[index1] == curr) {
                index1++;
            }

            while (index2 < M && nums2[index2] == curr) {
                index2++;
            }
        } else if(nums1[index1] < nums2[index2])
            index1++;
        else
            index2++;
    }
    cout << sum;
    return 0;
}
