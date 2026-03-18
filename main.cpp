#include <iostream>

#include "POINT.h"
#include "rectangle.h"

int main() {
    int n;
    std::cout << "Donner le nombre de rectangles: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Nombre invalide.\n";
        return 0;
    }

    RECTANGLE* tab = new RECTANGLE[n];

    for (int i = 0; i < n; i++) {
        std::cout << "\n--- Rectangle " << (i + 1) << " ---\n";
        tab[i].saisir();
    }

    RECTANGLE inter = tab[0];
    RECTANGLE tmp;

    int ok = 1;
    for (int i = 1; i < n; i++) {
        ok = inter.intersection(tab[i], tmp);
        if (!ok) break;
        inter = tmp;
    }

    std::cout << "\n==== RESULTAT ====\n";
    if (!ok) {
        std::cout << "Intersection vide.\n";
        tmp.afficher();
    } else {
        std::cout << "Intersection de tous les rectangles:\n";
        inter.afficher();
    }

    delete[] tab;
    return 0;
}
