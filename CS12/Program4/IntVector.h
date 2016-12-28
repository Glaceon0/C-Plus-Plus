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
    void insert(unsigned, int);
    void erase(unsigned);
    void push_back(int);
    void pop_back();
    void clear();
    void resize(unsigned, int value = 0);
    void reserve(unsigned);
    void assign(unsigned, int);
    int& at(unsigned);
    int& front();
    int& back();
  private:
    unsigned sz;
    unsigned cap;
    int* data;
  private:
    void expand();
    void expand(unsigned);
};

#endif 