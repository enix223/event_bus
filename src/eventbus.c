/*
 *  The MIT License (MIT)
 * Copyright (c) 2024 Enix Yu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "eventbus.h"
#include "conf.h"

typedef struct cl_event_bus_t
{
  // event callbacks link list array
  //
  // event1 -> [callback1|next] -> [callback2|next] -> [callback3|null]
  // event2 -> [callback1|next] -> [callback2|next] -> [callback3|null]
  // ...
  // event4 -> [callback1|next] -> [callback2|next] -> [callback3|null]
  cl_event_bus_event_callback_t callbacks[CONFIG_EVENT_BUS_TOTAL_EVENTS];
} cl_event_bus_t;

void cl_event_bus_subscribe(cl_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback)
{
  event_bus->callbacks[event] = callback;
}

void cl_event_bus_unsubscribe(cl_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback)
{
}
