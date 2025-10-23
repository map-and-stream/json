#pragma once
#include "json.h"
#include "nlohmann.h"

class JsonFactory {
  public:
    static std::unique_ptr<IJson> createObject() { return std::make_unique<NlohmannJson>(); }

    static std::unique_ptr<IJson> createArray() {
        auto json = std::make_unique<NlohmannJson>();
        json->data = nlohmann::json::array();
        return json;
    }
};
