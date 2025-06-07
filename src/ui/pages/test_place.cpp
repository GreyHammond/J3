#include "test_place.hpp"

std::string_view test_place::id() {
    return "test-place";
}

std::string_view test_place::layout() {
    return R"(
        <rml>
        <head>
            <title>J3 - test place</title>
        </head>
        <body>
            <h1>J3</h1>
            <p>(obligatory lorem ipsum here)</p>
            <p>a text box for demonstration purposes:</p>
            <input type="text"/>
        </body>
        </rml>
    )";
}

std::string_view test_place::styles() {
    return R"(
        body {
            background-color: #0F0F0F;
            color: #FFFFFF;
        }

        input.text {
            background-color: #1E1E1E;
            color: #FFFFFF;
            padding: 0.5rem 1rem;
            width: 300px;
            tab-index: auto;
            cursor: text;
            box-sizing: border-box;
            box-shadow: 5px 5px #00000066;
        }
    )";
}
