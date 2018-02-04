*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     :  CSC 2312
*  Due Date  :  Feb. 3, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

Problem
 =======
 Build two grids which are each X width and Y long where X and Y are
  user inputs.

 Randomly select 1/3 of the grid cells to be 1's and 2/3 to be 0's.

 Compare the two to create a third grid in which 1's exist in only squares
  where both of the original grids contained a one.

 Special Things about my Solution
 ================================
  1. I store three 2D vectors of bool objects because I saw only two states in the problem.
     I don't use ints because it's a waste of memory.

 Test Strategy
 =============
 Execute the following tests by hand:

  1. Enter 2x2 grid size => grids should be 2x2
                         => all cells in gridThree should be the AND of gridOne and gridTwo
                         => There should be exactly 1 1 in grids 1 and 2
  2. Enter 5x5 grid size => grids should be 5x5
                         => all cells in gridThree should be the AND of gridOne and gridTwo
                         => There should be exactly 8 1's in grids 1 and 2
  3. Enter 5x3 grid size => grids should be 5x3
                         => all cells in gridThree should be the AND of gridOne and gridTwo
                         => There should be exactly 5 1's in grids 1 and 2

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   main() implements the entire program. It creates two grids filled wish 1/3rd 1's at
   random locations and ANDs them to create a third grid. All three are printed
   to console.
   
   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.

