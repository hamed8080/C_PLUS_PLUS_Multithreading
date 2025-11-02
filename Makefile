.PHONY: clean

CC=g++
BUILD_DIR=build
SRC_DIR=src
INCLUDE_PATH=/opt/homebrew/include
LIBRARY_PATH=/opt/homebrew/lib
CFLAGS=-I$(INCLUDE_PATH) -L$(LIBRARY_PATH) -lcurl -std=c++20 -pthread
RESOURCE_DIR=$(SRC_DIR)/resources
TARGET=$(BUILD_DIR)/main

$(BUILD_DIR)/main: $(SRC_DIR)/main.cpp 
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(SRC_DIR)/FetchDataFromServer.cpp -o $(BUILD_DIR)/main	

run_read_file: $(TARGET)
	@echo "Running the program with resources/example.txt file"
	@$(TARGET) 1 $(RESOURCE_DIR)/example.txt
	
run_fetch_server_simple_thread: $(TARGET)
	@echo "Running the program"
	@$(TARGET) 2

clean:
	rm -rf $(BUILD_DIR)

# g++ main.cpp FetchDataFromServer.cpp \
#  -I/opt/homebrew/include \
#  -L/opt/homebrew/lib \
#  -lcurl \
#  -std=c++17 \
#  -pthread \
#  -o main
