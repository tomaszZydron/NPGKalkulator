#include <iostream>
#include <vector>
#include <sstream>
#include "include/kalkulator.hpp"

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
    while (rows < 1){
        std::cout << "Podaj ilosc wierszy macierzy: ";
        std::cin >> rows;
    }
    int cols = 0;
    while (cols <1){
        std::cout << "Podaj ilosc kolumn macierzy: ";
        std::cin >> cols;
    }
    std::vector<int>size = {cols,rows};
    return size;
}

std::vector<std::vector<double>> type_matrix(int rows, int cols){
    std::vector<std::vector<double>> matrix;
    double value = 0;
    for (int x = 0 ; x < cols ; x++) {
        std::vector<double> column;
        std::cout << "Wpisz " << x+1 << " wiersz \n";
        for(int y = 0; y <rows ; y++){
            std::cout << "Wpisz " << y+1 << " wartosc: ";
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
    float x;
    for (int i = 0; i < size; i++){
        std::cout << "Wpisz wartosc przy x^" << i << " : ";
        std::cin>>x;
        v.push_back(x);
    }
    return v;
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
    bool should_calc_work = true;
    while (should_calc_work == true) {
        std::cout << "Witaj uzytkowniku w kalkulatorze matematycznym  :P ";
        std::cout
                << "Wybierz na czym chcesz wykonac operacje \n 1 - wektory \n 2 - macierze \n 3 - wielomiany  \n 4 - liczby zespolone \n  5 - trojkaty\n";
        int odp;
        std::cin >> odp;
            if (odp == 1) { //wektor
                std::cout
                        << "Wybierz operacje jaka chcesz wykonac \n 1 -dodawanie \n 2 - iloczyn skalarny \n 3 - mnozenie przez skalar \n 4 - sprawdzanie zaleznosci \n 5 - obliczanie normy \n";
                std::cin >> odp;

                if (odp == 1) { //dodawanie
                    int size = type_size_vec();
                    std::cout << "Pierwszy wektor: \n";
                    Vect v1 = type_vec(size);
                    std::cout << "Drugi wektor: \n";
                    Vect v2 = type_vec(size);
                    std::cout << "Suma wektorow to: " << vector_to_string(add_vectors(v1, v2));
                }

                if (odp == 2) { // iloczyn skalarny
                    int size = type_size_vec();
                    std::cout << "Pierwszy wektor: \n";
                    Vect v1 = type_vec(size);
                    std::cout << "Drugi wektor: \n";
                    Vect v2 = type_vec(size);
                    std::cout << "Iloczyn skalarny wektorow to: " << scalar_product(v1, v2);
                }

                if (odp == 3) { // mnożenie przez skalar
                    int size = type_size_vec();
                    Vect v1 = type_vec(size);
                    double scalar = 0;
                    std::cout << "Podaj skalar: ";
                    std::cin >> scalar;
                    std::cout << "Wektor przemnozony przez skalar to : "
                              << vector_to_string(multiply_vector(v1, scalar));
                }

                if (odp == 4) { // sprawdzenie zależności
                    int size = type_size_vec();

                    std::cout << "Pierwszy wektor: \n";
                    Vect v1 = type_vec(size);
                    std::cout << "Drugi wektor: \n";
                    Vect v2 = type_vec(size);

                    bool dependance = two_vector_dependance(v1, v2);
                    if (dependance == true) {
                        std::cout << "Wektory sa zalezne.";
                    } else {
                        std::cout << "Wektory nie sa zalezne.";
                    }

                }

                if (odp == 5) { //obliczanie normy
                    int size = type_size_vec();
                    Vect v1 = type_vec(size);

                    std::cout << "Norma wektora wynosi: " << v1.norm();

                }
            }
            else if (odp == 2) { //macierze
                std::cout
                        << "Wybierz operacje jaka chcesz wykonać: \n 1 -dodawanie \n 2 - iloczyn \n 3 - macierz transponowana \n 4 - wyznacznik macierzy \n  5 - postac schodkowa macierzy \n 6 - mnozenie przez skalar \n";
                std::cin >> odp;

                if (odp == 1) { //dodawanie
                    std::cout << "Podaj rozmiar macierzy. \n";
                    std::vector<int> size = type_size_matrix();
                    std::cout << "Podaj pierwsza macierz. \n";
                    Matrix matrix_1 = type_matrix(size[0], size[1]);
                    std::cout << "Podaj druga macierz. \n";
                    Matrix matrix_2 = type_matrix(size[0], size[1]);
                    std::cout << "Suma  to: " << matrix_to_string(add_matrices(matrix_1, matrix_2));
                }
                if (odp == 2) { //iloczyn
                    std::cout << "Podaj lewa macierz\n ";
                    std::vector<int> size_1 = type_size_matrix();
                    while (size_1[0] == 0 and size_1[1] == 0) {
                        std::cout << "Rozmiar macierzy musi być wiekszy od 0x0, wpisz rozmiar macierzy jeszcze raz: \n";
                        size_1 = type_size_matrix();
                    }
                    Matrix matrix_1 = type_matrix(size_1[0], size_1[1]);
                    std::cout << "\n Podaj prawa macierz\n ";
                    std::vector<int> size_2 = type_size_matrix();
                    while (size_2[0] != size_1[1]) {
                        std::cout
                                << " Ilosc wierszy prawej macierzy musi byc rowna iloci kolumn lewej macierzy, czyli: "
                                << size_1[1] << "\n Wpisz rozmiar macierzy jeszcze raz ";
                        size_2 = type_size_matrix();
                    }
                    Matrix matrix_2 = type_matrix(size_2[0], size_2[1]);
                    std::cout << "\nIloczyn macierzy to " << matrix_to_string(multiply_matrices(matrix_1, matrix_2));
                }
                if (odp == 3) { //macierz transponowana
                    std::vector<int> size = type_size_matrix();
                    Matrix matrix_1 = type_matrix(size[0], size[1]);
                    std::cout << "Macierz tranponowana to: \n " << matrix_to_string(transpose_matrix(matrix_1));
                }
                if (odp == 4) { //wyznacznik macierzy
                    std::vector<int> size = type_size_matrix();
                    while (size[0] != size[1]) {
                        std::cout
                                << "Macierz musi byc kwadratowa (wymiary nxn), wpisz rozmiar macierzy jeszcze raz: \n";
                        size = type_size_matrix();
                    }
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
                    std::cout << "Iloczyn to:\n " << matrix_to_string(multiply_matrix(matrix_1, scalar));
                }

            } else if (odp == 3) { //wielomiany
                std::cout
                        << "Wybierz operacje jaka chcesz wykonac \n 1 - dodawanie \n 2 - mnozenie \n 3 - podstawienie argumentu \n 4 - pochodna \n 5 - calka \n 6 - dzielenie przez (x-a) \n";
                std::cin >> odp;
                if (odp == 1) { // dodawanie
                    std::cout << "Pierwszy wielomian: \n";
                    int size = type_size_polynomial();
                    Polynomial p1 = type_polynomial(size);
                    std::cout << "Drugi wielomian: \n";
                    size = type_size_polynomial();
                    Polynomial p2 = type_polynomial(size);
                    std::cout << "Suma tych wielomianow to: " << to_str(add_polynomials(p1, p2));
                }
                if (odp == 2) { //mnożenie
                    std::cout << "Pierwszy wielomian: \n";
                    int size = type_size_polynomial();
                    Polynomial p1 = type_polynomial(size);
                    std::cout << "Drugi wielomian: \n";
                    size = type_size_polynomial();
                    Polynomial p2 = type_polynomial(size);
                    std::cout << "Iloczyn tych wielomianow to: " << to_str(polynomial_multiplication(p1, p2));
                }
                if (odp == 3) { //podstawienie argumentu
                    std::cout << "Podaj wielomian: \n";
                    int size = type_size_polynomial();
                    Polynomial p1 = type_polynomial(size);
                    std::cout << "Podaj wartosc x, dla ktorej chcesz obliczyc wartosc wielomianu: \n";
                    float val = 0;
                    std::cin >> val;
                    std::cout << "Wartosc wielomianu dla podanego argumentu to: \n" << value(p1, val);
                }
                if (odp == 4) { //pochodna
                    std::cout << "Podaj wielomian: \n";
                    int size = type_size_polynomial();
                    Polynomial p1 = type_polynomial(size);
                    std::cout << "Pochodna tego wielomianu to: " << to_str(derivate(p1));
                }
                if (odp == 5) { //całka
                    std::cout << "Podaj wielomian: \n";
                    int size = type_size_polynomial();
                    Polynomial p1 = type_polynomial(size);
                    std::cout << "Całka tego wielomianu to: " << to_str(integral(p1));
                }
                if (odp == 6) { //dzielenie przez (x-a)
                    std::cout << "Podaj wielomian do podzielenia: \n";
                    int size = type_size_polynomial();
                    Polynomial p1 = type_polynomial(size);
                    float a = 0;
                    std::cout << "Podaj wartosc a w (x-a): ";
                    std::cin >> a;
                    std::cout << "Wynik tego dzielenia to: " << to_str(std::get<0>(divide(p1, a))) << " + reszta: "
                              << std::get<1>(divide(p1, a));
                }
            } else if (odp == 4) { //zespolone
                std::cout
                        << "Wybierz operacje jaka chcesz wykonac \n 1 -dodawanie \n 2 - odejmowanie \n 3 - mnozenie \n 4 - dzielenie \n 5 - pierwiastkowanie \n 6 - postac trygonometryczna \n 7 - postac wykladnicza \n";
                std::cin >> odp;

                std::vector<double> complex_number;

                if (1 <= odp and odp <= 4) {
                    std::cout << "Podaj pierwsza liczbe zespolona: \n";
                    complex_number = type_complex_number();

                    Complex z1;
                    z1.Re = complex_number[0];
                    z1.Im = complex_number[1];

                    std::cout << "\n Podaj druga liczbe zespolona: \n";
                    complex_number = type_complex_number();

                    Complex z2;
                    z2.Re = complex_number[0];
                    z2.Im = complex_number[1];

                    if (odp == 1) { //dodawanie
                        Complex z3 = ComplexAdd(z1, z2);

                        std::cout << "\n Suma liczb zespolonych to: " << complex_to_string(z3) << "\n";

                        //std::cout << "Postac trygonometryczna: " << complex_trig_string(z3) << "\n";
                        //std::cout << "Postac wykladnicza: " << complex_euler_string(z3) << "\n";

                    } else if (odp == 2) { //odejmowanie
                        Complex z3 = ComplexSubtraction(z1, z2);
                        std::cout << "\n Roznica liczb zespolonych to: " << complex_to_string(z3) << "\n";

                    } else if (odp == 3) { //mnożenie
                        Complex z3 = ComplexMultiply(z1, z2);
                        std::cout << "Iloczyn liczb zespolonych to: " << complex_to_string(z3) << "\n";

                    } else if (odp == 4) { //dzielenie
                        Complex z3 = ComplexDivide(z1, z2);
                        std::cout << "Iloraz liczb zespolonych to: " << complex_to_string(z3) << "\n";
                    }
                } else if (odp == 5) {//pierwiastek
                    std::cout << "Podaj liczbe zespolona: \n";
                    complex_number = type_complex_number();

                    Complex z1;
                    z1.Re = complex_number[0];
                    z1.Im = complex_number[1];

                    int degree;
                    std::cout << "Podaj stopien pierwiastka: \n";
                    std::cin >> degree;

                    std::cout << "Pierwiastki " << degree << "-ego stopnia to: \n" << ComplexRoot(z1, degree);
                } else if (odp == 6 or odp == 7) {
                    std::cout << "Podaj liczbe zespolona: \n";
                    complex_number = type_complex_number();

                    Complex z1;
                    z1.Re = complex_number[0];
                    z1.Im = complex_number[1];


                    if (odp == 6) {//postać trygonometryczna
                        std::cout << "Postac trygonometryczna: \n" << complex_trig_string(z1) << "\n";
                    }
                    if (odp == 7) {//postać wykładnicza
                        std::cout << "Postac wykladnicza: \n" << complex_euler_string(z1) << "\n";
                    }
                }
            } else if (odp == 5) {//geometria {
                float x, y;
                std::cout << "\npodaj wspolrzedna x punktu A: ";
                std::cin >> x;
                std::cout << "\npodaj wspolrzedna y punktu A: ";
                std::cin >> y;
                Point A = Point(x, y);
                std::cout << "\npodaj wspolrzedna x punktu B: ";
                std::cin >> x;
                std::cout << "\npodaj wspolrzedna y punktu B: ";
                std::cin >> y;
                Point B = Point(x, y);
                std::cout << "\npodaj wspolrzedna x punktu C: ";
                std::cin >> x;
                std::cout << "\npodaj wspolrzedna y punktu C: ";
                std::cin >> y;
                Point C = Point(x, y);
                Triangle t = Triangle(A, B, C);
                odp = 0;
                while (odp != 5) {
                    std::cout
                            << "Wybierz operacje jaka chcesz wykonac \n 1 - pole trojkata \n 2 - dlugosci bokow trojkata \n 3 - katy trojkata \n 4 - srodek ciezkosci trojkata\n 5- wyjscie\n";
                    std::cin >> odp;
                    switch (odp) {
                        case 1: {
                            std::cout << "Pole trojkata to " << t.triangle_area() << "\n";
                            break;
                        }
                        case 2: {
                            std::map<Point, float> dictionary = t.sides_lengths();
                            std::cout << "lA = " << dictionary[t.get_a()] << std::endl;
                            std::cout << "lB = " << dictionary[t.get_b()] << std::endl;
                            std::cout << "lC = " << dictionary[t.get_c()] << std::endl;
                            break;
                        }
                        case 3: {
                            std::map<Point, float> dictionary = t.angles();
                            std::cout << "kat przy wierzcholku A = " << dictionary[t.get_a()] << std::endl;
                            std::cout << "kat przy wierzcholku B = " << dictionary[t.get_b()] << std::endl;
                            std::cout << "kat przy wierzcholku C = " << dictionary[t.get_c()] << std::endl;
                            break;
                        }
                        case 4: {
                            Point center = t.center_of_mass();
                            std::cout << "Srodek ciezkosci to (" << center.get_x() << ", " << center.get_y() << ")\n";
                            break;
                        }
                        case 5: {
                            break;
                        }
                        default: {
                            std::cout << "niepoprawne wejscie, sprobuj jeszcze raz: ";
                            break;
                        }
                    }
                }
            }

            std::string ans;
            std::cout << "\n \n Czy chcesz wykonac kolejne dzialanie T/N: ";
            std::cin >> ans;
            if (ans == "N" or ans == "n" or ans == "nie" or ans == "Nie") {
                should_calc_work = false;
                std::cout << "Dziekujemy za korzystanie z naszego kalkulatora, zyczymy milego dnia i ladnej delty :P ";
            }
            std::cout << "\n\n";
        }

        return 0;
}

