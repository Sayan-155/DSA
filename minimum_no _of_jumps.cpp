#include<bits/stdc++.h>
using namespace std;

int min_jumps_recur(int i , vector<int> &arr)
{
    if(i > arr.size()-1)
        return 0;
    
    int ans = INT_MAX;

    for(int j= i+1 ; j<= i+arr[i] ; j++)
    {
        int val = min_jumps_recur(j , arr);
        if(val != INT_MAX)
            ans = min(val+1 , ans);
    }
    return ans;
}

int min_jumps(int i , vector<int> &arr)
{
    if(i >= arr.size()-1)
        return INT_MAX;
    int ans = INT_MAX;

    for(int j=i+1 ; j< i+arr[i] ; j++)
    {
        int val = min_jumps(j , arr);
        if (val != INT_MAX)
            ans= min(val+1 , ans);
    }
    
}

int min_jump(vector<int> &arr)
{
    int ans = min_jumps_recur(0 , arr);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}

int main()
{
    vector<int> arr = { 1,2,0,0,0,9,5 };
    cout<<min_jump(arr);

    return 0;
}