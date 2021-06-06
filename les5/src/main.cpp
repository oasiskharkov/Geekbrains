#include <iostream>
#include <iterator>
#include <numeric>
#include <stdarg.h>
#include "func.h"

void print_array(const int* arr, const size_t size);

void inverse(int* arr, const size_t size);

void add_three(int arr[], const size_t size);

std::pair<int, bool> check_balance(int arr[], const size_t size);

void shift(int arr[], const size_t size, const int n);

void print_inverse(size_t count, ...);

int main()
{
   // ---------#1---------
   srand(time(NULL));
   constexpr size_t SIZE1 = 20;
   int arr1[SIZE1] = {};
   std::for_each(arr1, arr1 + SIZE1, [](int& elem) { elem = rand() % 2; });
   print_array(arr1, SIZE1);
   inverse(arr1, SIZE1);
   print_array(arr1, SIZE1);

   // ---------#2---------
   constexpr size_t SIZE2 = 8;
   int arr2[SIZE2] = {};
   print_array(arr2, SIZE2);
   add_three(arr2, SIZE2);
   print_array(arr2, SIZE2);

   // ---------#3---------
   constexpr size_t SIZE3 = 16;
   int arr3[SIZE3] = {};
   while(true)
   {
       std::for_each(arr3, arr3 + SIZE3, [](int& elem) { elem = rand() % 10; });
       print_array(arr3, SIZE3);
       auto [index, result] = check_balance(arr3, SIZE3);
       std::cout << "Balance index: " << index << " balance is reached: " << std::boolalpha << result << std::endl;
       if(result)
               break;
   };

   // ---------#4---------
   constexpr size_t SIZE4 = 20;
   int arr4[SIZE4] = {};
   std::for_each(arr4, arr4 + SIZE4, [](int& elem) { elem = rand() % 10; });
   print_array(arr4, SIZE4);
   shift(arr4, SIZE4, 10);
   print_array(arr4, SIZE4);
   shift(arr4, SIZE4, -10);
   print_array(arr4, SIZE4);
   shift(arr4, SIZE4, 0);
   print_array(arr4, SIZE4);
   shift(arr4, SIZE4, 5);
   print_array(arr4, SIZE4);

   // ---------#5---------
   int x1 = 0, x2 = 1, x3 = 0, x4 = 1, x5 = 1, x6 = 0, x7 = 0;
   print_inverse(7, x1, x2, x3, x4, x5, x6, x7);
   print_inverse(5, x3, x4, x5, x6, x7);
   print_inverse(3, x2, x3, x4);
   print_inverse(1, x1);
   print_inverse(0);

   // ---------#6---------
   print_array(arr1, SIZE1);
   void(*f1)(int*, const size_t);
   f1 = &Func::inverse;
   f1(arr1, SIZE1);
   print_array(arr1, SIZE1);

   print_array(arr4, SIZE4);
   void(*shift_pow2)(int arr[], const size_t, const int);
   shift_pow2 = Func::shift;
   (*shift_pow2)(arr4, SIZE4, 2);
   print_array(arr4, SIZE4);

   return 0;
}

void print_array(const int* arr, const size_t size)
{
   std::copy(arr, arr + size, std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;
}

void inverse(int* arr, const size_t size)
{
    std::for_each(arr, arr + size, [](int& elem) { elem = !elem; });
}

void add_three(int arr[], const size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        arr[i] = i * 3 + 1;
    }
}

std::pair<int, bool> check_balance(int arr[], const size_t size)
{
    int sum = std::accumulate(&arr[0], &arr[size], 0);
    int sum_left = arr[0];
    int sum_right = sum - sum_left;
    for(size_t i = 1; i < size; ++i)
    {
        std::cout << sum_left << " " << sum_right << std::endl;
        if (sum_left == sum_right)
            return std::make_pair(i, true);
        sum_left += arr[i];
        sum_right -= arr[i];
    }
    return std::make_pair(-1, false);
}

void shift(int arr[], const size_t size, const int n)
{
    int shift = abs(n) % size;
    shift = n >= 0 ? shift : size - shift;

    for(int k = 0; k < shift; ++k)
    {
        int temp = arr[size - 1];
        for(size_t i = size - 1; i > 0; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}

void print_inverse(size_t count, ...)
{
    va_list ap;
    va_start(ap, count);
    for (size_t i = 0; i < count; ++i) {
        std::cout << (int)!va_arg(ap, int) << ' ';
    }
    va_end(ap);
    std::cout << std::endl;
}
