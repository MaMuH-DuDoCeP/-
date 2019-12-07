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
	cout << "������� ����� ��������: ";
	stream >> marsh.id;
	cout << "������� �������� ���������� ������: ";
	stream >> marsh.nameOfStartPoint;
	cout << "������� �������� ��������� ������: ";
	stream >> marsh.nameOfEndPoint;
	return stream;
}

ostream & operator<<(ostream & stream, const MARSH & marsh)
{
	stream << "����� ��������: " << marsh.id << "\n�������� ���������� ������: " << marsh.nameOfStartPoint << "\n�������� ��������� ������: " << marsh.nameOfEndPoint;
	return stream;
}

int main()
{
	setlocale(LC_ALL, "ru");

	MARSH arr[8];

	for (int i = 0; i < 8; i++)
	{
		cout << "������� ������ " << i << " ��������:\n";
		cin >> arr[i];
	}

	sort(arr, arr + 8);

	int n;
	cout << "������� ����� �������� ������� �����: ";
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
			cout << "������� �� ������\n";
			break;
		}
	}

	getchar();
	getchar();

	return 0;
}
