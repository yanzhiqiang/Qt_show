#include <QApplication>
#include <QPushButton>
#include "standarddialogs.h"

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
    	StandardDialogs m_standdialog;
	m_standdialog.show();
	return app.exec();
}
