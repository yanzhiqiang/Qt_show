#include "standarddialogs.h"
#include <QDialog>

//StandardDialogs::StandardDialogs(QWidgt* parent,Qt::WindowFlags f) : QDialog(parent,f)
StandardDialogs::StandardDialogs(QWidget* parent,Qt::WindowFlags f)
{
	QDialog(parent,f);
	setWindowTitle(tr("Standard Dialogs"));
	
	layout =  new QGridLayout(this);
	
	filePushButton = new QPushButton();
	filePushButton->setText(tr("File Dialog"));
	
	colorPushButton = new QPushButton();
	colorPushButton->setText(tr("color Dialog"));
	
	fontPushButton = new QPushButton();
	fontPushButton->setText(tr("Font Dialog"));
	
	fileLineEdit = new QLineEdit;
	
	colorFrame = new QFrame;
	colorFrame->setFrameShape(QFrame::Box);
	colorFrame->setAutoFillBackground(true);
	
	fontLineEdit = new QLineEdit;
	fontLineEdit->setText(tr("hello world"));
	
	layout->addWidget(filePushButton,0,0);
	layout->addWidget(fileLineEdit,0,1);
	layout->addWidget(colorPushButton,1,1);
	layout->addWidget(colorFrame,1,2);
	layout->addWidget(fontPushButton,2,0);
	layout->addWidget(fontLineEdit,2,1);
	layout->setMargin(15);
	layout->setSpacing(10);

	connect(filePushButton,SIGNAL(clicked()),this,SLOT(slotOpenFileDlg()));
	connect(colorPushButton,SIGNAL(clicked()),this,SLOT(slotOpenColorDlg()));
	connect(fontPushButton,SIGNAL(clicked()),this,SLOT(slotOpenFontDlg()));
}

void StandardDialogs::slotOpenFileDlg()
{
	QString s = QFileDialog::getOpenFileName(
				this,
				"open file dialog",
				"/",
				"All files(*.*)");
	fileLineEdit->setText(s.toAscii());
}

void StandardDialogs::slotOpenColorDlg()
{
	QColor color = QColorDialog::getColor(Qt::blue);
	if(color.isValid())
	{
		//colorFrame->setpalette(QPalette(color));
	}
}

void StandardDialogs::slotOpenFontDlg()
{
	bool ok;
	QFont font = QFontDialog::getFont(&ok);
	if(ok)
	{
		fontLineEdit->setFont(font);
	}
}

StandardDialogs::~StandardDialogs()
{
	if(filePushButton)
	{
		delete filePushButton;
		filePushButton = NULL;
	}
	
	if(colorPushButton)
	{
		delete colorPushButton;
		colorPushButton = NULL;
	}	

	if(fontPushButton)
	{
		delete fontPushButton;
		fontPushButton = NULL;
	}
	
	if(fileLineEdit)
	{
		delete fileLineEdit;
		fileLineEdit = NULL;
	}
	
	if(fontLineEdit)
	{
		delete fontLineEdit;
		fontLineEdit = NULL;
	}
	
	if(colorFrame)
	{
		delete colorFrame;
		colorFrame = NULL;
	}

	if(layout)
	{
		delete layout;
		layout = NULL;
	}
	return ;
}
