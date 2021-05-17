#pragma once

struct Car
{
   char model[32];
   int wheels : 4;
   int doors : 4;
   int engine : 3;
};