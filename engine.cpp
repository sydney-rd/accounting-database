#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>

#define DB "db.txt"

void erase_all_data() {
    std::ofstream file;
    file.open("aadb.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();

}

void max_sum() {

}

// print all names in file
void print_entry_names() {
    std::ifstream file("aadb.txt");
    std::string line;
    while(std::getline(file, line)) {
        int position = line.find(","); //occurence
        std::string name = line.substr(0, position);
        std::cout << name << std::endl;
    }    
}

//prints individual data depending on user inputted name
void print_individual_name_data(std::string vendor_name) {
    std::ifstream file("aadb.txt");
    std::string line;
    while(std::getline(file, line)) {
        int position = line.find(","); 
        std::string name = line.substr(0, position);
        size_t pos = line.find(vendor_name);
        if(pos != std::string::npos) {
            std::cout << line << std::endl;
        }
    }
}

void get_field(const char* field_name, std::string& field) {
    std::cout << "Enter " << field_name << ": ";
    std::getline(std::cin, field);   
}

std::string entry_formatter(const std::vector<std::string>& fields, const std::string& delimiter) {
    std::string ret = "";
    for (int i = 0; i < fields.size(); i++) {
        ret += fields[i];
        if (i != 3) {
            ret += delimiter;
        }
    }
    return ret;
}

//adds entry to database
void add_entry() {
    std::ofstream file;
    file.open("aadb.txt", std::ios::app);
    std::string name, comment, date, amount;
    //print_header();

    get_field("name", name);
    get_field("amount", amount);
    get_field("date", date);
    get_field("comments", comment);

    file << entry_formatter({name, amount, date, comment}, ",") << std::endl;
    file.close();
}

int string_find(const std::string& str, int nth_delimiter, char delimiter) {
    int ret = -1;
    for(int i = 0; i < str.size(); i++) { // looping over the string
        if(str[i] == ',') { 
            nth_delimiter--;
        }
        if (nth_delimiter == 0) {
            ret = i;
            break;
        }
    }
    return ret;

}

std::string get_name(std::string line) {
    int pos1 = string_find(line, 1, ',');
    return line.substr(0, pos1);
}

std::string get_amount(std::string line) {
    int pos1 = string_find(line, 1, ',');
    int pos2 = string_find(line, 2, ',');
    return std::string(line.c_str() + pos1 + 2, line.c_str() + pos2);
}

std::string get_date(std::string line) {
    int pos1 = string_find(line, 2, ',');
    int pos2 = string_find(line, 3, ',');
    return std::string(line.c_str() + pos1 + 1, line.c_str() + pos2);
}

std::string get_comment(std::string line) {
    int pos1 = string_find(line, 3, ',');
    return line.substr(pos1 + 1, line.size() - pos1);
}

void view_all_entries() {
    std::string line;
    int i = 0;
    std::ifstream file("aadb.txt");
    while(std::getline(file, line)) {
        std::cout << ++i << ". " << get_name(line) << "  $" << get_amount(line) << "  " << get_date(line) << "  " << get_comment(line) << std::endl;
    }
}

// prints each name and its sums in database - unfinished
// Sydney David - total sum
// Pavlos Sakoglou - total sum 
void print_names_and_sums(std::string vendor_name) {
    std::ifstream file("aadb.txt");  // ok
    std::string line; // ok
    double sum = 0; // ok
    while(std::getline(file, line)) { // ok
        std::string name = get_name(line); // ok
        if (name == vendor_name) { // ok
            std::string amount = get_amount(line); // 
            sum += std::stod(amount);
        }
    }
    if (sum > 0) {
        std::cout << vendor_name << " : $" << sum << std::endl;
    }
}