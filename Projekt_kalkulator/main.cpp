#include <iostream>
#include <vector>
#include <sstream>
#include "kalkulator.hpp"

int type_size_vec(){
    int size = 0;
    while (size < 1){
        std::cout << "Podaj rozmiar wektora: \n";
        std::cin >> size;
    }
    return size;
}


std::vector<double> type_vec(int size ){
    std::vector <double> v;
    std::cout << "Wpisz wektor: \n";
    double x;
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

std::vector<std::vector<int>> type_matrix(int rows, int cols){
    std::vector<std::vector<int>> matrix;
    int value = 0;
    for (int x = 0 ; x < cols ; x++) {
        std::vector<int> column;
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

void print_matrix(int rows, int cols, std::vector<std::vector<int>> matrix) {
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

std::vector<double> type_complex_number(){

    std::vector<double> complex_number;
    double x;

    std::cout << "Podaj czesc rzeczywista: ";
    std::cin >> x;
    complex_number.push_back(x);

    std::cout << "Podaj czesc urojona: ";
    std::cin >> x;
    complex_number.push_back(x);

    return complex_number;
}

int main() {
    std::cout << "Witaj uzytkowniku w kalkulatorze matematycznym  :P ";
    std::cout << "Wybierz na czym chcesz wykonać operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany  \n 4 - liczby zespolone  \n";
    int odp;
    std::cin >> odp;
    if (odp == 1) { //wektor
        std::cout<< "Wybierz operacje jaka chcesz wykonac \n 1 -dodawanie \n 2 - iloczyn skalarny \n 3 - mnozenie przez skalar \n 4 - sprawdzanie zaleznosci \n 5 - obliczanie normy \n";
        std::cin >> odp;

        if (odp == 1){ //dodawanie
            int size = type_size_vec();
            std::cout << "Pierwszy wektor: \n";
            Vect v1 = type_vec(size);
            std::cout << "Drugi wektor: \n";
            Vect v2 = type_vec(size);
            std::cout << "Suma wektorow to: " << vector_to_string(add_vectors(v1, v2)) ;
        }

        if (odp == 2){ // iloczyn skalarny
            int size = type_size_vec();
            std::cout << "Pierwszy wektor: \n";
            Vect v1 = type_vec(size);
            std::cout << "Drugi wektor: \n";
            Vect v2 = type_vec(size);
            std::cout << "Iloczyn skalarny wektorow to: " << scalar_product(v1, v2);
        }

        if (odp == 3){ // mnożenie przez skalar
            int size = type_size_vec();
            Vect v1 = type_vec(size);
            double scalar = 0;
            std::cout << "Podaj skalar: ";
            std::cin >> scalar;
            std::cout << "Wektor przemnozony przez skalar to : " << vector_to_string(multiply_vector(v1, scalar));
        }

        if (odp == 4){ // sprawdzenie zależności
            int size = type_size_vec();

            std::cout << "Pierwszy wektor: \n";
            Vect v1 = type_vec(size);
            std::cout << "Drugi wektor: \n";
            Vect v2 = type_vec(size);

            bool dependance = two_vector_dependance(v1, v2);
            if(dependance == true){
                std::cout << "Wektory sa zalezne.";
            }
            else {
                std::cout << "Wektory nie sa zalezne.";
            }

        }

        if (odp == 5){ //obliczanie normy
            int size = type_size_vec();
            Vect v1 = type_vec(size);

            std::cout << "Norma wektora wynosi: " << v1.norm();

        }
    }
    else if (odp == 2) { //macierze
        std::cout<< "Wybierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn \n";
        std::cin >> odp;
        if (odp == 1){ //dodawanie
            std::vector<int> size = type_size_matrix();
            std::vector<std::vector<int>>matrix1 = type_matrix(size[0],size[1]);
            //std::vector<std::vector<int>>matrix2 = type_matrix(size[0],size[1]);

            print_matrix(size[0],size[1],matrix1);

        }
        if (odp == 2){ //iloczyn
            std::vector<int> size = type_size_matrix();
            std::vector<std::vector<int>>matrix1 = type_matrix(size[0],size[1]);
            std::vector<std::vector<int>>matrix2 = type_matrix(size[0],size[1]);
        }
    }
    else if (odp == 3) { //wielomiany
        std::cout << "";
        std::cin >> odp;
    }

    //liczby zespolone
    else if (odp == 4) {
        std::cout << "Wybierz operacje jaka chcesz wykonac \n 1 -dodawanie \n 2 - odejmowanie \n 3 - mnozenie \n 4 - dzielenie \n";
        std::cin >> odp;

        std::vector<double> complex_number;
        std::cout << "Podaj pierwsza liczbe zespolona:";
        complex_number = type_complex_number();

        Complex z1;
        z1.Re = complex_number[0];
        z1.Im = complex_number[1];

        std::cout << "Podaj druga liczbe zespolona:";
        complex_number = type_complex_number();

        Complex z2;
        z2.Re = complex_number[0];
        z2.Im = complex_number[1];

        if (odp == 1){ //dodawanie
            Complex z3 = ComplexAdd(z1, z2);

            std::cout << "Suma liczb zespolonych to: \n";
            std::cout << "Postac kanoniczna: " << complex_to_string(z3) << "\n";
            std::cout << "Postac trygonometryczna: " << complex_trig_string(z3) << "\n";
            std::cout << "Postac wykladnicza: " << complex_euler_string(z3) << "\n";

        }
        else if (odp == 2){ //odejmowanie

        }
        else if (odp == 3){ //mnożenie

        }
        else if (odp == 4){ //dzielenie

        }
    }
    return 0;
}