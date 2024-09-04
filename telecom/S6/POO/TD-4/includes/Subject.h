#ifndef SUBJECT
#define SUBJECT
#include <stdlib.h>
#include <string>

/**
 * @class Subject
 * @brief A Subject class described by its name, weight and grade
 * @param name The name of the subject
 * @param weight The weight of the subject
 * @param grade The grade obtained in the subject
 */
class Subject {
private:
    std::string name;
    short int weight;
    float grade;

public:
    Subject(std::string name = "", short int weight = 0, float grade = 0) : name(name), weight(weight), grade(grade) {}
    Subject(const Subject& subj) : name(subj.name), weight(subj.weight), grade(subj.grade) {}

    std::string getName(void) const { return this->name; }
    int getWeight(void) const { return this->weight; }
    float getGrade(void) const { return this->grade; }
    void print(void) const { printf("\nName:\t %s\nWeigth:\t %d\nGrade:\t %f", this->name.c_str(), this->weight, this->grade); }
};

#endif