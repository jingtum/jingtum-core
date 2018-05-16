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

#include <BeastConfig.h>
#include <data/nodestore/DummyScheduler.h>

namespace skywell {
namespace NodeStore {

DummyScheduler::DummyScheduler ()
{
}

DummyScheduler::~DummyScheduler ()
{
}

void
DummyScheduler::scheduleTask (Task& task)
{
    // Invoke the task synchronously.
    task.performScheduledTask();
}

void
DummyScheduler::scheduledTasksStopped ()
{
}

void
DummyScheduler::onFetch (const FetchReport& report)
{
}

void
DummyScheduler::onBatchWrite (const BatchWriteReport& report)
{
}

}
}