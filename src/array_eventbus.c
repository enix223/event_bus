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

#define TOTAL_EVENTS CONFIG_EVENT_BUS_TOTAL_EVENTS
#define MAX_CALLBACKS_PER_EVENT CONFIG_EVENT_BUS_MAX_EVENT_CALLBACKS_PER_EVENT

// Event bus implement with static linked list
typedef struct cl_array_event_bus_t
{
  cl_event_bus_initialize initialize;

  cl_event_bus_subscribe subscribe;

  cl_event_bus_unsubscribe unsubscribe;

  cl_event_bus_publish publish;

  // event callbacks array
  cl_event_bus_event_callback_t callbacks[TOTAL_EVENTS][MAX_CALLBACKS_PER_EVENT];
} cl_array_event_bus_t;

static void cl_array_event_bus_initialize(cl_array_event_bus_t *event_bus);

// subscribe to given event
static cl_event_ret_t cl_array_event_bus_subscribe(cl_array_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback);

// unsubscribe to given event
static cl_event_ret_t cl_array_event_bus_unsubscribe(cl_array_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback);

// publish given event
static cl_event_ret_t cl_array_event_bus_publish(cl_array_event_bus_t *event_bus, cl_event_t event, void *payload);

// event bus implmentation with array
static cl_array_event_bus_t array_event_bus = {
    .publish = (cl_event_bus_publish)cl_array_event_bus_publish,
    .subscribe = (cl_event_bus_subscribe)cl_array_event_bus_subscribe,
    .initialize = (cl_event_bus_initialize)cl_array_event_bus_initialize,
    .unsubscribe = (cl_event_bus_unsubscribe)cl_array_event_bus_unsubscribe,
};

cl_event_bus_t *cl_event_bus_get_array_impl()
{
  return (cl_event_bus_t *)&array_event_bus;
}

static void cl_array_event_bus_initialize(cl_array_event_bus_t *event_bus)
{
  for (int i = 0; i < TOTAL_EVENTS; i++)
  {
    for (int j = 0; j < MAX_CALLBACKS_PER_EVENT; j++)
    {
      event_bus->callbacks[i][j] = CL_EVENT_NULL;
    }
  }
}

static cl_event_ret_t cl_array_event_bus_subscribe(cl_array_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback)
{
  int i = 0;
  if (event >= TOTAL_EVENTS)
  {
    return CL_EVENT_RET_FAILED;
  }
  for (; i < MAX_CALLBACKS_PER_EVENT; i++)
  {
    if (event_bus->callbacks[event][i] == CL_EVENT_NULL)
    {
      event_bus->callbacks[event][i] = callback;
      return CL_EVENT_RET_OK;
    }
  }
  return CL_EVENT_RET_FAILED;
}

static cl_event_ret_t cl_array_event_bus_unsubscribe(cl_array_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback)
{
  int i = 0;
  if (event >= TOTAL_EVENTS)
  {
    return CL_EVENT_RET_FAILED;
  }
  for (; i < MAX_CALLBACKS_PER_EVENT; i++)
  {
    if (event_bus->callbacks[event][i] == callback)
    {
      event_bus->callbacks[event][i] = CL_EVENT_NULL;
      return CL_EVENT_RET_OK;
    }
  }
  return CL_EVENT_RET_FAILED;
}

static cl_event_ret_t cl_array_event_bus_publish(cl_array_event_bus_t *event_bus, cl_event_t event, void *payload)
{
  int i = 0;
  if (event >= TOTAL_EVENTS)
  {
    return CL_EVENT_RET_FAILED;
  }
  for (; i < MAX_CALLBACKS_PER_EVENT; i++)
  {
    cl_event_bus_event_callback_t callback = event_bus->callbacks[event][i];
    if (callback != CL_EVENT_NULL)
    {
      callback((cl_event_bus_t *)event_bus, event, payload);
    }
  }
  return CL_EVENT_RET_OK;
}
