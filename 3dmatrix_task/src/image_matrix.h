#ifndef IMAGE_MATRIX_H
#define IMAGE_MATRIX_H
#include <stdio.h>
#include <iostream>
class IMatrix
{
public:
    IMatrix(std::string path);
    bool read_file(int*** array, std::string path);
    int ***data;
private:
    std::string filename;
};
#endif
