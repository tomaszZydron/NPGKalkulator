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
double scalar_product(const Vect& v1, const Vect& v2) {
    double scalar = 0;
    for(std::size_t i = 0; i < v1.size(); i++){
        scalar += v1[i] * v2[i];
    }
    return scalar;
}

//mnożenie wektora przez skalar
Vect multiply_vector(const Vect& v, double scalar){
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


//wektor na string
std::string vector_to_string(const Vect& v){
    std::ostringstream to_string;
    to_string << "[";
    for(auto i = v.cbegin(); i != v.cend(); ++i){
        to_string << *i;
        if(i != v.cend() - 1) {
            to_string << ", ";
        }
    }
    to_string << "]";
    return to_string.str();
}

//konstruktor kopiujący?
Matrix::Matrix(const std::vector<std::vector<double>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
}

//matrix na stringa
std::string matrix_to_string(const Matrix& m){
    std::ostringstream to_string;

    to_string << "[" << "\n";
    for (auto i = m.cbegin(); i != m.cend(); ++i) {
        to_string << " " << vector_to_string(*i);
        if (i != m.cend() - 1){
            to_string << ";";
        }
        to_string << "\n";
    }
    to_string << "]";

    return to_string.str();
}

//dodawanie macierzy
Matrix add_matrices(const Matrix& m1, const Matrix& m2){
    Matrix matrices_sum(m1);
    for(std::size_t i = 0; i < m1.size(); i++){
        matrices_sum[i] = add_vectors(m1[i], m2[i]);
    }
    return matrices_sum;
}

//mnożenie macierzy przez skalar
Matrix multiply_matrix(const Matrix& m, double scalar){
    Matrix multiplied_matrix(m);
    for(std::size_t i = 0; i < m.size(); i++){
        multiplied_matrix[i] = multiply_vector(m[i], scalar);
    }
    return multiplied_matrix;
}

//macierz transponowana
Matrix transpose_matrix(const Matrix& m){
    std::size_t m_cols = m[0].size();
    std::size_t m_rows = m.size();
    Matrix transpose(m_cols, m_rows);
    for (std::size_t i = 0; i < m_cols; i++){
        for(std::size_t j = 0; j < m_cols; j++){
            transpose[i][j] = m[j][i];
        }
    }
    return transpose;
}

//mnożenie dwóch macierzy
Matrix multiply_matrices(const Matrix& m1, const Matrix& m2 ){
    transpose_matrix(m2);
    std::size_t size = m1.size();
    Matrix result(size, size);
    for (std::size_t i = 0; i < size; i++){
        for(std::size_t j = 0; j < size; j++){
            result[i][j] = scalar_product(m1[i], m2[j]);
        }
    }
    return result;
}
//mnożenie wiersza przez skalar
void multiply_row(Matrix& m, int row, double c){

    multiply_vector(m[row], c);

}

//dodawanie wiersza razy skalar
void add_row(Matrix& m, int row_1, int row_2, double c){
    for(size_t i = 0; i < m[0].size(); i++){
        m[row_1][i] = c * m[row_2][i];
    }
}

//zamiana wierszy
void swap_rows(Matrix& m, int row_1, int row_2){
     Vect swap(m[row_1].size());
     swap = m[row_1];
     m[row_1] = m[row_2];
     m[row_2] = swap;
}

//postać schodkowa macierzy
void echelon_form(Matrix& m){
    int m_rows = m.size();
    int m_cols = m[0].size();

    int r = 0;
    int c = 0;
    while(r < m_rows and c < m_cols){
        int i =0;
        while(i + r < m_rows and m[i+r][c] == 0){
            i++;
        }
        if(i + r == m_rows){
            c += 1;
        }
        else {
            if(i != 0){
                swap_rows(m, r, r + i);
            }
            for(int j = 1; r + j < m_rows; j++){
                if(m[r + j][c] != 0){
                    add_row(m, r + j, r, -m[r + j][c]/m[r][c]);
                }
            }
            r += 1;
            c += 1;
        }
    }
}

//
int **submatrix(int **matrix, int n, int x, int y) {
    int **submatrix = new int *[n - 1];
    int subi = 0;
    for (int i = 0; i < n; i++) {
        submatrix[subi] = new int[n - 1];
        int subj = 0;
        if (i == y) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j == x) {
                continue;
            }
            submatrix[subi][subj] = matrix[i][j];
            subj++;
        }
        subi++;
    }
    return submatrix;
}

//liczenie wyznacznika macierzy
double matrix_determinant(Matrix& m){
    double det = 1;
//brak sprawdzenia czy wymiary są równe!!!

    if (m.size() == 1) {
        //wyznacznik macierzy jednoelementowej to ten element
        det = m[0][0];
    }
    else if (m.size() == 2) {
        //dla macierzy 2x2 metoda "na cebulkę"
        det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }
    else {
        echelon_form(m);
        for(size_t i = 0; i < m.size(); i++){
            det *= m[i][i];
        }

    }
    return det;
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

//Dodawanie liczb zespolonych
Complex ComplexAdd(Complex z1, Complex z2) {
    Complex z3;
    z3.Re = z1.Re + z2.Re;
    z3.Im = z1.Im + z2.Im;
    return z3;
}

//Odejmowanie liczb zespolonych
Complex ComplexSubtraction(Complex z1, Complex z2) {
    Complex z3;
    z3.Re = z1.Re - z2.Re;
    z3.Im = z1.Im - z2.Im;
    return z3;
}

//Mnożenie liczb zespolonych
Complex ComplexMultiply(Complex z1, Complex z2) {
    Complex z3;
    z3.Re = z1.Re * z2.Re - z1.Im * z2.Im;
    z3.Im = z1.Re * z2.Im + z1.Im * z2.Re;
    return z3;
}

//Dzielenie liczb zespolonych
Complex ComplexDevide(Complex z1, Complex z2) {
    Complex z3;
    double w;
    w = z2.Re * z2.Re + z2.Im * z2.Im;

    if (w > 0) {
        z3.Re = (z1.Re * z2.Re + z1.Im * z2.Im) / w;
        z3.Im = (z2.Re * z1.Im - z1.Re * z2.Im) / w;
        return z3;
    }

    else {
        printf("FUNCTION C_DIV ERROR: Wystapil blad podczas dzielenia \n");
        system("PAUSE");
        exit(10);
    }
}

//Liczba zespolona na stringa (postać kanoniczna)
std::string complex_to_string(Complex z) {
    std::ostringstream to_string;
    if (z.Re != 0) {
        to_string << z.Re;
        to_string << " + ";
    }
    if (z.Im != 0) {
        to_string << z.Im;
        to_string << "i";
    }
    return to_string.str();
}

//Postać trygonometryczna liczby zespolonej jako string
std::string complex_trig_string(Complex z) {
    std::ostringstream trig_string;

    double phi; //kąt skierowany
    double r; //moduł liczby zespolonej

    r = sqrt(z.Re * z.Re + z.Im * z.Im);

    if (r == 0) {
        trig_string << 0;
    }

    else {
        if (z.Im >= 0) {
            phi = acos(z.Re / r);
        }
        else {
            phi = -acos(z.Re / r);
        }

        trig_string << r;
        trig_string << "( cos(";
        trig_string << phi;
        trig_string << ") + i sin(";
        trig_string << phi;
        trig_string << ") )";
    }

    return trig_string.str();
}

//Postać wykładnicza liczby zespolonej jako string
std::string complex_euler_string(Complex z) {
    std::ostringstream euler_string;

    double phi; //kąt skierowany
    double r; //moduł liczby zespolonej

    r = sqrt(z.Re * z.Re + z.Im * z.Im);

    if (r == 0) {
        euler_string << 0;
    }

    else {
        if (z.Im >= 0) {
            phi = acos(z.Re / r);
        }
        else {
            phi = -acos(z.Re / r);
        }

        euler_string << r;
        euler_string << " exp(i ";
        euler_string << phi;
        euler_string << ")";
    }

    return euler_string.str();
}

//Pierwiastkowanie liczb zespolonych
std::string ComplexRoot(Complex z, int degree) {
    std::ostringstream answers;
    answers << "(";

    double phi; //kąt skierowany
    double r; //moduł liczby zespolonej

    r = sqrt(z.Re * z.Re + z.Im * z.Im);

    if (r == 0) {
        for(int i = 0; i < degree; i++) {
            answers << 0;
            answers << ", ";
        }

    }

    else {
        if (z.Im >= 0) {
            phi = acos(z.Re / r);
        }
        else {
            phi = -acos(z.Re / r);
        }
        for (int i = 0; i < degree; i++) {
            std::ostringstream answer_string;
            answer_string << r;
            answer_string << "( cos(";
            answer_string << (phi + 2 * i) / degree;
            answer_string << ") + i sin(";
            answer_string << (phi + 2 * i) / degree;
            answer_string << ") )";
            answers << answer_string.str();
            answers << ",    ";
        }
    }
    answers << ")";
    return answers.str();
}
