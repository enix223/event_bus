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

#ifndef CL_EVENT_BUS_H_
#define CL_EVENT_BUS_H_

typedef struct cl_event_bus_t cl_event_bus_t;

typedef int cl_event_t;

typedef void (*cl_event_bus_event_callback_t)(cl_event_bus_t *event_bus, char *event, void *payload);

void cl_event_bus_subscribe(cl_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback);

void cl_event_bus_unsubscribe(cl_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback);

#endif
