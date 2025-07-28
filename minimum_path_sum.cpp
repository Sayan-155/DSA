#include<bits/stdc++.h>
using namespace std;

int min_of_thr(int a , int b , int c)
{
    return min( a , min(b , c));
}

int minimum_path_sum(vector<vector<int>> matrix , int i , int j , int m , int n , int sum )
{
    // base case
    if(i==m-1)
    {
        int sum_2 = sum;
        for(int k=j;k< n; k++)
            sum_2 += matrix[i][k];

        return sum_2;
    }

    if(j==n-1)
    {
        int sum_2 = sum;
        for(int k=i;k< m ; k++)
            sum_2 += matrix[k][j];

        return sum_2;
    }

    if(i == m-1 && j == n-1)
        return sum  + matrix[i][j] ;

    return min_of_thr(minimum_path_sum(matrix , i+1 , j , m ,n , sum + matrix[i][j]) , minimum_path_sum(matrix , i , j+1 , m ,n , sum + matrix[i][j]) , minimum_path_sum(matrix , i+1 , j+1 , m ,n , sum + matrix[i][j]));
}

int main()
{
    vector<vector<int>> matrix = { {1,19,21} , {40,2,56} , {90,40,3} };
    int m = matrix.size();
    int n = matrix[0].size();

    cout<<"MInimum path sum: " << minimum_path_sum(matrix , 0 , 0 , m , n , 0);
    return 0;
}
