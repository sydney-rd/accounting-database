#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>

#define DB "db.txt"

void help() {
    std::cout << "\n./adb view - View all vendor entries" << std::endl;
    std::cout << "./adb view \"First Last\" - View entry by vendor name" << std::endl;
    std::cout << "./adb names - Views all vendor names in file" << std::endl;
    std::cout << "./adb add - Add vendor entry" << std::endl;
    std::cout << "./adb sum \"First Last\" - View total sum of vendor name" << std::endl;
    std::cout << "./adb max - Finds largest sum in vendor list" << std::endl;
    std::cout << "./adb destroy - Erases all entries and data\n" << std::endl;
}

void print_entry_names() {
    std::ifstream file(DB);
    std::string line;
    int i = 0;
    while (std::getline(file, line)) {
        int position = line.find(","); 
        std::string name = line.substr(0, position);
        std::cout << ++i << ". " << name << std::endl;
    }    
}

static void init_field(const char* field_name, std::string& field) {
    std::cout << "Enter " << field_name << ": ";
    std::getline(std::cin, field);   
}

static std::string entry_formatter(const std::vector<std::string>& fields, const std::string& delimiter) {
    std::string ret = "";
    for (int i = 0; i < fields.size(); i++) {
        ret += fields[i];
        if (i != 3) {
            ret += delimiter;
        }
    }
    return ret;
}

void add_entry() {
    std::ofstream file;
    file.open(DB, std::ios::app);
    std::string name, comment, date, amount;
    init_field("name", name);
    init_field("amount", amount);
    init_field("date", date);
    init_field("comments", comment);
    file << entry_formatter({name, amount, date, comment}, ",") << std::endl;
    file.close();
}

static int string_find(const std::string& str, int nth_delimiter, char delimiter) {
    int ret = -1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') { 
            nth_delimiter--;
        }
        if (nth_delimiter == 0) {
            ret = i;
            break;
        }
    }
    return ret;
}

static std::string get_name(std::string line) {
    int pos1 = string_find(line, 1, ',');
    return line.substr(0, pos1);
}

static std::string get_amount(std::string line) {
    int pos1 = string_find(line, 1, ',');
    int pos2 = string_find(line, 2, ',');
    return std::string(line.c_str() + pos1 + 2, line.c_str() + pos2);
}

static std::string get_date(std::string line) {
    int pos1 = string_find(line, 2, ',');
    int pos2 = string_find(line, 3, ',');
    return std::string(line.c_str() + pos1 + 1, line.c_str() + pos2);
}

static std::string get_comment(std::string line) {
    int pos1 = string_find(line, 3, ',');
    return line.substr(pos1 + 1, line.size() - pos1);
}

static void print_line(std::string line, int i) {
    std::cout << ++i << ". " << get_name(line) << "  $" << get_amount(line) << "  " << get_date(line) << "  " << get_comment(line) << std::endl;
}

void view_all_entries() {
    std::string line;
    int i = 0;
    std::ifstream file(DB);
    while (std::getline(file, line)) {
        print_line(line, i);
    }
}

void print_individual_name_data(std::string vendor_name) {
    std::ifstream file(DB);
    std::string line;
    int i = 0;
    while (std::getline(file, line)) {
        if (get_name(line) == vendor_name) {
            print_line(line, i);
        }
    }
}

static double get_sum(std::string vendor_name) {
    std::ifstream file(DB); 
    std::string line; 
    double sum = 0; 
    while (std::getline(file, line)) {
        if (get_name(line) == vendor_name) { 
            std::string amount = get_amount(line); 
            sum += std::stod(amount);
        }
    }
    return sum;
}

void print_names_and_sums(std::string vendor_name) {
    double sum = get_sum(vendor_name);
    if (sum > 0) {
        std::cout << vendor_name << ": $" << sum << std::endl;
    }
}

void max_sum() { 
    std::ifstream file(DB);
    std::string line;
    double maxsum = 0;
    std::string maxname;
    while (std::getline(file, line)) {
        std::string current_name = get_name(line);
        double current_sum = get_sum(current_name);
        if (current_sum > maxsum) {
            maxsum = current_sum; 
            maxname = current_name; 
        }
    }
    std::cout << maxname << ": $" << maxsum << std::endl; 
}

void erase_all_data() {
    std::ofstream file;
    file.open(DB, std::ofstream::out | std::ofstream::trunc);
    file.close();
}