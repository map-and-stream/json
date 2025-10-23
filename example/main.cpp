#include "factory.h"
#include <iostream>

int main() {
    auto json = JsonFactory::createObject();
    json->set("name", "John");
    json->set("age", 30);
    json->set("is_admin", true);

    auto skills = JsonFactory::createArray();
    auto skill = JsonFactory::createObject();
    skill->set("title", "C++");
    skills->push(std::move(skill));

    json->set("skills", std::move(skills));

    std::cout << json->stringify(true) << std::endl;


    return 0;
}
