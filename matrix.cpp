#include "matrix.h"
#include "mymath.h"

Matrix::~Matrix()
{
  destroy(t_, m_);
}
Matrix::Matrix(): Matrix(1, 1)
{}
Matrix::Matrix(size_t m, size_t n):
  t_(::create(m, n)), 
  m_(m), 
  n_(n)
{
  ::construct(t_, m_, n_);
}
Matrix::Matrix(const Matrix & torig_):
  t_(::copy(torig_.t_, torig_.m_, torig_.n_)),
  m_(torig_.m_),
  n_(torig_.n_)
{}
void Matrix::size(size_t m, size_t n)
{
  t_ = ::size(t_, m_, n_, m, n);
  m_ = m;
  n_ = n;
}
void Matrix::print(std::ostream & out) const
{
  ::print(out, t_, m_, n_);
}
std::istream & Matrix::input(std::istream & in) const
{
  ::input(in, t_, m_, n_);
  return in;
}

void destroy(int ** t, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] t[i];
  }
  delete[] t;
}

int ** create(size_t m, size_t n)
{
  int ** t = new int * [m];
  size_t created = 0;
  try
  {
    for (; created < m; ++created)
    {
      t[created] = new int[n];
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(t, created);
    throw;
  }
  return t;
}

std::istream & input(std::istream & in, int ** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      in >> t[i][j];
    }
  }
  return in;
}

void print(std::ostream & out, const int * const * t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; (j + 1) < n; ++j)
    {
      out << t[i][j] << " ";
    }
    out << t[i][n - 1];
    out << "\n";
  }
}

void construct(int ** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      t[i][j] = 0;
    }
  }
}

int ** size(int ** t, size_t m, size_t n, size_t new_m, size_t new_n)
{
  int ** new_t = create(new_m, new_n);
  construct(new_t, new_m, new_n);
  for (size_t i = 0; i < mymath::min(new_m, m); ++i)
  {
    for (size_t j = 0; j < mymath::min(new_n, n); ++j)
    {
      new_t[i][j] = t[i][j];
    }
  }
  destroy(t, m);
  return new_t;
}

int ** copy(int ** t, size_t m, size_t n)
{
  int ** new_t = create(m, n);
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      new_t[i][j] = t[i][j];
    }
  }
  return new_t;
}
