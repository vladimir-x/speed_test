#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

class Calculator{
    public: long incrementator(long a, long p) {
        long res = 0;
        for (long i = 0; i < p; ++i) {
            res+=i+i;
        }
        return res;
    }

    public: long multiplier(long a, long p) {
        long res = a;
        for (long i = 1; i < p; ++i) {
            res*=i;
        }
        return res;
    }

    public: long divider(long a, long p) {
        long res = 1;
        for (long i = 1; i < p; ++i) {
            res *= a / i;
        }
        return res;
    }

    public: long modder(long a, long p) {
        long res = 1;
        for (long i = 1; i < p; ++i) {
            res += a % i;
        }
        return res;
    }

    public: long xorder(long a, long p) {
        long res = 1;
        for (long i = 0; i < p; ++i) {
            res ^= i;
        }
        return res;
    }

    public: long factorial(long a) {
        if (a == 1) return 1;
        return a*factorial(a-1);
    }

    public: long factorialCycle(long a, long p) {
        long res = 1;
        for (long i = 0; i < p; ++i) {
            res *=factorial(a);
        }
        return res;
    }

};

int calculate_run(char* func, long a, long p) {
    Calculator* c = new Calculator();
    if (!strcmp("incrementator",func)){
        return c->incrementator(a, p);
    }
    if (!strcmp("multiplier",func)){
      return  c->multiplier(a, p);
    }
    if (!strcmp("divider",func)){
      return c->divider(a, p);
    }
    if (!strcmp("modder",func)){
      return c->modder(a, p);
    }
    if (!strcmp("xorder",func)){
        return c->xorder(a, p);
    }
    if (!strcmp("factorial",func)){
       return c->factorialCycle(a, p);
    }
    return 0;
}

