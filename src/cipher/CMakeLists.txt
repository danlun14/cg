set(cipher_target cipher)

add_library(${cipher_target} STATIC)

include(CompileOptions)
set_compile_options(${cipher_target})

target_sources(
  ${cipher_target}
  PRIVATE
    ${cipher_target}/${cipher_target}.cpp
)

target_link_libraries(
  ${cipher_target}
  PRIVATE
    basic
    BigInt
)

target_include_directories(
  ${cipher_target}
  PUBLIC
    ${root}/src/include
)