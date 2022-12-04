set(lab5_target lab5)

add_executable(${lab5_target})

include(CompileOptions)

set_compile_options(${lab5_target})

target_sources(
  ${lab5_target}
  PRIVATE
    ${lab5_target}/${lab5_target}.cpp
)

target_link_libraries(
  ${lab5_target}
  PRIVATE
    voting
)

target_include_directories(
  ${lab5_target}
  PUBLIC
    ${root}/src/include/
)

set_target_properties(
  ${lab5_target}
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${root}/bin/
)