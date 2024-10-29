#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <iostream>

struct Matrix 
{
  private:
    int ** t_;
    size_t m_, n_;
  public:
    ~Matrix();
    Matrix();
    Matrix(size_t m, size_t n);
    Matrix(const Matrix & torig_);
    void size(size_t m, size_t n);
    void print(std::ostream & out) const;
    void input(std::istream & in) const;
    size_t width() const
    {
      return n_;
    }
    size_t hight() const
    {
      return m_;
    }
};

int** create(size_t m, size_t n);
void destroy(int ** t, size_t m);
void input(std::istream & in, int ** t, size_t m, size_t n);
void print(std::ostream & out, const int * const * t, size_t m, size_t n);
int ** size(int ** t, size_t & m, size_t & n, size_t new_m, size_t new_n);
void construct(int ** t, size_t m, size_t n);
int ** copy(int ** t, size_t m, size_t n);


#endif