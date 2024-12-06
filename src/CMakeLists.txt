add_library(eventbus
            array_eventbus.c
)

target_include_directories(eventbus PUBLIC ${CMAKE_SOURCE_DIR}/inc)
