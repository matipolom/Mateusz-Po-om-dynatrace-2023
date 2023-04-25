#include <chrono>
#include <fstream>
#include <iostream>
#include <date/date.h>
#include <nlohmann/json.hpp>
#include "internship.h"
#include <vector>
using json = nlohmann::json;
using namespace date;

namespace internship {
    // remove this function before submitting your solution
    void example(const std::string& jsonFileName) {
        std::ifstream f(jsonFileName);
        json data = json::parse(f);

        std::cout << "Dynatrace Gdansk Summer Internship 2023\n"
                    << "UTC time now: " << std::chrono::system_clock::now() << "\n\n";

        for(const auto& [id, product] : data.items()) {
            std::cout << "Product name: " << product["name"] << "\n";
        }
    }  
    
    void myfunction(const std::string& jsonFileName, const int elementsCount){
        std::ifstream f(jsonFileName);
        json data = json::parse(f);
        std::vector <int> indexes;
        int iterator = data.size();
        std::tm tm1 = {};
        std::stringstream ss1;
        std::tm tm2 = {};
        std::stringstream ss2;
        std::tm tm3 = {};
        std::stringstream ss3;
        std::tm tm4 = {};
        std::stringstream ss4;
        
        for (int i =0; i<iterator ;i++)
        {
            bool is_os= data[i]["os"].get<bool>();
            if(is_os==true)
            {
                
                if(indexes.size()<elementsCount)
                {
                    indexes.push_back(i);
                }else
                {
                    indexes.begin();
                    
                    auto eol1=data[i]["/versions/0/eol"_json_pointer].get<std::string>();
                    auto releaseDate1=data[i]["/versions/0/releaseDate"_json_pointer].get<std::string>();
                    ss1.str(eol1);
                    ss1 >> std::get_time(&tm1, "%Y-%m-%d");
                    std::put_time(&tm1, "%Y-%m-%d");
            
                    ss2.str(releaseDate1);
                    ss2 >> std::get_time(&tm2, "%Y-%m-%d");
                    std::put_time(&tm2, "%Y-%m-%d");
                    auto tp1 = std::chrono::system_clock::from_time_t(std::mktime(&tm1));
                    auto tp2 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));
                    //(floor<days>(tp1)-floor<days>(tp2));

                    for(int j =0; j<elementsCount; j++)
                    {
                        int vector_iteration=indexes[j];

                        auto eol2=data[i]["/versions/0/eol"_json_pointer].get<std::string>();
                        auto releaseDate2=data[i]["/versions/0/releaseDate"_json_pointer].get<std::string>();
                        ss1.str(eol2);
                        ss1 >> std::get_time(&tm1, "%Y-%m-%d");
                        std::put_time(&tm1, "%Y-%m-%d");
            
                        ss2.str(releaseDate2);
                        ss2 >> std::get_time(&tm2, "%Y-%m-%d");
                        std::put_time(&tm2, "%Y-%m-%d");
                        auto tp3 = std::chrono::system_clock::from_time_t(std::mktime(&tm1));
                        auto tp4 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));
                        //(floor<days>(tp3)-floor<days>(tp4));

                        if((floor<days>(tp1)-floor<days>(tp2))>(floor<days>(tp3)-floor<days>(tp4)))
                        {
                            indexes.insert(indexes.begin()+j,i);
                            indexes.pop_back();
                            break;
                        }
                    }

                }       
            }
        }
        for (const int x: indexes){
            
            std::string name= data[x]["name"].get<std::string>();
            std::cout<<" "<<name;
            auto eol=data[x]["/versions/0/eol"_json_pointer].get<std::string>();
            auto releaseDate=data[x]["/versions/0/releaseDate"_json_pointer].get<std::string>();
            auto cycle=data[x]["/versions/0/cycle"_json_pointer].get<std::string>();
            std::cout<<" "<<cycle;
            
            
            ss1.str(eol);
            ss1 >> std::get_time(&tm1, "%Y-%m-%d");
            std::put_time(&tm1, "%Y-%m-%d");
            
            ss2.str(releaseDate);
            ss2 >> std::get_time(&tm2, "%Y-%m-%d");
            std::put_time(&tm2, "%Y-%m-%d");
            auto output1 = std::chrono::system_clock::from_time_t(std::mktime(&tm1));
            auto output2 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));
            std::cout<<" "<<(floor<days>(output1)-floor<days>(output2))<<"\n";
        }
    }
    // do not remove this function
    void solution(const std::string& jsonFileName, int elementsCount) {
        

        myfunction(jsonFileName, elementsCount);// put the call to your solution here
    }

}