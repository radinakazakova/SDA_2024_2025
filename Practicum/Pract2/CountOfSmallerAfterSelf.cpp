//merge sort, защото работим с инверсии
class Solution {
public:

    void merge(int left, int mid, int right, vector<pair<int, int>>& arr,vector<int>& count)
    {
        vector<pair<int, int>> temp(right - left + 1);
        
        //s indexaciq w nachaloto na dwete polovini
        //iteratori
        int l = left;
        int m = mid + 1;
        int k = 0;

        //[6,5,2,1] [4,3,2,1] left = 0, right = 7, m = 3 + 1 = 4, mid=3
        while(l <= mid && m <= right)
        {
            if(arr[l].first <= arr[m].first) //stoinost
            {
                temp[k++] = arr[m++]; //sortirane v nishodqsht red
            }
            else
            {
                //shtom vlqvo imame po-golqmo chislo vdqsno vs sa po-malki, 
                //zashtoto otdqsno sa sortirani vuv nishodqsht red 
                //demek purvoto ako e po-malko vs sa po-malki nadqsno
                count[arr[l].second] += (right - m + 1); //right - m + 1 = kolko elementaimame otdqsno, vajno e che izpolzvame 'm' ne 'mid'
                
                temp[k++] = arr[l++];
            }
        }
        
        while(l <= mid)
        {
            temp[k++] = arr[l++];
        }
        
        while(m <= right)
        {
            temp[k++] = arr[m++];
        }
        
        for(int i = left; i <= right; i++)
            arr[i] = temp[i - left];
        
    }
                
    void mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int>& count)
    {
        if(left >= right)
        {
            return;
        }

        int mid = left + (right - left) / 2;
        
        mergeSort(left, mid, arr, count); //lqva
        mergeSort(mid + 1, right, arr, count); //dqsna
        
        merge(left, mid, right, arr, count);
    }
    
	vector<int> countSmaller(vector<int>& nums) {
	    
        int n=nums.size();
	    vector<pair<int, int>> arr; //pazim stoinost i na koj index sedi purvonachalno
        
	    for(int i = 0; i < n; i++)
	    {
	        arr.push_back({nums[i], i});
	    }
	    
	    vector<int> count(n, 0); //vrushtame
	    
	    mergeSort(0, n - 1, arr, count);
	    
	    return count;
	}
  
};
