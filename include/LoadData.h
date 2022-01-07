#ifndef LOADDATA_H
#define LOADDATA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// Funkcja do czytania danych z pliku typu .csv
//
// @parm file_name Nazwa pliku do odczytu
// @return lista typu vector z wartoscimi przewalutowan
std::vector<float> read_csv(const std::string file_name);

#endif