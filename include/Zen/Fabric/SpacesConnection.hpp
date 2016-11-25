#pragma once
#include "Configuration.hpp"

#include <string>

#include <zmqpp/zmqpp.hpp>

#include <Zen/Enterprise/I_Connection.hpp>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
/// Connection to Zen Spaces server daemon
class FABRIC_DLL_LINK SpacesConnection
:   public Zen::Enterprise::I_Connection
{
    /// @name I_Connection implementation
    /// @{
public:
    virtual void registerReactor(Zen::Enterprise::I_Reactor& _reactor);
    /// @}

    /// @name Structors
    /// @{
public:
             SpacesConnection(const std::string& _senderId,
                const std::string& _requestAddr, const std::string& _subAddr);
    virtual ~SpacesConnection();
    /// @}
    
    /// @name Implementation
    /// @{
protected:
    void handleMessage();
    /// @}

private:
    zmqpp::context  m_context;
    std::string     m_senderId;
    std::string     m_requestAddr;
    std::string     m_subAddr;

    zmqpp::socket   m_requestSocket;
    zmqpp::socket   m_subSocket;
};  // class SpacesConnection

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
