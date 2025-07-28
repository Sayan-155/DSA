#include<bits/stdc++.h>
using namespace std;

int min_3(int a , int b , int c)
{
    return min(a , min(b , c));
}

int edit_distance_rec(string &s1 , string &s2 , int m , int n)
{
    if (m==0) return n;
    if (n==0) return m;

    if (s1[m-1] == s2[n-1]) 
        return edit_distance_rec(s1, s2 , m-1 , n-1);
    else
       return (1 + min_3(edit_distance_rec(s1 , s2 , m-1 , n) , edit_distance_rec(s1 , s2 , m , n-1) , edit_distance_rec(s1 , s2 , m-1 , n-1)));
}

int edit_distance(string &s1 , string &s2)
{
    int m = s1.size();
    int n = s2.size();

    return edit_distance_rec(s1 , s2 , m , n);
}

int main()
{
    string s1 = "RADHA";
    string s2 = "DHARA";

    cout<< edit_distance(s1 , s2);

    return 0;
}