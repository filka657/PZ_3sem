#include <iostream>
using namespace std;


template <class T>
class Mass
{
private:
    int size;
    T* a;    
public:
    //конструктор
    Mass(int length)
    {
        size = length;
        a = new T[size];
    }
    //конструктор копирования
    Mass(const Mass& mass)
    {
        size = mass.size;
        a = new T[size];
        for (int i = 0; i < size; i++)
            a[i] = mass.a[i];
    }
    //деструктор
    ~Mass()
    {
        delete[] a;       
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
    void set(T value, int position)
    {
        
        if ((position >= 0) && (position < size))
        {
            if (value >= -100 || value <= 100)
            {
                a[position] = value;
            }
            else
            {
                throw invalid_argument("Invalid argument!");
            }
        }
        else
        {
            throw out_of_range("Out of range!");
        }
        return a[position];
    }
    //Геттер
    T get(int num)
    {
        if ((num >= 0) && (num < size))
        {
            return a[num];
        }
        else
        {
            throw out_of_range("Out of range!");            
        }
    }

    //Добавление элемента в конец
    int AdditionEnd(T value)
    {
        int len = size;
        T* newa = new T[size + 1];
        for (int i = 0; i < len; i++)
        {
            newa[i] = a[i];
        }
        if (value < -100 || value > 100)
        {
            throw invalid_argument("Invalid argument!");
        }
        else
        {
            newa[len] = value;
        }
        len++;
        delete[] a;
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


    Mass& operator=(const Mass& mass);
    template <class T>
    friend ostream& operator <<(ostream out, Mass<T>& mass);
};
    template <>
    void Mass<int>::set(int value, int position)
    {
        if ((position >= 0) && (position < size))
        {
            if (value >= -100 || value <= 100)
            {
                a[position] = value;
            }
            else
            {
                throw invalid_argument("Invalid argument!");
            }
        }
        else
        {
            throw out_of_range("Out of range!");
        }
    }
    template <class T>
    Mass<T>& Mass<T>::operator=(const Mass& mass)
    {

    }


int main()
{    
    try
    {
        Mass<int> a(2);
        Mass<int> a1(2);
        Mass<int> a2(2);

        a.show();
        a1.show();
        a2.show();
        a1.AdditionEnd(1);
        a1.sum(a2);
        a1.raz(a2);

    }
    catch (bad_alloc& e)
    {
        cout << "Error initiating!" << endl << e.what() << endl;
    }
    catch (out_of_range e)
    {
        cout << "Error while accessing array element" << endl << e.what() << endl;
    }
    catch (invalid_argument e)
    {
        cout << "Error while setting arguments" << endl << e.what() << endl;
    }
    return 0;
}