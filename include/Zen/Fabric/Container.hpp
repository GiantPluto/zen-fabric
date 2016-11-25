#pragma once
#include "Configuration.hpp"

#include <thread>

#include <zmqpp/zmqpp.hpp>

#include <Zen/Enterprise/I_Connection.hpp>

#include <Zen/Fabric/ZeroReactor.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class FABRIC_DLL_LINK Container
{
public:
    void registerConnection(Zen::Enterprise::I_Connection& _connection);
    void startProcessing();
    void stopProcessing();
    void waitForJoin();

public:
     Container();
    ~Container();
    
private:

    // zmqpp::reactor  m_reactor;
    ZeroReactor     m_reactor;
    volatile bool   m_shouldStop;
    std::thread     m_workerThread;
    
};  // class Container

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
