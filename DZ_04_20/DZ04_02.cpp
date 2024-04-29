// DZ04_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <windows.h> 
using namespace std;


int main(int argc, char* argv[])
{
    //DZ 0402 Задание 1

    setlocale(LC_ALL, "rus");
    
    float const Pizza_vegitable = 9;
    float const Pizza_pipperoni = 10;
    float const Pizza_margarita = 11;
    float const Pizza_diablo = 12;
    float const cola = 2;
    float const sprite = 1;
    float const coffee = 4;
    float cost_drinks, cost_meals;
    int free_meals=0;

    cout << "List of MENU1 (MEALS)" << endl << endl;
    cout << "1-Pizza vegitable-9$" << "\n" << "2-Pizza pipperoni-10$" << "\n" << "3-Pizza margarita-11$" << "\n" << "4-Pizza diablo-12$" << endl;
    cout << "0-nothing" << endl << endl;
    int choice_meals;
    cout << "enter number of product :" << endl;
    cin >> choice_meals;
    cout << "how much ? " << endl;
    int how_much_meals;
    cin >> how_much_meals;

    cout << endl << endl;
    cout << "List of MENU2 (DRINKS)" << endl << endl;
    cout << "1-cola-2$" << "\n" << "2-sprite-1$" << "\n" << "3-coffee-4$" << endl;
    cout << "0-nothing" << endl << endl;
    int choice_drinks;
    cout << "enter number of product :" << endl << endl;
    cin >> choice_drinks;
    cout << " how much ?   " << endl;
    int how_much_drinks;
    cin >> how_much_drinks;
    cout << endl;


    // выбираем еду


    if (choice_meals == 1 &&how_much_meals>5)
    
    {
        cost_meals = Pizza_vegitable * how_much_meals;
        free_meals = (how_much_meals / 5) * Pizza_vegitable;
        cout << "  wow! " << how_much_meals / 5 << " pizza (s) free for you!" << endl << endl;
        cout << "  you discount : " << free_meals<<" $ "<<endl << endl;
         
    }
    else if (choice_meals == 1 && how_much_meals < 5)
    {
       
        cost_meals = Pizza_vegitable * how_much_meals;
    }

     if (choice_meals == 2 && how_much_meals > 5)
     {
         cost_meals = Pizza_pipperoni * how_much_meals;
         free_meals = (how_much_meals / 5) * Pizza_pipperoni;
         cout << "  wow! " << how_much_meals / 5 << " pizza (s) free for you!" << endl << endl;
         cout << "  discount : " << free_meals << " $ " << endl << endl;
     }
     else if (choice_meals == 2 && how_much_meals < 5)
         
     {
         cost_meals = Pizza_pipperoni * how_much_meals;
     }

     if (choice_meals == 3 && how_much_meals > 5)
     {
         cost_meals = Pizza_margarita * how_much_meals;
         free_meals = (how_much_meals / 5) * Pizza_margarita;
         cout << "  wow! " << how_much_meals / 5 << " pizza (s) free for you!" << endl << endl;
         cout << "  discount : " << free_meals << " $ " << endl;
     }
     else if (choice_meals == 3 && how_much_meals < 5)
     {
         
         cost_meals = Pizza_margarita * how_much_meals;
     }
     if (choice_meals == 4 && how_much_meals > 5)
     {
         cost_meals = Pizza_diablo * how_much_meals;
         free_meals = (how_much_meals / 5) * Pizza_diablo;
         cout << " wow! " << how_much_meals / 5 << " pizza (s) free for you!" << endl << endl;
         cout << " discount : " << free_meals << " $ " << endl << endl;
     }
     else if (choice_meals == 4 && how_much_meals < 5)
     {
         
         cost_meals = Pizza_diablo * how_much_meals;
     }

                
     if (choice_meals == 0)
                {
                    cout << "next part menu!" << endl << endl;
                }
    else if(choice_meals>4)
                {
                    cout << "product is over of menu" << endl << endl;
                }
  
     //выбираем напитки

        if (choice_drinks == 1 && how_much_drinks > 3)
        {
            cost_drinks =float( (cola * how_much_drinks) - ((((cola * how_much_drinks) / 100) * 15)));
            cout << "  you ordered more 3 drinks!" <<  endl;
            cout << "  discount : " << float((cola * how_much_drinks) / 100 * 15) <<" $ " << endl << endl;
        
            }
        else if (choice_drinks == 1 && how_much_drinks < 3)
        {
            cost_drinks = cola * how_much_drinks;
        }
        
        else if (choice_drinks == 2)
            {
                cost_drinks = sprite * how_much_drinks;
            }

        else if (choice_drinks == 3 && how_much_drinks > 3)
            {
                cost_drinks = float((coffee * how_much_drinks) - ((((coffee * how_much_drinks) / 100) * 15)));
                cout << "  you ordered more 3!" << endl;
                cout << "  discount : " << float ((coffee * how_much_drinks) / 100 * 15) <<" $ "<<endl<< endl;
            }
        else if (choice_drinks == 3 && how_much_drinks < 3)
             {
                 cost_drinks = coffee * how_much_drinks;
             }
        if (choice_drinks == 0)
        {
            cout << " good bye!!! " << endl << endl;
        }
        else if (choice_drinks > 3)
        {
            cout << "product is over of menu" << endl << endl;
        }
        cout << endl << endl << endl <<  endl << endl << endl;

        
        
        cout << "-------------------==TOTAL==-------------------" << endl;
        cout << "-----------------------------------------------" << endl;
        if (choice_meals == 1)
        {
            cout << "  Vegitable Pizza    " <<how_much_meals<<" units "<< " x " <<" 9 $ "<<" = " << cost_meals << " $ " << endl;
            
        }
        else if (choice_meals == 2)
        {
            cout << "  Pipperoni Pizza   " << how_much_meals<< " units " <<" x "<<"10 $ " << " = " << cost_meals << " $ " << endl;
            
        }
        else if (choice_meals == 3)
        {
            cout << "  Margarita Pizza   " << how_much_meals<< " units " << " x " <<" 11 $ " << " = " << cost_meals << " $ " << endl;
           
        }
        else if (choice_meals == 4)
            
        {
            cout << "  Diablo Pizza   " << how_much_meals<<" units " << " x "  << " 12 $ " << " = " << cost_meals << " $ " << endl;
            
        }


        if (choice_drinks == 1)
        {
            cout << "  Cola    " << how_much_drinks << " units " << " x " << " 2 $ " << " = " << cost_drinks << " $ " << endl;
        }
        else if  (choice_drinks == 2)
        {
            cout << "  Sprite   " << how_much_drinks << " units " << " x " << " 1 $ " <<" = "<< cost_drinks << " $ " << endl;
        }
        else if (choice_drinks == 3)
        {
            cout << "  Coffee   " << how_much_drinks << " units " << " x " << " 4 $ " <<" = "<< cost_drinks << " $ " << endl;
        }
        
        float total = (cost_meals + cost_drinks) - free_meals;
        if (total > 50)
        {
            cout << "You've order more 50$!!! you discount is 20%!!!" << endl  << endl;
            
            cout << "_______________________________________________" << endl << endl;
            cout<<  "Prize without discont____________________ "<< total<<" $ "<<endl;



            cout << "Final price :____________________________ " << total - (total * 0.20) << " $ " << endl;
            cout << "_______________________________________________"<< endl << endl;
        }
        else if (total < 50)
        {

            cout << "The total cost of the order is : " << total << " $ " << endl << endl;
            cout << "_______________________________________________" << endl << endl;

        }




//return 0;

  
    

}
