#include <iostream>
#include <cstring>
#include "person.h"
#include "union.h"
#include "car.h"
#include "holder.h"
#include "ticTacToe.h"

extern int ex1;
extern int ex2;

void init();

#define SIZE 10

typedef unsigned long ulong;
using ullong = unsigned long long;

int main() {
   init();
   std::cout << "ex1=" << ex1 << " ex2=" << ex2 << std::endl;

   int a, b = 2;
   a = b + 3;
   const int d = 10;
   volatile int y = 11;

   printf("a=%d b=%d d=%d y=%d\n", a, b, d, y);

   short c1{3};
   short c2(10);
   short c3 = {20};
   short c4 = 0b111;
   short c5 = 0x11;
   short c6 = 010;

   printf("c1=%d c2=%d c3=%d c4=%d c5=%d c6=%d\n", c1, c2, c3, c4, c5, c6);

   double pi = 3.14;
   double c = 1.12e-10;
   float e = 2.71;

   std::cout << "PI=" << pi << " C="<< c << " E=" << e << std::endl;

   long l1 = -10000000l;
   ulong l2 = 999999999ul;
   ullong l3 = 100000000000000ull;

   std::cout << l1 << " " << l2 << " " << l3 << std::endl;

   float f1 = 1.2f;
   float f2 = 2.3E10;

   printf("%1.1f %1.1e\n", f1, f2);

   char A = 77;
   char B = 'A';

   printf("%c=%d %c=%d\n", A, A, B, B);

   int arr1[3];
   int arr2[SIZE] = {};
   int arr3[4] = {1, 2, 3, 4};

   int arr4[2][3] =
      { {1, 2, 3},
        {4, 5, 6}};

   int arr5[2][2] =
      { 1, 2,
        3, 4};

   Person Alex = {"Aleksei", "Klopkov", "Evgenievich", 39, 175, 80 };
   Person Oleg;
   strcpy(Oleg.name, "Oleg");
   strcpy(Oleg.surname, "Ivanov");
   strcpy(Oleg.patronymic, "Ivanovich");
   Oleg.age = 35;
   Oleg.height = 182;
   Oleg.weight = 85;

   printf("%s %s %s age=%dуo, height=%dсm, weight=%dkg\n", Alex.surname, Alex.name, Alex.patronymic, Alex.age, Alex.height, Alex.weight);

   Car car1{"Tesla", 4, 4, 1};
   Car car2{"Toyota RAV4 Hybrid", 4, 4, 2};
   Car car3;
   strcpy(car3.model, "BMW X3");
   car3.wheels = 4;
   car3.doors = 5;
   car3.engine = 1;

   printf("%s has %d wheels %d doors %d engines\n", car2.model, car2.wheels, car2.doors, car2.engine);
   printf("Size of car is %l\n", sizeof(Car));

   Measure stone1;
   stone1.weight = 3.4f;
   Measure stone2;
   stone2.age = 1200000;
   Measure stone3;
   stone3.volume = 0.001;

   printf("Stone weight is %1.2f\n", stone1.weight);

   Holder h;
   h.val.i = 10;
   h.is_int = 1;
   h.is_float = 0;
   h.is_double = 0;
   h.is_char = 0;

   printf("Value %d has type int\n", h.val.i);

   TicTacToe ttt;
   strcpy(ttt.playerA, "Alex");
   strcpy(ttt.playerB, "Oleg");
   ttt.moveA = true;

   return 0;
}
