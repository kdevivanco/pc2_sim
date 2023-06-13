//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_SIMULACRO_PC2_V2023_1B_FIND_IN_COLLECTION_H
#define PROG3_SIMULACRO_PC2_V2023_1B_FIND_IN_COLLECTION_H

#include<vector>
using namespace std;
//
//template <typename Iterator, typename Unary, typename T = Iterator::value_type> //
//vector<T> find_in_collection(Iterator start, Iterator stop, Unary unary_fn) {
//    vector<T> result;
//    copy_if(start, stop, back_inserter(result), unary_fn);
//    return result;
//}

//template<typename T>
//void fill_random(std::vector<T>& vdatos, int rango, T r1, T r2) {
//    for (int i = 1; i < rango; i++) {
//        T value = r1 + (rand() % r2);
//        vdatos.push_back(value);
//    }
//}
//
//
//
//template<typename T = int, int amount>
//vector<T> generate_container_v(T r1, T r2) {
//    int nthreads = amount / 10;
//    vector<T> resultado(nthreads);
//    vector<thread> vhilos(nthreads);
//
//    int rango = amount / nthreads;
//
//    for (int j = 0; j < vhilos.size(); ++j) {
//        vhilos[j] = std::thread(fill_random<T>,ref(resultado),ref(rango),r1,r2);
//    }
//
//    for (int j = 0; j < vhilos.size(); ++j) {
//        vhilos[j].join();
//    }
//
////    for (const auto& elem:resultado){
////        cout << elem << ",  ";
////    }
//
//    return resultado;
//}

template<typename T,typename lambda>
auto find_in_collection(T beg, T last, lambda la){

    vector<int> v;
    for (auto it = beg; it != last; ++it) {
        bool mybool = la(*it);
        if(mybool == true){
            v.push_back(*it);
        }
        else{
            continue;
        }
    }
    return v;
}


template<typename M>
ostream& operator<<(ostream& os, vector<M>& v){
    for(const auto& elem : v){
        cout << elem << " ";
    }
    return os;
}
#endif //PROG3_SIMULACRO_PC2_V2023_1B_FIND_IN_COLLECTION_H
