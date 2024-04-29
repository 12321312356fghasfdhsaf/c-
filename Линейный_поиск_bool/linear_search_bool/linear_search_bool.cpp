// linear_search_bool.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int LinnerSearch(int arr[][5], int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[i][j] == key)
            {
                return 1;
            }

        }
    }
    return 0;
}


int main()
{
    const int razmyer = 5;
    int mass[razmyer][5];

    for (int i = 0; i < razmyer; ++i)
    {
        for (int j = 0; j < razmyer; ++j)
        {
            mass[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < razmyer; ++i)
    {
        for (int j = 0; j < razmyer; ++j)
        {
           cout<< mass[i][j]<<" ";
        }
    }


    cout << "Input key: ";
    int key;
    cin >> key;
    bool search = true;
    search = LinnerSearch(mass, razmyer, key);
    if (search == true)
    {
        cout << "there is key ";
    }
    else
    {
        cout << "there is no key ";
    }

}
