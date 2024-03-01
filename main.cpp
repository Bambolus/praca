#include <iostream>
#include <cstdlib>
#include "sortowanie.hpp"
#include "wyszukiwanie.hpp"
#include "sortowanie.cpp"
#include "wyszukiwanie.cpp"
using namespace std;

// Funkcja do generowania losowych liczb i wyświetlania tablicy
void tablica(int t[], int rozmiar, int klucz) {
    int x = 25;
    bool znaleziono = false;
    for(int i = 0; i < rozmiar; i++) {
        t[i] = rand() % x;
        cout << t[i] << ", ";
        if (t[i] == klucz && !znaleziono) {
            znaleziono = true;
        }
    }
    cout << "\n";
}
int main() {
    const int n = 12;
    int t[n];
    cout << "Tablica: ";
    int klucz = 8;
    tablica(t, n, klucz);
    cout << "Tablica po sortowaniu bombelkowym: ";
    bombelkowe(t, n);
    cout << "Tablica po sortowaniu koktajlowym: ";
    koktajlowe(t, n);
    cout << "Tablica po sortowaniu przez scalanie: ";
    scalanie(t, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << t[i] << ", ";
    }
    cout << endl;
    cout << "Tablica po sortowaniu szybkim: ";
    szybkiesortowanie(t, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << t[i] << ", ";
    }
    cout << endl;
    cout << "Wyszukiwanie liniowe: ";
    int index = liniowe(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    cout << "Wyszukiwanie liniowe z wartownikiem: ";
    index = liniowezwartownikiem(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    cout << "Wyszukiwanie skokowe: ";
    index = skokowe(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    cout << "Wyszukiwanie binarne: ";
    index = binarne(t, n, klucz);
    if (index != -1)
        cout << "Znaleziono na indeksie: " << index << endl;
    else
        cout << "Nie znaleziono" << endl;

    return 0;
}

