#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

void Thomas(int, double*, double*, double*, double*, double*);
void readFromFile(int, double**, std::string);
void outputAll(int, double*, double*, double);
void outputSingle(int, double*, std::string, char);
void outputErrors(int, double*, double*);