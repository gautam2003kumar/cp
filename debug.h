// debug.h
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void __print(const T& x) { cerr << x; }

template<typename T, typename U>
void __print(const pair<T, U>& p) {
    cerr << "(";
    __print(p.first);
    cerr << ", ";
    __print(p.second);
    cerr << ")";
}

template<typename T>
void __print(const vector<T>& v) {
    cerr << "[";
    for (const auto& i : v) { __print(i); cerr << " "; }
    cerr << "]";
}

template<typename T>
void __print(const set<T>& s) {
    cerr << "{ ";
    for (const auto& i : s) { __print(i); cerr << " "; }
    cerr << "}";
}

template<typename T, typename U>
void __print(const map<T, U>& m) {
    cerr << "{ ";
    for (const auto& i : m) {
        __print(i);
        cerr << " ";
    }
    cerr << "}";
}

template<typename Tuple, size_t... I>
void __print_tuple_impl(const Tuple& t, index_sequence<I...>) {
    ((cerr << (I == 0 ? "" : ", "), __print(get<I>(t))), ...);
}

template<typename... Args>
void __print(const tuple<Args...>& t) {
    cerr << "(";
    __print_tuple_impl(t, index_sequence_for<Args...>{});
    cerr << ")";
}


#define debug(x) cerr << #x << " = "; __print(x); cerr << endl;
