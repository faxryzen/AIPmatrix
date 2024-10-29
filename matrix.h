#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>

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
void read(const int ** t, size_t m, size_t n);
void print(const int * const * t, size_t m, size_t n);
void construct(const int ** t, size_t m, size_t n);

#endif