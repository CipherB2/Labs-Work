#include <iostream>
#include <math.h>
using namespace std;
int F1(int x)
{
	int result;
	if (x >= 0)
	{
		result = pow(x, x);
	}
	else
	{
		result = 2 * (x * x);
	}
	return result;
}
void F2(int& x)
{
	x = F1(x);
}


int main()
{
	int N;
	cin >> N;
	for (int i = -3; i < N; i++)
	{
		float f = F1(i);
		cout << "i=" << i << "; F1(i)=" << f << endl;
	}

	system("pause");
	return 0;
}

//#include<iostream>
//#include<math.h>
//using namespace std;
//float F1(int& x)
//{
//	float result;
//	if (x >= 0)
//	{
//		result = pow(x, x);
//	}
//	else
//	{
//		result = 2 * (x * x);
//	}
//	return result;
//}
//void F2(int& x)
//{
//	x = F1(x);
//


//int main()
//{
//	int N;
//	cin >> N;
//	for (int i = -3; i < N; i++)
//	{
//		float f = F1(i);
//		cout << "i=" << i << "; F1(i)=" << f << endl;
//	}
//	cout << endl;
//	for (int i = -3; i < N; i++)
//	{
//		cout << "i=" << i << ";";
//		F2(i);
//		cout << "i=" << i << endl;
//	}
//	system("pause");
//	return 0;
//}
