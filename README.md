# accounting-database

This is a program that can help manage, organize and store your finanical data for your company

From the terminal, run:

g++ -std=c++20 cpp/* -o adb

# commands

You can then choose between:

./adb help 

./adb view

./adb view "First Last"

./adb names

./adb add

./adb sum "First Last"

./adb max

./adb destroy

# command definitions

I recommend initially running the command:

./adb help - displays the optional commands the user can run and what they do

./adb view - views all vendor entries

./adb view "First Last" - view entry by vendor name

./adb names - views all vendor names in file

./adb add - adds vendor entry

./adb sum "First Last" - view total sum of vendor name

./adb max - Finds largest sum in vendor list

./adb destroy - erases entire file (use with caution)


