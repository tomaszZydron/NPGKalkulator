#include <iostream>
#include <vector>

int main() {
    std::cout << "Witaj użytkowniku w kalkulatorze matematycznym  :P ";
    std::cout << "Wtbierz na czym chcesz wykonać operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany";
    int odp;
    std::cin >> odp;
    if (odp == 1) {
        std::cout<< "Wtbierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn skalarny \n 3 - mnożenie przez skalar";
        std::cin >> odp;
        if (odp == 1){ //dodawanie
            int rozmiar = 0;
            while (rozmiar <= 1){
                std::cout<< "Podaj rozmiar wektora: ";
                std::cin >> rozmiar;
            }
            std::vector < int > v1;
            std::cout << "wpisz pierwszy wektor";
            int x;
            for (int i = 0; i < rozmiar; i++){
                std::cin>>x;
                v1.push_back(x);
            }
            std::vector < int > v2;
            std::cout << "wpisz drugi wektor";
            for (int i = 0; i < rozmiar; i++){
                std::cin>>x;
                v2.push_back(x);
            }
            std:std::cout << "Suma wektorów to: " ;
        }
        if (odp == 2){ // iloczyn skalarny
            int rozmiar = 0;
            while (rozmiar <= 1){
                std::cout<< "Podaj rozmiar wektora: ";
                std::cin >> rozmiar;
            }
            std::vector < int > v1;
            std::cout << "wpisz pierwszy wektor";
            int x;
            for (int i = 0; i < rozmiar; i++){
                std::cin>>x;
                v1.push_back(x);
            }
            std::vector < int > v2;
            std::cout << "wpisz drugi wektor";
            for (int i = 0; i < rozmiar; i++){
                std::cin>>x;
                v2.push_back(x);
            }
            std:std::cout << "Suma wektorów to: " ;
        }
        if (odp == 3){ // mnożenie przez skalar

        }
    }
    else if (odp == 2) {
        std::cout<< "Wtbierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn";
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
