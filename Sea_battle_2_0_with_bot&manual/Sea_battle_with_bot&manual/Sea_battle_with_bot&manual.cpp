

#include <iostream>
#include "windows.h"
#include <conio.h>
#include<vector>

using namespace std;
#define Size 10
#define NUM_SHIPS 8 // количество кораблей


int ships_id = 1;
//int ships[10] = { 0 };



void goto_xy(int x_f, int y_f) // ДЛЯ РУЧНОЙ РАССТАНОВКИ
{
	COORD p = { x_f,y_f };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);  /// функция ставит курсор в позицию x_f y_f
}

void ship_show(int x_f, int y_f, int dim_f, int size_ship) /// для установки корабля вручную
{
	for (int i = 0; i < size_ship; i++)
	{

		goto_xy(x_f + 1, y_f + 1);
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
		if (x_f < 0 || y_f < 0 || x_f >= Size || y_f >= Size)
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

bool setting_ship(int map1[Size][Size], int x_f, int y_f, int dim_f, int size_ship)  // установка корбля(который вручную) в массив
{
	int temp_x = x_f;
	int temp_y = y_f;
	bool setting_is_possible = 0;
	// проверка возможности постановки корабля
	for (int i = 0; i < size_ship; i++)
	{
		if (x_f < 0 || y_f < 0 || x_f >= Size || y_f >= Size) /// cкорее всего эта проверка не нужна!
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
		if (y_f < Size - 1)
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
		if (x_f < Size - 1)
		{
			if (map1[x_f + 1][y_f])
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f < Size - 1 && y_f < Size - 1)
		{
			if (map1[x_f + 1][y_f + 1] >= 1)
			{
				setting_is_possible = 1;
				break;
			}
		}
		if (x_f < Size - 1 && y_f>0)
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
		if (x_f > 0 && y_f < Size - 1)
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
			map1[x_f][y_f] = ships_id;  // используется только для этой функции

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



void set_place_ships_rand(int map1[Size][Size], int size_ship, int ship_id)
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
		x_f = rand() % Size;
		y_f = rand() % Size;

		int temp_x = x_f;
		int temp_y = y_f;

		// генерация направления
		dim_f = rand() % 4;

		bool setting_is_possible = 0;
		// проверка возможности постановки корабля
		for (int i = 0; i < size_ship; i++)
		{
			if (x_f < 0 || y_f < 0 || x_f >= Size || y_f >= Size)
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


void output_map1(int map1[Size][Size], int mask_map1[Size][Size], bool onoff_mask) //// аргумент onoff_mask включает/выключает маску
{
	// прорисовка результатов действий
	cout << ' ';
	for (int i = 0; i < Size; i++)
	{
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < Size; i++)
	{
		cout << i;
		for (int j = 0; j < Size; j++)
		{
			if (mask_map1[j][i] == 1 || onoff_mask == 0)            //туман войны on/off
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
					cout << '*';
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

void set_place_ship_manual(int map1[Size][Size], int mask_map1[Size][Size], int size_ship, int ship_id, int x_f, int y_f, int dim_f)
{
		
	int counter = 0;
		


		while(size_ship > 0)                           //// установка вручную
		{	
			
				 


				output_map1(map1, mask_map1, 0);   // 0- карта открыта
				ship_show(x_f, y_f, dim_f, size_ship);

				int temp_x_f = x_f;
				int temp_y_f = y_f;
				int temp_dim_f = dim_f;
				int ch;
				
				ch = _getch();

				switch (ch)     // по ASCII ( через условие можно  прописать русскую раскладку)
				{
				case 100:      // кнопка d вправо
					x_f++;
					break;
				case 115:       // кнопка s вниз
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
					if (!setting_ship(map1, x_f, y_f, dim_f,size_ship))//////////////////
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
				
			
		}
	


}

int hit(int map[Size][Size], int x, int y, int ships[NUM_SHIPS + 1], int mask_map[Size][Size])/// функция универсальна для обеих карт, массивов данных о палубах 
{                                                                                            /// и масках     

	int result = 0;

	if (map[x][y] == -1 || map[x][y] == -2)
	{
		result = 3;               ////для бота(чтобы не стелял по уже стреляной ячейке)
	}

	else if (map[x][y] >= 1)                     // проверка попадания

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
	setlocale(LC_ALL, "rus");
	srand(time(0));

	while (true)
	{

		int map1[Size][Size] = { 0 };         //// карта человека
		int map2[Size][Size] = { 0 };         ////карта компа
		int mask_map1[Size][Size] = { 0 };    /// маски
		int mask_map2[Size][Size] = { 0 };
		int ships1[NUM_SHIPS + 1] = { 0 ,4,4,3,3,2,2,1,1 };  // элемент с индексом 0 должен остаться пустой// массив содержит инфу о количестве палуб человека
		int ships2[NUM_SHIPS + 1] = { 0 ,4,4,3,3,2,2,1,1 }; // инфа о количестве кораблей и палуб компа

		int x_f = 0, y_f = 0; /// первичные координаты установки корабля
		int dim_f = 0;        /// направление
		int size_ship = ships1[1];     /// размер корабля для ручной установки
		
		

		int ship_id = 0; ///
		int choice_set;

		cout <<" Выбери режим: " << endl;
		cout << " 1 - ручная установка кораблей " << endl;
		cout << " 2 - автоматическая " << endl;
		cin >> choice_set;
		switch (choice_set)
		{
		case 1:

		{
			system("cls");
			
		   		
					
			set_place_ship_manual(map1, mask_map1, size_ship, ship_id, x_f, y_f, dim_f); //вручную человеку
			set_place_ship_manual(map1, mask_map1, size_ship, ship_id, x_f, y_f, dim_f);
				
			
			for (int i = 1; i <= NUM_SHIPS; i++)
			{

				set_place_ships_rand(map2, ships2[i], i); // рандомно расставили компу
			}
			break;

		}

		
		case 2:
		{
			system("cls");
			for (int i = 1; i <= NUM_SHIPS; i++)    //// рандом расстановка по количеству NUM
			{
				


				set_place_ships_rand(map1, ships1[i], i); // расставили человеку

				for (int i = 1; i <= NUM_SHIPS; i++)
				{

					set_place_ships_rand(map2, ships2[i], i); // рвсставили компу
				}
			}
			break;
		}
		}

		


		int mode = 0;                     
		int xBot = 0;                        //координаты цели для бота
		int yBot = 0;                        ////////////
		int dim = 0;            // переменная напрвления bot

		vector<int>dims;                 //вектор направлений
		dims.push_back(3);               //вектор вниз
		dims.push_back(2);               ///вверх
		dims.push_back(1);               ///вправо
		dims.push_back(0);               //влево

		int first_hit_x = 0;             //////////////////
		int first_hit_y = 0;     //переменная для сохранения первого случайного попадания/////////

		bool winner_Human = 0;
		bool winner_Bot = 0;


		bool turn_onoff = 1;
		while (winner_Human == false && winner_Bot == false)
		{
			int result_hit = 0;

			do
			{
				int x = 0, y = 0; // координаты цели (для человека)
				output_map1(map1, mask_map1, 0); // 0 off mask
				cout << endl;
				output_map1(map2, mask_map2, 1); // 1 on mask



				if (turn_onoff == 1) ////переключение режимов стрельбы
				{
					cout << "введите координаты цели"<<endl;
					cin >> x >> y;
					result_hit = hit(map2, x, y, ships2, mask_map2);    // выстрел человека

					if (result_hit == 1)
					{
						cout << " Ранен " << endl;
					}
					else if (result_hit == 2)
					{
						bool terminate = 1;

						for (int i = 1; i <= NUM_SHIPS; i++)// проверка остались ли еще корабли компа (массив  ships2)
						{
							if (ships2[i] != 0)
							{
								terminate = 0;
								break;                               /// для ду вайла вс брейки (поочередной стрельбы)
							}
							if (terminate = 1)
							{
								winner_Human = 1;                /////////// человек победил
								break;
							}

						}
						cout << " Потоплен!!!" << endl;
					}
					else
					{
						cout << " Промазал! " << endl;
					}

				}
				else
				{
					cout << " ход компа ";
					Sleep(1000);

					
					if (mode == 0) // 1й режим случайный
					{
						do
						{
							xBot = rand() % Size; //случайный выстрел бота
							yBot = rand() % Size;

							result_hit = hit(map1, xBot, yBot, ships1, mask_map1);     // выстрел компа

						} while (result_hit == 3);   // если бот наткнулся на ячейку по которой стрелял- повторить рандом

						if (result_hit == 1)    // если ранен
						{
							mode = 1;      // переключаемся на режим анализа(режим 2)

							first_hit_x = xBot;
							first_hit_y = yBot;


							if (!dims.empty())  // если вектор не пуст
							{
								dim = dims[dims.size() - 1]; // записываем последний элемент внетора в переменную
								dims.pop_back();           //  удаляем последний элемент
							}
							cout << " Ранен " << endl;
						}

						else if (result_hit == 2)   /// если убит
						{
							bool terminate = 1;

							for (int i = 1; i <= NUM_SHIPS; i++)// проверка остались ли еще корабли человека (массив  ships1)
							{
								if (ships1[i] != 0)
								{
									terminate = 0;
									break;
								}
								if (terminate = 1)
								{
									winner_Bot = 1;                /////////// комп победил
									break;
								}

							}
							cout << " Потоплен!!!" << endl;
						}
						else
						{
							cout << " Промазал! " << endl;
						}


					}
					else if (mode == 1)  ////////////// 2й режим (анализа)

					{
						bool change_dim = 0;

						if (dim == 0) // влево
						{
							if (xBot > 0)
							{
								xBot--;                //ограничение выхода за пределы влево
							}
							else
							{
								change_dim = 1;

							}
						}
						else if (dim == 1)  //вправо
						{
							if (xBot < Size - 1) // ограничение выхода за пределы вправо
							{
								xBot++;
							}
							else
							{
								change_dim = 1;

							}
						}
						else if (dim == 2)  //вверх
						{
							if (yBot > 0) // ограничение выхода за пределы влево
							{
								yBot--;
							}
							else
							{
								change_dim = 1;

							}
						}
						else if (dim == 3)  //вниз
						{
							if (yBot < Size - 1) // ограничение выхода за пределы вправо
							{
								yBot++;
							}
							else
							{
								change_dim = 1;
							}
						}

						if (change_dim == 1)
						{
							if (!dims.empty())  // если вектор не пуст
							{
								dim = dims[dims.size() - 1];
								dims.pop_back();
							}
							xBot = first_hit_x;
							yBot = first_hit_y;

							continue; /// перекидываем на mode 0 (1й режим)

						}

						result_hit = hit(map1, xBot, yBot, ships1, mask_map1);     // выстрел компа

						if (result_hit == 1)
						{
							mode = 1;      // переключаемся на режим анализа(режим 2)

							first_hit_x = xBot;
							first_hit_y = yBot;


							if (!dims.empty())  // если вектор не пуст
							{
								dim = dims[dims.size() - 1];
								dims.pop_back();
							}
							cout << " Ранен " << endl;
						}

						else if (result_hit == 2)
						{
							mode = 0;                        //// корабль потоплен, переходим в режим 1

							dims.clear();                   //// очищаю на всяк случай 

							dims.push_back(3);              //// восстанавливаем содержимое направлений вектора
							dims.push_back(2);
							dims.push_back(1);
							dims.push_back(0);

							bool terminate = 1;

							for (int i = 1; i <= NUM_SHIPS; i++)// проверка остались ли еще корабли человека (массив  ships1)
							{
								if (ships1[i] != 0)
								{
									terminate = 0;
									break;
								}
								if (terminate = 1)
								{
									winner_Bot = 1;                /////////// комп победил
									break;
								}

							}

							cout << " Потоплен!!!" << endl;
						}
						else
						{
							if (!dims.empty())  // если вектор не пуст
							{
								dim = dims[dims.size() - 1];
								dims.pop_back();
							}
							xBot = first_hit_x;
							yBot = first_hit_y;

							cout << " Промазал! " << endl;
						}


						//mass[x][y] = 3;

					}

				}

				_getch();
				system("cls");

			} while (result_hit != 0);       // когда не попал
			turn_onoff = !turn_onoff;     //переключение хода
		}
		if (winner_Human == true)
		{
			cout << " YOU WIN!!!!! " << endl;
		}
		else if (winner_Bot == true)
		{
			cout << " YOU LOOSE!!!! " << endl;
		}

	}

}



