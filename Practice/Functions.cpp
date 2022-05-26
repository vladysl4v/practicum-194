#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	while (a % b != 0) {
		a = a % b;
		int t = a;
		a = b;
		b = t;
	}
	return b;
}

int lcm(int a, int b) 
{
    return (a * b) / gcd(a, b);
}

int lcm_n(int n, int** values) {
    if (n == 1)
        return values[0][1];
    int lcm_value = lcm(values[0][1], values[1][1]);
    for (int i = 2; i < n; ++i) {
        lcm_value = lcm(lcm_value, values[i][1]);
    }
    return lcm_value;
}

int sum_n(int n, int** arr)
{
	int denum = lcm_n(n, arr);
	int res = 0;

	for (int i = 0; i < n; i++)
	{
		res += arr[i][0] * (denum / arr[i][1]);
	}
	return res;
}

int count_remain(int &num, int denum)
{
	int ost = 0;
	if (num > denum)
	{
		while (num > denum)
		{
			num -= denum;
			ost++;
		}
	}
	return ost;
}

