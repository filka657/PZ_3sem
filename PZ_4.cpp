
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map <string, int> dict;
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    cout << "Напишите текст: ";
    getline(cin, str);
    str += " ";
    int i = 0;
    string tmp;
    for (int j = 0; j < str.size(); j++)
    {
        if (str[j] == ' ' || str[j] == '/0')
        {
            tmp = str.substr(i, j - i);
            //cout << tmp << endl;
            i = j + 1;
            if (!tmp.empty())
            {
                if (dict.find(tmp) != dict.end())
                {
                    dict[tmp]++;
                }
                else
                {
                    dict.insert(make_pair(tmp, 1));
                }
            }
        }
    }
    for (auto it = dict.begin(); it != dict.end(); it++)
    {
        cout << (*it).first << ": " << (*it).second << endl;
    }
    return 0;
}
