#include "IUtils.h"

IUtils *iUtils;
void registerNodeJsService(const char*);
extern "C" void
#ifdef DEBUG
registerModuleDebug
#else
registerModule
#endif
(IUtils* f, const char* pn)
{

    iUtils=f;
    registerNodeJsService(pn);
}

