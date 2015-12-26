#ifndef STUDENTINFORMATION_H
#define STUDENTINFORMATION_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class StudentInformation;
}

class StudentInformation : public QDialog
{
	Q_OBJECT

public:
	explicit StudentInformation(QWidget *parent = 0);
	~StudentInformation();

	void initData();
	void reloadData();
	QString readAllData();

private:
	Ui::StudentInformation *ui;

	QFile *file;
	QTextStream *in;
	int stuCounter;

};

#endif // STUDENTINFORMATION_H
