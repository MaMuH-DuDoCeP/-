#include <iostream>
#include <ctime>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int matrix[10][10];
	
	srand(time(0));
	
	cout << "Матрица:\n";
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
			cout<< setw(3) << (matrix[y][x] = rand() % 20 - 10) << " ";
		cout << "\n";
	}

	int localMins = 0;
	int sum = 0;

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (x > y)
				sum += abs(matrix[y][x]);
			bool b = false;
			for (int i = y - 1; i <= y + 1; i++)
			{
				if (i < 0 || i > 9) continue;
				for (int j = x - 1; j <= x + 1; j++)
				{
					if (j < 0 || j > 9 || (i==y && j==x)) continue;
					if (matrix[y][x] >= matrix[i][j])
					{
						b = true;
						break;
					}
				}
				if (b) break;
			}
			if (!b) localMins++;
		}
	}
	cout << "Локальных минимумов: " << localMins << "\n";
	cout << "Сумма модулей элементов выше главной диагонали: " << sum << "\n";
	getchar();
	getchar();
	return 0;	
}