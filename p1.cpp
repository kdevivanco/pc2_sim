// Diseñar y desarrollar el template de función find_uncommon_elements que
// permita generar a partir de 2 contenedores un contenedor que contenga los
// valores no comunes entre ellos. Ejemplo:

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;

template<typename T>
void bubblesort(T& input) {

    int n = input.size();
    if (n == 0 or n == 1){
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (auto it = input.begin(); next(it) != input.end(); ++it) {
            if (*it > *(next(it))) {
                swap(*it, *(next(it)));
            }
        }
    }
}

template<template<typename...> class Res = vector, typename T=int,typename C1, typename C2> 
Res<T> find_uncommon_elements(const C1& cont1, const C2& cont2){
    Res<T> res;
    for(const auto& item: cont2){
        if(find(cont1.begin(), cont1.end(), item) == cont1.end()){
            res.push_back(item);
            }
        }
        for(const auto& item: cont1){
        if(find(cont2.begin(), cont2.end(), item) == cont2.end()){
            res.push_back(item);
            }
        }
        //sort using iterator
        bubblesort(res);
        return res;

}



void test_1(){
    vector<int> vec1= { 1, 4, 15, 19, 20, 11, 22, 1 };
    vector<int> vec2= { 1, 1, 14, 5,13,19,20,22};
    vector<int> res = find_uncommon_elements<vector>(vec1,vec2);
    cout << "difference" << endl;

    for(const auto& item : res){
        cout << item << " ";  
    }   
}

void test_2(){
    int n=4;
    deque<int> deq1(n);
    list<int> lis1(n);
    for(auto& item: deq1)
    cin >> item;
    for(auto& item: lis1)
    cin >> item;
    deque<int> res = find_uncommon_elements<deque>(deq1, lis1);
    cout << "difference" << endl;
    for(const auto& item: res)
    cout << item << " ";
}

void test_3(){
    int n = 3;
    deque<int> deq1(n);
    list<int> lis1(n);
    for(auto& item: deq1)
    cin >> item;
    for(auto& item: lis1)
    cin >> item;
    list<int> res = find_uncommon_elements<list>(deq1, lis1);
    cout << "difference" << endl;
    for(const auto& item: res)
    cout << item << " ";
}
int main(){
    //Test the function
    cout << "Test1 : " << endl;
    test_1();
    cout << "Test2 : " << endl;
    test_2();
    cout << "Test3 : " << endl;
    test_3();
}