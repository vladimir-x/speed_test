#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "red-black-tree.h"
#include "quick-sort.h"

long array_cp(long a, long p) {
    char *source = (char*)malloc(a* sizeof(char));
    char *dest = (char*)malloc(a* sizeof(char));

    for (long i = 0; i < p; ++i) {
        memcpy(dest, source , a);
    }

    return (long)dest[0];
}

//---------------------list----------------
int store[10000000];
int size = 0;

int listPush(int v){
    store[size++]=v;
}
int listGet(int i){
    return store[i];
}
int listClear(){
    size=0;
}
int hasInList(int v){
    for (int i=0;i<size;++i){
        if (store[i]==v){
            return 1;
        }
    }
    return 0;
}
//-------------------------------------------

//----------------------hash-set------------------
// 10000 размер возможно сильно зависит от процессорного кэша.
// если поставить больше - сильная деградация производительсноти
int hashStore[10000][1010];

// Высота хэш таблицы (сколько всего хэшей)
int hashTableMax = 10000;

//массив для дедубликаии хэшей. Значения с одинаковым хэшем
int hashLineMax = 1010;

int hashCode(int x){
    return ((long)x*13L)%hashTableMax;
}

int pushToHashStore(int x){
    int h = hashCode(x);

    int* line = hashStore[h];

    int size = line[0];
    for (int i = 1; i <= size; ++i) {
        if (x == line[i]){
            // такой элемент уже есть в хэше
            return 1;
        }
        //printf(">");
    }

    if (size>=hashLineMax-5){
        printf("ALERT !!! HASH OWERHEEPED !!!");
        return 0;
    }

    line[0]++;
    line[size+1] = x;

    return 1;
}

int hasInHashStore(int x){
    int h = hashCode(x);

    int* line = hashStore[h];

    for (int i = 1; i <= line[0]; ++i) {
        if (x == line[i]){
            // такой элемент уже есть в хэше
            return 1;
        }
    }
    // не нашли
    return 0;
}


//-------------------------------------------

long list_custom_check_append(long a, long p) {

   int res = 0;
   for (int i = 0; i < p; ++i) {
       for (int j = 0; j < a; ++j) {
             listPush(j);
       }
       res += listGet(3);
       listClear();
   }
   return size;
}

long tree_set_custom(long a, long p) {
   for (int i = 0; i < a; ++i) {
       insertion(i);
   }
   //inorderTraversal(root);
   for (int j = 0; j < p; ++j) {
        int r = hasInSet(root, j);
   }
}


long hash_set_custom(long a, long p) {

    // 10000 размер возможно сильно зависит от процессорного кэша.
    // если поставить больше - сильная деградация производительсноти
    hashTableMax = 10000;
    hashLineMax = 1010;



    for (int i = 0; i < a; ++i) {
        pushToHashStore(i);
    }

    int zcnt =0;
     for (int j = 0; j < p; ++j) {
          int r = hasInHashStore(j);
          if (r==0 ){
            zcnt++;
          }
     }
     return zcnt;
}

// все объекты имеют одинаковый хэш, поэтому лежат в одной массиве
long hash_set_bad_custom(long a, long p) {

    // 10000 размер возможно сильно зависит от процессорного кэша.
    // если поставить больше - сильная деградация производительсноти
    hashTableMax = 10000;
    hashLineMax = 1010;

    //int hashStore[hashTableMax][hashLineMax];


    for (int i = 0; i < a; ++i) {
        listPush(i);
    }

    int zcnt =0;
     for (int j = 0; j < p; ++j) {
          int r = hasInList(j);
          if (r==0){
            zcnt++;
          }
     }
     return zcnt;
}

// надо понять сколько занимает время только копироване
long array_cp_prepare_to_qsort(long a, long p) {

    //генерация массива
    int etalon[1000000];

    for (int i = 0; i < a; ++i) {
        etalon[i]=(i*i*13)%100000;
    }

    int *work2 = (int*)malloc(a * sizeof(int));

    int zcnt =0;
    for (int j = 0; j < p; ++j) {
        memcpy(work2, etalon , a * sizeof(int));

        int r = work2[0];
        if (r==0){
            zcnt++;
        }
    }
    return zcnt;
}

long qsort_custom(long a, long p) {

    //генерация массива
    int etalon[1000000];

    for (int i = 0; i < a; ++i) {
        etalon[i]=(i*i*13)%100000;
    }

    int *work2 = (int*)malloc(a * sizeof(int));

    int zcnt =0;
    for (int j = 0; j < p; ++j) {
        memcpy(work2, etalon , a * sizeof(int));

        quickSort(work2, 0, a-1);

        int r = work2[0];
        if (r==0){
            zcnt++;
        }
    }
    return zcnt;
}


int compare (const void * num1, const void * num2) {
   if(*(int*)num1 > *(int*)num2)
    return 1;
   else
    return -1;
}


long qsort_standart(long a, long p) {

    //генерация массива
    int etalon[1000000];

    for (int i = 0; i < a; ++i) {
        etalon[i]=(i*i*13)%100000;
    }

    int *work2 = (int*)malloc(a * sizeof(int));

    int zcnt =0;
    for (int j = 0; j < p; ++j) {
        memcpy(work2, etalon , a * sizeof(int));

        qsort(work2, a, sizeof(int),compare);

        int r = work2[0];
        if (r==0){
            zcnt++;
        }
    }
    return zcnt;
}


//---------------------------------------

int collection_run(char* func, long a, long p) {
    int res = 0;
    if (!strcmp("array_cp",func)){
        res = array_cp(a,p);
    }
    if (!strcmp("list_custom_check_append",func)){
        res = list_custom_check_append(a,p);
    }
    if (!strcmp("tree_set_custom",func)){
        res = tree_set_custom(a,p);
    }
    if (!strcmp("hash_set_custom",func)){
        res = hash_set_custom(a,p);
    }
    if (!strcmp("hash_set_bad_custom",func)){
        res = hash_set_bad_custom(a,p);
    }
    if (!strcmp("array_cp_prepare_to_qsort",func)){
        res = array_cp_prepare_to_qsort(a,p);
    }
    if (!strcmp("qsort_custom",func)){
        res = qsort_custom(a,p);
    }
    if (!strcmp("qsort_standart",func)){
        res = qsort_standart(a,p);
    }
    return res;
}
