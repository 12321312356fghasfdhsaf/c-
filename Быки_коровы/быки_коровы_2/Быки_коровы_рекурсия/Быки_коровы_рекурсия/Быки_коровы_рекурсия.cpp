// Быки_коровы_рекурсия.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

#define size 4


// Напечатать число (которое в массиве)
void print_mass(char ar[], int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << ar[i];
	}
}

// размещаем цифры из числа value в массив ar
void user_mass(int value, char ar[], int number)
{
	for (int i = size - 1; i >= 0; i--)
	{
		ar[i] = '0' + value % 10;
		value = value / 10;
	}
}

// генерируем случайное число и записываем его в массив
void rand_mass(char ar[], int number)
{
	user_mass(rand() % 9999, ar, number);
}

// есть ли в массиве одинаковые цифры
bool SameDigits(char ar[], int number)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (ar[i] == ar[j])
				counter++;
		}
	}

	return (counter != 0);
}

int cicle_r (char rand_mass[], char user_mass[], int bools, int cows,int raz) /// рекурсивная функция
{
	
	if (bools != 4)
	{
		for (int i = 0; i < size; i++)
		{
			if (rand_mass[i] == user_mass[i])
			{
				bools++;
			}
			for (int j = 0; j < size; j++)
			{
				if (rand_mass[i] == user_mass[j])
				{
					cows++;
				}
			}
		}
		cows = cows - bools;
			

		cout << "Попытка №" << raz << ": Быков " << bools << "; Коров " << cows << std::endl;
		return  bools;
		
		
	}
	else
	{
		return cicle_r(rand_mass, user_mass, bools, cows, raz);
		
	}


}


	



int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	char auto_number[size];
	char user_number[size];

	int raz = 0; // количество попыток
	int bools = 0; // быки
	int cows = 0;  // коровы





	// повторяем пока не будет сгенерировано число с разными цифрами
	do
	{
		rand_mass(auto_number, size);
	} while (SameDigits(auto_number, size));

	print_mass(auto_number, size);
	cout << endl;

	int input_number;	//число, введенное пользователем


	do
	{

		// Предлагаем пользователю ввести целое число из size различных цифр от 123 до 9876
		// 0 означает конец игры
		cout << "Введите число из " << size << " цифр ";
		cin >> input_number;
		if (input_number == 0)
		{
			cout << "Вам надоело играть!";
			break;
		}
		if (input_number > 9876)
		{
			cout << "вы ввели слишком большое число " << endl;
			continue;
		}
		if (input_number < 123)
		{
			cout << "вы ввели слишком маленькое число " << endl;
			continue;
		}

		// помещаем введенное число в массив user_number []
		user_mass(input_number, user_number, size);

		if (SameDigits(user_number, size))
		{
			cout << "нельзя вводить одинаковые цифры! " << endl;
			continue;
		}

		// пользователь ввел число 
		// которое удовлетворяет всем нашим условиям

		raz++; // количество попыток угадывания числа

		

		bools= cicle_r(auto_number, user_number, bools, cows, raz);

		// если не угадали - переходим к запросу следующего числа у пользователя
	} while (bools != 4);

}