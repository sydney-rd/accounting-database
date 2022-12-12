# accounting-database

This is a program that can help manage, organize and store your finanical data for your company

From the terminal, run:

g++ -std=c++20 main.cpp launchers.cpp engine.cpp -o db

# commands

You can then choose between:

./db help 

./db view

./db view "First Last"

./db names

./db add

./db sum "First Last"

./db max

./db destroy

# command definitions

I recommend initially running the command:

./db help - displays the optional commands the user can run and what they do

./db view - views all vendor entries

./db view "First Last" - view entry by vendor name

./db names - views all vendor names in file

./db add - adds vendor entry

./db sum "First Last" - view total sum of vendor name

./db max - Finds largest sum in vendor list

./db destory - erases entire file (use with caution)


