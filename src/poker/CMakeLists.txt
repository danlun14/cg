set(poker_target poker)

add_executable(${poker_target})

include(CompileOptions)

set_compile_options(${poker_target})

target_sources(
  ${poker_target}
  PRIVATE
    ${poker_target}/${poker_target}.cpp
)

target_link_libraries(
  ${poker_target}
  PRIVATE
    basic
    cipher
)

target_include_directories(
  ${poker_target}
  PUBLIC
    ${root}/src/include/
)

set_target_properties(
  ${poker_target}
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${root}/bin/
)