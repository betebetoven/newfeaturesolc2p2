// environmentvect.h
#ifndef ENVIRONMENTVECT_H
#define ENVIRONMENTVECT_H

#include <iostream>
#include <string>
#include <map>
#include <QVector>

struct VectInfo {
    std::string type;
    QVector<int> values;
};

class EnvironmentVect {
public:
    EnvironmentVect();
    EnvironmentVect(EnvironmentVect* father);
    void addVariable(const std::string& name, const std::string& type, const QVector<int>& values);
    int getNumberOfDimensions(const std::string& id);
    int linearSize(const std::string& id);
    int getDimensionFrom(const std::string& id, int index);
    std::map<std::string, VectInfo> vect_table;
};

#endif // ENVIRONMENTVECT_H
