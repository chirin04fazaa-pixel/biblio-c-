#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class livre {
private:
    int id;
    vector<char> titre;
    vector<char> auteur;

public:
    livre(int i=0, const char* t="", const char* a="");

    int getid() const;
    const vector<char>& gettitre() const;
    const vector<char>& getauteur() const;

    void afficher() const;

    void save(const char* filename) const;
    void load(const char* filename);
};

#endif



