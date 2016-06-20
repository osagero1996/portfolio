#ifndef MAIN_WIDGET_INCLUDED
#define MAIN_WIDGET_INCLUDED


#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <string>
#include <QScrollArea>
#include <QListWidget>
#include <QGridLayout>
#include "ProgramState.h"
#include "Statement.h"
#include "../InspectWidget.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <QListWidgetItem>

class MainWidget: public QWidget{
	Q_OBJECT

public:
	MainWidget();
	~MainWidget();

	void readFile();



 private slots:
 	void openFile();
 	void helpRead();
 	void quitLoadFile();
 	void closeDebugger();
 	void openInspector();
 	void changeColor();
 	void stepButtonFunction();
 	void continueButtonFunction();


private:
// Components of the Debugger Window
	QWidget* debugger;
	QScrollArea *scrollArea;
	QListWidget* programList;
	QVBoxLayout *layout;
	QGridLayout* buttons;

	QPushButton* stepButton;
	QPushButton* nextButton;
	QPushButton* breakPointButton;
	QPushButton* continueButton;
	QPushButton* inspectButton;
	QPushButton* quitButton;

// Components of the Values Window
	InspectWidget* valWindow;





	std::string line;
// Components of the Load Window
	QWidget* loadBox;
	QLabel* header;
	QLineEdit* filename;
	QPushButton* load;
	QPushButton* quit;


	ProgramState* state;
	int counter;
	int nextCounter;
	// Statement * statement;	

	std::vector<std::string> programLines;
	std::vector<Statement *> program;
	std::vector<int> breakPointVector; 








};


#endif