// bot_1_version.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
#define size 10




int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	//int const size = 10;
	int mass2d[size][size] = { {0,0,1,1,1,1,0,0,0,0},////еденицами помечены палубы 
		{1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1}
	};



	int live = 4;  // количество палуб(жизней)
	int mode = 0; // состояние режима ( выстрел/анализ)
	int x = 0;
	int y = 0;
	int dim = 0;    // переменная напрвления

	int first_hit_x = 0; //переменная для сохранения первого случайного попадания
	int first_hit_y = 0;
	int mass_horizontal[size] = { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mass2d[i][j];
		}
		cout << endl;


	}


	while (mode != 1)
	{
		x = rand() % size; //случайный выстрел
		y = rand() % size;

		if (mass2d[x][y] == 1) //если попали
		{

			mass2d[x][y] = 2;// помечаю подбитую палубу (2)
			cout << " ранен " << endl;
			first_hit_x = x; //переменная для сохранения первого случайного попадания
			first_hit_y = y;
			mode = 1;

			//// и вот тут нужна инфа о количестве палуб и уменьшение палуб в результате подбития
		}

	}

	for (int i = 0; i < size; i++)
	{

		cout << mass2d[x][i];
		mass_horizontal[i] = mass2d[x][i];


	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		if (mass_horizontal[i] == 2)
		{
			x = mass_horizontal[i];
		}
	
	}
	while (true)
	{
		if (dim == 0)
		{
			if (x > 0)
			{
				x--;                //ограничение выхода за пределы влево
			}
			else
			{
				dim = 1;
				x = first_hit_x + 1; // здесь не может быть корабля (вплотную)
			}
		}
		else
		{
			if (x < size - 1) // ограничение выхода за пределы вправо
			{
				x++;
			}
		}

		if (mass_horizontal[x] == 1 && live > 1)
		{
			mass_horizontal[x] = 2;
			cout << " ранен " << endl;
			live--;
		}
		else if (mass_horizontal[x] == 1 && live == 1)
		{
			mass_horizontal[x] = 2;
			cout << " убит " << endl;
			//mode = 0;    // переключаем в режим 1
			live = 0;
		}
		else
		{
			dim = 1;
			x = first_hit_x;
		}

		

	}






	for (int i = 0; i < size; i++)
	{
		cout << mass_horizontal[i];
	}

}


