#pragma once

#include <algorithm>

namespace
{
    void pow2(int* arr, const size_t size)
    {
        std::for_each(arr, arr + size, [](int& elem) { elem *= elem; });
    }
}

namespace Func
{
   void inverse(int* arr, const size_t size)
   {
      std::for_each(arr, arr + size, [](int& elem) { elem = !elem; });
   }

   void shift(int arr[], const size_t size, const int n)
   {
       pow2(arr, size);
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
}
