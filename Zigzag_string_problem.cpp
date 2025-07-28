#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> make_Zigzag_string(string str)
{
    vector<char> s1(str.length());
    vector<char> s2(str.length());
    vector<char> s3(str.length());

    int c1= 0 ;
    int c2 = 0 ; 

    for(int i=0; i< str.length() ; i+= 4)
    {
        s1[c1] = str[i];
        if(i+4 < str.length())
            s2[c1] = str[i+4];

        c1++;
    }
    for(int i =1 ; i<str.length() ; i+= 2)
    {
        s2[c2] = str[i];
        c2++;
    }
    
    vector<vector<char>> str_arr(3);
        str_arr.push_back(s1);
        str_arr.push_back(s2);
        str_arr.push_back(s2);

    return str_arr;
}

int main()
{
    string s1 = "RADHARANI";
    
    vector<vector<char>> str_arr = make_Zigzag_string(s1);

    for(int i= 0 ;i< str_arr.size() ; i++)
    {
        for(int j = 0; j < str_arr[i].size() ; j++)
        {
            if(i%2 == 0)
                cout<<str_arr[i][j] << "  ";
            else
                cout<<str_arr[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}