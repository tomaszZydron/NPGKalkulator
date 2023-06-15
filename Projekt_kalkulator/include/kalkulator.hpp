
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
    Vect(std::size_t n) : v_(n, 0.0) {}
    Vect(const std::vector<double>& v) : v_(v) {}

    //operatory
    const double& operator[](std::size_t position) const {return v_[position];}
    double& operator[](std::size_t position) {return v_[position];}

    //iteratory
    std::vector<double>::const_iterator cbegin() const {return v_.cbegin(); }
    std::vector<double>::const_iterator cend() const {return v_.cend(); }

    std::vector<double>::iterator begin() {return v_.begin(); }
    std::vector<double>::iterator end() {return v_.end(); }

    std::vector<double>::const_iterator begin() const {return v_.cbegin(); }
    std::vector<double>::const_iterator end() const {return v_.cend(); }

    //metoda zwracająca rozmiar wektora
    std::size_t size() const { return v_.size(); }

    //metoda zwracająca normę wektora
    double norm() const;

private:
    std::vector<double> v_;
};

//dodawanie wektorów
Vect add_vectors(const Vect& v1, const Vect& v2);

//iloczyn skalarny wektorów
double scalar_product(const Vect& v1, const Vect& v2);

//mnożenie wektora przez skalar
Vect multiply_vector(const Vect& v, double scalar);

//czy dwa wektory są zależne
bool two_vector_dependance(const Vect& v1, const Vect& v2);

//wektor na stringa
std::string vector_to_string(const Vect& v);


//klasa odpowiadająca za macierze
class Matrix {
public:
    //konstruktory
    Matrix(std::size_t n_rows, std::size_t n_cols) :
            matrix_(n_rows, Vect(n_cols)) {}

    Matrix(const Matrix&) = default;

    Matrix(const std::vector<std::vector<double>>& m);

    std::size_t size() const { return matrix_.size(); }

    //operatory
    const Vect& operator[](std::size_t pos) const { return matrix_[pos]; }
    Vect& operator[](std::size_t pos) { return matrix_[pos]; }

    //iteratory
    std::vector<Vect>::const_iterator cbegin() const { return matrix_.cbegin(); }
    std::vector<Vect>::const_iterator cend() const { return matrix_.cend(); }
    std::vector<Vect>::iterator begin() { return matrix_.begin(); }
    std::vector<Vect>::const_iterator begin() const { return matrix_.cbegin(); }
    std::vector<Vect>::iterator end() { return matrix_.end(); }
    std::vector<Vect>::const_iterator end() const { return matrix_.cend(); }

private:
    std::vector<Vect> matrix_;
};

//matrix na stringa
std::string matrix_to_string(const Matrix& m);

//dodawanie macierzy
Matrix add_matrices(const Matrix& m1, const Matrix& m2);

//macierz transponowana
Matrix transpose_matrix(const Matrix& m);

//mnożenie macierzy przez skalar
Matrix multiply_matrix(const Matrix& m, double scalar);

//mnożenie dwóch macierzy
Matrix multiply_matrices(const Matrix& m1, const Matrix& m2 );

//mnożenie wiersza przez skalar
void multiply_row(Matrix& m, double c);

//dodawanie wiersza razy skalar
void add_row(Matrix& m, int row_1, int row_2, double c);

//zamiana wierszy
void swap_rows(Matrix& m, int row_1, int row_2);

//postać schodkowa macierzy
void echelon_form(Matrix& m);

//liczenie wyznacznika macierzy
double matrix_determinant(const Matrix& m);


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

std::size_t size_t_max(std::size_t a, std::size_t b);


int intmax(int a, int b);

std::string to_str(const Polynomial& v);

Polynomial derivate(const Polynomial& polinomial);

Polynomial integral(const Polynomial& polinomial);

//klasa liczb zespolonych
class Complex{
public:
    double Re;
    double Im;
};

//dodawanie liczb zespolonych
Complex ComplexAdd(Complex c1, Complex c2);

//odejmowanie liczb zespolonych
Complex ComplexSubtraction(Complex c1, Complex c2);

//mnożenie liczb zespolonych
Complex ComplexMultiply(Complex c1, Complex c2);

//Dzielenie liczb zespolonych
Complex ComplexDivide(Complex z1, Complex z2);

//Liczba zespolona na stringa (postać kanoniczna)
std::string complex_to_string(Complex z);

//Postać trygonometryczna liczby zespolonej jako string
std::string complex_trig_string(Complex z);

//Postać wykładnicza liczby zespolonej jako string
std::string complex_euler_string(Complex z);

//Pierwiastkowanie liczb zespolonych
std::string ComplexRoot(Complex z, int degree);

Polynomial polynomial_multiplication(const Polynomial& p1, const Polynomial& p2);

float pow(float a, int power);

float value(const Polynomial& polynomial, float val);

Polynomial multiplicate_polynomial(const Polynomial& p, float a);

float sqr(float a, int n = 2, int accuracy = 100000);

std::tuple<Polynomial, float> divide(const Polynomial& p, float x);

int sn(int n, int k);

class Point
{
    public:
        Point(float x, float y) : x_(x), y_(y) {}
        float get_x() const {return x_;}
        float get_y() const {return y_;}
        ~Point() = default;
        void move(float dx, float dy) {x_ += dx; y_ += dy;}
    private:
        float x_;
        float y_;
};

class Line
{
    public:
        Line(float a, float b, float c) : A_(a), B_(b), C_(c) {}
        Line(const Point& A,const Point& B);
        float get_a() const {return A_;}
        float get_b() const {return B_;}
        float get_c() const {return C_;}
    private:
        float A_;
        float B_;
        float C_;
};
float distance(const Point& A, const Line& line);


#endif //PROJEKT_KALKULATOR_KALKULATOR_HPP
