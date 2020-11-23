#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <cpp-httplib/httplib.h>
#include <nlohman/json.hpp>
using json = nlohmann::json;
using namespace httplib;
json get_json();
json get_cache();
json get_hourly_request(json &hourly);
bool cachejson(json cacheView);
json get_time();
void findandreplace(std::string & data, std::string toSearch, std::string replaceStr){
    size_t pos = data.find(toSearch);
    while(pos != std::string::npos){
        data.replace(pos, toSearch.size(), replaceStr);
        pos = data.find(toSearch, pos + replaceStr.size());
    }
}
void responce(const Request &req, Response &res){
    json body;
    json forecast;
    body = get_cache();
    if (body.empty()){
        body = get_json();
        if (!body["Error"].is_null()){
            res.set_content(body["Error"], "text/plain");
            return;
        }else if (!body["Error"].is_null()) {
            res.set_content(body, "text/json");
        }
        cachejson(body);
        forecast = get_hourly_request(body["hourly"]);
        if (!forecast["Error"].is_null()){
            res.set_content(forecast["Error"], "text/plain");
            return;
        }
    }
    std::string tamplname = "templ.html";
    std::ifstream tamplate(tamplname);
    std::string str;
    if (tamplate.is_open()){
        getline(tamplate,str, '\0');
        tamplate.close();
    }
    else {
        res.set_content("Error", "text/plain");
        return;
    }
    findandreplace(str, "{hourly[i].weather[0].description}", forecast["weather"][0]["description"]);
    findandreplace(str, "{hourly[i].weather[0].icon}", forecast["weather"][0]["icon"]);
    findandreplace(str, "{hourly[i].temp}", std::to_string(int(round(forecast["temp"].get<double>()))));
    res.set_content(str, "text/html");
}
void responceraw(const Request &req, Response &res){
    json bodyRow;
    json forecastRow;
    bodyRow = get_cache();
    if (bodyRow.empty()){
        bodyRow = get_json();
        if (!bodyRow["Error"].is_null()) {
            res.set_content(bodyRow, "text/json");
            return;
        }
    } else if (!bodyRow["Error"].is_null()) {
        res.set_content(bodyRow, "text/json");
    }
    
    forecastRow = get_hourly_request(bodyRow["hourly"]);
    if (!forecastRow["Error"].is_null()) {
            res.set_content(forecastRow["Error"], "text/plain");
            return;
        }
    cachejson(bodyRow);
    std::string tamplname = "templ.html";
    std::ifstream tamplate(tamplname);
    std::string str;
    if (tamplate.is_open()){
        getline(tamplate,str, '\0');
        tamplate.close();
    }
    else {
        res.set_content("Error", "text/plain");
        return;
    }
    json output;
    output["temp"] = forecastRow["temp"];
    output["description"] = forecastRow["weather"][0]["description"];
    res.set_content(output.dump(), "text/json");
    }
int main(){
    Server myserv;
    myserv.Get("/", responce);
    myserv.Get("/raw", responceraw);
    myserv.listen("localhost", 3000);
}