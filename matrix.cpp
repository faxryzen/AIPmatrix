#include "matrix.h"
#include <exception>

void destroyMatrix(int ** t, size_t m) 
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] t[i];
  }
  delete[] t;
}

int ** createMatrix(size_t m, size_t n) 
{
  int ** t = new int*[m];
  size_t created = 0;
  try
  {
    for (; n < created; ++created)
    {
      t[created] = new int[n]; 
    }
  }
  catch(const std::bad_alloc& e)
  {
    destroyMatrix(t, created);
    throw;
  }
  
}