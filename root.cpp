#include "root.h"
#include "ui_root.h"
#include "newstudent.h"
#include "studentinformation.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

Root::Root(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Root)
{
	ui->setupUi(this);
}

Root::~Root()
{
        delete ui;
}

void Root::on_exit_btn_clicked()
{
	Root::close();
}

void Root::on_newStudent_btn_clicked()
{
	NewStudent *newStudent = new NewStudent;
	const int resualt = newStudent->exec();

	if (resualt == QDialog::Accepted) {

		QMessageBox *message = new QMessageBox(this);
		message->setWindowTitle("ذخیره اطلاعات");
		message->setText("اطلاعات با موفقیت ذخیره شد");
		message->setIcon(QMessageBox::Information);
		message->exec();

	}

	else if (resualt == QDialog::Rejected) {
	}
}

void Root::on_list_of_Student_btn_clicked()
{
	QFile *file = new QFile("/home/reza/Documents/Data.txt", this);

	if (file->exists()) {

		StudentInformation *stuList = new StudentInformation(this);
		stuList->show();

	}

	else {

		QMessageBox *message = new QMessageBox(this);

		message->setWindowTitle("ERROR");
		message->setText("متاسفانه فایل پیدا نشد");
		message->setIcon(QMessageBox::Critical);
		message->exec();

	}
}
