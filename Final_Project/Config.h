#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
#include "Menu.h"
#include "gMap.h"
#include "inithelper.h"
#include "constants.h"
class Config
{
    public:
    Config();
    ~Config();
    void renderConfig();
    void handleEventConfig();
    void modifyStat();
};


#endif // CONFIG_H_INCLUDED
