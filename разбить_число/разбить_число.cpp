// разбить_число.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");


    const int size = 4;
     double long mobile_number_all[size];
    
    
    //int home_number[size_home];
    int exit;
    long long number = 0;
    float long small_number = 0;
    /*
    cout << "enter number of 10 digit"<<endl;
    cin >> number;
    part1 = number % 100000 ;
    part2 = number % 10000000000/100000;
    cout << part2<<endl;
    cout << part1<<endl;
    */





    for (int i = 0; i < size; i++)
    {
        cout << "введи мобильный номер ( 10 цифр ) ------ " << " ( +7 ) ";
        cin >> number;

        small_number = number/2;
        

        mobile_number_all[i] = small_number;

        

    }
    for (int i = 0; i < size; i++)
    {
        cout << (long long) mobile_number_all[i] * 2<<" ";
    }














}
