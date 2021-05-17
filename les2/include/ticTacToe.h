#pragma once

static constexpr size_t FSIZE = 3;
static constexpr size_t PNAME = 32;

struct TicTacToe
{
   enum CellType {EMPTY, CROSS, ZERO};
   CellType field[FSIZE][FSIZE];
   char playerA[PNAME];
   char playerB[PNAME];
   bool moveA;
};