//
//  main.cpp
//  Multithreading
//
//  Created by Hamed Hosseini on 11/1/25.
//

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <future>
#include <coroutine>
#include "FetchDataFromServer.hpp"

using namespace std;

void readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    
    if (!file) {
        cerr << "Error opening the file " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

void readFileExample(const string& filePath) {
    /// Use file full path if run through the Xcode. like /Users/your_user/Desktop/...
    thread t(readFile, filePath); // Compiles now!

    cout << "Continue on the main thread" << endl;

    t.join();

    cout << "File reading complete" << endl;
}

void readSeverJsonSimpleThreadExample() {
    cout << "Fetching JSON with simple thread in the background...\n";
    thread t(fetchAndParseJson, "https://jsonplaceholder.typicode.com/todos/1");
    t.join();
}

void readSeverJsonModernAsyncExample() {
    auto future = async(launch::async, fetchAndParseJson, "https://jsonplaceholder.typicode.com/todos/1");
    try {
        cout << "Fetching JSON with modern async in the background...\n";
        future.get();
    } catch (const exception& e) {
        cerr << "Error fetching JOSN\n";
    }
}

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }
    
    int type = stoi(argv[1]);

    switch (type) {
        case 1:
            // C++ does not allow you to declare and init a variable inside a case.
            // That's the reason why you should create a new ``scope`` to create a variable, unless you will ran into
            // a compile issue.
        {
            string filePath = argv[2];
            readFileExample(filePath);
            break;
        }
        case 2:
            readSeverJsonSimpleThreadExample();
            break;
        case 3:
            readSeverJsonModernAsyncExample();
            break;
    }
    return 0;
}

