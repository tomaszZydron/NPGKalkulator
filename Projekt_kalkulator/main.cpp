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

//zmienić typ
std::vector<double> type_vec(int size ){
    std::vector <double> v;
    std::cout << "Wpisz wektor: \n";
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
    int size = -1;
    while (size < 0){
        std::cout << "Podaj stopien wielomianu: ";
        std::cin >> size;
    }
    return size + 1;
}

std::vector<float> type_polynomial(int size){
    std::vector <float> v;
    std::cout << "Wpisz wielomian: \n";
    int x;
    for (int i = 0; i < size; i++){
        std::cout << "Wpisz wartosc przy x^" << i << " : ";
        std::cin>>x;
        v.push_back(x);
    }
    return v;
}

int main() {
    std::cout << "Witaj uzytkowniku w kalkulatorze matematycznym  :P ";
    std::cout << "Wybierz na czym chcesz wykonać operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany  \n";
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
        std::cout << "Wybierz operacje jaka chcesz wykonac \n 1 - dodawanie \n 2 - mnozenie \n 3 - znajdowanie pierwiastkow \n 4 - podstawienie argumentu \n 5 - pochodna \n 6 - calka \n";
        std::cin >> odp;
        if(odp == 1) { // dodawanie
            std::cout << "Pierwszy wielomian: \n";
            int size = type_size_polynomial();
            Polynomial p1 = type_polynomial(size);
            std::cout << "Drugi wielomian: \n";
            size = type_size_polynomial();
            Polynomial p2 = type_polynomial(size);
            std::cout << "Suma wielomianow to: " << to_str(add_polynomials(p1, p2));
            //POTRZEBNA POPRAWA FUNKCJI add_polynomials !!!
        }
    }
    return 0;
}