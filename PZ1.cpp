#include <iostream>
using namespace std;

class Mass 
{
    private:
        int size;
        int* a;
        int* newa;

    public:
        //конструктор
        Mass(int length)
        {
            size = length;
            a = new int[size];
        }
        //конструктор копирования
        Mass(const Mass& mass)
        {
            size = mass.size;
            a = new int[size];
            for (int i = 0; i < size; i++)
                a[i] = mass.a[i];
        }
        //деструктор
        ~Mass()
        {
            delete[] a;
            delete[] newa;
        }        
        //вывод массива
        void show()
        {
            cout << "mass: ";
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << " ";                
            }
            cout << endl;            
        }
        //сеттер
        void set(int value,int position)
        {
            if ((position >= 0) && (position < size))
            {
                if (value >= -100 || value <= 100)
                {
                    a[position] = value;
                }
                else
                {
                    cout << "Error!" << endl;
                }
            }
            else
            {
                cout << "Error!" << endl;
            }
        }
        //Геттер
        int get(int num)
        {
            if ((num >= 0) && (num < size))
            {
                return a[num];
            }
            else
            {
                cout << "Error!" << endl;
            }
        }

        //Добавление элемента в конец
        int AdditionEnd(const int value)
        {
            int len = size;
            int* newa = new int[size + 1];
            for (int i = 0; i < len; i++)
            {
                newa[i] = a[i];
            }
            if (value < -100 || value > 100)
            {
                cout << "Error!" << endl;
            }
            else
            {
                newa[len] = value;
            }
            len++;
            a = newa;
            cout << "AdditionEnd: ";
            for (int i = 0; i < len; i++)
            {
                cout << a[i] << " ";                
            }
            cout << endl;
            return 0;
        }

        //Сложение элементов        
        int sum(const Mass& arr)
        {           
            for (int i = 0; i < size; i++)
            {
                a[i] += arr.a[i];
            }
            cout << "Sum:";
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << " ";                
            }
            cout << endl;
            return 0;
        }

        //Вычитание элементов        
        int raz(const Mass& arr)
        {
            for (int i = 0; i < size; i++)
            {
                a[i] -= arr.a[i];
            }
            cout << "Raz:";
            for (int i = 0; i < size; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
            return 0;
        }
};

int main()
{
    Mass a(2), a1(2), a2(2);
    a.show();
    a1.show();
    a2.show();
    a1.AdditionEnd(1);
    a1.sum(a2);
    a1.raz(a2);
    return 0;
}