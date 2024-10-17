#include "matrix.h"
#include <iostream>

void destroyMatrix(int** t, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] t[i];
  }
  delete[] t;
}

int** createMatrix(size_t m, size_t n)
{
  int** t = new int* [m];
  size_t created = 0;
  try
  {
    for (; created < m; ++created)
    {
      t[created] = new int[n];
    }
  }
  catch (const std::bad_alloc& e)
  {
    destroyMatrix(t, created);
    throw;
  }
  return t;
}

void readMatrix(int** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      t[i][j] = (i + 1) * 10 + (j + 1);
    }
  }
}

void printMatrix(const int* const* t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; (j + 1) < n; ++j)
    {
      std::cout << t[i][j] << " ";
    }
    std::cout << t[i][n - 1];
    std::cout << "\n";
  }
}