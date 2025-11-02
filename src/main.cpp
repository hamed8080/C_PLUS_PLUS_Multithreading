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

void readFileExample() {
    /// Use file full path if run through the Xcode. like /Users/your_user/Desktop/...
    thread t(readFile, "example.txt"); // Compiles now!

    cout << "Continue on the main thread" << endl;

    t.join();

    cout << "File reading complete" << endl;
}

void readSeverJsonSimpleThreadExample() {
    thread t(fetchAndParseJson, "https://jsonplaceholder.typicode.com/todos/1");
    cout << "Fetching JSON in the background...\n";
    t.join();
}

int main(int argc, const char * argv[]) {
    // readFileExample(); 
    readSeverJsonSimpleThreadExample();
    return 0;
}

