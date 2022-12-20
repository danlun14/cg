set(graphgenerator_target graphgenerator)

add_executable(${graphgenerator_target})

include(CompileOptions)

set_compile_options(${graphgenerator_target})

target_sources(
  ${graphgenerator_target}
  PRIVATE
    ${graphgenerator_target}/${graphgenerator_target}.cpp
)

target_link_libraries(
  ${graphgenerator_target}
  PRIVATE
)

target_include_directories(
  ${graphgenerator_target}
  PUBLIC
    ${root}/src/include/
)

set_target_properties(
  ${graphgenerator_target}
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${root}/bin/
)