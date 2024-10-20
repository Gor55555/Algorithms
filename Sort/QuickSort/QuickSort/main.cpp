#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

template <typename T>
T GetRandom();

template <>
int GetRandom<int>() 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 100);
    return dis(gen);
}

template <>
double GetRandom<double>() 
{
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
int Partition(std::vector<T>& v, int left, int right)
{
    int pivot_value = v[right];
    int i = left;
    for (size_t j = left; j < right; ++j)
    {
        if (v[j] <= pivot_value)
        {
            std::swap(v[i], v[j]);
            ++i;
        }
    }
    std::swap(v[i], v[right]);
    return i;
}

template <typename T>
void QuickSortRecursion(std::vector<T>& v, int left, int right)
{
    if (left < right)
    {
        int pivot_index = Partition(v, left, right);
        QuickSortRecursion(v, left, pivot_index - 1);
        QuickSortRecursion(v, pivot_index + 1, right);
    }
}

template <typename T>
void QuickSort(std::vector<T>& v)
{
    std::cout << std::setw(15) << std::left << "QuickSort: ";
    QuickSortRecursion(v, 0, v.size() - 1);
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
    std::vector<int> v(size);
    RandomNumbers(v);
    QuickSort(v);
}

