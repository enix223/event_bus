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
#include "assert.h"
#include "event_bus_test.h"

static int sleep_value = 0;
static void cl_sleep_event_sleep_callback(cl_event_bus_t *event_bus, cl_event_t event, void *payload);

int test_subscribe_should_success(cl_event_bus_t *event_bus)
{
  int ret = event_bus->subscribe(event_bus, CL_TEST_EVENT_SLEEP, cl_sleep_event_sleep_callback);
  ASSERT_EQ(ret, CL_EVENT_RET_OK);
  return 0;
}

int test_unsubscribe_should_success(cl_event_bus_t *event_bus)
{
  int ret = event_bus->subscribe(event_bus, CL_TEST_EVENT_SLEEP, cl_sleep_event_sleep_callback);
  ASSERT_EQ(ret, CL_EVENT_RET_OK);
  ret = event_bus->unsubscribe(event_bus, CL_TEST_EVENT_SLEEP, cl_sleep_event_sleep_callback);
  ASSERT_EQ(ret, CL_EVENT_RET_OK);
  return 0;
}

int test_publish_should_success(cl_event_bus_t *event_bus)
{
  int ret = event_bus->subscribe(event_bus, CL_TEST_EVENT_SLEEP, cl_sleep_event_sleep_callback);
  ASSERT_EQ(ret, CL_EVENT_RET_OK);

  int payload = 10;
  sleep_value = 0;
  ret = event_bus->publish(event_bus, CL_TEST_EVENT_SLEEP, &payload);
  ASSERT_EQ(ret, CL_EVENT_RET_OK);

  ASSERT_EQ(sleep_value, payload);
  return 0;
}

static void cl_sleep_event_sleep_callback(cl_event_bus_t *event_bus, cl_event_t event, void *payload)
{
  sleep_value = *((int *)payload);
}
