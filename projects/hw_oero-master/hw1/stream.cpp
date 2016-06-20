#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main(int argc, char* argv[])
{
	//there must be a text file name when running program
	if(argc != 2)
	{
    cout << "Please provide a text file" << endl;
    return 1;
    }


    vector <string> words;
    string line;
    string row;
    int len;

    ifstream infile(argv[1]);

    //if file does not open, end program
    if(infile.fail())
    {
    	cout <<  "Text file failed to open" << endl;
    	return 1;
    }
    else{


    getline(infile, line);

    stringstream aa;
    aa << line;
    aa >> len;

    while(getline(infile, row))
    {
    	stringstream ss;
    	ss << row;

    	string hello;
    	while(ss >> hello)
    	{
    		words.push_back(hello);
    	}
    }

    for(int i = len -1; i >= 0; i--)
    {
    	cout << words[i] << endl;
    }

}

return 0;





}


