
#include <iostream>
#include <string>
#include <stdlib.h>
#include "json.h"

int main()
{
	JsonObject json;
	std::string jsonPersonStr;
	std::string jsonResult; 
	
	//convert string to json
	jsonPersonStr = R"({"name":"zhangsan","age": 18, "gender":"male","weight": 66.3})";
	if (json.read_from_string(jsonPersonStr))
	{
		std::cout << "name: " << json["name"].as_string().c_str() << std::endl;
		std::cout << "age: " << json["age"].as_int16() << std::endl;
		std::cout << "gender: " << json["gender"].as_string().c_str() << std::endl;
		std::cout << "weight: " << json["weight"].as_double() << std::endl;
	}

	//json to string
	if (json.write_to_string(jsonResult))
	{
		std::cout << "the raw string: " << jsonResult.c_str() << std::endl;
	}

	json.clear();

	//json object
	json["name"] = "zhangsan";
	json["age"] = 18;
	json["gender"] = "male";
	json["weight"] = 66.3;

	//json to string
	if (json.write_to_string(jsonResult))
	{
		std::cout << "the raw string: " << jsonResult.c_str() << std::endl;
	}

	json.clear();

	//json array
	json[0] = "Monday";
	json[1] = "Tuesday";
	json[2] = "Wednesday";
	json[3] = "Thursday";
	json[4] = "Friday";
	json[5] = "Saturday";
	json[6] = "Sunday";

	//json to string
	if (json.write_to_string(jsonResult))
	{
		std::cout << "the week string: " << jsonResult.c_str() << std::endl;
	}

    return 0;
}

