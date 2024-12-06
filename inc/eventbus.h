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

/**
 * @brief event bus operation return code
 */
typedef enum
{
  // Operation success
  CL_EVENT_RET_OK,

  // Operation failed
  CL_EVENT_RET_FAILED,
} cl_event_ret_t;

/**
 * @brief event bus null value
 */
#define CL_EVENT_NULL ((void *)0)

/**
 * @brief event bus type
 */
typedef struct cl_event_bus_t cl_event_bus_t;

/**
 * @brief event type
 */
typedef int cl_event_t;

/**
 * @brief initialize the event bus
 *
 * @param event_bus pointer to the event bus
 */
typedef void (*cl_event_bus_initialize)(cl_event_bus_t *event_bus);

/**
 * @brief event trigger callback function
 *
 * @param event_bus pointer to the event bus
 * @param event which event happened
 * @param payload payload associate to the event
 */
typedef void (*cl_event_bus_event_callback_t)(cl_event_bus_t *event_bus, cl_event_t event, void *payload);

/**
 * @brief subscribe to given event
 *
 * @param event_bus pointer to the event bus
 * @param event which event happened
 * @param callback callback when event happened
 *
 * @return CL_EVENT_RET_OK if subscribe success, CL_EVENT_RET_FAILED if subscribe failed
 */
typedef cl_event_ret_t (*cl_event_bus_subscribe)(cl_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback);

/**
 * @brief unsubscribe given event
 *
 * @param event_bus pointer to the event bus
 * @param event which event happened
 * @param callback callback when event happened
 *
 * @return CL_EVENT_RET_OK if unsubscribe success, CL_EVENT_RET_FAILED if unsubscribe failed
 */
typedef cl_event_ret_t (*cl_event_bus_unsubscribe)(cl_event_bus_t *event_bus, cl_event_t event, cl_event_bus_event_callback_t callback);

/**
 * @brief publish given event
 *
 * @param event_bus pointer to the event bus
 * @param event which event happened
 * @param payload pointer to the event payload, CL_EVENT_NULL if not provided
 *
 * @return CL_EVENT_RET_OK if publish success, CL_EVENT_RET_FAILED if publish failed
 */
typedef cl_event_ret_t (*cl_event_bus_publish)(cl_event_bus_t *event_bus, cl_event_t event, void *payload);

typedef struct cl_event_bus_t
{
  /**
   * initialize the event bus
   */
  cl_event_bus_initialize initialize;

  /**
   * subscribe to given event
   */
  cl_event_bus_subscribe subscribe;

  /**
   * unsubscribe given event
   */
  cl_event_bus_unsubscribe unsubscribe;

  /**
   * publish given event
   */
  cl_event_bus_publish publish;
} cl_event_bus_t;

/**
 * @brief get an event bus implementation with array
 *
 * @return pointer to the event bus implementation
 */
cl_event_bus_t *cl_event_bus_get_array_impl();

/**
 * @brief get an event bus implementation with linked list
 *
 * @return pointer to the event bus implementation
 */
cl_event_bus_t *cl_event_bus_get_linked_list_impl();

#endif
