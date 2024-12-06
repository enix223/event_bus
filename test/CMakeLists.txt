add_executable(eventbus_test
               event_bus_test.c
               array_eventbus_test.c
)

target_include_directories(eventbus_test
                           PRIVATE
                           ${CMAKE_SOURCE_DIR}/inc)

target_link_libraries(eventbus_test PRIVATE eventbus)

enable_testing()
add_test(
  NAME eventbus_test
  COMMAND $<TARGET_FILE:eventbus_test>
)
