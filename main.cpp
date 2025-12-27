#include <iostream>
#include <vector>
#include "livre.h"
#include "categorie.h"
#include "arbre.h"

using namespace std;

int main(){
    //racine de arbre
    categorie biblio(vector<char>{'B','i','b','l','i','o'});
    arbre<categorie> arbre(biblio);

    // ajout de Catégories
    noeud<categorie>* romans = arbre.ajouterenfant(arbre.getracine(),categorie(vector<char>{'R','o','m','a','n','s'}));
    noeud<categorie>* science = arbre.ajouterenfant(arbre.getracine(),categorie(vector<char>{'S','c','i','e','n','c','e'}));
    //ajout de livres
    romans->data.ajouterlivre(livre(1,"1984","Orwell"));
    science->data.ajouterlivre(livre(2,"Cosmos","Sagan"));
    //affichage
    arbre.afficher(arbre.getracine());

    cout << "\nSauvegarde des livres dans romans.txt...\n";
    romans->data.savefile("romans.txt");

    cout << "\nSauvegarde des livres dans science.txt...\n";
    science->data.savefile("science.txt");
    return 0;
}

