# Multithreading in C++

This project demonstrates C++ multithreading concepts through practical examples. It covers thread creation and synchronization.

## 📦 Requirements
- C++17 or later
- `make` utility
- POSIX-compatible environment (Linux, macOS)

## 🚀 How to Build and Run

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/multithreading-examples.git
   cd multithreading-examples
   ```

2. Build and run the project:
   ```bash
   make option
   ```
### Options:
    1- run_read_file: Read from the example.txt file with a normal thread.
    2- run_fetch_server_simple_thread: Read a JSON url and parse it with normal thread.
    3- run_fetch_server_modern_async_thread: Read a JSON url and parse it with modern async.
    

3. To clean build files:
   ```bash
   make clean
   ```

## 🧩 Project Structure
```
project_directory/
├── src/        # Source code files
├── include/    # Header files
├── Makefile    # Build configuration
└── README.md   # Project documentation
```

## 🧠 Topics Covered
- Thread creation and management
- Condition variables

## 📝 License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
