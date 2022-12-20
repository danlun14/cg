set(gcycle_target gcycle)

add_library(${gcycle_target} STATIC)

include(CompileOptions)
set_compile_options(${gcycle_target})

target_sources(
  ${gcycle_target}
  PRIVATE
    ${gcycle_target}/${gcycle_target}.cpp
)

target_link_libraries(
  ${gcycle_target}
  PRIVATE
    cipher
)

target_include_directories(
  ${gcycle_target}
  PUBLIC
    ${root}/src/include
)