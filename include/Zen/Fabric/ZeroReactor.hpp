#pragma once
#include "Configuration.hpp"

#include <Zen/Enterprise/I_Reactor.hpp>

#include <zmqpp/zmqpp.hpp>


//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class FABRIC_DLL_LINK ZeroReactor 
:   public Zen::Enterprise::I_Reactor
{
public:
    /// Poll with a specified timeout
    /// @param _timeout timeout in milliseconds
    void poll(long _timeout);
    
    /// Poll, with a forever timeout.
    //void poll();
public:
             ZeroReactor();
    virtual ~ZeroReactor();
    
    // TODO This should be private
public:
    /// The reactor implementation
    zmqpp::reactor m_reactor;
};  // class ZeroReactor

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
