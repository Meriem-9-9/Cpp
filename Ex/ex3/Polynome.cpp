#include "Polynome.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructeur
Polynome::Polynome(int d)
{
    if (d < 0)
    {
        cout << "Degre incorrect, utilisation de la valeur par defaut 1." << endl;
        degre = 1;
    }
    else
    {
        degre = d;
    }

    contenu = new int[degre + 1];

    for (int i = 0; i <= degre; i++)
    {
        contenu[i] = 1;
    }
}

// Constructeur de copie
Polynome::Polynome(const Polynome& p)
{
    degre = p.degre;
    contenu = new int[degre + 1];

    for (int i = 0; i <= degre; i++)
    {
        contenu[i] = p.contenu[i];
    }
}

// Destructeur
Polynome::~Polynome()
{
    delete[] contenu;
}

// Affichage mathématique
void Polynome::affiche() const
{
    bool premier = true;

    for (int i = 0; i <= degre; i++)
    {
        if (contenu[i] != 0)
        {
            if (!premier)
            {
                if (contenu[i] > 0)
                    cout << " + ";
                else
                    cout << " - ";
            }
            else
            {
                if (contenu[i] < 0)
                    cout << "-";
            }

            int coeff = abs(contenu[i]);

            if (i == 0)
            {
                cout << coeff;
            }
            else if (i == 1)
            {
                if (coeff != 1)
                    cout << coeff;
                cout << "x";
            }
            else
            {
                if (coeff != 1)
                    cout << coeff;
                cout << "x^" << i;
            }

            premier = false;
        }
    }

    if (premier)
        cout << "0";

    cout << endl;
}

// Opérateur <<
ostream& operator<<(ostream& os, const Polynome& p)
{
    os << "[";

    for (int i = 0; i <= p.degre; i++)
    {
        os << p.contenu[i];
        if (i < p.degre)
            os << ",";
    }

    os << "]";
    return os;
}

// Opérateur >>
istream& operator>>(istream& is, Polynome& p)
{
    int d;
    is >> d;

    if (d < 0)
    {
        cout << "Degre incorrect, utilisation de la valeur par defaut 1." << endl;
        d = 1;
    }

    delete[] p.contenu;

    p.degre = d;
    p.contenu = new int[p.degre + 1];

    for (int i = 0; i <= p.degre; i++)
    {
        is >> p.contenu[i];
    }

    return is;
}

// Opérateur ==
bool Polynome::operator==(const Polynome& p) const
{
    if (degre != p.degre)
        return false;

    for (int i = 0; i <= degre; i++)
    {
        if (contenu[i] != p.contenu[i])
            return false;
    }

    return true;
}

// Opérateur * : P * k
Polynome Polynome::operator*(double k) const
{
    Polynome res(degre);

    for (int i = 0; i <= degre; i++)
    {
        res.contenu[i] = contenu[i] * k;
    }

    return res;
}

// Fonction externe : k * P
Polynome operator*(double k, const Polynome& p)
{
    return p * k;
}