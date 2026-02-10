#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "POINT.h"

class RECTANGLE {
    private:
        int X1, Y1, X2, Y2;

    public:
        RECTANGLE();
        RECTANGLE(int x1 , int y1, int x2, int y2 );
        RECTANGLE(const POINT &p1, const POINT &p2);

        int getX1() const;
        int getY1() const { return Y1; }
        int getX2() const { return X2; }
        int getY2() const { return Y2; }

        void afficher() const;
        void saisir();
        bool carre() const;
        int surface() const;
        void rotation90();

        int position(const POINT &p) const;
        void translation(const POINT &origine, const POINT &p);

        int comparer(const RECTANGLE& r) const;
        int position(const RECTANGLE &r) const;

        RECTANGLE unionRect(const RECTANGLE& r) const;

        RECTANGLE intersection(const RECTANGLE& r) const;

        int intersection(const RECTANGLE& r, RECTANGLE& result) const;

        void ordonner();
};

#endif
