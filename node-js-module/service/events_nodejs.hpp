#ifndef __________nodejs_EventInfo__HH
#define __________nodejs_EventInfo__HH


#include "IUtils.h"

#include "Events/System/timerEvent.h"
#include <Events/System/Run/startServiceEvent.h>
#include <Events/System/timerEvent.h>
#include <Events/Tools/webHandlerEvent.h>
inline std::set<EVENT_id> getEvents_nodejs()
{

	std::set<EVENT_id> out;
	out.insert(systemEventEnum::startService);
	out.insert(timerEventEnum::TickAlarm);
	out.insert(timerEventEnum::TickTimer);
	out.insert(webHandlerEventEnum::RegisterDirectory);
	out.insert(webHandlerEventEnum::RegisterHandler);
	out.insert(webHandlerEventEnum::RequestIncoming);

	return out;
}

inline void regEvents_nodejs()
{
	iUtils->registerEvent(systemEvent::startService::construct);
	iUtils->registerEvent(timerEvent::TickAlarm::construct);
	iUtils->registerEvent(timerEvent::TickTimer::construct);
	iUtils->registerEvent(webHandlerEvent::RegisterDirectory::construct);
	iUtils->registerEvent(webHandlerEvent::RegisterHandler::construct);
	iUtils->registerEvent(webHandlerEvent::RequestIncoming::construct);
}
#endif
