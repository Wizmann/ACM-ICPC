#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

void beforeMain (void) __attribute__((constructor));

void beforeMain (void) {
    srand(time(nullptr));
}

template <typename T>
class MyHashFunction {
public:
    MyHashFunction() {
        _rand = rand();
    }
    size_t operator()(const T& item) const {
        static_assert(is_pod<T>::value , "not a POD");

        size_t size = sizeof(T);
        const char* ptr = reinterpret_cast<const char*>(&item);

        size_t hash_value = 0;
        for (size_t i = 0; i < size; i++) {
            hash_value = hash_value * _rand + hash_value * 101 + *ptr;
            ptr++;
        }
        return hash_value;
    }
private:
    size_t _rand;
};

template <typename T>
using unordered_set_pod = unordered_set<T, MyHashFunction<T> >;
