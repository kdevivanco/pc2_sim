//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_SIMULACRO_PC2_V2023_1B_FIND_UNCOMMON_ELEMENTS_H
#define PROG3_SIMULACRO_PC2_V2023_1B_FIND_UNCOMMON_ELEMENTS_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include<set>

using namespace std;

//template <
//        template <typename...> class CResult,
//        template <typename...> class CFirst,
//        template <typename...> class CSecond,
//        typename T>
//CResult<T> find_uncommon_elements(CFirst<T>& cnt1, CSecond<T>& cnt2) {
//    CResult<T> result;
//    set<T> s1(begin(cnt1), end(cnt1));
//    set<T> s2(begin(cnt2), end(cnt2));
//    set_symmetric_difference(begin(s1), end(s1),
//                             begin(s2), end(s2),
//                             back_inserter(result));
//    return result;
//}


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

set<int> convertToSet(vector<int> v)
{
    // Declaring the set
    set<int> s;

    // Traverse the Vector
    for (int x : v) {

        // Insert each element
        // into the Set
        s.insert(x);
    }

    // Return the resultant Set
    return s;
}

template<template<typename...> class Res = vector, typename T=int,typename C1, typename C2>
Res<T> find_uncommon_elements(const C1& cont1, const C2& cont2){
    vector<T> res;
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
    set<T> clean = convertToSet(res);

    Res<T> answer;
    for(const auto& item : clean){
        answer.push_back(item);
    }
    return answer;

}

#endif //PROG3_SIMULACRO_PC2_V2023_1B_FIND_UNCOMMON_ELEMENTS_H
