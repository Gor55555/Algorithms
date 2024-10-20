#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

template <typename T>
T GetRandom();

template <>
int GetRandom<int>() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(0, 100);
	return dis(gen);
}

template <>
double GetRandom<double>() {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<> dis(1.0, 100.0);
	return dis(gen);
}

template <typename T>
void RandomNumbers(std::vector<T>& v)
{
	std::cout << "\n";
	std::cout << std::setw(15) << std::left << "RandomNumbers: ";
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] = GetRandom<T>();
		std::cout << v[i] << (i != v.size() - 1 ? ", " : "");
	}
	std::cout << "\n";
}

template <typename T>
void InsertionSort(std::vector<T>& v)
{
	std::cout << std::setw(15) << std::left << "InsertionSort: ";
	for (size_t i = 1; i < v.size(); ++i)
	{
		int j = i - 1;
		T k = v[i];

		while (j >= 0 && v[j] > k)
		{
			v[j + 1] = v[j];
			--j;
		}
		v[j + 1] = k;
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << (i != v.size() - 1 ? ", " : "");
	}
	std::cout << "\n";
}

int main()
{
	size_t size;
	std::cout << "Size: ";
	std::cin >> size;
	std::vector <int> v(size);
	RandomNumbers(v);
	InsertionSort(v);
}