#include <string>

// prints header file - useless
void print_header();

// prints all entries in file

// print all names in file
void print_entry_names();

//prints individual data depending on user inputted name
void print_individual_name_data(std::string vendor_name);

void get_field(const char* field_name, std::string& field);

std::string entry_formatter(const std::vector<std::string>& fields, const std::string& delimiter);

//adds entry to database
void add_entry();

int string_find(const std::string& str, int nth_delimiter, char delimiter);

std::string get_name(std::string line);

std::string get_amount(std::string line);

std::string get_date(std::string line);

std::string get_comment(std::string line);

void view_all_entries();

// prints each name and its sums in database - unfinished
// Sydney David - total sum
// Pavlos Sakoglou - total sum 
void print_names_and_sums(std::string vendor_name);

//prints individual sum dependent on user inputted name - unfinished
//user inputs name: Sydney David
//prints Sydney David 
//total sum from all SD entries
void given_name_sum(std::string name);

//max sum func - unfinished
//search for specific delimiter and add that total column up 
void max_sum();

//erases all data
void erase_all_data();

void ExecuteViewMaybe(const std::string& action1, std::string action2);

void ExecuteAddMaybe(const std::string& action);

void ExecuteNamesMaybe(const std::string& action);

void ExecuteSumMaybe(const std::string& action1, std::string action2);

void ExecuteDestroyMaybe(const std::string& action);

void ExecuteMaxMaybe(const std::string& action);