#ifndef NOEUD_H
#define NOEUD_H

template<typename t>
class noeud {
public:
    t data;
    noeud<t>* enfant;
    noeud<t>* frere;

    noeud(const t& d) : data(d), enfant(nullptr), frere(nullptr) {}
};

#endif

