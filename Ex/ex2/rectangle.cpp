#include "rectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

void RECTANGLE::ordonner()
{
    int x1 = P1.abscisse();
    int y1 = P1.ordonnee();
    int x2 = P2.abscisse();
    int y2 = P2.ordonnee();

    if (x1 > x2)
    {
        int t = x1;
        x1 = x2;
        x2 = t;
    }

    if (y1 > y2)
    {
        int t = y1;
        y1 = y2;
        y2 = t;
    }

    P1 = POINT(x1, y1);
    P2 = POINT(x2, y2);
}

// Constructeur par défaut
RECTANGLE::RECTANGLE() : P1(0, 0), P2(0, 0)
{
}

// Constructeur avec 2 points
RECTANGLE::RECTANGLE(const POINT& p1, const POINT& p2)
    : P1(p1), P2(p2)
{
    ordonner();
}

// Affichage
void RECTANGLE::afficher() const
{
    cout << "P1(" << P1.abscisse() << "," << P1.ordonnee() << ")" << endl;
    cout << "P2(" << P2.abscisse() << "," << P2.ordonnee() << ")" << endl;
}

// Saisie
void RECTANGLE::saisir()
{
    int x1, y1, x2, y2;

    cout << "Saisir X1 : ";
    cin >> x1;
    cout << "Saisir Y1 : ";
    cin >> y1;
    cout << "Saisir X2 : ";
    cin >> x2;
    cout << "Saisir Y2 : ";
    cin >> y2;

    P1 = POINT(x1, y1);
    P2 = POINT(x2, y2);

    ordonner();
}

// Test carré
bool RECTANGLE::carre() const
{
    int dx = P2.abscisse() - P1.abscisse();
    int dy = P2.ordonnee() - P1.ordonnee();

    return dx == dy;
}

// Surface
int RECTANGLE::surface() const
{
    int dx = P2.abscisse() - P1.abscisse();
    int dy = P2.ordonnee() - P1.ordonnee();

    return dx * dy;
}

// Rotation de 45 degrés par rapport au centre
void RECTANGLE::rotation45()
{
    double cx = (P1.abscisse() + P2.abscisse()) / 2.0;
    double cy = (P1.ordonnee() + P2.ordonnee()) / 2.0;

    double angle = 3.1415926535 / 4.0; // 45°
    double c = cos(angle);
    double s = sin(angle);

    double x1 = P1.abscisse();
    double y1 = P1.ordonnee();
    double x2 = P2.abscisse();
    double y2 = P2.ordonnee();

    int nx1 = (int)(cx + (x1 - cx) * c - (y1 - cy) * s);
    int ny1 = (int)(cy + (x1 - cx) * s + (y1 - cy) * c);

    int nx2 = (int)(cx + (x2 - cx) * c - (y2 - cy) * s);
    int ny2 = (int)(cy + (x2 - cx) * s + (y2 - cy) * c);

    P1 = POINT(nx1, ny1);
    P2 = POINT(nx2, ny2);

    ordonner();
}

// Opérateur +
RECTANGLE RECTANGLE::operator+(const RECTANGLE& r) const
{
    POINT np1 = P1 + r.P1;
    POINT np2 = P2 + r.P2;

    return RECTANGLE(np1, np2);
}

// Opérateur ==
bool RECTANGLE::operator==(const RECTANGLE& r) const
{
    return P1 == r.P1 && P2 == r.P2;
}