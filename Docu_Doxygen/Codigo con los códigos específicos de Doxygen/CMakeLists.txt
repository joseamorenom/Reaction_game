cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD "pico_w")

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(React_game)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(React_game
	main.c
	botones.c
	display_7seg.c
	LED.c
)

target_include_directories(React_game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(React_game pico_stdlib hardware_gpio pico_rand)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(React_game)

