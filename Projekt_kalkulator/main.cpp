#include <iostream>
#include <vector>
#include <sstream>


int type_size_vec(){
    int size = 0;
    while (size <= 1){
        std::cout << "Podaj rozmiar wkektora: ";
        std::cin >> size;
    }
    return size;
}

std::vector<int> type_vec(int size ){
    std::vector < int > v;
    std::cout << "wpisz wektor: \n";
    int x;
    for (int i = 0; i < size; i++){
        std::cout << "Wypisz " << i+1 << " wartosc: ";
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


int main() {
    std::cout << "Witaj uzytkowniku w kalkulatorze matematycznym  :P ";
    std::cout << "Wybierz na czym chcesz wykonać operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany  \n";
    int odp;
    std::cin >> odp;
    if (odp == 1) { //wektor
        std::cout<< "Wybierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn skalarny \n 3 - mnożenie przez skalar \n";
        std::cin >> odp;
        if (odp == 1){ //dodawanie
            int size = type_size_vec();
            std::vector<int>v1 = type_vec(size);
            std::vector<int>v2 = type_vec(size);
            std::cout << "Suma wektorów to: " ;
        }
        if (odp == 2){ // iloczyn skalarny
            int size = type_size_vec();
            std::vector<int>v1 = type_vec(size);
            std::vector<int>v2 = type_vec(size);
            std:std::cout << "Iloczyn skalarny wektorów to: " ;
        }
        if (odp == 3){ // mnożenie przez skalar
            int size = type_size_vec();
            std::vector<int>v1 = type_vec(size);
            int scalar = 0;
            std::cout << "podaj skalar: ";
            std::cin >> scalar;

        }
    }
    else if (odp == 2) { //macierze
        std::cout<< "Wybierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn \n";
        std::cin >> odp;
        if (odp == 1){ //dodawanie
            std::vector<int> size = type_size_matrix();
            std::vector<std::vector<int>>matrix1 = type_matrix(size[0],size[1]);
            std::vector<std::vector<int>>matrix2 = type_matrix(size[0],size[1]);

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
    return 0;
}
