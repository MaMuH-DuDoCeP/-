#include<iostream>
#include <iomanip>

using namespace std;

float f(float a, float b, float c, float x)
{
	if (!((~((int)a | (int)b)) & ((int)a ^ (int)c)))
	{
		a = (int)a;
		b = (int)b;
		c = (int)c;
	}

	if (x < 3 && b != 0)
		return a * x*x - b * x + c;
	if (x > 3 && b == 0)
		return (x - a) / (x - c);

	return x / c;
}


int main()
{
	setlocale(LC_ALL, "ru");

	float a, b, c, xs, xe, dx;

	cout << "������� a: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	cout << "������� c: ";
	cin >> c;
	cout << "������� x ���.: ";
	cin >> xs;
	cout << "������� x ���.: ";
	cin >> xe;
	do
	{
		cout << "������� dx(>0): ";
		cin >> dx;
	} while (dx <= 0);

	cout.precision(3);
	for (float i = xs; i < xe; i += dx)
		cout << setw(7) << i << " ";
	cout << "\n";
	for (float i = xs; i < xe; i += dx)
		cout << setw(7) << f(a,b,c,i) << " ";
	cout << "\n";

	getchar();
	getchar();

	return 0;
}
