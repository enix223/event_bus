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

#ifndef CL_EVENT_BUS_CONF_H_
#define CL_EVENT_BUS_CONF_H_

/**
 * @brief How many total events does the event bus support
 */
#ifndef CONFIG_EVENT_BUS_TOTAL_EVENTS
#define CONFIG_EVENT_BUS_TOTAL_EVENTS (10)
#endif

/**
 * @brief The maximum number of callbacks for each event
 */
#ifndef CONFIG_EVENT_BUS_MAX_EVENT_CALLBACKS_PER_EVENT
#define CONFIG_EVENT_BUS_MAX_EVENT_CALLBACKS_PER_EVENT (10)
#endif

#endif