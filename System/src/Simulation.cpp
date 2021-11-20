#include "../include/Simulation.h"

Simulation::Simulation() : state(0) {
    //state = new State("Cargo", 0);
}

Simulation::~Simulation() {
    //delete state;
}

Memento* Simulation::createMemento() {
    if (state != 0) {
        Memento* tmp = new Memento();
        tmp->setState(state);
        return tmp;
    }
}

void Simulation::setMemento(Memento* m) {
    state = m->getState();
}

std::string Simulation::getFilePath() {
    return filePath;
}