// Matrix_multiple.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void Random(int** matrix_1, int y, int x)
{
    srand(time(0));

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
        {
            matrix_1[i][j] = rand() % 100 + 1;
        }

}
void Random2(int** matrix_2, int y1, int x1)
{
    srand(time(0));

    for (int i = 0; i < y1; i++)
        for (int j = 0; j < x1; j++)
        {
            matrix_2[i][j] = rand() % 100 + 1;
        }

}

void Show(int** matrix_1, int y, int x)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << "   " << matrix_1[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
void Show2(int** matrix_2, int y1, int x1)
{
    for (int i = 0; i < y1; i++)
    {
        for (int j = 0; j < x1; j++)
        {
            cout << "   " << matrix_2[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}


void Delete(int** matrix_1, int y)
{
    for (int i = 0; i < y; i++)
    {
        delete[] matrix_1[i];
    }
    delete[] matrix_1;
}
void Delete2(int** matrix_2, int y1)
{
    for (int i = 0; i < y1; i++)
    {
        delete[] matrix_2[i];
    }
    delete[] matrix_2;
}

void Multiply(int** matrix_3, int** matrix_2,int**matrix_1, int y,int x1)
{
    
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x1; ++j)
        {
            matrix_3[i][j] = 0;
            for (int k = 0; k < y; ++k)
            {
                matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
            cout << matrix_3[i][j] << " ";
        }
        cout << endl;
    }

}

void Delete_Multiplay(int** matrix_3, int y)
{
    for (int i = 0; i < y; i++)
    {
        delete[] matrix_3[i];
    }
    delete[] matrix_3;
}
int main()
{
    int y, x;
    int y1,x1;

    cout << "Size1: ";
    cout << endl;
    cin >> y >> x;
    cout << "Size2: ";
    cout << endl;
    cin >> y1 >> x1;

    int** matrix_1 = new int* [y];
    int** matrix_2 = new int* [y1];

    for (int i = 0; i < y; i++)
    {
        matrix_1[i] = new int[x];
    }
    for (int i = 0; i < y; i++)
    {
        matrix_2[i] = new int[x1];
    }

    Random(matrix_1, y, x);
    Show(matrix_1, y, x);
   
    Random2(matrix_2, y1, x1);
    Show2(matrix_2, y1, x1);
    

    int** matrix_3=new int*[y];

    for (int i = 0; i < y; i++)
    {
        matrix_3[i] = new int[x];
    }

    Multiply(matrix_3, matrix_2, matrix_1, y, x1);

    Delete(matrix_1, y);
    Delete2(matrix_2, y1);
    Delete_Multiplay(matrix_3, y);

    
}