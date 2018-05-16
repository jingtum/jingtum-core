//------------------------------------------------------------------------------
/*
    This file is part of skywelld: https://github.com/skywell/skywelld
    Copyright (c) 2012, 2013 Skywell Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef SKYWELL_PEERFINDER_SLOT_H_INCLUDED
#define SKYWELL_PEERFINDER_SLOT_H_INCLUDED

#include <protocol/SkywellPublicKey.h>
#include <boost/optional.hpp>
#include <memory>
#include <boost/asio.hpp>

namespace skywell {
namespace PeerFinder {

/** Properties and state associated with a peer to peer overlay connection. */
class Slot
{
public:
    typedef std::shared_ptr<Slot> ptr;

    enum State
    {
        accept,
        connect,
        connected,
        active,
        closing
    };

    virtual ~Slot () = 0;

    /** Returns `true` if this is an inbound connection. */
    virtual bool inbound () const = 0;

    /** Returns `true` if this is a fixed connection.
        A connection is fixed if its remote endpoint is in the list of
        remote endpoints for fixed connections.
    */
    virtual bool fixed () const = 0;

    /** Returns `true` if this is a cluster connection.
        This is only known after then handshake completes.
    */
    virtual bool cluster () const = 0;

    /** Returns the state of the connection. */
    virtual State state () const = 0;

    /** The remote endpoint of socket. */
    virtual boost::asio::ip::tcp::endpoint const& remote_endpoint () const = 0;

    /** The local endpoint of the socket, when known. */
    virtual boost::optional<boost::asio::ip::tcp::endpoint> const& local_endpoint () const = 0;

    virtual boost::optional<std::uint16_t> listening_port () const = 0;

    /** The peer's public key, when known.
        The public key is established when the handshake is complete.
    */
    virtual boost::optional<SkywellPublicKey> const& public_key () const = 0;
};

}
}

#endif