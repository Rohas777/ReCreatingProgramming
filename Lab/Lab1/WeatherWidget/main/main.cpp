#include <iostream>
#include "cpp-httplib/httplib.h"
#include "nlohman/json.hpp"
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
#include <string>
using json = nlohmann::json;
using namespace httplib;

Client cli("http://api.openweathermap.org");
Client timez("http://worldtimeapi.org");

json get_json() {
    auto res = cli.Get("/data/2.5/onecall?lat=44.9698623&lon=34.1329217&exclude=current,minutely,daily,alerts&units=metric&lang=ru&appid=922ae5c7ebbebc281380526c9977222c");
    if (!res) {
        return ("Err");
    }
    int stat = res->status;
    if (stat < 200 || stat >= 300) {
        return ("Err");
    }
    return json::parse(res->body);
}
json get_cache() {
    json cache;
    std::ifstream cacheChecking("cache.json");
    if (cacheChecking.is_open()) {
        std::string info;
        std::getline(cacheChecking, info, '\0');

        if (!info.empty()) {
            cache = json::parse(info);
        }
        cacheChecking.close();
    }
    else {
        return ("Err");
    }
    return cache;
}
bool cachejson(json cacheView) {
    std::ofstream cacheChecking("cache.json");
    if (cacheChecking.is_open()) {
        cacheChecking << cacheView;
        cacheChecking.close();
    }
    else return false;
    return true;
}
json get_time() {
    auto time = timez.Get("/api/timezone/Europe/Simferopol");
    if (!time) {
        return("Err");
        return json::object();
    }
    int stat = time->status;
    if (stat < 200 || stat >= 300) {
        return ("Err");
    }
    return json::parse(time->body);
}
json get_hourly_request(json& hourly) {
    json hourly_request;
    int lastTime = hourly.size() - 1;
    json timeAtMoment = get_time();
    int currentTime = timeAtMoment["unixtime"];
    if (hourly[lastTime]["dt"] < currentTime) {
        return json::object();
    }
    for (int i = 0; i <= lastTime; ++i) {
        if (hourly[i]["dt"] >= timeAtMoment) {
            hourly_request = hourly[i];
            break;
        }
    }
    return hourly_request;
}