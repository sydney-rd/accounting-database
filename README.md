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

./db view - views all entries in the file

./db view "First Last" - views all entries of a particular name

./db names - views only the names in the file

./db add - adds an entry

./db sum "First Last" - shows total sum of a given name

./db max - gives you the vendor with the largest sum

./db destory - erases entire file (use with caution)


