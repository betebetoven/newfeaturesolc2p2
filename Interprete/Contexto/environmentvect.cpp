#include "environmentvect.h"

EnvironmentVect::EnvironmentVect(EnvironmentVect* father) {
    if (father != nullptr) {
        vect_table.insert(father->vect_table.begin(), father->vect_table.end());
    }
}

void EnvironmentVect::addVariable(const std::string& name, const std::string& type, const QVector<Value>& values) {
    VectInfo vect_info{type, values};
    vect_table[name] = vect_info;
}

Value EnvironmentVect::getVariableValue(const std::string& name, int index) {
    auto it = vect_table.find(name);
    if (it != vect_table.end()) {
        if (index >= 0 && index < it->second.values.size()) {
            return it->second.values[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }
    throw std::runtime_error("Variable does not exist");
}
