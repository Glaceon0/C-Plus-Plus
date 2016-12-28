#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"

using namespace std;

class SortedSet : public IntList {
  public:
    SortedSet();
    SortedSet(const SortedSet&);
    SortedSet(const IntList&);
    ~SortedSet();
    bool in(int) const;
    void add(int);
    void insert_ordered(int);
    void push_front(int);
    void push_back(int);
    const SortedSet operator|(const SortedSet&) const;
    const SortedSet operator&(const SortedSet&) const;
    SortedSet& operator|=(const SortedSet&);
    SortedSet& operator&=(const SortedSet&);
};

#endif