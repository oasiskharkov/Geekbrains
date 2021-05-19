#pragma once

struct Holder
{
   union Value
   {
      int i;
      double d;
      float f;
      char c;
   } val;
   int is_int : 1;
   int is_float : 1;
   int is_double : 1;
   int is_char : 1;
};