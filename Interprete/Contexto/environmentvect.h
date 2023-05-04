#ifndef ENVIRONMENTVECT_H
#define ENVIRONMENTVECT_H

#include <iostream>
#include <string>
#include <map>
#include <variant>
#include <QVector>

using Value = std::variant<int, float, std::string, bool>;
struct VectInfo {
    std::string type;
    QVector<Value> values;
};

class EnvironmentVect {
public:
    EnvironmentVect();
    EnvironmentVect(EnvironmentVect* father);
    void addVariable(const std::string& name, const std::string& type, const QVector<Value>& values);
    Value getVariableValue(const std::string& name, int index);
    std::map<std::string, VectInfo> vect_table;
};

#endif // ENVIRONMENTVECT_H
