#include "InspectWidget.h"
#include <QVBoxLayout>
#include <iostream>

InspectWidget::InspectWidget()
{
	inspector = new QWidget();
	inspector->setWindowTitle("Inspector");
	oLayout = new QHBoxLayout();

	valuesList = new QListWidget();

	oLayout->addWidget(valuesList);
	vScrollArea = new QScrollArea();
	// scrollArea->setBackgroundRole(QPalette::Dark);
	vScrollArea->setWidget(valuesList);

	

	groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));

    radio1 = new QRadioButton(tr("&Alphabetical"));
    radio2 = new QRadioButton(tr("R&everse Alphabetical"));
    radio3 = new QRadioButton(tr("&Number Forward"));
    radio4 = new QRadioButton(tr("N&umber Backward"));
	radio1->setChecked(true);

	QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addStretch(1);
    oLayout->addLayout(vbox);

    update = new QPushButton("Update");
    close = new QPushButton("Close");

    oLayout->addWidget(update);
    oLayout->addWidget(close);


    inspector->setLayout(oLayout);

    connect(close, SIGNAL(clicked()), this, SLOT(hideWindow()) );
    connect(update, SIGNAL(clicked()), this, SLOT(updateValues()) );

}

InspectWidget::~InspectWidget()
{

}

void InspectWidget::showValueWindow()
{
	inspector->show();
}

void InspectWidget::hideWindow()
{
	inspector->hide();
}

void InspectWidget::passState(ProgramState* state)
{
	states = state;
}

void InspectWidget::updateValues()
{
	states->valueReader(valueVector);

	//std::cout << valueVector[0].first << std::endl;
}






