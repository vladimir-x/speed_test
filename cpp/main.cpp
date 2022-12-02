#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

#include <sys/time.h>

long long timeInMilliseconds(void) {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

#include "calculate.cpp"
#include "crc.cpp"
#include "collections.cpp"

int main (int argc, char *argv[]) {

    long st = timeInMilliseconds();

    char* func = argv[1];
    long a = atol(argv[2]);
    long p = atol(argv[3]);

    int res = 0;
    res += calculate_run(func, a, p);
    res += crc_run(func, a, p);
    res += collection_run(func, a, p);

    if (res == -987654){
        // защита от оптимизатора
        printf("kek");
    }

    long en = timeInMilliseconds();

    printf(">>> lang: C++; func: %s; argA: %s; argP: %s; time: %ld;\n",argv[1], argv[2] , argv[3], (en - st));

    return 0;
}

