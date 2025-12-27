#include "livre.h"
using namespace std;

livre::livre(int i, const char* t, const char* a) : id(i) {
    for (int j = 0; t[j] != '\0'; j++) titre.push_back(t[j]);
    for (int j = 0; a[j] != '\0'; j++) auteur.push_back(a[j]);
}

int livre::getid() const {
    return id; }

const vector<char>& livre::gettitre() const {
     return titre; }

const vector<char>& livre::getauteur() const {
    return auteur; }

void livre::afficher() const {
    cout << "id: " << id << " | ";

    for (int i = 0; i < titre.size(); i++) {
        cout << titre[i];
    }

    cout << " - ";

    for (int i = 0; i < auteur.size(); i++) {
        cout << auteur[i];
    }

    cout << endl;
}
 void livre::save(const char* nomfichier) const {
    FILE* f = fopen(nomfichier, "a");
    if (!f) {
        cout << "erreur" << endl;
        return;
    }


    fprintf(f, "%d;", id);

    fputc(';', f);
    for (int i = 0; i < titre.size(); i++) {
        fputc(titre[i], f);
    }

    fputc(';', f);
    for (int i = 0; i < auteur.size(); i++) {
        fputc(auteur[i], f);
    }

    fputc('\n', f);
    fclose(f);
}


void livre::load(const char* nomfichier) {
    FILE* f = fopen(nomfichier, "r");
    if(!f){
        cout << "erreur" << endl;
        return;
    }
    titre.clear();
    auteur.clear();
    int etape = 0;
    char c;
    vector<char> temp;
    while((c = fgetc(f)) != EOF && c != '\n'){
        if(c == ';'){
            if(etape == 0){
                id = atoi(&temp[0]);
                temp.clear();
                etape = 1;
            }
            else if(etape == 1){
                titre = temp;
                temp.clear();
                etape = 2;
            }
        }
        else {
            temp.push_back(c);
        }
    }
    if(!temp.empty()){
        auteur = temp;
    }

    fclose(f);
}
