#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }

  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  string ***trojans;
  string curr;
  

  input >> floors;
  trojans = new string**[floors];

  //2D array to keep track of possessions of students
  



  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];

  int **stuff = new int*[floors];

  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
  }

  getline(input, curr);

  while(getline(input, curr)) {

  	
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i >> k;

		  if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else if(floorsizes[i] != 0)//check if floor is occupied
		  {
		  	output << "People already live on this floor" << endl;
		  }

		  else if(i > floors ||  i < 0)//make sure floors is in range 
		  {

		  	output << "floor does not exist" << endl;
		  }
		  else 
		  {
		  	//populate 2D pointers with pointers to ints
		  	for(int x = 0; x < floors; x++)
		  	{
		  		stuff[x] = new int[k];
		  	}

		 	//populate 2D array with possession value of zero	
		  	for(int x = 0; x < floors; x++)
		  	{
		  		for(int y = 0; y < k; y++)
		  		{
		  			stuff[x][y] = 0;
		  		}
		  	}


		  	trojans[i] = new string*[k];

		  	//setting students possessions to NULL
		  	for(int x = 0; x < k; x++)
		  	{
		  		trojans[i][x] = NULL;
		  	}

		  	//update the number of students on the floor 
		  	floorsizes[i] = k;
		  }


		  
	  }
	  else if (curr == "MOVEOUT") {

	  	int i;
	  	ss >> i;

	  	if (ss.fail()) 
	  	{
		  	output << "Error - incorrect command" << endl;
	    }
		else if(floorsizes[i] = 0)
		  {
		  	output << "Floor is empty" << endl;
		  }
		  //save number of students on floor in variable
	  	else if(i < floors && i >= 0)//make sure that floor exists
		{
			//save number of students on the floor
			int students = floorsizes[i];

			//delete the student on that floor 
		  	for(int j = 0; j < students; j++)
		  	{

		  		delete [] trojans[i][j];
		  		
	  		}
	  		output << "Removing kids from floor" << endl;
	  		trojans[i] = NULL;

	  		floorsizes[i] = 0;
		}
		else
		{
			output << "Floor doesn't exist" << endl;
		}
	  	
	  }

	  else if (curr == "OBTAIN") 
	  {
	  	//read in information from line
	  	int i,j,k;
	  	ss >> i >> j >> k;
	  	string item;

	  	//If incorrect format, output error
	  	if (ss.fail()) 
	  	{
		  	output << "Error - incorrect command" << endl;
	    }
	    //if no one lives on the floor, output the floor is empty
	    else if(floorsizes[i] = 0)
		  {
		  	output << "Floor is empty" << endl;
		  }
		else if(stuff[i][j] != 0)//check if student has possessions already
		{
			output << "Student already has possessions" << endl;
		}

		else
		{
		  	trojans[i][j] = new string [k];

		  	//with every string, add it to the students possessions
		  	for(int x = 0; x < k; x++)
		  	{
		  		ss >> item;
		  		trojans[i][j][x] = item;
		  		
		  	}
		  	stuff[i][j] = k;
	    }
	}
	  else if (curr == "OUTPUT") 
	  {
	  	int i, j;
	  	ss >> i >> j;

	  	if (ss.fail()) 
	  	{
		  	output << "Error - incorrect command" << endl;
	    }
	    else if(j > floorsizes[i] || j < 0)//make sure there is a student i
	    {
	    	output << "Student does not exist" << endl;
	    }
	    else if(stuff[i][j] == 0)
	    {
	    	output << "Student doesn't have any stuff" << endl;
	    }
	    else
	    {
	    	for(int k = 0; k < stuff[i][j]; k++)
	    	{
	    		output << trojans[i][j][k] << endl;
	    	}
	    }
	  
	  }
	  else 
	  {
	  	output << "incorrect Command" << endl;
	  }
	  ss.str("");
	  ss.clear();
  }


  
  for(int a = 0; a < floors; a++)
  {
  	for(int b = 0; b < floorsizes[a]; b++)
  	{
  		delete [] trojans[a][b];
  	}
  	
  	delete [] trojans[a];
  }

  for(int a = 0; a < floors; a++)
  {
  	delete [] stuff[a];
  }

  
  delete [] trojans;
  delete [] stuff;
  delete [] floorsizes;

  return 0;
}
