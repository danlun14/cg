set(lab3_target lab3)

add_executable(${lab3_target})

include(CompileOptions)

set_compile_options(${lab3_target})

target_sources(
  ${lab3_target}
  PRIVATE
    ${lab3_target}/${lab3_target}.cpp
)

target_link_libraries(
  ${lab3_target}
  PRIVATE
    cipher
    BigInt
    sign
)

target_include_directories(
  ${lab3_target}
  PUBLIC
    ${root}/src/include/
)

set_target_properties(
  ${lab3_target}
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${root}/bin/
)