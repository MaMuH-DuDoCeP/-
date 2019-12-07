#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct MARSH
{
	int id=0;
	string nameOfStartPoint="";
	string nameOfEndPoint="";

	bool operator<(const MARSH & m)
	{
		return id < m.id;
	}
};


istream & operator>>(istream & stream, MARSH & marsh)
{
	cout << "Введите номер маршрута: ";
	stream >> marsh.id;
	cout << "Введите название начального пункта: ";
	stream >> marsh.nameOfStartPoint;
	cout << "Введите название конечного пункта: ";
	stream >> marsh.nameOfEndPoint;
	return stream;
}

ostream & operator<<(ostream & stream, const MARSH & marsh)
{
	stream << "Номер маршрута: " << marsh.id << "\nНазвание начального пункта: " << marsh.nameOfStartPoint << "\nНазвание конечного пункта: " << marsh.nameOfEndPoint;
	return stream;
}

int main()
{
	setlocale(LC_ALL, "ru");

	MARSH arr[8];

	for (int i = 0; i < 8; i++)
	{
		cout << "Введите данные " << i << " маршрута:\n";
		cin >> arr[i];
	}

	sort(arr, arr + 8);

	int n;
	cout << "Введите номер маршрута который найти: ";
	cin >> n;

	for (int i=0; i < 8; i++)
	{
		if (arr[i].id == n)
		{
			cout << arr[i] << "\n";
			break;
		}
		if (arr[i].id > n || i==7)
		{
			cout << "Маршрут не найден\n";
			break;
		}
	}

	getchar();
	getchar();

	return 0;
}
