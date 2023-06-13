// Escribir la función template find_in_collection que debe retornar todos los
// valores en un vector que cumplan las condiciones definidas por el lambda
// utilizado como parametro.
// Caso de uso #1
// Caso de uso #2

//  vector<int> vec = generate_container<int, 10000>(-100, 100);

//  auto result = find_in_collection(begin(vec), end(vec),
// [](auto value){ return value % 2 == 0; });
//  cout << result << endl;

//  list<long int> lst = generate_container<long int, 10000>(-100, 100);



#include <vector>
#include <list> 
#include <deque> 
#include <algorithm>
#include <iostream> 
#include <thread>
#include <initializer_list>
using namespace std;


template<typename T>
void fill_random(std::vector<T>& vdatos, int rango, T r1, T r2) {
    for (int i = 1; i < rango; i++) {
        T value = r1 + (rand() % r2);
        vdatos.push_back(value);
    }
}



template<typename T = int, int amount>
vector<T> generate_container_v(T r1, T r2) {
    int nthreads = amount / 10;
    vector<T> resultado(nthreads);
    vector<thread> vhilos(nthreads);

    int rango = amount / nthreads;

    for (int j = 0; j < vhilos.size(); ++j) {
        vhilos[j] = std::thread(fill_random<T>,ref(resultado),ref(rango),r1,r2);
    }

    for (int j = 0; j < vhilos.size(); ++j) {
        vhilos[j].join();
    }

//    for (const auto& elem:resultado){
//        cout << elem << ",  ";
//    }

    return resultado;
}

template<typename T,typename lambda>
auto find_in_collection(T beg, T last, lambda la){
    int size = last-beg;
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

int main() {
    auto v = generate_container_v<int, 10>(-20, 80);
    for (const auto& elm : v) {
        std::cout << elm << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec = generate_container_v<int, 10>(-100, 100);
    for (const auto& e : vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    auto result = find_in_collection(begin(vec), end(vec),
    [](auto value){ return value % 2 == 0; });


    
    cout << "result1 " << endl;
    cout << result << endl;

     auto result2 = find_in_collection(begin(v), end(v),
    [](auto value){ return abs(value) > 50; });
        cout << "result2 " << endl;

    cout << result2 << endl;


}



