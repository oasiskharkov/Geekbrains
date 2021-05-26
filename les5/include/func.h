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
       for(int k = 0; k < shift; ++k)
       {
           if(n >= 0)
           {
               int temp = arr[size - 1];
               for(size_t i = size - 1; i > 0; --i)
               {
                   arr[i] = arr[i - 1];
               }
               arr[0] = temp;
           }
           else
           {
               int temp = arr[0];
               for(size_t i = 0; i < size - 1; ++i)
               {
                  arr[i] = arr[i + 1];
               }
               arr[size - 1] = temp;
           }
       }
   }
}
