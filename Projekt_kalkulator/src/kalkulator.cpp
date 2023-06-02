#include "kalkulator.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <string>
#include <math.h>

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

//iloczyn skalarny wektorów
int scalar_product(const Vect& v1, const Vect& v2) {
    int scalar = 0;
    for(std::size_t i = 0; i < v1.size(); i++){
        scalar += v1[i] * v2[i];
    }
    return scalar;
}

//mnożenie wektora przez skalar
Vect multiply_vector(const Vect& v, int scalar){
    Vect multiplied_vect(v.size());
    for(std::size_t i = 0; i < v.size(); i++) {
        multiplied_vect[i] = scalar * v[i];
    }
    return multiplied_vect;
}

//zależność dwóch wektorów
bool two_vector_dependance(const Vect& v1, const Vect& v2){

    for(size_t i =0; i < v1.size() - 1; i++){
        if(v2[i] != 0 and v2[i+1] != 0){
            if(v1[i]/v2[i] != v1[i+1]/v2[i+1])
                return false;
        }
        else if((v2[i] == 0 and v1[i] != 0) or (v2[i+1] == 0 and v1[i+1] != 0)){
            return false;
        }
        }
    return true;
}

//wektor na stringa
std::string vector_to_string(const Vect& v){
    std::ostringstream to_string;
    to_string << "[";
    for(auto i = v.cbegin(); i != v.cend(); ++i){
        if(i != v.cend() - 1) {
            to_string << *i << "; ";
        }
    }
    to_string << "]";
    return to_string.str();
}

//funkcja zwracająca większą liczbę
std::size_t size_t_max(std::size_t a, std::size_t b)
{
    if(a>b) return a;
    return b;
}

//suma wielomianów
Polynomial add_polynomials(const Polynomial& p1, const Polynomial& p2)
{
    std::size_t size = size_t_max(p1.get_size(), p2.get_size());
    Polynomial sumvect = Polynomial(size);
    for(std::size_t i = 0; i < size; i++) sumvect[i] += p1[i] + p2[i];
    return sumvect;

}

std::string to_str(const Polynomial& v)
{
    std::ostringstream oss;
    for(int i = v.get_size() - 1; i >= 0; i--)
    {
        if(v[i] != 0)
        {
            if ((i != v.get_size() - 1) && (v[i] > 0)) oss << " + ";
            if ((i != v.get_size() - 1) && (v[i] < 0)) oss << " - ";
            if (i == v.get_size() - 1) oss << v[i] << "*x^" << i;
            if (i != v.get_size() - 1) oss << abs(v[i]) << "*x^" << i;
        }
    }
    return oss.str();
}

Polynomial derivate(const Polynomial& polinomial)
{
    std::size_t pol_size = polinomial.get_size();
    Polynomial derivative = Polynomial(pol_size - 1);
    for(std::size_t i = 0; i < pol_size - 1; i++)
    {
        derivative[i] = (i + 1)*polinomial[i+1];
    }
    return derivative;
}

Polynomial integral(const Polynomial& polinomial)
{
    std::size_t pol_size = polinomial.get_size();
    Polynomial integral_pol = Polynomial(pol_size + 1);
    for(int i = 1; i < (int) pol_size + 1; i++)
    {
        integral_pol[i] = polinomial[i - 1]/i;
    }
    return integral_pol;
}