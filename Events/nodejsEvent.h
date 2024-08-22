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

    const EVENT_id ExecJsREQ(genum_ptAddTokenREQ);
    const EVENT_id ExecJsRSP(genum_ptAddTokenRSP);

}

namespace nodejsEvent {




    class ExecJsREQ: public Event::Base
    {
    public:
        static Base* construct(const route_t &r)
        {
            return new ExecJsREQ(r);
        }
        ExecJsREQ(int64_t _reqId, const std::string& _code,
                   const route_t&r)
            :Base(nodejsEventEnum::ExecJsREQ,r),
             reqId(_reqId),code(_code)
        {}
        ExecJsREQ(const route_t&r)
            :Base(nodejsEventEnum::ExecJsREQ,r) {}
        int64_t reqId;
        std::string code;
        void unpack(inBuffer& o)
        {
            o>>reqId>>code;
        }
        void pack(outBuffer&o) const
        {
            o<<reqId<<code;
        }
        void jdump(Json::Value &) const
        {
        }

    };
    class ExecJsRSP: public Event::Base
    {
    public:
        static Base* construct(const route_t &r)
        {
            return new ExecJsRSP(r);
        }
        ExecJsRSP(int64_t _reqId,
                   const route_t&r)
            :Base(nodejsEventEnum::ExecJsRSP,r),
             reqtId(_reqId)
        {}
        ExecJsRSP(const route_t&r)
            :Base(nodejsEventEnum::ExecJsRSP,r) {}
        int64_t reqtId;
        int result;
        std::string error;
        void unpack(inBuffer& o)
        {
            o>>reqtId>>result>>error;
        }
        void pack(outBuffer&o) const
        {
            o<<reqtId<<result<<error;
        }
        void jdump(Json::Value &) const
        {
        }

    };

}




