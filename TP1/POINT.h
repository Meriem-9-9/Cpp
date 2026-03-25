#ifndef POINT_H
#define POINT_H

class POINT {
public:

    POINT (int x=0, int y=0) {X=x; Y=y; }
    int abscisse () const {return X; }

    int ordonnee () const {return Y; }

private:
    int X;
    int Y;

};

#endif //POINT_H