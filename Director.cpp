//
// Created by Dobricean Ioan Dorian on 21.05.2024.
//

#include "Director.h"

Director::Director(const Profesor &other, const Scoala &scoala) : Profesor(other), scoala(scoala) {

}
bool Director::verificaCalitatea() {
    scoala.getRank();
}