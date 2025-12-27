
template<typename t>
arbre<t>::arbre(const t& r) {
    racine = new noeud<t>(r);
}

template<typename t>
noeud<t>* arbre<t>::getracine() const {
    return racine;
}

template<typename t>
noeud<t>* arbre<t>::ajouterenfant(noeud<t>* parent, const t& val) {
    noeud<t>* nv = new noeud<t>(val);

    if(!parent->enfant)
        parent->enfant = nv;
    else {
        noeud<t>* tmp = parent->enfant;
        while(tmp->frere)
            tmp = tmp->frere;
        tmp->frere = nv;
    }

    return nv;
}

template<typename t>
void arbre<t>::afficher(noeud<t>* n, int niveau) const {
    if(!n) return;
    for(int i = 0; i < niveau * 2; i++) std::cout << '-';
    std::cout << n->data.getnom() << std::endl;
    afficher(n->enfant, niveau + 1);
    afficher(n->frere, niveau);
}
