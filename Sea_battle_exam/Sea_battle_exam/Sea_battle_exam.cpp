// Sea_battle_exam.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


// НА ДАННОМ ЭТАПЕ СДЕЛАНО:
// 2 КАРТЫ, ПООЧЕРЕДНЫЕ ВЫСТРЕЛЫ КОМПА И ЧЕЛОВЕКА,
// ЕСЛИ КТО-ТО ИЗ ИГРОКОВ ПОПАДАЕТ, ТО ОН ПРОДОЛЖАЕТ СЛЕДУЮЩИЙ ВЫСТРЕЛ (ПОКА НЕ ПРОМАЖЕТ)
// ТУМАН ВОЙНЫ НА КАРТЕ СОПЕРНИКА
// РУЧНАЯ РАССТАНОВКА СДЕЛАНА, ПРОТЕСТИРОВАНА НО НЕАКТИВНА
// БОТ ВО ВТОРОМ ФАЙЛЕ (ОН АНАЛИЗИРУЕТ ПОПАДАНИЕ И НЕ СТРЕЛЯЕТ В МОЛОКО, ЕСЛИ ПОПАЛ)
// ВМЕСТЕ ЕЩЕ ВСЕ НЕ СВЯЗАЛ, БОТА НЕ ИНТЕГРИРОВАЛ


#include <iostream>
#include "windows.h"
#include <conio.h>
#define size 10
#define NUM_SHIPS 9 // количество кораблей

using namespace std;
int ships_id = 1;


void goto_xy(int x_f, int y_f) // ДЛЯ РУЧНОЙ РАССТАНОВКИ
{
	COORD p = { x_f,y_f };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);  /// функция ставит курсор в позицию x_f y_f
}

void ship_show(int x_f, int y_f, int dim_f, int size_ship)
{
	for (int i = 0; i < size_ship; i++)
	{
		
		goto_xy(x_f+1, y_f+1);
		cout << '#';

		switch (dim_f)
		{
		case 0:
			x_f++;
			break;
		case 1:
			y_f++;
			break;
		case 2:
			x_f--;
			break;
		case 3:
			y_f--;
			break;

		}
	}


}

bool ship_area_map1(int x_f, int y_f, int dim_f, int size_ship)
{
	bool area_map = 0; // или наоборот
	// проверка возможности постановки корабля
	for (int i = 0; i < size_ship; i++)
	{
		if (x_f < 0 || y_f < 0 || x_f >= size || y_f >= size)
		{
			area_map = 1;
			break;
		}
			

		switch (dim_f)
		{
		case 0:
			x_f++;
			break;
		case 1:
			y_f++;
			break;
		case 2:
			x_f--;
			break;
		case 3:
			y_f--;
			break;

		}

	}


	return area_map;
}

bool setting_ship(int map1[size][size], int x_f, int y_f, int dim_f, int size_ship)  // установка корбля(который вручную) в массив
{
	int temp_x = x_f;
	int temp_y = y_f;
	bool setting_is_possible = 0;
	// проверка возможности постановки корабля
	for (int i = 0; i < size_ship; i++)
	{
		if (x_f < 0 || y_f < 0 || x_f >= size || y_f >= size) /// cкорее всего эта проверка не нужна!
		{
			setting_is_possible = 1;
			break;
		}

		/*if (map1[x_f][y_f] >= 1 ||
			map1[x_f][y_f + 1] >= 1 ||
			map1[x_f][y_f - 1] >= 1 ||
			map1[x_f + 1][y_f] >= 1 ||                 ///////// здесь  не всегда срабатывает условие проверки, нужна еще проверка
			map1[x_f + 1][y_f + 1] >= 1 ||              /// иногда выскакивает за границу 9й ячейки
			map1[x_f + 1][y_f - 1] >= 1 ||
			map1[x_f - 1][y_f] >= 1 ||
			map1[x_f - 1][y_f + 1] >= 1 ||
			map1[x_f - 1][y_f - 1] >= 1) // проверка не занята ли ячейка 
		{
			setting_is_possible = 1;
			break;
		}*/

		if (map1[x_f][y_f] >= 1)   ////// проверка длинная и стремная, но по другому не придумал
		{
			setting_is_possible = 1;
			break;
		}
		if (y_f < size - 1)
		{
			if (map1[x_f][y_f + 1] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (y_f > 0)
		{
			if (map1[x_f][y_f - 1] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f < size - 1)
		{
			if (map1[x_f + 1][y_f])
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f < size - 1 && y_f < size - 1)
		{
			if (map1[x_f + 1][y_f + 1] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f < size - 1 && y_f>0)
		{
			if (map1[x_f + 1][y_f - 1] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f > 0)
		{
			if (map1[x_f - 1][y_f] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f > 0 && y_f < size - 1)
		{
			if (map1[x_f - 1][y_f + 1] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f > 0 && y_f > 0)
		{
			if (map1[x_f - 1][y_f - 1] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}


		switch (dim_f)
		{
		case 0:
			x_f++;
			break;
		case 1:
			y_f++;
			break;
		case 2:
			x_f--;
			break;
		case 3:
			y_f--;
			break;

		}

	}

	// если есть возможность поставить-ставим!
	if (setting_is_possible == 0)
	{
		x_f = temp_x;
		y_f = temp_y;

		for (int i = 0; i < size_ship; i++)
		{
			map1[x_f][y_f] = ships_id;

			switch (dim_f)
			{
			case 0:
				x_f++;
				break;
			case 1:
				y_f++;
				break;
			case 2:
				x_f--;
				break;
			case 3:
				y_f--;
				break;

			}
		}
		//ships[ships_id] = size_ship;
		ships_id++;
		


	}

	return setting_is_possible;
}



void set_place_ships_rand(int map1[size][size], int size_ship,int ship_id)
{
	int x_f, y_f;
	int dim_f = 0;
	int count_ship = 0;
	int count_iteration = 0;

	while (count_ship < 1)
	{
		count_iteration++;
		if (count_iteration > 1000) // предохранитель от перполнения кораблями и зацикливания
		{
			break;
		}
		// первичная позиция
		x_f = rand() % size;
		y_f = rand() % size;

		int temp_x = x_f;
		int temp_y = y_f;

		// генерация направления
		dim_f = rand() % 4;

		bool setting_is_possible = 0;
		// проверка возможности постановки корабля
		for (int i = 0; i < size_ship; i++)
		{
			if (x_f < 0 || y_f < 0 || x_f >= size || y_f >= size)
			{
				setting_is_possible = 1;
				break;
			}

			if (map1[x_f][y_f] >= 1 ||
				map1[x_f][y_f + 1] >= 1 ||
				map1[x_f][y_f - 1] >= 1 ||
				map1[x_f + 1][y_f] >= 1 ||
				map1[x_f + 1][y_f + 1] >= 1 ||
				map1[x_f + 1][y_f - 1] >= 1 ||
				map1[x_f - 1][y_f] >= 1 ||
				map1[x_f - 1][y_f + 1] >= 1 ||
				map1[x_f - 1][y_f - 1] >= 1) // проверка не занята ли ячейка 
			{
				setting_is_possible = 1;
				break;
			}

			switch (dim_f)
			{
			case 0:
				x_f++;
				break;
			case 1:
				y_f++;
				break;
			case 2:
				x_f--;
				break;
			case 3:
				y_f--;
				break;

			}

		}

		// если есть возможность поставить-ставим!
		if (setting_is_possible == 0)
		{
			x_f = temp_x;
			y_f = temp_y;

			for (int i = 0; i < size_ship; i++)
			{
				map1[x_f][y_f] = ship_id;

				switch (dim_f)
				{
				case 0:
					x_f++;
					break;
				case 1:
					y_f++;
					break;
				case 2:
					x_f--;
					break;
				case 3:
					y_f--;
					break;

				}
			}
			//ships[ships_id] = size_ship;
			//ships_id++;
			count_ship++;

		}


	}
}


void output_map1(int map1[size][size],int mask_map1[size][size],bool onoff_mask) //// аргумент onoff_mask включает/выключает маску
{
	// прорисовка
	cout << ' ';
	for (int i = 0; i < size; i++)
	{
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i;
		for (int j = 0; j < size; j++)
		{
			if (mask_map1[j][i] == 1|| onoff_mask==0)            //туман войны on/off
			{


				if (map1[j][i] == 0)
				{
					cout << '-';                  //отображаем промахи
				}
				else if (map1[j][i] == -1)        
				{
					cout << 'X';                  //отображаем подбитые палубы вместо -1
				}
				else if (map1[j][i] == -2)
				{
					cout << '.';
				}
				else
				{
					cout << map1[j][i];
				}
			}
			else
			{
				cout << ' ';                      // туман войны on/off
			}
		}
		cout << endl;
	}

}
int hit(int map[size][size], int x, int y, int ships[NUM_SHIPS + 1],int mask_map[size][size])/// функция универсальна для обеих карт, массивов данных о палубах 
{                                                                                            /// и масках     
	                                                                                            
	int result = 0;

		if (map[x][y] >= 1)                     // проверка попадания
		{
			ships[map[x][y]]--;                 // подбитые палубы массива ships --
			
			if (ships[map[x][y]] <= 0)
			{
				
				result = 2;
			}
			else
			{
				
				result = 1;
			}
			map[x][y] = -1; // помечаем палубу, в которую попали/////
		}
		else
		{
			map[x][y] = -2;
		}
		mask_map[x][y] = 1;
		
		return result;
	
}

int main()
{
	setlocale(LC_ALL,"rus");
	srand(time(0));
		
	while (true)
	{
				
		int map1[size][size] = { 0 };         //// карта человека
		int map2[size][size] = { 0 };         ////карта компа
		int mask_map1[size][size] = { 0 };    /// маски
		int mask_map2[size][size] = { 0 };
		int ships1[NUM_SHIPS + 1] = { 0 ,4,3,3,2,2,2,1,1,1};  // элемент с индексом 0 должен остаться постотой// массив содержит инфу о количестве палуб человека
		int ships2[NUM_SHIPS + 1] = { 0 ,4,3,3,2,2,2,1,1,1 }; // инфа о количестве кораблей и палуб компа

		for (int i = 1; i <= NUM_SHIPS; i++)
		{

			set_place_ships_rand(map1, ships1[i], i); // расставили человеку
		}

		for (int i = 1; i <= NUM_SHIPS; i++)
		{

			set_place_ships_rand(map2, ships2[i], i); // рвсставили компу
		}

		

		int x_f = 0, y_f = 0; /// первичные координаты установки корабля
		int dim_f = 0;        /// направление
		int size_ship = 4;     /// размер корабля
		int ch;
		
		bool turn_onoff = 1;
		while (true)
		{
			int result_hit = 0;

			do 
			{
				int x = 0, y = 0;
				output_map1(map1, mask_map1,0); // 0 off mask
				cout << endl;
				output_map1(map2, mask_map2,1); // 1 on mask

				

				if (turn_onoff == 1)
				{
					cout << "введите координаты цели";
					cin >> x >> y;
					result_hit = hit(map2, x, y, ships2, mask_map2);    // выстрел человека
				}
				else
				{
					cout << " ход компа ";
					Sleep(1000);
					x = rand() % size;
					y = rand() % size;
					result_hit = hit(map1, x, y, ships1, mask_map1);     // выстрел компа
				}

				

				if (result_hit == 1)
				{
					cout << " Ранен " << endl;
				}
				else if (result_hit == 2)
				{
					cout << " Потоплен!!!" << endl;
				}
				else
				{
					cout << " Промазал! " << endl;
				}
				

				/*while (true)                           //// установка вручную
				{
					output_map1(map1, mask_map1);
					ship_show(x_f, y_f, dim_f, size_ship);

					int temp_x_f = x_f;
					int temp_y_f = y_f;
					int temp_dim_f = dim_f;

					ch = _getch();

					switch (ch)     // по ASCII ( через условие можно  прописать русскую раскладку)
					{
					case 100 :      // кнопка d вправо
						x_f++;
						break;
					case 115 :       // кнопка s вниз
						y_f++;
						break;
					case 97:        // кнопка a влево
						x_f--;
						break;
					case 119:       // кнопка w вверх
						y_f--;
						break;
					case 114:       // кнопка r поворот
						dim_f = !dim_f;
						break;
					case 13:          // установка корабля ентер
						if (!setting_ship(map1, x_f, y_f, dim_f, size_ship))
						{
							x_f = 0;
							y_f = 0;
							dim_f = 0;
							size_ship--;
						}
						break;
					}

					if (ship_area_map1(x_f, y_f, dim_f, size_ship)) //// проверка выхода за область карты корабля вручную (логика если ! то ретёрн 1)
					{
						 x_f = temp_x_f;             // откат переменных
						 y_f = temp_y_f;
						 dim_f = temp_dim_f;

					}

					system("cls");
				}*/

				_getch();
				system("cls");

			}while (result_hit !=0);       // когда не попал
			turn_onoff = !turn_onoff;     //переключение хода
		}
				
	}

}

