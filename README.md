# datToCsv

This program converts a binray sensor data file into a csv file.

## How to build

Using WSL, you can compile  using gcc: "gcc -o datToCsv main.c"

## How to use

In general first argument is input second is output.
Pipe the output to a log file, since it the printed output can slow down the program and clutter the screem.

In WSL: dataToCsv "inputFile.dat" "outputFile.csv" > "logfile.txt"

## Data Format

The binary data should be stored as  packed (x,y,z) samples, each sample being a 16 bit signed number, stored little-endian.

