
#include <cstdlib>
#include <iostream>

#include "includes/Subject.h"
#include "includes/menuavg.h"

using namespace std;

MenuAvg::MenuAvg() : Menu("Exemple de menu :") {
    ajouterOption("aide", "Afficher de l'aide");
    ajouterOption("nouvelleOption", "Executer la nouvelle option");
    ajouterOption("quitter", "Sortir de l'application");
}

void MenuAvg::executerOption(const string& nom, bool& fin) {
    if (nom == "nouvelleOption")
        fetchSubject();
    else
        Menu::executerOption(nom, fin);
}

Subject MenuAvg::fetchSubject() {
    cout << "Fetching new subjects" << endl
         << endl;
    // system("pause");

    string name;
    cout << "Enter subject name: ";
    while (!(cin >> name)) {
        cerr << "Invalid name entered";
    }

    short int weight;
    cout << "Enter subject weight: ";
    while (!(cin >> weight)) {
        cerr << "Invalid weight entered";
    }

    float grade;
    cout << "Enter subject grade: ";
    while (!(cin >> grade)) {
        cerr << "Invalid grade entered";
    }

    return Subject(name, weight, grade);
}
