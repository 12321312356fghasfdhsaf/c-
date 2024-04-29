// циклические сдвиги.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");

    const int size = 5;
    srand(time(0));
    int mass[size][size];

    int number;
    int choice;



    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
            mass[i][j] = rand() % 10 + 1;
        }

    }

    cout << endl;


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << " ";

        }
        cout << endl;
    }

    cout << endl;

    cout << " на сколько ячеек сдвигаем массив ? " << endl;
    cin >> number;

    cout << " куда сдвигаем массив? " << endl;
    cout << " 1-вниз " << endl;
    cout << " 2-вверх " << endl;
    cout << " 3-влево " << endl;
    cout << " 4-вправо " << endl;
    

    cin >> choice;

    switch (choice)

    {

    case 1:
    {



        for (int i = 0; i < size; i++)// сдвиг вниз
        {
            for (int j = 0; j < number; j++)
            {
                int temp = 0;
                temp = mass[size - 1][i];
                for (int k = size - 1; k > 0; k--)
                {
                    mass[k][i] = mass[k - 1][i];
                }
                mass[0][i] = temp;
            }


        }
        break;
    }
       
    

    case 3:
    {

     for (int i = 0; i < number; i++)//смещение влево
     {
         for (int j = 0; j < size; j++)
         {
             int temp = 0;
             temp = mass[j][0];
             for (int k = 0; k < size - 1; k++)
                {
                 mass[j][k] = mass[j][k + 1];
                 }
             mass[j][size - 1] = temp;
         }


     }
     break;
     }


    case 4:
    {


     for (int i = 0; i < number; i++)//смещение вправо
     {
         for (int j = 0; j <size ; j++)
         {
             int temp = 0;
             temp = mass[j][size-1];
             for (int k = size-1; k >0; k--)
             {
                 mass[j][k]=mass[j][k -1];
             }
                 mass[j][0] = temp;


         }
     }
     break;
     }

    case 2:
    {

     for (int i = 0; i < size; i++)// смещение вверх
     {
         for (int j = 0; j < number; j++)
         {
             int temp = 0;
             temp = mass[0][i];
             for (int k = 0; k < size - 1; k++)
             {
                 mass[k][i] = mass[k+1][i];
             }
             mass[size-1][i] = temp;
         }


     }
     break;
     }

     
    }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << mass[i][j] << " ";
            }

            cout << endl;


        }

    
















}
