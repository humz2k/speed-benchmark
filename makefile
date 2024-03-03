BUILD_DIR ?= build
SOURCE_DIR ?= src

SOURCES := $(shell find $(SOURCE_DIR) -name '*.c')
OBJECTS := $(SOURCES:%.c=%.o)
OUTPUTS := $(OBJECTS:src%=build%)

HEADERS := $(shell find $(SOURCE_DIR) -name '*.h')

main: driver

driver: $(OUTPUTS)
	$(CC) -O3 $^ -o $@

build/%.o: $(SOURCE_DIR)/%.c $(HEADERS) | $(BUILD_DIR)
	$(CC) -Wall -Wpedantic -Werror -O3 -I$(SOURCE_DIR) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf build
	rm -rf driver