// environmentvect.cpp
#include "environmentvect.h"

EnvironmentVect::EnvironmentVect(EnvironmentVect* father) {
    if (father != nullptr) {
        vect_table.insert(father->vect_table.begin(), father->vect_table.end());
    }
}

void EnvironmentVect::addVariable(const std::string& name, const std::string& type, const QVector<int>& values) {
    VectInfo vect_info{type, values};
    vect_table[name] = vect_info;
}

int EnvironmentVect::getNumberOfDimensions(const std::string& id) {
    auto it = vect_table.find(id);
    if (it != vect_table.end()) {
        return it->second.values.size();
    } else {
        throw std::runtime_error("Variable does not exist");
    }
}

int EnvironmentVect::linearSize(const std::string& id) {
    auto it = vect_table.find(id);
    if (it != vect_table.end()) {
        int product = 1;
        for (int value : it->second.values) {
            product *= value;
        }
        return product;
    } else {
        throw std::runtime_error("Variable does not exist");
    }
}

int EnvironmentVect::getDimensionFrom(const std::string& id, int index) {
    auto it = vect_table.find(id);
    if (it != vect_table.end()) {
        if (index >= 0 && index < it->second.values.size()) {
            return it->second.values[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    } else {
        throw std::runtime_error("Variable does not exist");
    }
}
