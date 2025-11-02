#ifndef FETCH_DATA_FROM_SERVER_HPP
#define FETCH_DATA_FROM_SERVER_HPP

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void fetchAndParseJson(const std::string& ulr);

#endif // !FETCH_DATA_FROM_SERVER_HPP
