#pragma once
#include "EVENT_id.h"
#include "SERVICE_id.h"
#include "event_mt.h"
#include "genum.hpp"
#include "msockaddr_in.h"
namespace ServiceEnum
{
    const SERVICE_id nodejsBoss(genum_nodejsBoss);
    const SERVICE_id nodejsNode(genum_nodejsNode);
}

namespace nodejsEventEnum
{

    const EVENT_id AddTokenREQ(genum_ptAddTokenREQ);
    const EVENT_id AddTokenRSP(genum_ptAddTokenRSP);

}

namespace nodejsEvent {




    class AddTokenREQ: public Event::Base
    {
    public:
        static Base* construct(const route_t &r)
        {
            return new AddTokenREQ(r);
        }
        AddTokenREQ(const int& _ur,
                   const route_t&r)
            :Base(nodejsEventEnum::AddTokenREQ,r),
             ur(_ur)
        {}
        AddTokenREQ(const route_t&r)
            :Base(nodejsEventEnum::AddTokenREQ,r) {}
        int ur;
        void unpack(inBuffer& o)
        {
            o>>ur;
        }
        void pack(outBuffer&o) const
        {
            o<<ur;
        }
        void jdump(Json::Value &) const
        {
        }

    };
    class AddTokenRSP: public Event::Base
    {
    public:
        static Base* construct(const route_t &r)
        {
            return new AddTokenRSP(r);
        }
        AddTokenRSP(int64_t _lastId,
                   const route_t&r)
            :Base(nodejsEventEnum::AddTokenRSP,r),
             lastId(_lastId)
        {}
        AddTokenRSP(const route_t&r)
            :Base(nodejsEventEnum::AddTokenRSP,r) {}
        int64_t lastId;
        void unpack(inBuffer& o)
        {
            o>>lastId;
        }
        void pack(outBuffer&o) const
        {
            o<<lastId;
        }
        void jdump(Json::Value &) const
        {
        }

    };

}




