#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string_view>

using namespace std;



class List{
    int store[1000000];
    int size = 0;

    public: void listPush(int v){
        store[size++]=v;
    }
    public: void listClear(){
        size=0;
    }
    public: int  get(int i){
        return store[i];
    }

};

class Collections{


    public: long array_cp(long a, long p) {
        char *source = (char*)malloc(a * sizeof(char));
        char *dest = (char*)malloc(a * sizeof(char));

        for (long i = 0; i < p; ++i) {
            memcpy(dest, source , a);
        }
        return (long)dest[0];
    }

    public: long list_custom_check_append_clear(long a, long p) {
       int res = 0;
       List* l = new List();        // теряем время на создание и удаление объекта
       for (int i = 0; i < p; ++i) {
           for (int j = 0; j < a; ++j) {
                 l->listPush(j);
           }
           res += l -> get(3);
           l->listClear();
       }
       return res;
    }

    public: long list_custom_check_append_recreate(long a, long p) {
       int res = 0;
       for (int i = 0; i < p; ++i) {
           List* l = new List();        // теряем время на создание и удаление объекта
           for (int j = 0; j < a; ++j) {
                 l->listPush(j);
           }
           res += l -> get(3);
           delete l;
       }
       return res;
    }

    public: long list_standart_check_append_clear(long a, long p) {
       int res = 0;
       vector <int> v;
       for (int i = 0; i < p; ++i) {
           for (int j = 0; j < a; ++j) {
                 v.push_back(j);
           }
           res += v[3];
           v.clear();
       }
       return res;
    }

    public: long list_standart_check_append_recreate(long a, long p) {
       int res = 0;
       for (int i = 0; i < p; ++i) {
           vector <int> v;
           for (int j = 0; j < a; ++j) {
                 v.push_back(j);
           }
           res += v[3];
           v.clear();
       }
       return res;
    }

    public: long tree_set_standart(long a, long p) {
       set <int> s;
       for (int i = 0; i < a; ++i) {
           s.insert(i);
       }
       //inorderTraversal(root);
       for (int j = 0; j < p; ++j) {
            s.find(j);
       }
       return a;
    }

    public: long hash_set_standart(long a, long p) {
       unordered_set<int> s;
       for (int i = 0; i < a; ++i) {
           s.insert(i);
       }
       //inorderTraversal(root);
       int zcnt = 0;
       for (int j = 0; j < p; ++j) {
            if (s.find(j) == s.end()){
                zcnt++;
            }
       }
       return zcnt;
    }

    public: long array_cp_prepare_to_qsort(long a, long p) {
       for (int i=0;i<p;++i){
           vector<int> s;
           for (int j = 0; j < a; ++j) {
                s.push_back((j*j*13)%100000);
           }
       }
       return 0;
    }

    public: long sort_with_array_cp(long a, long p) {
       for (int i=0;i<p;++i){
           vector<int> s;
           for (int j = 0; j < a; ++j) {
                s.push_back((j*j*13)%100000);
           }

           std::sort(s.begin(), s.end());
       }
       return 0;
    }

};


int collection_run(char* func, long a, long p) {

    Collections* c = new Collections();

    if (!strcmp("array_cp",func)){
        return c->array_cp(a, p) ;
    }
    if (!strcmp("list_custom_check_append_clear",func)){
        return  c->list_custom_check_append_clear(a, p) ;
    }
    if (!strcmp("list_custom_check_append_recreate",func)){
        return  c->list_custom_check_append_recreate(a, p) ;
    }
    if (!strcmp("list_standart_check_append_clear",func)){
        return  c->list_standart_check_append_clear(a, p) ;
    }
    if (!strcmp("list_standart_check_append_recreate",func)){
        return  c->list_standart_check_append_recreate(a, p) ;
    }
    if (!strcmp("tree_set_standart",func)){
        return  c->tree_set_standart(a, p) ;
    }
    if (!strcmp("hash_set_standart",func)){
        return  c->hash_set_standart(a, p) ;
    }
    if (!strcmp("array_cp_prepare_to_qsort",func)){
        return  c->array_cp_prepare_to_qsort(a, p) ;
    }
    if (!strcmp("sort_with_array_cp",func)){
        return  c->sort_with_array_cp(a, p) ;
    }

  return 0;
}

