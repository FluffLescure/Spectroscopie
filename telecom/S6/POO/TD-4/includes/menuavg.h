#ifndef _MENU_EXEMPLE
#define _MENU_EXEMPLE

#include "Subject.h"
#include "menu.h"

class MenuAvg : public Menu {
public:
    MenuAvg();
    void executerOption(const string& nom, bool& fin);
    Subject fetchSubject();
};

#endif
