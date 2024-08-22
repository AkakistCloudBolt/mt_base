#include "IInstance.h"
#include "colorOutput.h"
#include "configObj.h"
#include "CUtils.h"
#include <unistd.h>
void registerSocketModule(const char* pn);
void registerTimerService(const char* pn);
void registerTelnetService(const char* pn);
void registerOscarModule(const char* pn);
void registerRPCService(const char* pn);

//void registerteldemo1(const char* pn);
void registerNodeJsService(const char*);
int mainFunc(int argc, char** argv )
{
    try {
        iUtils=new CUtils(argc, argv, "NodeJsService");

        registerSocketModule(nullptr);
        registerTimerService(nullptr);
        registerTelnetService(nullptr);
        registerOscarModule(nullptr);
        registerRPCService(nullptr);
        registerNodeJsService(nullptr);


        // printf(GREEN("RUN TEST %s"),__PRETTY_FUNCTION__);

        {
            IInstance *instance1=iUtils->createNewInstance("nodejsNode");
            ConfigObj *cnf1=new ConfigObj("nodejsNode",
                                          "\nStart=RPC,nodejsNode"
                                          "\nTelnet.BindAddr=127.0.0.1:8081"
                                          "\nTelnet.deviceName=Device"
                                          "\nSocketIO.ListenerBuffered.MaxThreadsCount=10"
                                          "\nSocketIO.listen_backlog=128"
                                          "\nSocketIO.size=1024"
                                          "\nSocketIO.timeout_millisec=10"

                                          "\nSocketIO.epoll_timeout_millisec=2000"
                                          "\n"
                                          "\n# socket poll thread count"
                                          "\nSocketIO.n_workers=3"
                                          "\nOscar.maxPacketSize=33554432"
"\n# oscar type - Oscar || OscarSecure"
"\nnodejsNode.oscarType=Oscar"
"\nnodejsNode.IterateTimeoutSec=60.000000"

"\n# oscar type - Oscar || OscarSecure"
"\nRPC.oscarType=Oscar"
"\nRPC.IterateTimeoutSec=60.000000"
"\nRPC.ConnectionActivity=600.000000"

"\n# Address used to work with dfs network RPC_UL. NONE - no bind"
"\nRPC.BindAddr_MAIN=INADDR_ANY:0,INADDR6_ANY:0"

"\n# Address used to communicate with local apps RPC_DL, must be fixed. NONE - no bind"
"\nRPC.BindAddr_RESERVE=NONE"
                                         );
            instance1->setConfig(cnf1);
            instance1->initServices();
        }
	printf("isterm %d\n",iUtils->isTerminating());
        while(!iUtils->isTerminating())
        {
	    printf("sleep\n");
            sleep(1);
        }
        delete iUtils;
        return 0;

    } catch (CommonError& e)
    {
        printf("CommonError %s\n",e.what());
    }
    return 1;
}

int main(int argc, char** argv)
{
    return mainFunc(argc, argv);
}