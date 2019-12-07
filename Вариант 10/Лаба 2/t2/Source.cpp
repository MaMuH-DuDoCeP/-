#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	do
	{
		cout << "Введите длину массива(>0): ";
		cin >> n;
	} while (n <= 0);

	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i << " элемент массива: ";
		cin >> arr[i];
	}

	int min = abs(arr[0]);

	int sum = 0;
	bool was0 = false;

	for (int i = 0; i < n; i++)
	{
		int a = abs(arr[i]);
		if (a < min)
			min = a;

		if (was0)
			sum += a;
		else if (a == 0)
			was0 = true;
	}

	cout << "Минимальный по модулю элемент массива: " << min << "\n";
	cout << "Сумма всех модулей элементов после первого 0: " << sum << "\n";

	cout << "Было:\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	for (int i = 1; i < n / 2 + n % 2; i+=2)
	{
		int x = arr[i];
		arr[i] = arr[(n - i) - (n - i) % 2];
		arr[(n - i) - (n - i) % 2] = x;
	}

	cout << "Стало:\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();

	delete[] arr;
	return 0;
}