#include<bits/stdc++.h>
using namespace std;

int stock_max_profit(vector<int> &arr)
{
    int n = arr.size();

    int max_profit = 0;
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] > arr[i])
            {
                if((arr[j] - arr[i])> max_profit)   //update the max profit
                    max_profit = arr[j] - arr[i];
            }
        }
    }
    return max_profit;
}

int stock_max_profit_2(vector<int> arr)
{
    int last_min = arr[0];
    int max_profit = 0;

    for(int i=0 ; i<arr.size() ; i++)
    {
        if(arr[i] < last_min)
            last_min = arr[i];
        else if((arr[i]- last_min) >= max_profit)
            max_profit = (arr[i]- last_min) ;
    }
    return max_profit;
}

int main()
{
    vector<int> arr = {10,2,7,4,2,1,9};
    cout<<stock_max_profit_2(arr);

    return 0;
}