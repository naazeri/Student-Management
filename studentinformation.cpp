#include "studentinformation.h"
#include "ui_studentinformation.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>

StudentInformation::StudentInformation(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::StudentInformation)
{
	ui->setupUi(this);

	initData();
	reloadData();

}

void StudentInformation::initData()
{
	file = new QFile("/home/reza/Documents/Data.txt", this);
	in = new QTextStream(file);

	in->setCodec("UTF-8");
}

StudentInformation::~StudentInformation()
{
	delete ui;
}

void StudentInformation::reloadData()
{
	if( file->open(QFile::ReadOnly | QFile::Text)) {

		QTableWidget *table = ui->tableWidget;
		unsigned int row = 1, col = 1;

		while(!in->atEnd()) {

			QString data = in->readLine();

			if (data == "#") {

				row++;
				col = 1;
				continue;
			}

			if (table->rowCount() != row) {

				table->setRowCount(row);
			}

			if (table->columnCount() < col) {

				table->setColumnCount(col);
			}

			QTableWidgetItem *cell = new QTableWidgetItem(data);
			table->setItem(row-1, col-1, cell);
			col++;

			if (col == 13 && data != "مهمان") {

				col++;
			}
		}
	}

	else {

		QMessageBox *message = new QMessageBox(this);

		message->setWindowTitle("ERROR");
		message->setText("متاسفانه فایل باز نشد");
		message->setIcon(QMessageBox::Critical);
		message->exec();

	}
}

QString StudentInformation::readAllData()
{
	QString data = in->readAll();

	stuCounter = data.split("\n").size() - 1;	//find student count
	data.remove("\n");

	return data;
}
