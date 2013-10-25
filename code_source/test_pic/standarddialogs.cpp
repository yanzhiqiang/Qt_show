#include "standarddialogs.h"
#include <QDialog>

#define _PIC_TIME	1
#define	_VIDEO_TIME	40

//StandardDialogs::StandardDialogs(QWidgt* parent,Qt::WindowFlags f) : QDialog(parent,f)
StandardDialogs::StandardDialogs(QWidget* parent,Qt::WindowFlags f)
{
	QDialog(parent,f);
	setWindowTitle(tr("Standard Dialogs"));

	this->resize( QSize( 800, 600 ));
	layout =  new QGridLayout(this);

	videoLabel = new QLabel("video");	

	timeLabel = new QLabel("time");	
	
	picLabel = new QLabel("pic");	

	startPushButton = new QPushButton();
	startPushButton->setText(tr("Start"));
	
	stopPushButton = new QPushButton();
	stopPushButton->setText(tr("Stop"));
	
	resetPushButton = new QPushButton();
	resetPushButton->setText(tr("Reset"));
	
	picTime = new QTimer();
	
	videoTime = new QTimer();
	
	layout->addWidget(videoLabel,0,0,2,0);
	layout->addWidget(timeLabel,0,1);
	layout->addWidget(picLabel,1,1);
	layout->addWidget(startPushButton,2,0);
	layout->addWidget(stopPushButton,2,1);
	layout->addWidget(resetPushButton,2,2);	

	layout->setMargin(15);
	layout->setSpacing(10);

	picTime->setInterval(_PIC_TIME);
	videoTime->setInterval(_VIDEO_TIME);
	
	picTime->start();
	videoTime->start();
	
	pic_counter=1;
	connect(picTime,SIGNAL(timeout()),this,SLOT(slotPicShow()));
	connect(videoTime,SIGNAL(timeout()),this,SLOT(slotVideoShow()));	

}

void StandardDialogs::slotPicShow()
{
	QString strTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
	timeLabel->setText(strTime);
	
	char file_name[20] = {0};
	sprintf(file_name,"./image/%d%s",pic_counter,".png");
	QImage* image = new QImage(file_name);
	picLabel->setPixmap(QPixmap::fromImage(*image));
	pic_counter++;
	if(pic_counter>=8)
		pic_counter=1; 
}


void StandardDialogs::slotVideoShow()
{
}


StandardDialogs::~StandardDialogs()
{
	/*if(filePushButton)
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
	}*/
	return ;
}
