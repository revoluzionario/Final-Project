#ifndef ABOUTMENU_H_INCLUDED
#define ABOUTMENU_H_INCLUDED
#include "Menu.h"
#include "gMap.h"
#include "inithelper.h"
#include "constants.h"
class AboutMenu
{
    public:
    int page;
    AboutMenu();
    ~AboutMenu();
    renderAbout();
    handleEventAbout();
};

#endif // ABOUTMENU_H_INCLUDED
