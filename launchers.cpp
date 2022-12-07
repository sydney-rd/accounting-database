#include <string>
#include <iostream>
#include "func.h"

void ExecuteViewMaybe(const std::string& action1, std::string action2) {
    bool isView = action1 == "view";
    if (isView) {
        if (action2.empty()) {
            view_all_entries();
        } else {
            print_individual_name_data(action2);
        }
    }
}

void ExecuteAddMaybe(const std::string& action) {
    if (action == "add") {
        add_entry();
    }
}

void ExecuteNamesMaybe(const std::string& action) {
    if (action == "names") {
        print_entry_names(); 
    }
}

void ExecuteSumMaybe(const std::string& action1, std::string action2) {
    if (action1 == "sum" && !action2.empty()) {
        print_names_and_sums(action2);
    }
}

void ExecuteDestroyMaybe(const std::string& action) {
    if (action == "destroy") {
        erase_all_data();
    }
}

void ExecuteMaxMaybe(const std::string& action) {
    if (action == "max") {
        max_sum();
    }
}