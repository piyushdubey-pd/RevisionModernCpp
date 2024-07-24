#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

void flatten(const json& input, json& output, const std::string& prefix = "", int parentArrayIndex = -1) {
    for (auto& el : input.items()) {
        std::string new_key = prefix.empty() ? el.key() : prefix + "_" + el.key();
        if (parentArrayIndex != -1) {
            // If this element is part of an array, append the parent array index to the key
            new_key += "_" + std::to_string(parentArrayIndex);
        }

        if (el.value().is_primitive()) {
            output[new_key] = el.value();
        } else if (el.value().is_object()) {
            flatten(el.value(), output, new_key);
        } else if (el.value().is_array()) {
            int index = 0;
            for (auto& item : el.value()) {
                if (item.is_primitive()) {
                    output[new_key + "_" + std::to_string(index)] = item;
                } else {
                    // Recurse with the current index for array elements
                    flatten(item, output, new_key, index);
                }
                index++;
            }
        }
    }
}

int main() {
    // Example JSON object
    json example = {
        {"column1", "value1"},
        {"multidimensional_column", {"item1", "item2"}},
        {"nested_table", {
            {"child1", "value2"},
            {"child2", {"nested_item1", "nested_item2"}},
            {"deeply_nested", {
                {"deep_child", "deep_value"}
            }}
        }}
    };

    json flat_json;
    flatten(example, flat_json);

    std::cout << flat_json.dump(4) << std::endl;

    return 0;
}