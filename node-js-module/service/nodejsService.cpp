#include "mutexInspector.h"
#include <unistd.h>
#define STATICLIB 1

#include "nodejsService.h"

#include "version_mega.h"
#include "Events/System/timerEvent.h"
#include "Events/nodejsEvent.h"
#include "events_nodejs.hpp"
nodejs::Service::Service(const SERVICE_id &svs, const std::string&  nm, IInstance* ifa):
    UnknownBase(nm),
    ListenerBuffered1Thread(nm,svs),
    Broadcaster(ifa),
    myOscar(ifa->getConfig()->get_string("oscarType","Oscar","oscar type - Oscar || OscarSecure")),
    iterateTimeout_(ifa->getConfig()->get_real("IterateTimeoutSec",60,"")),
    iInstance(ifa),
    m_isTerminating(false)
{

    try
    {

        XTRY;
        {
        }

        XPASS;
    }
    catch (const std::exception &e)
    {
        logErr2("exception: %s %s %d",e.what(),__FILE__,__LINE__);
        throw;
    }
}
nodejs::Service::~Service()
{
    m_isTerminating=true;

}



bool nodejs::Service::on_startService(const systemEvent::startService* )
{
    MUTEX_INSPECTOR;
    XTRY;

    auto svs=iUtils->serviceIdByName(myOscar);


#ifdef WEBDUMP
    sendEvent(ServiceEnum::WebHandler, new webHandlerEvent::RegisterDirectory("nodejs","nodejs"));
    sendEvent(ServiceEnum::WebHandler, new webHandlerEvent::RegisterHandler("nodejs/details","Dump state",ListenerBase::serviceId));
#endif


    XPASS;
    return true;
}



UnknownBase* nodejs::Service::construct(const SERVICE_id& id, const std::string&  nm,IInstance* ifa)
{
    XTRY;
    return new Service(id,nm,ifa);
    XPASS;
}




void registerNodeJsService(const char* pn)
{
    if(pn)
    {
        iUtils->registerPlugingInfo(COREVERSION,pn,IUtils::PLUGIN_TYPE_SERVICE,ServiceEnum::nodejsNode,"nodejsNode",getEvents_nodejs());
    }
    else
    {
        iUtils->registerService(COREVERSION,ServiceEnum::nodejsNode,nodejs::Service::construct,"nodejsNode");
        regEvents_nodejs();
    }

}



bool nodejs::Service::on_TickAlarm(const timerEvent::TickAlarm*e)
{
    MUTEX_INSPECTOR;
    return true;
}


bool nodejs::Service::handleEvent(const REF_getter<Event::Base>& e)
{
    MUTEX_INSPECTOR;
    XTRY;
    auto& ID=e->id;
    if(timerEventEnum::TickAlarm==ID)
        return on_TickAlarm((const timerEvent::TickAlarm*)e.get());

    if(systemEventEnum::startService==ID)
        return on_startService((const systemEvent::startService*)e.get());

    if(webHandlerEventEnum::RequestIncoming==ID)
        return on_RequestIncoming((webHandlerEvent::RequestIncoming*)e.get());

    XPASS;
    return false;

}


bool nodejs::Service::on_RequestIncoming(const webHandlerEvent::RequestIncoming*e)
{
    HTTP::Response cc(iInstance);
    cc.content+="<h1>nodejs report</h1><p>";

    Json::Value j;
    cc.content="<pre>"+j.toStyledString()+"</pre>";



    cc.makeResponse(e->esi);

    return true;

}
