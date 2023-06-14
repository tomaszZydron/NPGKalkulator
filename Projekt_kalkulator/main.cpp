#include <iostream>
#include <vector>
#include <sstream>
#include "include/kalkulator.hpp"

int type_size_vec(){
    int size = 0;
    while (size < 1){
        std::cout << "Podaj rozmiar wektora: ";
        std::cin >> size;
    }
    return size;
}

//zmienić typ
std::vector<int> type_vec(int size ){
    std::vector < int > v;
    std::cout << "wpisz wektor: \n";
    int x;
    for (int i = 0; i < size; i++){
        std::cout << "Wpisz " << i+1 << " wartosc: ";
        std::cin>>x;
        v.push_back(x);
    }
    return v;
}

std::vector<int> type_size_matrix(){
    int rows = 0;
    while (rows <= 1){
        std::cout << "Podaj ilosc wierszy macierzy: ";
        std::cin >> rows;
    }
    int cols = 0;
    while (cols <= 1){
        std::cout << "Podaj ilosc kolumn macierzy: ";
        std::cin >> cols;
    }
    std::vector<int>size;
    size.push_back(cols);
    size.push_back(rows);
    return size;
}

std::vector<std::vector<double>> type_matrix(int rows, int cols){
    std::vector<std::vector<double>> matrix;
    double value = 0;
    for (int x = 0 ; x < cols ; x++) {
        std::vector<double> column;
        std::cout << "Wypisz " << x+1 << " kolumne \n";
        for(int y = 0; y <rows ; y++){
            std::cout << "Wypisz " << y+1 << " wartosc: ";
            std::cin >> value;
            column.push_back(value);
        }
        matrix.push_back(column);
    }
    return matrix;
}

void print_matrix(int rows, int cols, std::vector<std::vector<double>> matrix) {
    std::stringstream ss;
    for (int x = 0; x < rows; x++){
        for(int y = 0; y < cols ; y++ ){
            ss <<matrix[x][y]<<" ";
        }
        ss << '\n';
    }
    std::cout << ss.str();
}

int type_size_polynomial(){
    int size = 0;
    while (size <= 1){
        std::cout << "Podaj stopien wielomianu: ";
        std::cin >> size;
    }
    return size;
}

float type_polynomial(int size){
    std::stringstream ss;
    int a = 0;
    for (int i = size; i > 0; i--){
        std::cout << "podaj wartosc przy x^"<<size<<": ";
        std::cin >> a;
        ss<<a<<"*x^"<<i<<" + ";
    }
    float polynomial = ss.get();
    return polynomial;
}

int main() {
    std::cout << "Witaj uzytkowniku w kalkulatorze matematycznym  :P ";
    bool should_calc_work = true;
    while (should_calc_work == true) {
        std::cout << "Wybierz na czym chcesz wykonać operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany  \n";
        int odp;
        std::cin >> odp;
        if (odp == 1) { //wektor
            std::cout
                    << "Wybierz operacje jaka chcesz wykonac \n 1 -dodawanie \n 2 - iloczyn skalarny \n 3 - mnozenie przez skalar \n";
            std::cin >> odp;
            if (odp == 1) { //dodawanie
                int size = type_size_vec();
                std::vector<int> v1 = type_vec(size);
                std::vector<int> v2 = type_vec(size);
                std::cout << "Suma wektorow to: ";
            }
            if (odp == 2) { // iloczyn skalarny
                int size = type_size_vec();
                std::vector<int> v1 = type_vec(size);
                std::vector<int> v2 = type_vec(size);
                std::cout << "Iloczyn skalarny wektorow to: ";
            }
            if (odp == 3) { // mnożenie przez skalar
                int size = type_size_vec();
                std::vector<int> v1 = type_vec(size);
                int scalar = 0;
                std::cout << "podaj skalar: ";
                std::cin >> scalar;

            }
        } else if (odp == 2) { //macierze
            std::cout << "Wybierz operacje jaka chcesz wykonać: \n 1 -dodawanie \n 2 - iloczyn \n 3 - macierz transponowana \n 4 - wyznacznik macierzy \n  5 - postac schodkowa macierzy \n 6 - mnozenie przez skalar \n";
            std::cin >> odp;

            if (odp == 1) { //dodawanie
                std::vector<int> size = type_size_matrix();
                Matrix matrix_1 = type_matrix(size[0], size[1]);
                Matrix matrix_2 = type_matrix(size[0], size[1]);
                std::cout << "Suma  to: " << matrix_to_string(add_matrices(matrix_1, matrix_2));
            }
            if (odp == 2) { //iloczyn
                std::vector<int> size = type_size_matrix();
                std::cout << "Podaj lewa macierz\n ";
                Matrix matrix_1 = type_matrix(size[0], size[1]);
                std::cout << "\n Podaj prawa macierz\n ";
                Matrix matrix_2 = type_matrix(size[0], size[1]);
                std::cout << "\nIloczyn macierzy to " << matrix_to_string(multiply_matrices(matrix_1, matrix_2));
            }
            if (odp == 3) { //macierz transponowana
                std::vector<int> size = type_size_matrix();
                Matrix matrix_1 = type_matrix(size[0], size[1]);
                std::cout << "Macierz tranponowana to: \n " << matrix_to_string(transpose_matrix(matrix_1));
            }
            if (odp == 4) { //wyznacznik macierzy
                std::vector<int> size = type_size_matrix();
                Matrix matrix_1 = type_matrix(size[0], size[1]);
                std::cout << "Wyzancznik macierzy to:  " << matrix_determinant(matrix_1);
            }
            if (odp == 5) { //postać schodkowa macierzy
                std::vector<int> size = type_size_matrix();
                Matrix matrix_1 = type_matrix(size[0], size[1]);
                echelon_form(matrix_1);
                std::cout << "Postac schodkowa macierzy to: \n " << matrix_to_string((matrix_1));
            }
            if (odp == 6) { //mnozenie przez skalar
                std::vector<int> size = type_size_matrix();
                Matrix matrix_1 = type_matrix(size[0], size[1]);
                std::cout << "Podaj skalar: ";
                double scalar;
                std::cin >> scalar;
                std::cout << "Iloczyn to:\n " << matrix_to_string(multiply_matrix(matrix_1,scalar));
            }

        }
        else if (odp == 3) { //wielomiany
            std::cout << "";
            std::cin >> odp;
        }
        std::string ans;
        std::cout << "\n \n czy chcesz wykonać kolejne działanie T/N: ";
        std::cin >> ans;
        if (ans == "N" or ans == "n" or ans == "nie" or ans == "Nie") {
            should_calc_work = false;
            std::cout << "Dziekujemy za korzystanie z naszego kalkulatora, zyczymy milego dnia i ladnej delty :P ";
        }
        std::cout << "\n\n";
    }
        return 0;
}
