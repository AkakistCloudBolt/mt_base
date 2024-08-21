#pragma once
#include <REF.h>
#include <webDumpable.h>
#include <SOCKET_id.h>

#include <epoll_socket_info.h>
#include <json/value.h>
#include <broadcaster.h>
#include <msockaddr_in.h>


#include "listenerBuffered1Thread.h"


#include <Events/System/timerEvent.h>
#include <Events/System/Run/startServiceEvent.h>
#include <Events/Tools/webHandlerEvent.h>


namespace nodejs
{



    class Service:
        public UnknownBase,
        public ListenerBuffered1Thread,
        public Broadcaster
    {


        std::string myOscar;
        const real iterateTimeout_;



    protected:

    public:
    public:




        bool on_startService(const systemEvent::startService*);




        bool on_TickAlarm(const timerEvent::TickAlarm*);
        bool on_RequestIncoming(const webHandlerEvent::RequestIncoming*);



        bool handleEvent(const REF_getter<Event::Base>& e);



        IInstance* iInstance;
        bool m_isTerminating;


        void deinit()
        {
            ListenerBuffered1Thread::deinit();
        }

        Service(const SERVICE_id &svs, const std::string&  nm,  IInstance *ifa);
        static UnknownBase* construct(const SERVICE_id& id, const std::string&  nm,IInstance* ifa);

        ~Service();



    };
}



