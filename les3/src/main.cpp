#include <iostream>
#include <iomanip>
#include "init.h"

extern const int a2;
extern const int b2;
extern const int c2;
extern const int d2;

int main()
{
   const int a = 9;
   const int b = 4;
   const int c = 3;
   const int d = 7;

   double res1 = (double)(a * (b + (c / d)));
   double res2 = a * (b + ((double)c / d));

   double res3 = (double)(a1 * (b1 + (c1 / d1)));
   double res4 = a1 * (b1 + ((double)c1 / d1));

   double res5 = (double)(a2 * (b2 + (c2 / d2)));
   double res6 = a2 * (b2 + ((double)c2 / d2));

   std::cout << std::setprecision(4) << res1 << " " << res2 << std::endl;
   std::cout << std::setprecision(6) << res3 << " " << res4 << std::endl;
   std::cout << std::setprecision(6) << res5 << " " << res6 << std::endl;
   std::cout << std::fixed;

   int val;
   std::cout << "Input value: ";
   std::cin >> val;
   std::cout << (val > 21 ? (val - 21 ) << 1 : 21 - val) << std::endl; // разница

   int arr[3][3][3] = {};
   arr[1][1][1] = 35;
   size_t mid = 3 * 3 * 3 / 2;
   int* p = &arr[0][0][0];
   std::cout << *(p + mid) << std::endl;

   return 0;
}
