set(basic_target basic)

add_library(${basic_target} STATIC)

include(CompileOptions)
set_compile_options(${basic_target})

target_sources(
  ${basic_target}
  PRIVATE
    ${basic_target}/${basic_target}.cpp
)

target_link_libraries(
  ${basic_target}
  PUBLIC
    BigInt
)

target_include_directories(
  ${basic_target}
  PUBLIC
    ${root}/src/include
)