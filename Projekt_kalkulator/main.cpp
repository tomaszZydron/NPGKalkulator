#include <iostream>

int main() {
    std::cout << "Witaj użytkowniku w kalkulatorze matematycznym  :P ";
    std::cout << "Wtbierz na czym chcesz wykonać operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany";
    int odp;
    std::cin >> odp;
    if (odp == 1) {
        std::cout
                << "Wtbierz operacje jaka chcesz wykonać \n 1 -dodawanie \n 2 - iloczyn skalarny \n 3 - mnożenie przez skalar";
        std::cin >> odp;
    }
    else if (odp == 2) {
        std::cout << "";
        std::cin >> odp;
    }
    else if (odp == 3) {
        std::cout << "";
        std::cin >> odp;
    }
    return 0;
}
