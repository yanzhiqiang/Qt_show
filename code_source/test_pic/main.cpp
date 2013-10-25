#include <QApplication>
#include <QPushButton>
#include "standarddialogs.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	//Q_INIT_RESOURCE(test_pic);	
	QApplication app(argc,argv);
    	StandardDialogs m_standdialog;
	
	
	if(argc == 2 && strcmp(argv[1],"-full-screen")==0)
	{
		m_standdialog.showFullScreen();
	}
	else
	{
		m_standdialog.show();
	}	
	return app.exec();
}
