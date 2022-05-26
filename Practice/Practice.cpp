#include <iostream>
#include <iomanip>

using namespace std;

int lcm_n(int, int**);
int sum_n(int, int**);
int count_remain(int&, int);

int main()
{
	int** nums;
	int n;
	int i;
	cout << "Enter the number of numbers ->";
	cin >> n;

	nums = new int* [n];
	for (i = 0; i < n; i++)
		nums[i] = new int[1];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (!j)
				cout << "Enter numerator ->";
			else
				cout << "Enter denumerator ->";
			cin >> nums[i][j];
		}
	}
	int num = sum_n(n, nums);
	int denum = lcm_n(n, nums);

	cout << "AVG: " << sum_n(n, nums) << "/" << (lcm_n(n, nums) * n) << endl;

	int remain = count_remain(num, denum);

	cout << "Sum: "  << remain << " " << num << "/" << denum;

	
	return 0;
}
