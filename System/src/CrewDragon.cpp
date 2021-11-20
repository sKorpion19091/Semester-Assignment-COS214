#include "../include/CrewDragon.h"
#include <iostream>
#include <sstream>

CrewDragon::CrewDragon(Falcon* falcon) : Dragon(falcon) {
}

CrewDragon::~CrewDragon() {
    // for(auto it = crewMembers.begin(); it != crewMembers.end(); ++it) {
    //     delete (*it);
    // }

    // for(auto it = cargoList.begin(); it != cargoList.end(); ++it) {
    //     delete (*it);
    // }
    delete cargoList;
    delete crewMembers;
}

void CrewDragon::load() {
    std::ifstream crewData("../Data/CrewManifest.txt");

    if(crewData.is_open()) {
        std::string crewMember, name, title;
        while(getline(crewData,crewMember)) {
            std::stringstream ss(crewMember); 
            getline(ss,name,',');
            getline(ss,title,',');
            crewMembers.addCrewMember(new Crew(name,title));
            std::cout << "[" << name << "]" <<  " boarded Dragon\n";
        }

    } else {
        std::cerr << __FILE__ << " " << __LINE__ << " Could not open CrewManifest";
    }

    std::ifstream cargoData("../Data/CargoList.txt");

    if(cargoData.is_open()) {
        std::string cargoItem, description, weight;
        while(getline(cargoData,cargoItem)) {
            std::stringstream ss(cargoItem); 
            getline(ss,description,',');
            getline(ss,weight);
            cargoList.addCargo(new Cargo(description,stod(weight)));
            std::cout << "Loaded [" << description << "]" << " {" << weight << "kg} into Dragon\n";
        }
    } else {
        std::cerr << __FILE__ << " " << __LINE__ << " Could not open CargoList";
    }

}
