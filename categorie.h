#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <vector>
#include "livre.h"
using namespace std;

class categorie {
private:
    vector<char> nom;
    vector<livre> livres;

public:
    categorie(const vector<char>& n = vector<char>());
    vector<char>& getnom() const;

    void ajouterlivre(const livre& l);
    void afficher() const;

    void savefile(const char* filename) const;
};

#endif


