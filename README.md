# Event bus

Event bus implementation in pure C

## Usage

0. Define macros

    ```c
    // How many total events does the event bus support
    #define CONFIG_EVENT_BUS_TOTAL_EVENTS 10

    // The maximum number of callbacks for each event
    #define CONFIG_EVENT_BUS_MAX_EVENT_CALLBACKS_PER_EVENT 5
    ```

1. Define your events

    ```c
    typedef enum
    {
        CL_TEST_EVENT_SLEEP,

        CL_TEST_EVENT_AWAKE,
    } cl_test_event_t;
    ```

2. Get and event bus implementation

    ```c
    cl_event_bus_t *event_bus = cl_event_bus_get_array_impl();
    event_bus->initialize(event_bus);
    ```

3. Subscribe event

    ```c

    static void cl_sleep_event_callback(cl_event_bus_t *event_bus, cl_event_t event, void *payload)
    {
        // HANDLE EVENT HERE
    }

    event_bus->subscribe(event_bus, CL_TEST_EVENT_SLEEP, cl_sleep_event_callback);
    ```

4. Publish event

    ```c
    int payload = 10;
    event_bus->publish(event_bus, CL_TEST_EVENT_SLEEP, &payload);
    ```
