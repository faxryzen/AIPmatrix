#include <cstddef>
#ifndef MTX_HPP
#define MTX_HPP

int ** createMatrix(size_t m, size_t n);
void destroyMatrix(int ** t, size_t m);
void readMatrix(int ** t, size_t m, size_t n);
void printMatrix(const int * const * t, size_t m, size_t n);

#endif