#ifndef POLYNOME_H
#define POLYNOME_H

#include <iostream>

class Polynome
{
private:
    int degre;
    int* contenu;

public:
    // Constructeur
    Polynome(int d = 1);

    // Constructeur de copie
    Polynome(const Polynome& p);

    // Destructeur
    ~Polynome();

    // Affichage mathématique
    void affiche() const;

    // Comparaison
    bool operator==(const Polynome& p) const;

    // Multiplication par un réel : P * k
    Polynome operator*(double k) const;

    // Opérateurs de flux
    friend std::ostream& operator<<(std::ostream& os, const Polynome& p);
    friend std::istream& operator>>(std::istream& is, Polynome& p);
};

// Pour permettre k * P
Polynome operator*(double k, const Polynome& p);

#endif