
#include <iostream>
#include <string>
#include <stdlib.h>
#include "json.h"

int main()
{
	JsonObject json;
	std::string jsonStr;
	std::string jsonResult;

	//1. convert string to json
	jsonStr = R"({"name":"zhangsan","age": 18, "gender":"male","weight": 66.3})";
	if (json.read_from_string(jsonStr))
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

	//2. json object
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

	//3. json array
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

	for (int i = 0; i < json.array_size(); i++)
	{
		std::cout << "the " << i << " is:" << json[i].as_string() << std::endl;
	}

	json.clear();

	//4. json array parse
	jsonStr = R"(["orange", "banana", "apple"])";
	if (json.read_from_string(jsonStr))
	{
		for (int i = 0; i < json.array_size(); i++)
		{
			std::cout << "the " << i << " is:" << json[i].as_string() << std::endl;
		}
	}

	json.clear();

	return 0;
}

