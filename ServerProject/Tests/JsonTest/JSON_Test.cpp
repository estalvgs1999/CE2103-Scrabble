//
// Created by esteban on 20/03/19.
//

#include "../../lib/rapidjson/document.h"
#include "../../lib/rapidjson/writer.h"
#include "../../rapidjson/stringbuffer.h"
#include <iostream>
#include "JSON_Test.hpp"

using namespace rapidjson;

int JSON_Test::test1() {
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return 0;
}