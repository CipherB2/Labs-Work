#include <iostream>
using namespace std;
void F1(double*& mas, int& n)
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0)
		{
			k++;
		}
	}
	double* mas1 = new double[k];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0)
		{
			mas1[j] = mas[i];
			j++;
		}
	}
	mas = mas1;
	n = k;
}

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	double* mas = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
	}
	for (int i = 0; i < n; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
	F1(mas, n);
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	system("pause");
	return 0;
}