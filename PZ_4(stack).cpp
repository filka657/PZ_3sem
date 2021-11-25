#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void deep(int num, vector<vector<int>>& mat)
{
    vector<bool> dota(mat.size(), false);
    stack<int> reach;

    while (num != -1)
    {
        if (dota[num] == false)
        {
            dota[num] = true;

            for (int j = 0; j < mat.size(); j++)
                if (mat[num][j] == 1 && dota[j] == false) reach.push(j);
        }

        if (reach.size() > 0)
        {
            num = reach.top();
            reach.pop();
        }
        else num = -1;
    }
    for (bool a : dota) cout << a << ' ';
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int n = 0;
    cin >> n;
    vector < vector<int>> mat(n, vector<int>(n, 0));
    int x;
    for (int i = 0; i < n; i++)
    {
        do
        {
            cin >> x;
            if (x != 0)
            {
                mat[i][x - 1] = 1;
            }            
        }
        while (cin.peek() != '\n');
    }
    for (int i = 0; i < n; i++)
    {
        deep(i, mat);
    }
    return 0;
}