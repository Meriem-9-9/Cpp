#ifndef POINT_H
#define POINT_H

class POINT
{
private:
    int x;
    int y;

public:
    // Constructeurs
    POINT(int abs = 0, int ord = 0);
    POINT(const POINT& p);

    // Accesseurs
    int abscisse() const;
    int ordonnee() const;

    // Opérateurs
    POINT operator+(const POINT& p) const;
    bool operator==(const POINT& p) const;
};

#endif