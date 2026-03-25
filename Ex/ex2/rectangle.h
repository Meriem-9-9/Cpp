#ifndef RECTANGLE2_H
#define RECTANGLE2_H

#include "Point.h"

class RECTANGLE
{
private:
    POINT P1;
    POINT P2;

    void ordonner();

public:
    // Constructeurs
    RECTANGLE();
    RECTANGLE(const POINT& p1, const POINT& p2);

    // Méthodes
    void afficher() const;
    void saisir();
    bool carre() const;
    int surface() const;
    void rotation45();

    // Opérateurs
    RECTANGLE operator+(const RECTANGLE& r) const;
    bool operator==(const RECTANGLE& r) const;
};

#endif