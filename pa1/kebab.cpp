#include <vector>
#include <string>
#include "kebab.h"

Kebab::Kebab() {

}

bool Kebab::addIngredient (char item) {
    if (skewer.size() < maxlength
            && isValidIngredient(item)) {
        skewer.push_back(item);
        return true;
    } else {
        return false;
    }

}

void Kebab::buildKebab(std::string s) {
    for (char& c: s) {
        if (isValidIngredient(c)
            && skewer.size()<maxlength){
            addIngredient(c);
        }
    }
}

unsigned int Kebab::numMeats() const {
    int numMeat = 0;
    for (char item: skewer) {
        if (item == 'm' || item == 'M') {
            numMeat++;
        }
    }
    return numMeat;
}

bool Kebab::hasSameIngredients(Kebab& k) const {
    std::string listOfK = k.listIngredients();
    unsigned int b,t,m,p,s,b1,t1,m1,p1,s1; //counters for the ingredients
    b = t = m = p = s = b1 = t1 = m1 = p1 = s1 = 0; //initilizing everything to 0;

    for (char& c: listOfK){
        if (c == 'b' || c == 'B') b++;
        if (c == 't' || c == 'T') t++;
        if (c == 'm' || c == 'M') m++;
        if (c == 'p' || c == 'P') p++;
        if (c == 's' || c == 'S') s++;
    }
    for (char c: skewer){
        if (c == 'b' || c == 'B') b1++;
        if (c == 't' || c == 'T') t1++;
        if (c == 'm' || c == 'M') m1++;
        if (c == 'p' || c == 'P') p1++;
        if (c == 's' || c == 'S') s1++;
    }

    if (b <= b1 && t <= t1 && m <= m1 && p <= p1 && s <= s1)
        return true;
    else
        return false;

}


std::string Kebab::listIngredients() const {
    std::string list = "";
    for (char item: skewer) {
        list+=item;
    }
    return list;

}