#include "lib/Statement.h"
#include "lib/LetStatement.h"
#include "lib/EndStatement.h"
#include "lib/PrintStatement.h"
#include "lib/PrintAllStatement.h"
#include "lib/AddStatement.h"
#include "lib/SubStatement.h"
#include "lib/MultStatement.h"
#include "lib/DivStatement.h"
#include "lib/GotoStatement.h"
#include "lib/IfStatement.h"
#include "lib/GosubStatement.h"
#include "lib/ReturnStatement.h" 
#include "lib/stackint.h"
#include "lib/MainWidget.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


//Window for the Load button
MainWidget::MainWidget()
{

	loadBox = new QWidget();

	std::string name = "Select File You Want To Analyze";
	layout = new QVBoxLayout();

	header = new QLabel(QString::fromStdString(name));
	layout->addWidget(header);

	filename = new QLineEdit();
	filename->setPlaceholderText("Filename..");
	layout->addWidget(filename);

	load = new QPushButton("Load File");
	layout->addWidget(load);

	quit = new QPushButton("Quit");
	layout->addWidget(quit);
	
	// connects quit buttont to function that closes application
	connect(quit, SIGNAL(clicked()), this, SLOT(quitLoadFile( )));
	// connects load button to function that handles file
	connect(load, SIGNAL(clicked()), this, SLOT(openFile( )));

	//puts file into a vector of statement pointers
	connect(load, SIGNAL(clicked()), this, SLOT(helpRead( )));

	// connects textbox to load using enter in addition to load button
	connect(filename, SIGNAL(returnPressed()), load, SIGNAL(clicked()));
	loadBox->setLayout(layout);
	loadBox->setWindowTitle(tr("Load File"));
	loadBox->show();


	//////////////////////////////////////////////////////////////////////////////////////////////////

	nextCounter = 0;
	debugger = new QWidget();
	debugger->setWindowTitle("Debugger");
	QHBoxLayout* overallLayout = new QHBoxLayout();

	QVBoxLayout* dlayout = new QVBoxLayout();

	overallLayout->addLayout(dlayout);



	programList = new QListWidget();
	dlayout->addWidget(programList);
	//dlayout->addStretch();

	scrollArea = new QScrollArea();
	// scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setWidget(programList);

	stepButton = new QPushButton("Step");
	nextButton = new QPushButton("Next");
	breakPointButton = new QPushButton("Breakpoint");
	continueButton = new QPushButton("Continue");
	inspectButton = new QPushButton("Inspect");
	quitButton = new QPushButton("Quit");

	buttons = new QGridLayout();
	buttons->addWidget(stepButton, 0, 0, 1, 2);
	buttons->addWidget(nextButton, 0, 2, 1, 2);
  	buttons->addWidget(breakPointButton, 1, 0, 1, 2);
  	buttons->addWidget(continueButton, 1, 2, 1, 2);
  	buttons->addWidget(inspectButton, 2, 0, 1, 4);
  	buttons->addWidget(quitButton, 3, 0, 1, 4);

  	connect(quitButton, SIGNAL(clicked()), this, SLOT(closeDebugger( )) );
  	connect(breakPointButton, SIGNAL(clicked( )), this, SLOT(changeColor()) );
  	connect(stepButton, SIGNAL(clicked( )), this, SLOT(stepButtonFunction( )) );
  	connect(continueButton, SIGNAL(clicked()), this, SLOT(continueButtonFunction()));
  	// connect(continueButton, SIGNAL(clicked()), this, SLOT(continueButtonFunction()) );
  	//connect(programList, SIGNAL())

  	connect(inspectButton, SIGNAL(clicked()), this, SLOT(openInspector()) );

	
	overallLayout->addLayout(buttons);

	debugger->setLayout(overallLayout);

	////////////////////////////////////////////////////////////////////////////////////////////////////

	



//Notes
	//create a method to determine what errors are and open a Qdialog box
	//Inflate the values window
	//fix the 




}


MainWidget::~MainWidget()
{
	delete layout;
	delete header;
	delete filename;
	delete load;
	delete quit;
	  
}



void MainWidget::quitLoadFile()
{
	
	QApplication::quit();

}

void MainWidget::closeDebugger()
{
	QApplication::quit();
}

void MainWidget::openFile()
{
	//this->hide();
	// grab the filename inputted by user and saves it in a QString
	QString files = filename->text();

	// converty teh QString into a c++ string
	std::string lol = files.toStdString();
		
 

		// open the file 
        std::ifstream infile(lol.c_str());


        if (!infile)
        {
        	//if file fails, open a info box alerting the usre
          QMessageBox::information(this, "Error!", "File could not be opened.");

        }

        
        if(infile)
        {
        	//if the file opens, hid the loadbox and show the debugger window
        	loadBox->hide();
        	debugger->show();

        }


        // programLines.push_back(NULL);
        //while file is not at the end, add it to the programList
        while( ! infile.eof() )
	{
		getline(infile, line);

		programLines.push_back(line);

		programList->addItem(QString::fromStdString(line));
	}

	state = new ProgramState(programLines.size());


}

void MainWidget::helpRead()
{
	counter = 0;
	program.push_back(NULL);

	for(unsigned int i = 0; i < programLines.size(); i++)
	{
		readFile();
	}

}




void MainWidget::changeColor()
{
	// programList->currentItem()->setBackgroundColor(Qt::red);
	programList->currentItem()->setForeground(Qt::red);

	state->addBreakpoint(programList->currentRow());


	

}

void MainWidget::stepButtonFunction()
{
	if((nextCounter+2) == state->getNumLine())
	{
		//need to reset Program State counter to the beginning
	// need a clear all function for state 
		programList->item(nextCounter-1)->setBackgroundColor(Qt::white);
		std::cout << nextCounter << std::endl;
		nextCounter = 0;
		state->resetProgram();
		

	}


	program[state->getProgramState()]->execute(state, std::cout);
	
	
	if(nextCounter == 0)
	{

		programList->item(0)->setBackgroundColor(Qt::blue);

		
	}

	if(nextCounter > 0)
	{

		programList->item(nextCounter - 1)->setBackgroundColor(Qt::white);
		programList->item(nextCounter)->setBackgroundColor(Qt::blue);

	}


	nextCounter++;


}


void MainWidget::openInspector()
{
	valWindow = new InspectWidget();
	valWindow->showValueWindow();
	valWindow->passState(state);
}

void MainWidget::continueButtonFunction()
{

	// may be change program state implementation to a map instead of set
	while(state->breakpointFinder(state->getProgramState())  )
	{

		stepButtonFunction();
		/*
		if(program[state->getProgramState()] != 0)
		{
			program[state->getProgramState()]->execute(state, std::cout);
		}
		else
			return;
		*/
	}
}

void MainWidget::readFile()
{
	

	// for(unsigned int i = 1; i <= programLines.size(); i++)
	// {

		Statement * statement;	
		std::stringstream ss;
		std::stringstream aa;
		std::string type;
		std::string var;
		std::string carrie;
		std::string comp;
		int x;
		int y;
		int val;
		const int a = 1;
		const int b = 2;

		ss << programLines[counter]; 

		ss >> type;
		
		if ( type == "LET" )
		{
			ss >> var;
			ss >> val;
			// Note:  Because the project spec states that we can assume the file
			//	  contains a syntactically legal Facile program, we know that
			//	  any line that begins with "LET" will be followed by a space
			//	  and then a variable and then an integer value.
			statement = new LetStatement(var, val);
		}

		if(type == "END" || type == ".")
		{
			statement = new EndStatement();
		}

		if(type == "PRINT")
		{
			ss >> var;
			statement = new PrintStatement(var);
		}

		if(type == "PRINTALL")
		{
			statement = new PrintAllStatement();
		}

		if(type == "ADD")
		{

			ss >> var;
			ss >> carrie;

		

			if(carrie[0] >= 48 && carrie[0] <= 57)
			{
				aa << carrie;
				aa >> val;
				statement = new AddStatement(var, val, a);

			}
			else
			{
				statement = new AddStatement(var, carrie, b);
			}


		}

		if(type == "SUB")
		{
			ss >> var;
			ss >> carrie;
			if(carrie[0] >= 48 && carrie[0] <= 57)
			{
				aa << carrie;
				aa >> val;
				statement = new SubStatement(var, val, a);

			}
			else
			{
				statement = new SubStatement(var, carrie, b);
			}
		}

		if(type == "MULT")
		{
			ss >> var;
			ss >> carrie;

			if(carrie[0] >= 48 && carrie[0] <= 57)
			{
				aa << carrie;
				aa >> val;
				statement = new MultStatement(var, val, a);
			}
			else
			{
				statement = new MultStatement(var, carrie, b);
			}

		}

		if(type == "DIV")
		{
			ss >> var;
			ss >> carrie;

			if(carrie[0] >= 48 && carrie[0] <= 57)
			{
				aa << carrie;
				aa >> val;
				statement = new DivStatement(var, val, a);
			}
			else
			{
				statement = new DivStatement(var, carrie, b);
			}

		}

		if(type == "GOTO")
		{
			ss >> val;
			statement = new GotoStatement(val);
		}

		if (type == "IF")
		{
			ss >> var;
			ss >> comp;
			ss >> x;
			ss >> carrie;
			ss >> y;

			statement = new IfStatement(var, comp, x, y);
		}

		if(type == "GOSUB")
		{
			ss >> val;

			statement = new GosubStatement(val);
		}

		
		if(type == "RETURN")
		{
			statement = new ReturnStatement();
		}

		program.push_back(statement);
		counter++;
/*
		program.push_back(statement);
		ss.clear();
		ss.str("");
		aa.clear();
		aa.str("");
		delete statement;

	// }
*/

}