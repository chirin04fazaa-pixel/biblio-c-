#include "categorie.h"

categorie::categorie(const vector<char>& n) {
    nom = n;
} //initilise nom

vector<char>& categorie::getnom() const {
    return nom;
}

void categorie::ajouterlivre(const livre& l) {
    livres.push_back(l);
} // ajout des livres

void categorie::afficher() const {
    cout << "categorie : ";

 for(int i=0;i<nom.size();i++) cout<<nom[i];
     cout << "\n livres : \n";
    for(int i=0;i<livres.size();i++) livres[i].afficher();
}

void categorie::savefile(const char* filename) const {
    for(int i=0;i<livres.size();i++) livres[i].save(filename);
}

