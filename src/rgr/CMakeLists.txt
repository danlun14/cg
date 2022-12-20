set(rgr_target rgr)

add_executable(${rgr_target})

include(CompileOptions)

set_compile_options(${rgr_target})

target_sources(
  ${rgr_target}
  PRIVATE
    ${rgr_target}/${rgr_target}.cpp
)

target_link_libraries(
  ${rgr_target}
  PRIVATE
  basic
  cipher
)

target_include_directories(
  ${rgr_target}
  PUBLIC
    ${root}/src/include/
)

set_target_properties(
  ${rgr_target}
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${root}/bin/
)