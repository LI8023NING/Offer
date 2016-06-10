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

//·½°¸¶þ
long long Fibonacci2(int n)
{
	long long fibArray[3] = { 0, 1, n };

	for (int i = 2; i <= n; ++i)
	{
		fibArray[2] = fibArray[1] + fibArray[0];
		fibArray[0] = fibArray[1];
		fibArray[1] = fibArray[2];
	}

	return fibArray[2];
}
void Test()
{
	int n = 0;
	cout << "Please enter number:" << endl;
	cin >> n;
	long long num = Fibonacci2(n);
	cout << "FibonacciNumber is :" <<num<< endl;
}