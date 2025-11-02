#include <iostream>
#include <cstddef>
#include <curl/curl.h>
#include "FetchDataFromServer.hpp"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* out) {
    size_t totalSize = size * nmemb;
    out->append((char*) contents, nmemb);
    return totalSize;
}

void fetchAndParseJson(const std::string& url) {
    CURL* curl = curl_easy_init();
    
    if (!curl) {
        std::cerr << "Failed to init curl\n";
        return;
    }
    
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    try {
        auto data = json::parse(response);
        std::cout << "Parse JSON: \n" << data.dump(4) << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Json parse error: " << e.what() << "\n";
    }
}
