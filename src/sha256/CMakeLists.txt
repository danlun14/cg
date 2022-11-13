set(hash_target sha256)

add_library(${hash_target} STATIC)

include(CompileOptions)

set_compile_options(${hash_target})

target_sources(
  ${hash_target}
  PRIVATE
    ${hash_target}/${hash_target}.cpp
)


target_include_directories(
  ${hash_target}
  PUBLIC
    ${root}/src/include/
)