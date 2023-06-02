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

bool two_vector_dependance(const Vect& v1, const Vect& v2){
    //brak wersji dla wartości 0 -- poprawić
    for(size_t i =0; i < v1.size() - 1; i++){
        if(v1[i]/v2[i] != v1[i+1]/v2[i+1])
            return 0;
        }
    return 1;
}

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

int intmax(int a, int b)
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
//wielomian jako string
std::string to_str(const Polynomial& v)
{
    std::ostringstream oss;
    for(int i = v.get_size() - 1; i >= 0; i--)
    {
        if(v[i] != 0)
        {
            if ((i != v.get_size() - 1) && (v[i] > 0)) oss << " + ";
            if ((i != v.get_size() - 1) && (v[i] < 0)) oss << " - ";
            if (i == v.get_size() - 1 && i != 0) oss << v[i] << "*x^" << i;
            if (i != v.get_size() - 1 && i != 0) oss << abs(v[i]) << "*x^" << i;
            if (i == v.get_size() - 1 && i == 0) oss << v[i];
            if (i != v.get_size() - 1 && i == 0) oss << abs(v[i]);
        }
    }
    return oss.str();
}
//pochodna
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
//całka
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
//mnożenie wielomianów
Polynomial polynomial_multiplication(const Polynomial& p1, const Polynomial& p2)
{
    Polynomial result = Polynomial(p1.get_size() + p2.get_size() - 1);
    for(int i = 0; i < p1.get_size(); i++)
    {
        for(int j = 0; j < p2.get_size(); j++)
        {
            result[i+j] += p1[i] + p2[j];
        }
    }
    return result;
}
//potęga liczby
float pow(float a, int power)
{
    float answer = 1;
    if (power >= 0) {
        for (int i = 0; i < power; i++) {
            answer *= a;
        }
    }
    for (int i = 0; i > power; i--) {
        answer /= a;
    }
    return answer;
}
//wartość wielomianu dla argumentu
float value(const Polynomial& polynomial, float val)
{
    float result = 0;
    std::size_t size = polynomial.get_size();
    for(int i = 0; i < (int) size; i++) result += polynomial[i] * pow(val, i);
    return result;
}

//mnożenie wielomianu przez skalar
Polynomial multiplicate_polynomial(const Polynomial& p, float a)
{
    Polynomial result = p;
    for(int i = 0; i < p.get_size(); i++) result[i] *= a;
    return result;
}

