#include <iostream>
#include "matrix.h"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int** t = createMatrix(M, N);
  readMatrix(t, M, N);
  printMatrix(t, M, N);
  destroyMatrix(t, M);
}