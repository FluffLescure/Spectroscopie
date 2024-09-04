#ifndef SEMESTER
#define SEMESTER

#include "Subject.h"
#include <vector>

/**
 * @class Semester
 * @brief Contains a list of subjects which are included for the semester
 * @param subj A list of subjects in the semester
 */
class Semester {
private:
    std::vector<Subject*> subj;

public:
    /**
     * @brief Adds a given subject to the semester
     * @param subj Subject to be added
     */
    void addSubject(Subject* subj) { this->subj.push_back(subj); }

    int removeSubject(const Subject& subj);
    int removeSubject(const std::string& str);
    float Average(void) const;
    void print(void) const;
};

#endif