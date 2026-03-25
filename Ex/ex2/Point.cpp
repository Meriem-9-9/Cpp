#include "Point.h"

POINT::POINT(int abs, int ord) : x(abs), y(ord)
{
}

POINT::POINT(const POINT& p) : x(p.x), y(p.y)
{
}

int POINT::abscisse() const
{
    return x;
}

int POINT::ordonnee() const
{
    return y;
}

POINT POINT::operator+(const POINT& p) const
{
    return POINT(x + p.x, y + p.y);
}

bool POINT::operator==(const POINT& p) const
{
    return x == p.x && y == p.y;
}