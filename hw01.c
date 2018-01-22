/**
 * Name: Jake Billings
 * Date: 01/21/2018
 * Class: CSCI 2312
 * Description: Read the following description of the Battleship game and do a ROC(k)ET decomposition.  For the Test
 * phase, describe what testing you would need to do on each function to feel like the major threads of the function
 * were tested properly.
 * Status: psuedocode
 */

//---------Dependency Imports---------
//Include cout
//Include any classes we might need
//Use the standard namespace so that we don't have to type "std" all the time

//-----------Data Structures----------
//SHIP_TYPE
// Declare an enumeration called SHIP_TYPE with the following values:
// Carrier (length=5)
// Battleship (length=4)
// Cruiser (length=3)
// Submarine (length=3)
// Destroyer (length=2)

//SHIP_ORIENTATION
// Declare an enumeration called SHIP_TYPE with the following values:
// Horizontal
// Vertical

//SHIP
// Declare a data structure called Ship with the following properties:
// int x - the x value of the leftmost corner of the ship
// int y - the y value of the uppermost corner of the ship
// SHIP_TYPE shipType - the type (and therefore length) of the ship
// SHIP_ORIENTATION - the orientation of the ship (which determines where its lower right corner is)
//
// help from: https://www.geeksforgeeks.org/find-two-rectangles-overlap/
// bool overlapsWith(Ship other)
//  a boolean function that checks if this instance of ship overlaps with another
// If one rectangle is on left side of other
//  if (this.upperLeftX > other.lowerRightX || this.lowerRightX > other.upperLeftX ) return false
// If one rectangle is above other
//  if (this.upperLeftY < other.lowerRightY || this.lowerRightY < other.upperLeftY ) return false
// return true

//-----------Main Function------------
//Create grid
// Parameters: input stream (input stream is required since we're going to mock it for testing; it would be cin for a
//  real game)
// Return value: ship[2][5] - an array of ship arrays each ship[5] represents a fleet grid
//  *The return value might actually be vectors because .push_back() would be useful
//
//  declare a vector of ship vectors to store all boards for the game
//  For each player [0,1]
//     declare a ship vector for current player
//     For each shipType in SHIP_TYPES (5 ship types)
//       print message that says we're placing a ship of type shipType
//       print a message that says we want the upper left hand corner
//       input := getline() from cin
//       if the input isn't in the form A1, print error message and accept input again
//       convert the input to (x, y) coordinates where x is the number that corresponds with the letter and y is the number-1
//         E.g. D2 -> x=3, y=1 (since we're zero indexed)
//       if the x, y is outside the grid, print message and try again
//       calculate the two possible lower right corners of the ship
//         This are at x+length, y (horizontal) and x, y+length (vertical)
//       ask the user which option they want
//       if the selected option implies a lower right corner that is outside the grid, print message
//         and try again
//       init a ship object
//       for otherShip in ship vector for current player
//         if ship.overlapsWish(otherShip)
//           print an error message and try again
//       push the object into the vector for the current player
//    push the ship vector for the player into the multivector that stores data for the game
//  return the ship multivector that stores boards for the whole game


//-----------Test Strategy------------
//Declare automated function to test create grid
//  create a mock input stream with ships that break the rules, follow the rules, but overall but the
//  board in a known state
//  call createGrid() with that test input stream
//  check that the board is in the correct state