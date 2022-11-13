set(sign_target sign)

add_library(${sign_target} STATIC)

include(CompileOptions)
set_compile_options(${sign_target})

target_sources(
  ${sign_target}
  PRIVATE
    ${sign_target}/${sign_target}.cpp
)

target_link_libraries(
  ${sign_target}
  PRIVATE
    cipher
    sha256
)

target_include_directories(
  ${sign_target}
  PUBLIC
    ${root}/src/include
)