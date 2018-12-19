add_library(metrics STATIC
	metrics_gen.cpp
	perf.cpp
	metrics.cpp
	counters.cpp
	)

target_link_libraries(metrics ${CMAKE_DL_LIBS})

add_executable(main main.cpp)
target_link_libraries(main metrics)
