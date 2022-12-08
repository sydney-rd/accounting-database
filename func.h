#include <string>
#ifndef FUNC
#define FUNC

void help();

void print_entry_names();

void print_individual_name_data(std::string vendor_name);

void get_field(const char* field_name, std::string& field);

std::string entry_formatter(const std::vector<std::string>& fields, const std::string& delimiter);

void add_entry();

int string_find(const std::string& str, int nth_delimiter, char delimiter);

std::string get_name(std::string line);

std::string get_amount(std::string line);

std::string get_date(std::string line);

std::string get_comment(std::string line);

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