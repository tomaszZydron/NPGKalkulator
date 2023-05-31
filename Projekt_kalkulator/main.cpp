#include <iostream>
#include <vector>
//dupa dasiujhvgiugaysdfoasbfdn
int type_size_vec(){
    int size = 0;
    while (size <= 1){
        std::cout << "Podaj rozmiar wketora: ";
        std::cin >> size;
    }
    return size;
}

std::vector<int> type_vec(int size ){
    std::vector < int > v;
    std::cout << "wpisz wektor: \n";
    int x;
    for (int i = 0; i < size; i++){
        std::cin>>x;
        v.push_back(x);
    }
    return v;
}
std::vector<int> type_size_matrix(){
    int rows = 0;
    while (rows <= 1){
        std::cout << "Podaj ilość wierszy macierzy: ";
        std::cin >> rows;
    }
    int cols = 0;
    while (cols <= 1){
        std::cout << "Podaj ilość kolumn macierzy: ";
        std::cin >> cols;
    }
    std::vector<int>size;
    size.push_back(cols);
    size.push_back(rows);
    return size;
}
//std::vector<int> type_matrix(int rows, int cols){
//    std::vector<int> matrix;
//
//}

int main() {
    std::cout << "Witaj użytkowniku w kalkulatorze matematycznym  :P ";
    std::cout << "Wybierz na czym chcesz wykonać operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany";
    int odp;
    std::cin >> odp;
    if (odp == 1) {
        std::cout<< "Wybierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn skalarny \n 3 - mnożenie przez skalar";
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

        }
    }
    else if (odp == 2) {
        std::cout<< "Wybierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn";
        std::cin >> odp;
        if (odp == 1){

        }
        if (odp == 2){

        }
    }
    else if (odp == 3) {
        std::cout << "";
        std::cin >> odp;
    }
    return 0;
}
