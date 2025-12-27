#ifndef arbre_h
#define arbre_h
#include "noeud.h"
#include <iostream>
using namespace std;

template <typename t>
class arbre {
private:
    noeud<t>* racine;

public:
    arbre(const t& r) {
        racine = new noeud<t>(r);
    }

    noeud<t>* getracine() const {
        return racine;
    }

    noeud<t>* ajouterenfant(noeud<t>* parent, const t& val) {
        noeud<t>* nv = new noeud<t>(val);
        if(!parent->enfant) {
            parent->enfant = nv;
        } else {
            noeud<t>* temp = parent->enfant;
            while(temp->frere)
                temp = temp->frere;
            temp->frere = nv;
        }
        return nv;
    }

    void afficher(noeud<t>* n, int niveau = 0) const {
        if(!n) return;
        for(int i=0; i<niveau; i++) cout << "--";
        n->data.afficher(); // appel de la fonction afficher de type categorie "t"
        afficher(n->enfant, niveau + 1);
        afficher(n->frere, niveau);
    }
};

#endif


