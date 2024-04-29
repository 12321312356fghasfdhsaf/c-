// DZ04_02_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <ctime>
#include <windows.h> 

using namespace std;

int main(int argc, char* argv[])

{
    //DZ 0402 Задание 2
   
    setlocale(LC_ALL, "rus");
    
    float sales1 = 0, sales2 = 0, sales3 = 0, manager1 = 0, manager2 = 0, manager3 = 0;
    float const zp = 200;
    cout << "  Введите уровень продаж для трех менеджеров" << endl;
    cout << "Уровень продаж 1-го менеджера - ";
    cin >> sales1;
    cout << "Уровень продаж 2-го менеджера - ";
    cin >> sales2;
    cout << "Уровень продаж 3-го менеджера - ";
    cin >> sales3;
    
    
    if (sales1 < 500)
    {
        manager1 = ((zp)+(sales1 * 0.03));
        cout << manager1 << "    ЗП первого менеджера " << endl;
    }

    else if (sales1 >= 500 && sales1 <= 1000)
    {
        manager1 = ((zp)+(sales1 * 0.05));
        cout << manager1 << "    ЗП первого менеджера" << endl;

    }
    else if (sales1 >= 1000)
    {
        manager1 = ((zp)+(sales1 * 0.08));
        cout << manager1 << "    ЗП первого менеджера" << endl;
    }

    if (sales2 < 500)
    {
        manager2 = ((zp)+(sales2 * 0.03));
        cout << manager2 << "    ЗП второго менеджера " << endl;
    }

    else if (sales2 >= 500 && sales2 <= 1000) 
    {
        manager2 = ((zp)+(sales2 * 0.05));
        cout << manager2 << "    ЗП второго менеджера" << endl;

    }
    else if (sales2 > 1000)
    {
        manager2 = ((zp)+(sales2 * 0.08));
        cout << manager2 << "    ЗП второго менеджера" << endl;
    }
    if (sales3 < 500) 
    {
        manager3 = ((zp)+(sales3 * 0.03));
        cout << manager3 << "    ЗП третьего менеджера " << endl;
    }
    else if (sales3 >= 500 && sales3 <= 1000)
    {
        manager3 = ((zp)+(sales3 * 0.05));
        cout << manager3 << "    ЗП третьего менеджера" << endl;

    }
    else if (sales3 >= 1000)
    {
        manager3 = ((zp)+(sales3 * 0.08));
        cout << manager3 << "    ЗП третьего менеджера" << endl;
    }


    if (manager1 > manager2 && manager1 > manager3)
    {
        manager1 = manager1 + 200;
        cout << "    1 менеджер лучший. Он получает премию!!! Его зп составляет: " << manager1 << "$" << endl;
    }
    else if (manager2 > manager3 && manager2 > manager1) {
        manager2 = manager2 + 200;
        cout << "    2 менеджер лучший. Он получает премию!!! Его зп составляет: " << manager2 << "$" << endl;
    }
    else if (manager3 > manager1 && manager3 > manager2) {
        manager3 = manager3 + 200;
        cout << "    3 менеджер лучший. Он получает премию!!! Его зп составляет: " << manager3 << "$" << endl;
    }
    //return 0;


    
}
