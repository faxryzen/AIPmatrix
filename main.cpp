#include <iostream>
#include "matrix.h"

int main()
{
  size_t M = 0, N = 0;
  std::cout << "Write two numbers - the size of the array\n";
  std::cin >> M >> N;

  if (!std::cin.good())
  {
    std::cerr << "failure to read int\n";
    return 1;
  }

  int ** table = nullptr;

  try
  {
    table = createMatrix(M, N);
  }
  catch (const std::exception& e)
  {
    std::cerr << "failure to allocate storage: " << e.what() << "\n";
    return 3;
  }
  
  std::cout << "Now write down " << M * N << " numbers\n";

  readMatrix(table, M, N);

  if (!std::cin.good())
  {
    std::cerr << "failure to read int\n";
    return 1;
  }
  std::cout << "Your matrix\n";
  printMatrix(table, M, N);
  destroyMatrix(table, M);
}