#ifndef FD_H
#define FD_H

#include<iostream>
class FD{
  public:
    int operator()(std::string key, int size) {
        char *p = (char *)key.c_str();
        int s = 0;
        while (*p) {
          s += *p;
          p++;
        }
        return s % size;
    }
};

#endif // FD_H
