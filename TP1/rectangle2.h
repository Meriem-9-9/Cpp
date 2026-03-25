//
// Created by merie_luskpw8 on 18/03/2026.
//

#ifndef PARTIE1_2_RECTANGLE2_H
#define PARTIE1_2_RECTANGLE2_H

#include "POINT.h"

class RECTANGLE {

private:

    POINT P1;
    POINT P2;
    void ordonner();

public:
    RECTANGLE();
    // RECTANGLE(int x1, int y1, int x2, int y2);
    RECTANGLE(const POINT& p1, const POINT& p2);

    POINT getP1() const { return P1; }
    POINT getP2() const { return P2; }


    void afficher() const;
    void saisir();
    bool carre() const;
    int surface() const;
    void rotation90();

    int position(const POINT& p) const;
    void translation(const POINT& origine, const POINT& p);

    int comparer(const RECTANGLE& r) const;
    int position(const RECTANGLE& r) const;

    RECTANGLE unionRect(const RECTANGLE& r) const;
    RECTANGLE intersection(const RECTANGLE& r) const;
    int intersection(const RECTANGLE& r, RECTANGLE& result) const;
};




#endif //PARTIE1_2_RECTANGLE2_H