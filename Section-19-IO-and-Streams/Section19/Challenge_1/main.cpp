// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    // Unformatted display so you can see how to access the vector elements
    int longest_country_name{0};
    int longest_city_name{0};
    int longest_city_population{0};
    const int extra_characters{5};
    const int longest_city_cost{10};
    const int length_of_table{60};
    
    for(auto country : tours.countries) {
        if(country.name.length() > longest_country_name) {
            longest_country_name = country.name.length();
        }
        for(auto city : country.cities) {
            if(city.name.length() > longest_city_name) {
                longest_city_name = city.name.length();
            }
            if(std::to_string(city.population).length()  > longest_city_population) {
                longest_city_population = std::to_string(city.population).length() ;
            }
        }
    }
    
    longest_country_name += extra_characters;
    longest_city_name += extra_characters;
    longest_city_population += extra_characters;
    
    std::cout << "longest country name is: " << longest_country_name << std::endl;
    std::cout << "longest city name is: " << longest_city_name << std::endl;
    std::cout << "longest city population is: " << longest_city_population << std::endl;
    std::cout << "longest city cost is: " << longest_city_cost << std::endl;
    
    std::cout << std::setw(std::ceil(length_of_table/2 + tours.title.length()/2 )) << tours.title << std::endl;
    std::cout << std::setw(length_of_table) << std::setfill('-') << "-" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(longest_country_name)  << "Country"   
              << std::setw(longest_city_name) << "City"
              << std::setw(longest_city_population) << "Population"
              << std::setw(longest_city_cost) << "Cost" << std::endl;
              
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << std::setw(length_of_table) << std::setfill('-') << "-" << std::endl;
        std::cout << std::setfill(' ');
        std::cout << std::setw(longest_country_name) << country.name;
        int i = 0;
        for(auto city : country.cities) {       // loop through the cities for each country
            if(i == 0) {
            std::cout << std::setw(longest_city_name) << city.name 
                          << std::setw(longest_city_population) << city.population 
                          << std::setw(longest_city_cost) << city.cost 
                          << std::endl;
                          i++;
            }
            else {
                std::cout << std::setw(longest_city_name + longest_country_name) << city.name 
                          << std::setw(longest_city_population) << city.population 
                          << std::setw(longest_city_cost) << city.cost 
                          << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}