// Лабораторная работа №2 (2 семестр)
// 
// Реализуйте алгоритм быстрой сортировки по его псевдокоду. 
// Реализуйте алгоритм сортировки пузырьком из лекции 1. 
// Исследуйте при помощи класса Timer время выполнения на разных объемах входных данных(n = 10, n = 100, n = 100 000, n = 1 000 000).
// Объясните полученный результат.

#include <iostream>
#include <chrono>
#define N 100

using std::cout;
using std::endl;
using std::swap;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void QuickSort(int a, int b, int* x)
{
	if (a >= b) return;
	int m = ((a + b) / 2) + 1;
	int k = x[m];
	int l = a - 1;
	int r = b + 1;
	while (1)
	{
		do l++; while (x[l] < k);
		do r--; while (x[r] > k);
		if (l >= r) break;
		swap(x[l], x[r]);
	}
	r = l;
	l = l - 1;
	QuickSort(a, l, x);
	QuickSort(r, b, x);
}

void BubbleSort(int* mas, int n)
{
	bool fl = false;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				swap(mas[j], mas[j + 1]);
				fl = true;
			}
		}
		if (fl == false)
		{
			break;
		}
	}
}

int main()
{
	srand(time(0));
	int arr1[N];
	int arr2[N];
	for (int i = 0; i < N; i++)
	{
		int r = rand();
		arr1[i] = r;
		arr2[i] = r;
	}
	Timer a;
	QuickSort(1, N - 1, arr1);
	cout << "Quicksort: " << a.elapsed() << endl;
	Timer b;
	BubbleSort(arr2, N);
	cout << "Bubblesort: " << b.elapsed() << endl;
	return 0;
}

// при малом количестве вводных данных сортировка пузырьком может оказаться быстрее
