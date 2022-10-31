set(BigInt_target BigInt)

add_library(${BigInt_target} STATIC)

include(CompileOptions)
set_compile_options(${BigInt_target})

target_sources(
  ${BigInt_target}
  PRIVATE
    ${BigInt_target}/${BigInt_target}.cpp
)

target_include_directories(
  ${BigInt_target}
  PUBLIC
    ${root}/src/include
)