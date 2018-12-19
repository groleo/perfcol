find_package(PythonInterp)

set(GEN_API
	egl-shim.h
	egl-xmacro.h
	eglext-shim.h
	eglext-xmacro.h
	gl2-shim.h
	gl2-xmacro.h
	gl2ext-shim.h
	gl2ext-xmacro.h
)
add_custom_command(OUTPUT ${GEN_API}
	COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_SOURCE_DIR}/tools/genperfmon.py > ${PROJECT_SOURCE_DIR}/gen/perf_event_gen.cpp
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/xml/
	DEPENDS ${GENERATOR}
	COMMENT "Generating API"
)

add_custom_target(gen DEPENDS ${GEN_API}
	COMMENT "Generating dependencies"
)
