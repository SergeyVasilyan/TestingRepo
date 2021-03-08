#ifndef FILTR_MATRIX_H
#define FILTR_MATRIX_H
#include <stdio.h>
#include <iostream>
int rows=5;
int cols=5;
int layer=1;
class FMatrix
{
public:
    FMatrix(std::string path);
    bool read_file(int ***array, std::string path);
    void change();
    int ***data;
private:
    std::string filename;
};
#endif
