#pragma once

#include "structs.hpp"

namespace ioc
{
    struct rulesStruct
    {
        bool warnColorReset;
        bool errorColorReset;
        bool setLastColorBgWhenErrorOrWarnEnds;
        bool newlineWhenTextInput;
    };

    #ifdef CREATE_RULES
    struct rulesStruct rules;
    #else
    extern struct rulesStruct rules;
    #endif

}
