#include "grill.h"
#include "linkedlist.h"

Grill::Grill() {
}

bool Grill::swap(unsigned int pos1, unsigned int pos2) {
    unsigned int size = rack.size();
    unsigned int realPos1 = pos1-1;
    unsigned int realPos2 = pos2-1;
    if (realPos1<size && realPos2<size) {
        Kebab* k1 = rack.elementAt(realPos1);
        Kebab* k2 = rack.elementAt(realPos2);
        rack.insertAt(k2,realPos1);
        rack.removeAt(realPos1+1);
        rack.insertAt(k1,realPos2);
        rack.removeAt(realPos2);
        return true;
    } else {
        return false;
    }
}

Kebab* Grill::request(unsigned int pos) {
    if (rack.size() >= pos){
        unsigned int realpos = pos-1;
        Kebab* k = rack.elementAt(realpos);
        rack.removeAt(realpos);
        return k;
    } else {
        return NULL;
    }
}

Kebab* Grill::request(Kebab &r) {
    int size = rack.size();
    for (int p=0; p<size; p++){
        Kebab* k = rack.elementAt(p);
        if (k->hasSameIngredients(r)) {
            rack.removeAt(p);
            return k;
        }
    }
    return NULL;
}

void Grill::addKebab(Kebab &n) {
    rack.insertBack(&n);
}

void Grill::sortByMeat() {
    unsigned int size = rack.size();
    for (unsigned int p=1; p<size; p++){
        //removed unsigned otherwise it loops forever
        for ( int i=p-1; i>=0; i--) {
            Kebab *previousK = rack.elementAt(i);
            unsigned int previousNum = previousK->numMeats();
            Kebab *thisK = rack.elementAt(p);
            unsigned int thisNum = thisK->numMeats();
            if (previousNum > thisNum) {
                this->swap(i, p);
            } else
                break;
        }
    }
}

std::vector<std::string> Grill::showKebabs() const {
    std::vector<std::string> v;
    int size = rack.size();
    for ( int p=0; p<size; p++) {
        Kebab* k = rack.elementAt(p);
        v.push_back(k->listIngredients());
    }
    return v;
}
