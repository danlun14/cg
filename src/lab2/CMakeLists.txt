set(lab2_target lab2)

add_executable(${lab2_target})

include(CompileOptions)

set_compile_options(${lab2_target})

target_sources(
  ${lab2_target}
  PRIVATE
    ${lab2_target}/${lab2_target}.cpp
)

target_link_libraries(
  ${lab2_target}
  PRIVATE
    cipher
    basic
    BigInt
)

target_include_directories(
  ${lab2_target}
  PUBLIC
    ${root}/src/include/
)

set_target_properties(
  ${lab2_target}
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${root}/bin/
)