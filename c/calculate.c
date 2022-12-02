#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long incrementator(long a, long p) {
    long res = 0;
    for (long i = 0; i < p; ++i) {
        res+=i+i;
    }
    return res;
}


long multiplier(long a, long p) {
    long res = a;
    for (long i = 1; i < p; ++i) {
        res*=i;
    }
    return res;
}

long divider(long a, long p) {
    long res = a;
    for (long i = 1; i < p; ++i) {
        res *= a / i;
    }
    return res;
}

long modder(long a, long p) {
    long res = 1;
    for (long i = 1; i < p; ++i) {
        res += a % i;
    }
    return res;
}

long xorder(long a, long p) {
    long res = 1;
    for (long i = 0; i < p; ++i) {
        res ^= i;
    }
    return res;
}

long factorial(long a) {
    if (a == 1) return 1;
    return a*factorial(a-1);
}

long factorialCycle(long a, long p) {
    long res = 1;
    for (long i = 0; i < p; ++i) {
        res *= factorial(a);
    }
    return res;
}

int calculate_run(char* func, long a, long p) {
    int res = 0;
    if (!strcmp("incrementator",func)){
        res = incrementator(a,p);
    }
    if (!strcmp("multiplier",func)){
        res = multiplier(a,p);
    }
    if (!strcmp("divider",func)){
        res = divider(a,p);
    }
    if (!strcmp("modder",func)){
        res = modder(a,p);
    }
    if (!strcmp("xorder",func)){
        res = xorder(a,p);
    }
    if (!strcmp("factorial",func)){
        res = factorialCycle(a,p);
    }
    return res;
}
