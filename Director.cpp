//
// Created by Dobricean Ioan Dorian on 21.05.2024.
//

#include "Director.h"

Director::Director(const Profesor &other, const Scoala &scoala) : Profesor(other), scoala(scoala) {

}
bool Director::verificaCalitatea() {
    auto ranks = scoala.getRank();
    if(ranks.size()>0 and ranks[0].value>5)
        return true;
    return false;
}