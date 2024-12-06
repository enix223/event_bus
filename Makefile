.PHONY: macos-preset clean test

all: eventbus

macos-preset:
	cmake --preset macos

eventbus: macos-preset
	cmake --build --preset macos

clean: macos-preset
	cmake --build --preset macos --target clean

test: eventbus
	cd out/build/macos/test && ctest
