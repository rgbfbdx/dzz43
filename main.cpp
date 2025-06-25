// Reservoir.h
#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <string>
#include <iostream>

class Reservoir {
private:
    std::string name;
    std::string type;
    double width;
    double length;
    double maxDepth;

public:
    Reservoir();
    explicit Reservoir(const std::string& n);
    Reservoir(const std::string& n, const std::string& t, double w, double l, double d);
    Reservoir(const Reservoir& other);
    ~Reservoir();

    double getVolume() const;
    double getSurfaceArea() const;
    bool isSameType(const Reservoir& other) const;
    bool compareSurfaceArea(const Reservoir& other) const;

    Reservoir& operator=(const Reservoir& other);

    void setName(const std::string& n);
    void setType(const std::string& t);
    void setWidth(double w);
    void setLength(double l);
    void setMaxDepth(double d);

    std::string getName() const;
    std::string getType() const;
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;

    void display() const;
};

#endif

// Reservoir.cpp
#include "Reservoir.h"

Reservoir::Reservoir() : name(""), type(""), width(0), length(0), maxDepth(0) {}

Reservoir::Reservoir(const std::string& n) : name(n), type(""), width(0), length(0), maxDepth(0) {}

Reservoir::Reservoir(const std::string& n, const std::string& t, double w, double l, double d)
    : name(n), type(t), width(w), length(l), maxDepth(d) {}

Reservoir::Reservoir(const Reservoir& other)
    : name(other.name), type(other.type), width(other.width), length(other.length), maxDepth(other.maxDepth) {}

Reservoir::~Reservoir() {}

double Reservoir::getVolume() const {
    return width * length * maxDepth;
}

double Reservoir::getSurfaceArea() const {
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const {
    return type == other.type;
}

bool Reservoir::compareSurfaceArea(const Reservoir& other) const {
    return type == other.type && getSurfaceArea() > other.getSurfaceArea();
}

Reservoir& Reservoir::operator=(const Reservoir& other) {
    if (this != &other) {
        name = other.name;
        type = other.type;
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

void Reservoir::setName(const std::string& n) { name = n; }
void Reservoir::setType(const std::string& t) { type = t; }
void Reservoir::setWidth(double w) { width = w; }
void Reservoir::setLength(double l) { length = l; }
void Reservoir::setMaxDepth(double d) { maxDepth = d; }

std::string Reservoir::getName() const { return name; }
std::string Reservoir::getType() const { return type; }
double Reservoir::getWidth() const { return width; }
double Reservoir::getLength() const { return length; }
double Reservoir::getMaxDepth() const { return maxDepth; }

void Reservoir::display() const {
    std::cout << "Name: " << name << ", Type: " << type
              << ", Width: " << width << ", Length: " << length
              << ", Max Depth: " << maxDepth << std::endl;
}
