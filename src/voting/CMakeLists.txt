set(voting_target voting)

add_library(${voting_target} STATIC)

include(CompileOptions)
set_compile_options(${voting_target})

target_sources(
  ${voting_target}
  PRIVATE
    ${voting_target}/${voting_target}.cpp
)

target_link_libraries(
  ${voting_target}
  PRIVATE
)

target_include_directories(
  ${voting_target}
  PUBLIC
    ${root}/src/include
)