#include<bits/stdc++.h>
using namespace std;

int grid_path(int i , int j , int m ,int n)
{
    if(i == m-1 || j== n-1)
        return 1;
    if(i == m || j== n )
        return 0;  

    else
        return (grid_path(j+1 , i , m ,n) + grid_path(i , j+1 , m , n));
}

int grid_path_2_rec(int i ,int j , vector<vector<int>> &mat , int row , int col)
{
    if(mat[i][j] == 1) return 0;
    else if(i == row-1 || j == col-1) return 1;
    else
        return (grid_path_2_rec(i+1 , j , mat , row , col) + grid_path_2_rec(i , j+1 , mat , row , col));
}

int grid_path_2(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();

    return grid_path_2_rec(0 , 0 , mat , row , col);
}

int main()
{
    vector<vector<int>> grid = {{0 , 0 , 0} , {0 , 1 , 0} , {0 , 0 , 0}};

    cout<< grid_path_2(grid);
    return 0;
}