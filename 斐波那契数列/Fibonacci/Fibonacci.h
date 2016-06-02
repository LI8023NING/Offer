#pragma once

long long Fibonacci(unsigned n)
{
	int res[2] = {0,1};
	if (n < 2)
		return res[n];

	long long first = 0;
	long long second = 1;
	long long fibN = 0;
	for (size_t i = 2; i <= n; ++i)
	{
		fibN = first + second;
		first = second;
		second = fibN;
	}

	return fibN;
}

void Test()
{
	int n = 0;
	cout << "Please enter number:" << endl;
	cin >> n;
	long long num = Fibonacci(n);
	cout << "FibonacciNumber is :" <<num<< endl;
}