
#ifndef PROJEKT_KALKULATOR_KALKULATOR_HPP
#define PROJEKT_KALKULATOR_KALKULATOR_HPP

#include <vector>
#include <cstddef>
#include <string>
#include <stdexcept>
#include <tuple>

//klasa odpowiadająca za wektory
class Vect {
public:
    //konstruktory
    Vect(std::size_t n) : v_(n, 0) {}
    Vect(const std::vector<int>& v) : v_(v) {}

    //operatory
    const int& operator[](std::size_t position) const {return v_[position];}
    int& operator[](std::size_t position) {return v_[position];}

    //iteratory
    std::vector<int>::const_iterator cbegin() const {return v_.cbegin(); }
    std::vector<int>::const_iterator cend() const {return v_.cend(); }

    std::vector<int>::iterator begin() {return v_.begin(); }
    std::vector<int>::iterator end() {return v_.end(); }

    std::vector<int>::const_iterator begin() const {return v_.cbegin(); }
    std::vector<int>::const_iterator end() const {return v_.cend(); }

    //metoda zwracająca rozmiar wektora
    std::size_t size() const { return v_.size(); }

    //metoda zwracająca normę wektora
    double norm() const;

private:
    std::vector<int> v_;
};

//dodawanie wektorów
Vect add_vectors(const Vect& v1, const Vect& v2);

//iloczyn skalarny wektorów
int scalar_product(const Vect& v1, const Vect& v2);

//mnożenie wektora przez skalar
Vect multiply_vector(const Vect& v, int scalar);

//czy dwa wektory są zależne
bool two_vector_dependance(const Vect& v1, const Vect& v2);

//wektor na stringa
std::string vector_to_string(const Vect& v);

//klasa odpowiadająca za wielomiany
class Polynomial{
public:
    Polynomial(int size, float val = 0) : coeficient_(size, val) {}
    Polynomial(const std::vector<float>& v) : coeficient_(v) {}
    int get_size() const {return coeficient_.size();}
    ~Polynomial() = default;
    const float& operator[](std::size_t pos) const { return coeficient_[pos]; }
    float& operator[](std::size_t pos) { return coeficient_[pos]; }
    std::vector<float>::const_iterator cbegin() const {return coeficient_.cbegin(); }
    std::vector<float>::const_iterator cend() const {return coeficient_.cend(); }

    std::vector<float>::iterator begin() {return coeficient_.begin(); }
    std::vector<float>::iterator end() {return coeficient_.end(); }

    std::vector<float>::const_iterator begin() const {return coeficient_.cbegin(); }
    std::vector<float>::const_iterator end() const {return coeficient_.cend(); }

private:
    std::vector<float> coeficient_;
};

Polynomial add_polynomials(const Polynomial& p1, const Polynomial& p2);

std::size_t size_t_max(int a, int b);

int intmax(int a, int b);

std::string to_str(const Polynomial& v);

Polynomial derivate(const Polynomial& polinomial);

Polynomial integral(const Polynomial& polinomial);

Polynomial polynomial_multiplication(const Polynomial& p1, const Polynomial& p2);

float pow(float a, int power);

float value(const Polynomial& polynomial, float val);

Polynomial multiplicate_polynomial(const Polynomial& p, float a);

float sqr(float a, int n = 2, int accuracy = 100000);

std::tuple<Polynomial, float> divide(const Polynomial& p, float x);

#endif //PROJEKT_KALKULATOR_KALKULATOR_HPP
