//
// Created by merie_luskpw8 on 25/03/2026.
//

#include <iostream>
#include "Polynome.h"

using namespace std;

int main()
{
    Polynome p1(3);
    cout << "p1 en tableau : " << p1 << endl;
    cout << "p1 en mathematique : ";
    p1.affiche();

    Polynome p2(p1);
    cout << "p2 copie de p1 : " << p2 << endl;

    cout << "Saisir un polynome : degre puis coefficients" << endl;
    cin >> p2;

    cout << "p2 = " << p2 << endl;
    cout << "Affichage mathematique : ";
    p2.affiche();

    if (p1 == p2)
        cout << "p1 et p2 sont egaux" << endl;
    else
        cout << "p1 et p2 sont differents" << endl;

    Polynome p3 = p2 * 2;
    cout << "p2 * 2 = " << p3 << endl;

    Polynome p4 = 3 * p2;
    cout << "3 * p2 = " << p4 << endl;

    return 0;
}