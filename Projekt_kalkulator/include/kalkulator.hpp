
#ifndef PROJEKT_KALKULATOR_KALKULATOR_HPP
#define PROJEKT_KALKULATOR_KALKULATOR_HPP

#include <vector>
#include <cstddef>
#include <string>

//klasa odpoiwadająca za wektory
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

//klasa odpowiadająca za wielomiany
class Polynomial{
public:
    Polynomial(int size, float val = 0) : coeficient_(size, val) {}
    Polynomial(const std::vector<float>& v) : coeficient_(v) {}
    const float& operator[](std::size_t pos) const { return coeficient_[pos]; }
    float& operator[](std::size_t pos) { return coeficient_[pos]; }
private:
    std::vector<float> coeficient_;
};
#endif //PROJEKT_KALKULATOR_KALKULATOR_HPP
