#include "rectangle2.h"
#include <iostream>

void RECTANGLE::ordonner() {
    int x1 = P1.abscisse(), y1 = P1.ordonnee();
    int x2 = P2.abscisse(), y2 = P2.ordonnee();

    if (x1 > x2) { int t = x1; x1 = x2; x2 = t; }
    if (y1 > y2) { int t = y1; y1 = y2; y2 = t; }

    P1 = POINT(x1, y1);
    P2 = POINT(x2, y2);
}

// Constructeur par défaut
RECTANGLE::RECTANGLE() : P1(0, 0), P2(0, 0) {}

// Constructeur avec 4 entiers
/*RECTANGLE::RECTANGLE(int x1, int y1, int x2, int y2)
    : P1(x1, y1), P2(x2, y2) {
    ordonner();
}*/

// Constructeur avec 2 POINT
RECTANGLE::RECTANGLE(const POINT& p1, const POINT& p2)
    : P1(p1), P2(p2) {
    ordonner();
}

void RECTANGLE::afficher() const {
    std::cout << "Coin en haut a gauche : ("
              << P1.abscisse() << "," << P1.ordonnee() << ")\n";
    std::cout << "Coin en bas a droite  : ("
              << P2.abscisse() << "," << P2.ordonnee() << ")\n";
}

void RECTANGLE::saisir() {
    int x1, y1, x2, y2;
    std::cout << "Saisir X1 : "; std::cin >> x1;
    std::cout << "Saisir Y1 : "; std::cin >> y1;
    std::cout << "Saisir X2 : "; std::cin >> x2;
    std::cout << "Saisir Y2 : "; std::cin >> y2;
    P1 = POINT(x1, y1);
    P2 = POINT(x2, y2);
    ordonner();
}

bool RECTANGLE::carre() const {
    int dx = P2.abscisse() - P1.abscisse();
    int dy = P2.ordonnee() - P1.ordonnee();
    return dx == dy;
}

int RECTANGLE::surface() const {
    int dx = P2.abscisse() - P1.abscisse();
    int dy = P2.ordonnee() - P1.ordonnee();
    return dx * dy;
}

void RECTANGLE::rotation90() {
    int cx = (P1.abscisse() + P2.abscisse()) / 2;
    int cy = (P1.ordonnee() + P2.ordonnee()) / 2;
    int mx = (P2.abscisse() - P1.abscisse()) / 2;
    int my = (P2.ordonnee() - P1.ordonnee()) / 2;

    P1 = POINT(cx - my, cy - mx);
    P2 = POINT(cx + my, cy + mx);
    ordonner();
}

int RECTANGLE::position(const POINT& p) const {
    int px = p.abscisse(), py = p.ordonnee();
    int x1 = P1.abscisse(), y1 = P1.ordonnee();
    int x2 = P2.abscisse(), y2 = P2.ordonnee();

    if (px > x1 && px < x2 && py > y1 && py < y2)
        return 1;
    else if ((px == x1 || px == x2) && py >= y1 && py <= y2)
        return 0;
    else if ((py == y1 || py == y2) && px >= x1 && px <= x2)
        return 0;
    else
        return -1;
}

void RECTANGLE::translation(const POINT& origine, const POINT& p) {
    int dx = p.abscisse() - origine.abscisse();
    int dy = p.ordonnee() - origine.ordonnee();
    P1 = POINT(P1.abscisse() + dx, P1.ordonnee() + dy);
    P2 = POINT(P2.abscisse() + dx, P2.ordonnee() + dy);
}

int RECTANGLE::comparer(const RECTANGLE& r) const {
    int s1 = surface(), s2 = r.surface();
    if (s1 < s2) return -1;
    if (s1 > s2) return  1;
    return 0;
}

int RECTANGLE::position(const RECTANGLE& r) const {
    int x1 = P1.abscisse(), y1 = P1.ordonnee();
    int x2 = P2.abscisse(), y2 = P2.ordonnee();

    int rx1 = r.getP1().abscisse(), ry1 = r.getP1().ordonnee();
    int rx2 = r.getP2().abscisse(), ry2 = r.getP2().ordonnee();

    // this contient strictement r
    if (x1 < rx1 && y1 < ry1 && x2 > rx2 && y2 > ry2) return 1;
    // r contient strictement this
    if (rx1 < x1 && ry1 < y1 && rx2 > x2 && ry2 > y2) return 2;
    // intersection vide
    if (x2 < rx1 || x1 > rx2 || y2 < ry1 || y1 > ry2) return -1;
    // intersection non vide
    return 0;
}


/*

RECTANGLE RECTANGLE::unionRect(const RECTANGLE& r) const {
    int x1 = (P1.abscisse() < r.getX1()) ? P1.abscisse() : r.getX1();
    int y1 = (P1.ordonnee() < r.getY1()) ? P1.ordonnee() : r.getY1();
    int x2 = (P2.abscisse() > r.getX2()) ? P2.abscisse() : r.getX2();
    int y2 = (P2.ordonnee() > r.getY2()) ? P2.ordonnee() : r.getY2();
    return RECTANGLE(POINT(x1, y1), POINT(x2, y2));
}

RECTANGLE RECTANGLE::intersection(const RECTANGLE& r) const {
    int x1 = (P1.abscisse() > r.getX1()) ? P1.abscisse() : r.getX1();
    int y1 = (P1.ordonnee() > r.getY1()) ? P1.ordonnee() : r.getY1();
    int x2 = (P2.abscisse() < r.getX2()) ? P2.abscisse() : r.getX2();
    int y2 = (P2.ordonnee() < r.getY2()) ? P2.ordonnee() : r.getY2();

    if (x1 >= x2 || y1 >= y2)
        return RECTANGLE(); // vide = (0,0,0,0)
    return RECTANGLE(POINT(x1, y1), POINT(x2, y2));
}

int RECTANGLE::intersection(const RECTANGLE& r, RECTANGLE& result) const {
    int x1 = (P1.abscisse() > r.getX1()) ? P1.abscisse() : r.getX1();
    int y1 = (P1.ordonnee() > r.getY1()) ? P1.ordonnee() : r.getY1();
    int x2 = (P2.abscisse() < r.getX2()) ? P2.abscisse() : r.getX2();
    int y2 = (P2.ordonnee() < r.getY2()) ? P2.ordonnee() : r.getY2();

    if (x1 >= x2 || y1 >= y2) {
        result = RECTANGLE(); // vide
        return 0;
    }
    result = RECTANGLE(POINT(x1, y1), POINT(x2, y2));
    return 1;
}*/
/*
"Dans l'exercice 17, le changement de représentation interne de 4 entiers vers 2 objets POINT"
" impacte uniquement les fonctions liées à la construction et à l'entrée/sortie du rectangle"
" (constructeur, saisir, afficher), car ce sont les seules qui manipulent directement la structure interne."
" Les autres fonctions (surface, position, intersection, comparer...) restent logiquement inchangées car elles"
" ont besoin de calculs arithmétiques sur les coordonnées, ce qui les oblige de toute façon à extraire les valeurs "
"entières via abscisse() et ordonnee(), rendant le changement de représentation transparent à leur niveau."*/