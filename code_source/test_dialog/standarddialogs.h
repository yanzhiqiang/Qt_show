#ifndef __STANDARDDIALOGS_H
#define __STANDARDDiALOGS_H

#include <QtCore>
#include <QtGui>

QT_BEGIN_NAMESPACE


class StandardDialogs:public QDialog
{
	Q_OBJECT
public:
	StandardDialogs(QWidget *parent=0,Qt::WindowFlags f=0);
	~StandardDialogs();
public:
	QGridLayout *layout;
	QPushButton *filePushButton;
	QPushButton *colorPushButton;
	QPushButton *fontPushButton;
	QLineEdit   *fileLineEdit;
	QLineEdit   *fontLineEdit;
	QFrame 	    *colorFrame;
private slots:
	void slotOpenFileDlg();
	void slotOpenColorDlg();
	void slotOpenFontDlg();
};

QT_END_NAMESPACE

#endif

