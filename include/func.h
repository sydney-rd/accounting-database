#include <string>
#ifndef FUNC
#define FUNC

void help();

void print_entry_names();

void print_individual_name_data(std::string vendor_name);

void add_entry();

void view_all_entries();

void print_names_and_sums(std::string vendor_name);

void max_sum();

void erase_all_data();

void ExecuteHelpMaybe(const std::string& action);

void ExecuteViewMaybe(const std::string& action1, std::string action2);

void ExecuteAddMaybe(const std::string& action);

void ExecuteNamesMaybe(const std::string& action);

void ExecuteSumMaybe(const std::string& action1, std::string action2);

void ExecuteMaxMaybe(const std::string& action);

void ExecuteDestroyMaybe(const std::string& action);

#endif 