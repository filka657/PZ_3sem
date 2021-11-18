
#include <iostream>
#include <string>
#include <vector>
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
    vector<pair<unsigned int, string>>vect;

    for (pair<string, unsigned int> a : dict)
        vect.push_back(make_pair(a.second, a.first));

    sort(vect.begin(), vect.end());
    cout << "Список:\n" << endl;
    for (int i = 0; i < vect.size(); i++)
        cout << vect[vect.size() - i - 1].second << ": " << vect[vect.size() - i - 1].first << endl;
    return 0;
}
