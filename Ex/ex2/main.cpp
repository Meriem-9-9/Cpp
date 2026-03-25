#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
    POINT a(1, 2);
    POINT b(5, 6);

    RECTANGLE r1(a, b);

    cout << "Rectangle r1 :" << endl;
    r1.afficher();

    cout << "\nSurface : " << r1.surface() << endl;

    if (r1.carre())
        cout << "r1 est un carre" << endl;
    else
        cout << "r1 n'est pas un carre" << endl;

    RECTANGLE r2;
    cout << "\nSaisir le rectangle r2 :" << endl;
    r2.saisir();

    cout << "\nRectangle r2 :" << endl;
    r2.afficher();

    RECTANGLE r3 = r1 + r2;
    cout << "\nRectangle r3 = r1 + r2 :" << endl;
    r3.afficher();

    if (r1 == r2)
        cout << "\nr1 et r2 sont egaux" << endl;
    else
        cout << "\nr1 et r2 sont differents" << endl;

    cout << "\nRotation de r1 de 45 degres :" << endl;
    r1.rotation45();
    r1.afficher();

    return 0;
}