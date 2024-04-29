// DZ10_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");

    // Задание 1.

    /*const int size = 3;
    int mass[size][size];
    int number;
    int counter=0;
    
    cin>> number;

    for (int i = 0; i < size; i++) 
    {
        
        for (int j = 0; j < size; j++)
        {
            
            int temp = number+counter * 2;
            mass[i][j] = temp; 
            counter++;
            number=(number-2) + temp;
                                  
            
        }

    }

    cout << endl;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << " ";
            if (j == size - 1)
            {
                cout << endl;
            }
        }
    }

    cout << endl;*/

    // Задание 2.
    
    /*const int size = 3;
    int mass[size][size];
    int number;
    int counter = 0;

    cin >> number;

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {

            //int temp = (number + counter);// не совсем понял задание
            //mass[i][j] = temp;// или это, или вариант незакоментированый
            //counter++;// на всяк случай сделал оба.
           // number = number+1;

            int temp = (number + counter);// наверное все-таки так имелось ввиду.
            mass[i][j] = temp;
            counter++;
            
        }

    }

    cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << " ";
            if (j == size - 1)
            {
                cout << endl;
            }
        }
    }

    cout << endl;*/



    //Задание 3.


    const int size = 5;
    srand(time(0));
    int mass[size][size];
    
    int number;
    int counter = 0;

    

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {       
            mass[i][j] = rand() % 10+1;            
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

    cin >> number;

    for (int i = 0; i < size; i++)// сдвиг вниз
    {
        for (int j = 0; j < number; j++)
        {
            int temp = 0;
            temp = mass[size-1][i];
            for (int k = size-1; k >0; k--)
            {
                mass[k][i] = mass[k-1][i];
            }
            mass[0][i] = temp;
        }


    }

   
   










    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mass[i][j] << " ";
            if (j == size - 1)
            {
                cout << endl;
            }
        }
    }


    /*for (int i = 0; i < number; i++)//смещение влево
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
    
    */


    










    
    
    
        
    






    
}
