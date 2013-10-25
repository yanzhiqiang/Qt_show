#include "standarddialogs.h"
#include <QDialog>

#define _PIC_TIME	40
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

	connect(startPushButton,SIGNAL(clicked()),this,SLOT(slotStart()));
	connect(stopPushButton,SIGNAL(clicked()),this,SLOT(slotStop()));
	connect(resetPushButton,SIGNAL(clicked()),this,SLOT(slotReset()));
	//QResource::registerResource("/root/project/qt_show/code_source/test_pic/image/test_pic.rcc");

}

void StandardDialogs::slotPicShow()
{
	QString strTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
	timeLabel->setText(strTime);
	
	char file_name[20] = {0};
	sprintf(file_name,":/image/%d%s",pic_counter,".png");
	//sprintf(file_name,"./image/%d%s",pic_counter,".png");
	QImage* image = new QImage(file_name);
	picLabel->setPixmap(QPixmap::fromImage(*image));
	pic_counter++;
	if(pic_counter>=8)
		pic_counter=1; 
}


void StandardDialogs::slotVideoShow()
{
	return ;
}

void StandardDialogs::slotStart()
{
	picTime->start();
	videoTime->start();
}

void StandardDialogs::slotStop()
{
	picTime->stop();
	videoTime->stop();
}

void StandardDialogs::slotReset()
{
	picTime->start();
	videoTime->start();
}


StandardDialogs::~StandardDialogs()
{
	
	return ;
}
