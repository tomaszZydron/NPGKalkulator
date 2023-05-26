#include "kalkulator.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>

//norma wektora
double Vect::norm() const {
    return sqrt(std::accumulate(std::begin(v_), std::end(v_), 0.0,[](auto acc, auto elem) { return acc + elem * elem; }));
}

//dodawanie wektorów
Vect add_vectors(const Vect& v1, const Vect& v2) {
    Vect v_sum(v1.size());

    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v_sum.begin(), std::plus<>());

    return v_sum;
}
