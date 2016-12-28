#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector {
  public:
    IntVector();
    IntVector(unsigned size, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int& at(unsigned) const;
    const int& front() const;
    const int& back() const;
  private:
    unsigned sz;
    unsigned cap;
    int* data;
};

#endif 