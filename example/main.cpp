#include <iostream>
#include <string>

#include "factory.h"

int main() {
    auto json = JsonFactory::createObject();
    json->set("name", "John");
    json->set("family", std::string("Johniii"));
    json->set("age", 30);
    json->set("is_admin", true);

    auto skills = JsonFactory::createArray();
    auto skill = JsonFactory::createObject();
    skill->set("title", "C++");
    skills->push(std::move(skill));

    json->set("skills", std::move(skills));

    std::string jsonString = json->stringify(true);
    std::cout << jsonString << std::endl;

    auto jsonObject = json->parse(jsonString);

    std::cout << "name: " << jsonObject->getString("name")
              << " age:" << jsonObject->getNumber("age") << std::endl;

    return 0;
}
