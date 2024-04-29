// быки_коровы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


#define size 4

void ini_mass_4_number(int auto_number_f[size], int random_number_f)//заполнение случайным числом 4 ячеек массива
{
    for (int i = size - 1; i >= 0; i--)
    {
        auto_number_f[i] = random_number_f % 10;
        random_number_f = random_number_f / 10;
    }
}



    void print_mass_number(int auto_number_f[size])//вывод массива
    {

        for (int i = 0; i < size; i++)
        {

            cout << auto_number_f[i];
        }
    }

    bool same_number(int auto_number_f[size],int random_number_f)// random_number_f)//совпадение цифр
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (auto_number_f[i] == auto_number_f[j])
                {
                    counter++;

                }
            }
        }
        return(counter != 0);
        //cout << endl << "same = " << counter << endl;

        /*if (counter > 0)
        {
            return 1; //есть совпадения
        }
        else 
        {
            return 0; //нет совпадений
        }*/
        
        
        

    }




int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    
    int auto_number_mass[size];//массив 4х чисел (загаданный)
    int user_number_mass[size];//массив 4ч чисел (введенный пользователем)
    //int auto_number_mass_new[size] = { 0 };
    
    int raz = 0;
    //int random_number_new = rand() % 100;//одно случайное число

    int random_number = rand()%9999;
    int user_number;
    int bools = 0;
    int cows = 0;


    
    cout << random_number<<endl;

    // повторяем пока не будет сгенерировано число с разными цифрами
    /*do
    {
        ini_mass_4_number(auto_number_mass, random_number);
    } while (same_number(auto_number_mass));//, random_number));// !=0 );/////////разобраться с совпадениями!!!!!
    */
    


         

        ini_mass_4_number(auto_number_mass, random_number);
        print_mass_number(auto_number_mass);
        cout << endl;

      // cout<<same_number(auto_number_mass, random_number)<<endl;

        

        do {

            // Ограничиваем пользователя при вводе  числа из N различных цифр от 123 до 9876
            // 0 означает конец игры
            cout << "Введите число из " << size << " цифр ";
            cin >> user_number;
            if (user_number == 0)
            {
                cout << "Вам надоело играть!";
                break;
            }
            if (user_number > 9876)
            {
                cout << "вы ввели слишком большое число "<<endl;
                continue;
            }
            if (user_number < 123)
            {
                cout << "вы ввели слишком маленькое число "<<endl;
                continue;
            }
            if (same_number(user_number_mass,size))
            {
               cout << " вы ввели число с совпадениями цифр "<<endl;
                continue;
            }
                
            

            

            // заполняем массив  user_number_mass[] введенным числом
            ini_mass_4_number(user_number_mass, user_number);

           
            // пользователь ввел число 
            // которое удовлетворяет всем нашим условиям

            raz++; // количество попыток угадывания числа

            // считаем быков и коров
           // bools  // быки
           //cows  // коровы
            for (int i = 0; i < size; i++)
            {
                if (auto_number_mass[i] == user_number_mass[i])
                {
                    bools++;
                }
                for (int j = 0; j < size; j++)
                {
                    if (auto_number_mass[i] == user_number_mass[j])
                    {
                        cows++;
                    }
                }
            }
            
            cows = cows - bools;

            cout << "Попытка # " << raz << ": Быков " << bools << "; Коров " << cows << endl;


            

            // если не угадали - переходим к запросу следующего числа у пользователя
        } while (bools != 4);



      
        



    
    

    

    







    
}
