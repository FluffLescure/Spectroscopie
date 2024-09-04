#include "Semester.h"

/**
 * @brief Removes a given subject from the Semester
 * @param subj Subject to be removed
 * @return 0 if successful, 1 if not
 */
int Semester::removeSubject(const Subject& subj) {
    for (int i = 0; i < this->subj.size(); i++) {
        if (this->subj[i]->getName().compare(subj.getName())) {
            this->subj.erase(this->subj.begin() + i);
            return 0;
        }
    }
    return 1;
}

/**
 * @overload
 * @brief Removes a given subject from the Semester
 * @param str Name of subject to be removed
 * @return 0 if successful, 1 if not
 */
int Semester::removeSubject(const std::string& str) {
    for (int i = 0; i < this->subj.size(); i++) {
        if (!this->subj[i]->getName().compare(str)) {
            this->subj.erase(subj.begin() + i);
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Provides the average of all grades in the semester
 * @return Average of the semester, or -1 if empty
 */
float Semester::Average(void) const {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < this->subj.size(); i++) {
        sum += this->subj[i]->getGrade() * this->subj[i]->getWeight();
        count += this->subj[i]->getWeight();
    }

    if (count)
        return sum / count;
    else
        return -1;
}

/**
 * @brief Displays the entire semester infromation
 */
void Semester::print(void) const {
    printf("\nSemester:");
    printf("\n\tSubject\tGrade\t\tWeight\t");
    for (int i = 0; i < this->subj.size(); i++) {
        printf("\n\t%s\t%f\t%d", this->subj[i]->getName().c_str(), this->subj[i]->getGrade(), this->subj[i]->getWeight());
    }
}