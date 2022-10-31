#pragma once

#include "TemplatedFunctions.h"

void FillRand(float*& Array, const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(float**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);

void FillRand(double*& Array, const int ArraySize, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
void FillRand(double**& Array, const int ArrayColumns, const int ArrayStrings, bool& ArrayFilled, int& ActiveString, int MinRand = 0, int MaxRand = 255);
