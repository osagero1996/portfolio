#ifndef INSPECT_WIDGET_INCLUDED
#define INSPECT_WIDGET_INCLUDED

#include <QWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QListWidget>
#include <vector>
#include <string>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include "lib/ProgramState.h"


class InspectWidget: public QWidget{
	Q_OBJECT

public: 
	InspectWidget();
	~InspectWidget();
	void showValueWindow();
	
	void passState(ProgramState* state);

private slots:
	void hideWindow();
	void updateValues();

private: 
	QWidget* inspector;
	QListWidget* valuesList;
	QHBoxLayout* oLayout;
	QScrollArea* vScrollArea;

	std::vector<std::pair<std::string, int> > valueVector;

	QGroupBox *groupBox;
    QRadioButton *radio1; 
    QRadioButton *radio2;
    QRadioButton *radio3; 
    QRadioButton *radio4;

    QPushButton* update;
    QPushButton* close;

    ProgramState* states;
};

#endif
