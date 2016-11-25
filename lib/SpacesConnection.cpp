#include <Zen/Fabric/SpacesConnection.hpp>
#include <Zen/Fabric/ZeroReactor.hpp>

#include <boost/tokenizer.hpp>

#include <iostream>
#include <functional>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Fabric {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpacesConnection::SpacesConnection(const std::string& _senderId,
    const std::string& _requestAddr, const std::string& _subAddr)
:   m_context(),
    m_senderId(_senderId),
    m_requestAddr(_requestAddr),
    m_subAddr(_subAddr),
    m_requestSocket(m_context, zmqpp::socket_type::req),
    m_subSocket(m_context, zmqpp::socket_type::sub)
{
    m_requestSocket.connect(m_requestAddr);
    m_subSocket.connect(m_subAddr);
    m_subSocket.set(zmqpp::socket_option::identity, _senderId);
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
SpacesConnection::~SpacesConnection()
{
    // TODO Disconnect?  Or do the socket destructors clean up?
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
SpacesConnection::registerReactor(Zen::Enterprise::I_Reactor& _reactor)
{
    // Assume this is a ZeroReactor
    auto *pReactor = dynamic_cast<ZeroReactor*>(&_reactor);

    // TODO Throw an exception if pReactor is null
    // HACK directly accessing the zmqpp implementation; why do we
    // need Zen Enterprise if we're doing this?  I'm just being lazy and I'll
    // do a better job with the interface later.
    pReactor->m_reactor.add(m_requestSocket, std::bind(&SpacesConnection::handleMessage, this));
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
void
SpacesConnection::handleMessage()
{
    std::cout << "Got a reply" << std::endl << std::flush;
    zmqpp::message message;
    m_requestSocket.receive(message);

    // TODO Handle disconnect requests.
    // if(pRequest->isDisconnect())
    // {
    //     std::cout << "Got a disconnect message" << std::endl << std::flush;
    // }

    // TODO Handle the reply
}

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Fabric
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
