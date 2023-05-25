
#ifndef PROJEKT_KALKULATOR_KALKULATOR_HPP
#define PROJEKT_KALKULATOR_KALKULATOR_HPP

#include <vector>


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
