#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> vec1;
    vector<int> vec2;
    vector<int> exit;
    double S1 = 0.0, S2=0.0;
    int v1 = 0, v2 = 0;
    cout << "Введите размер первого вектора: ";
    cin >> v1;
    cout << endl;
    cout << "Введите размер второго вектора: ";
    cin >> v2;
    cout << endl;
    //Заоплняем вектора рандомными значениями
        for (int i = 0; i < v1; i++)
        {
            vec1.push_back(rand() % 200 - 100);
        }
        for (int i = 0; i < v2; i++)
        {
            vec2.push_back(rand() % 200 - 100);
        }
            //Считаем суммы элементов у каждого из векторов
            for (int i = 0; i < v1; i++)
            {
                S1 += static_cast<double>(vec1[i]);
            }
            for (int i = 0; i < v2; i++)
            {
                S2 += static_cast<double>(vec2[i]);
            }
                //Выводим содержимое векторов
                for (int i = 0; i < vec1.size(); i++)
                {
                    cout << vec1[i] << " ";
                }
                cout << endl;
                for (int i = 0; i < vec2.size(); i++)
                {
                    cout << vec2[i] << " ";
                }
                cout << endl;
                //Выводим среднее арифметическое векторов
                cout << S1/v1 << endl;
                cout << S2/v2 << endl;

    //Поиск одинаковых элементов в векторах  
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec2.size(); j++)
        {
            if (vec1[i] == vec2[j]) 
            {               
                if(find(exit.begin(),exit.end(),vec1[i]) == exit.end())
                    exit.push_back(vec1[i]);
            }
        }
    }

    for (int k = 0; k < exit.size(); k++)
    {
        cout << exit[k] << " ";
    }
    return 0;
}