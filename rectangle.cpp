#include "Rectangle.h"
#include <iostream>

RECTANGLE::RECTANGLE() {
    X1 = X2 = Y1 = Y2 = 0;
}

RECTANGLE::RECTANGLE(int x1, int y1, int x2, int y2) {
    X1 = x1;
    Y1 = y1;
    X2 = x2;
    Y2 = y2;
    ordonner();
}

RECTANGLE::RECTANGLE(const POINT& p1, const POINT& p2)
{
    X1 = p1.abscisse();
    Y1 = p1.ordonnee();
    X2 = p2.abscisse();
    Y2 = p2.ordonnee();

    ordonner();
}

void RECTANGLE::ordonner() {
    int temp;
    if (X1 > X2) {
        temp = X1;
        X1 = X2;
        X2 = temp;
    }
    if (Y1 > Y2) {
        temp = Y1;
        Y1 = Y2;
        Y2 = temp;
    }
}

void RECTANGLE::afficher() const {
    std::cout << "Coin en haut à gauche : (" << X1 << "," << Y1 << ")\n";
    std::cout << "Coin en bas à droite : (" << X2 << "," << Y2 << ")\n";
}

void RECTANGLE::saisir() {
    std::cout << "Saisir X1 : "; std::cin >> X1;
    std::cout << "Saisir Y1 : "; std::cin >> Y1;
    std::cout << "Saisir X2 : "; std::cin >> X2;
    std::cout << "Saisir Y2 : "; std::cin >> Y2;
    ordonner();
}

bool RECTANGLE::carre() const {
    int X = X2 - X1;
    int Y = Y2 - Y1;
    if (X == Y)
        return true;
    return false;
}

int RECTANGLE::surface() const {
    int X = X2 - X1;
    int Y = Y2 - Y1;
    int surface=X*Y;
    return surface;
}

void RECTANGLE::rotation90() {
    int centrex = (X1 + X2) / 2;
    int centrey = (Y1 + Y2) / 2;

    int milieux = (X2 - X1) / 2;
    int milieuy = (Y2 - Y1) / 2;

    X1 = centrex - milieuy;
    Y1 = centrey - milieux;
    X2 = centrex + milieuy;
    Y2 = centrey + milieux;

    ordonner();
}

int RECTANGLE::position(const POINT& p) const {
    int px = p.abscisse();
    int py = p.ordonnee();

    if (px > X1 && px < X2 && py > Y1 && py < Y2)
        return 1;
    else if ((px == X1 || px == X2) && py >= Y1 && py <= Y2)
        return 0;
    else if ((py == Y1 || py == Y2) && px >= X1 && px <= X2)
        return 0;
    else
        return -1;
}

void RECTANGLE::translation(const POINT &origine, const POINT &p) {
    int dx = p.abscisse() - origine.abscisse();
    int dy = p.ordonnee() - origine.ordonnee();

    X1 += dx;
    Y1 += dy;
    X2 += dx;
    Y2 += dy;
}

int RECTANGLE::comparer(const RECTANGLE &r) const {
    int s1 = surface();
    int s2 = r.surface();
    if (s1 < s2)
        return -1;
    else if (s1 > s2)
        return 1;
    else
        return 0;
}

int RECTANGLE::position(const RECTANGLE& r) const {
    if (X1 < r.X1 && Y1 < r.Y1 && X2 > r.X2 && Y2 > r.Y2) return 1;
    if (r.X1 < X1 && r.Y1 < Y1 && r.X2 > X2 && r.Y2 > Y2) return 2;

    bool intersect = !(X2 < r.X1 || X1 > r.X2 || Y2 < r.Y1 || Y1 > r.Y2);

    if (!intersect) return -1;
    return 0;
}

RECTANGLE RECTANGLE::unionRect(const RECTANGLE& r) const {
    RECTANGLE u;
    u.X1 = (X1 < r.X1) ? X1 : r.X1;
    u.Y1 = (Y1 < r.Y1) ? Y1 : r.Y1;
    u.X2 = (X2 > r.X2) ? X2 : r.X2;
    u.Y2 = (Y2 > r.Y2) ? Y2 : r.Y2;
    return u;
}

RECTANGLE RECTANGLE::intersection(const RECTANGLE& r) const {
    RECTANGLE inter;
    inter.X1 = (X1 > r.X1) ? X1 : r.X1;
    inter.Y1 = (Y1 > r.Y1) ? Y1 : r.Y1;
    inter.X2 = (X2 < r.X2) ? X2 : r.X2;
    inter.Y2 = (Y2 < r.Y2) ? Y2 : r.Y2;

    if (inter.X1 >= inter.X2 || inter.Y1 >= inter.Y2) {
        inter.X1 = inter.Y1 = inter.X2 = inter.Y2 = 0;
    }
    return inter;
}

int RECTANGLE::intersection(const RECTANGLE& r, RECTANGLE& result) const {
    result.X1 = (X1 > r.X1) ? X1 : r.X1;
    result.Y1 = (Y1 > r.Y1) ? Y1 : r.Y1;
    result.X2 = (X2 < r.X2) ? X2 : r.X2;
    result.Y2 = (Y2 < r.Y2) ? Y2 : r.Y2;

    if (result.X1 >= result.X2 || result.Y1 >= result.Y2) {
        result.X1 = result.Y1 = result.X2 = result.Y2 = 0;
        return 0;
    }
    return 1;
}
