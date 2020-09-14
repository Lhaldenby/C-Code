#include "Grid.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

Grid::Grid() 
	:width(0),height(0){
	// IMPLEMENT ME
}

Grid::~Grid(){
	// IMPLEMENT ME
}

void Grid::loadFromFile(const std::string& filename){
	// IMPLEMENT ME DONE
	
	std::string line; //used to store each line of the file
	std::ifstream file(filename); //open the file to read from
	int lineCount = 0; //number of lines thats been seen so that can seperate grid from start and goal
	std::vector<std::string> listElements; //used to store all elements in the grid
	
	if (file.is_open()){ //check file is open
		
		while (getline (file, line) ){ //get each line of the file
			
			if (lineCount == 0) { //if first line
				start[0] = (int) line.at(6) -48;  //get start x coord and -48 for ascii difference 
				start[1]= (int) line.at(8)-48;  //get start y coord and -48 for ascii difference
			} 
			
			if (lineCount == 1) { //if second line
				goal[0] = line[5] - 48;  //get goal x coord and -48 for ascii difference
				goal[1]=line[7] - 48; //get goal y coord and -48 for ascii difference
			}
			
			if (lineCount > 1) { //gets the rest of the grid
				
					grid.push_back( std::vector<std::string>()); //add row to the grid
					printGrid.push_back( std::vector<std::string>()); //add row to the print grid to be used for printing later
				
					width = 0; //used to set width of the grid
					for (std::string::size_type i = 0; i < line.size(); i++) { //loop through each row of the grid
						width = width + 1; //sets size of the width
						
						listElements.push_back( std::string(1,line[i]) ); //adds all elements from the row into one vector to be used later
						
					}
					height = height +1; //sets height of the grid
				
			}
			
			lineCount = lineCount + 1; //increases line count of the file by 1 for each new line
			
		}
		file.close(); //close the file
		
	} else {
	
		throw "Error loading grid description";
		
	}
	
	lineCount = 0; //sets line count to 0 so i can count through list of grid elements to put into the grid
	
	for (int j = height-1; j>=0; j--){
		for (int k = 0; k <width; k++){
			grid[k].push_back(listElements[lineCount]); //add each element into the grid
			printGrid[k].push_back(listElements[lineCount]); //add each element into the printed grid
			lineCount = lineCount + 1; //move onto next element in the grid
			
		}
	}
	
}

bool Grid::isStart(int x,int y) const{
	// IMPLEMENT ME DONE
	if ( (x >= width or y>= height) or (x < 0 or y < 0)){  //checks to see if x or y is in the grid
		throw "Position outside of the range of the grid.";
	}
	if (start[0] == x and start[1] == y){ //checks to see if x and y is the start 
		return true;
	} else {
		return false;
	}

}
bool Grid::isGoal(int x,int y) const{
	// IMPLEMENT ME DONE
	if ( (x >= width or y>= height) or (x < 0 or y < 0)){//checks to see if x or y is in the grid
		throw "Position outside of the range of the grid.";
	}
	if (goal[0] == x and goal[1] == y){  //checks to see if x and y is the goal
		return true;
	} else {
		return false;
	}

}
bool Grid::blocked(int x, int y) const{
	// IMPLEMENT ME DONE
	if ( (x >= width or y>= height) or (x < 0 or y < 0)){   //checks to see if x or y is in the grid
		throw "Position outside of the range of the grid.";
	}
	if (grid[x][y] == "x"){ //checks to see if grid location is blocked
		return true;
	} else {
		return false;
	}

}
void Grid::setStart(int x, int y){
	// IMPLEMENT ME DONE
	if ( (x >= width or y>= height) or (x < 0 or y < 0)){   //checks to see if x or y is in the grid
		throw "Position outside of the range of the grid.";
	}
	start[0] = x; //sets start x coord to x
	start[1] = y; //sets start y coord to y
}
void Grid::setGoal(int x, int y){
	// IMPLEMENT ME DONE
	if ( (x >= width or y>= height) or (x < 0 or y < 0)){  //checks to see if x or y is in the grid
		throw "Position outside of the range of the grid.";
	}

	goal[0] = x; //sets goal x coord to x
	goal[1] = y;  //sets goal y coord to y

}
void Grid::unblock(int x, int y){
	// IMPLEMENT ME DONE
	if ( (x >= width or y>= height) or (x < 0 or y < 0)){   //checks to see if x or y is in the grid
		throw "Position outside of the range of the grid.";
	} else {
		grid[x][y] = "o"; //sets grid x,y to o to be unblocked
	}
	
}
void Grid::block(int x, int y){
	// IMPLEMENT ME DONE
	if ( (x >= width or y>= height) or (x < 0 or y < 0)){   //checks to see if x or y is in the grid
		throw "Position outside of the range of the grid.";
	} else {
		grid[x][y] = "x"; //sets grid  x,y to be x to be blocked
	}
	
}
bool Grid::recursiveSolve(int x, int y){  //added method to solve the maze
	
	if (x == goal[0] and y == goal[1]){ return true; }  // checks if youre at the goal and returns true
	
	if (solveGrid[y][x] == true or grid[x][y] == "x") {return false;}  //checks to see if at a blocked coord or if youve been here before
	
	solveGrid[y][x] = true; //set new location to true
	
	if (x != 0) { //check to see if on x edge
		
		if (recursiveSolve(x-1, y)) { //recursively solve with new location
			path.push_back("EAST"); //if true add direction it went to solve
			return true; 
		}
	}
	
	if (x != (width -1) ){ //checks to see if on x edge other side
		
		if (recursiveSolve(x+1,y)){  //recursively solve with new location
			path.push_back("WEST"); //if true add direction it went to solve
			return true;
		}
	}
	
	if (y != 0 ) { //check to see if on y edge
		
		if (recursiveSolve(x, y-1)){  //recursively solve with new location
			path.push_back("SOUTH"); //if true add direction it went to solve
			return true;
		}
	}
	
	if (y != (height -1) ){ //checks to see if on y edge other side
		
		if (recursiveSolve(x,y+1)){  //recursively solve with new location
			path.push_back("NORTH"); //if true add direction it went to solve
			return true;
		}
	}
	return false; //if no path found return false
}
bool Grid::existsPath(){
	// IMPLEMENT ME DONE
	solveGrid.clear(); //clear old solved grid
	path.clear();  //clear old path found
	
	for (int i=0; i < height; i++){  //fill in solve grid with all falses so can be used by method to solve maze
		
		solveGrid.push_back(std::vector<bool>());
		
		for (int j = 0; j < width; j++){
			
			solveGrid[i].push_back(false);
		}
	}
	
	return recursiveSolve(start[0],start[1]); //solve maze and return whther possible or not

}
void Grid::outputPath(std::ostream& o){
	// IMPLEMENT ME
	if (existsPath()){ //check path exists
		
		printGrid[start[0]][start[1]] = "s"; //set start to s on printed grid
		printGrid[goal[0]][goal[1]] = "g"; //set goal to g on printed grid
		
		int x = start[0]; //set start x coord
		int y = start[1]; //set start y coord
		for (int k=0; k < path.size()-1; k++){ //loop through path to change grid to have *'s for correct path
			if (path[k] == "EAST"){ //if path says go east run this
				x = x+1; //move right
				printGrid[x][y] = "*"; //change this location to *
			}
			if (path[k] == "WEST"){  //if path says go west run this
				x = x-1; //move left
				printGrid[x][y] = "*"; //change this location to *
			}
			if (path[k] == "SOUTH"){ //if path says go south run this
				y = y-1; //move down
				printGrid[x][y] = "*"; //change this location to *
			}
			if (path[k] == "NORTH"){ //if path says go north run this
				y = y+1; //move up
				printGrid[x][y] = "*"; //change this location to *
			}
		}
		
		for (int i = height-1; i>=0; i--){ //print the grid with s,g and *'s
			for (int j = 0; j <width; j++){
				cout << printGrid[j][i];
			}
			cout <<endl;
		}
		
	} else {
		cout << "No path from start to goal" << endl; //if no path is found print this
	}
}
void Grid::outputDirections(std::ostream& o){
	// IMPLEMENT ME
	if (existsPath()){ //check path exists
		
		std::string currDir = "NONE"; //sets up current direction to see direction of movement
		std::string prevDir = path[0]; //sets up previous direction to see whether change of direction has occured
		int steps = 0; //sets up number of moves in certain direction
		int x = start[0]; //sets up start x
		int y = start[1]; //sets up start y
		
		for (int k = 0; k < path.size(); k++){ //loop through path list
			
			currDir = path[k]; //sets up current direction as current path element
			
			if (currDir != prevDir){ //checks to see if change of direction has occured
				
				if (prevDir == "EAST"){ //if last direction was east run this
					cout << "Move from (" <<x << "," << y<< ") to "; //move from previous location
					x = x+steps; //set up number of steps that has occured in this direction
					cout <<"("<<x << "," << y<< ")" << endl; //print new location after steps made
				}
				
				if (prevDir == "WEST"){ //if last direction was west run this
					cout << "Move from (" <<x << "," << y<< ") to ";
					x = x-steps;
					cout <<"("<<x << "," << y<< ")" << endl;
				}
				
				if (prevDir == "NORTH"){ //if last direction was north run this
					cout << "Move from (" <<x << "," << y<< ") to ";
					y = y+steps;
					cout <<"("<<x << "," << y<< ")" << endl;
				}
				
				if (prevDir == "SOUTH"){ //if last direction was south run this
					cout << "Move from (" <<x << "," << y<< ") to ";
					y = y-steps;
					cout <<"("<<x << "," << y<< ")" << endl;
				}
				
				cout << "Turn " << path[k] << "." << endl;
				
				prevDir = currDir; //sets new old direction as what just changed to
				steps = 1; //sets steps to 1 for new direction
			} else {
				steps = steps +1; //if no new direction then add onto steps
			}
		}
		cout << "Move from (" <<x << "," << y<< ") to " <<"("<<goal[0] << "," << goal[1]<< ")" << endl; //print last move to line
				
		cout << "You have arrived at your destination" << endl; //print final line
		
	} else {
		cout << "No path from start to goal" << endl; //if no path is found print this
	}
	
}




