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
void MergeSorted(std::vector<T>& v, size_t left, size_t mid, size_t right)
{
    size_t left_size = mid - left + 1;
    size_t right_size = right - mid;

    std::vector<T> left_temp(left_size);
    std::vector<T> right_temp(right_size);

    for (size_t i = 0; i < left_temp.size(); ++i)
        left_temp[i] = v[left + i];
    for (size_t i = 0; i < right_temp.size(); ++i)
        right_temp[i] = v[mid + 1 + i];

    size_t i = 0, j = 0, k = left;
    while (i < left_temp.size() && j < right_temp.size())
    {
        if (left_temp[i] <= right_temp[j])
        {
            v[k] = left_temp[i];
            ++i;
        }
        else
        {
            v[k] = right_temp[j];
            ++j;
        }
        ++k;
    }
    while (i < left_temp.size())
    {
        v[k] = left_temp[i];
        ++i;
        ++k;
    }
    while (j < right_temp.size())
    {
        v[k] = right_temp[j];
        ++j;
        ++k;
    }
}

template <typename T>
void MergeSortRecursion(std::vector<T>& v, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        MergeSortRecursion(v, left, mid);
        MergeSortRecursion(v, mid + 1, right);
        MergeSorted(v, left, mid, right);
    }
}

template <typename T>
void MergSort(std::vector<T>& v)
{
    std::cout << std::setw(15) << std::left << "MergeSort: ";
    MergeSortRecursion(v, 0, v.size() - 1);
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
    MergSort(v);
}
