#include "newstudent.h"
#include "ui_newstudent.h"
#include "datamanager.h"
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidget>
#include <QFile>

NewStudent::NewStudent(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::NewStudent),
	lessonCount(19), ledCount(13)
{
	ui->setupUi(this);

	initData();
}

void NewStudent::initData()
{
	led = new QLineEdit* [ledCount];

	led[0] = ui->name_led;
	led[1] = ui->family_led;
	led[2] = ui->fatherName_led;
	led[3] = ui->melliCode_led;
	led[4] = ui->shsh_led;
	led[5] = ui->id_led;
	led[6] = ui->uniName_led;
	led[7] = ui->degree_led;
	led[8] = ui->major_led;
	led[9] = ui->area_led;
	led[10]= ui->year_of_entry_led;
	led[11]= ui->guestFrom_led;
	led[12]= ui->guestTo_led;

	ui->guestFrom_led->setVisible(false);
	ui->guestTo_led->setVisible(false);
	ui->lesson_table->setVisible(false);
}

NewStudent::~NewStudent()
{
	delete ui;
}

bool NewStudent::saveData()
{
	QFile file("/home/reza/Documents/Data.txt", this);

	if( file.open(QFile::Append | QFile::Text)) {

		QTextStream out(&file);
		out.setCodec("UTF-8");
		QStringList list = storeInBuffer();

		foreach (QString s, list) {

			out << s << "\n";

		}

		out << "#\n";
		out.flush();

		return true;
	}

	else {

		return false;

	}
}

bool NewStudent::inputControl()
{

	for (int i = 0; i < ledCount; ++i) {

		if (i < ledCount - 2 && led[i]->text() == "") {

			return false;

		}

		if (i >= ledCount - 2 && ui->condition_combo->currentIndex() == ui->condition_combo->count() - 1) { //Guest condition selected

			if ( ui->guestFrom_led->text() == "" && ui->guestTo_led->text() == "") {

				return false;

			}
		}
	}

	if (ui->condition_combo->currentIndex() == 0 || ui->halfYear_combo->currentIndex() == 0 ) {

		return false;
	}

	if (ui->unitNum_spinBox->value() == 0 && ui->lessonNum_spinBox->value() != 0) {

		return false;
	}

	if (ui->unitNum_spinBox->value() != 0 && ui->lessonNum_spinBox->value() == 0) {

		return false;
	}

	for (int i = 0; i < ui->lessonNum_spinBox->value(); ++i) {

		for (int j = 0; j < 3; ++j) {

			if (ui->lesson_table->item(i, j)->text() == "") {

				return false;

			}
		}
	}

	return true;

}

QStringList NewStudent::storeInBuffer()
{
	QStringList list;
	list.push_back(ui->name_led->text());
	list.push_back(ui->family_led->text());
	list.push_back(ui->fatherName_led->text());
	list.push_back(ui->melliCode_led->text());
	list.push_back(ui->shsh_led->text());
	list.push_back(ui->id_led->text());
	list.push_back(ui->uniName_led->text());
	list.push_back(ui->degree_led->text());
	list.push_back(ui->major_led->text());
	list.push_back(ui->area_led->text());
	list.push_back(ui->year_of_entry_led->text());
	list.push_back(ui->condition_combo->currentText());
	if (list.last() == "مهمان") {

		if (ui->guestFrom_led->isEnabled()) {

			list.push_back(ui->guestFrom_led->text());

		} else if (ui->guestTo_led->isEnabled()) {

			list.push_back(ui->guestTo_led->text());
		}
	}

	list.push_back(ui->halfYear_combo->currentText());
	list.push_back(QString::number(ui->yearNum_spinBox->value()));
	list.push_back(QString::number(ui->termNum_spinBox->value()));
	list.push_back(QString::number(ui->unitNum_spinBox->value()));

	const int lessonNum = ui->lessonNum_spinBox->value();
	list.push_back(QString::number(lessonNum));

	for (int i = 0; i < lessonNum; ++i) {

		for (int j = 0; j < 3; ++j) {

			list.push_back(ui->lesson_table->item(i, j)->text());

		}
	}

	return list;
}

void NewStudent::on_save_btn_clicked()
{
	if (inputControl()) {	//Check data validation

		if (saveData()) {

			this->accept();	//Saved successfully

		}

		else {	//Saved unsuccessfully

			QMessageBox *message = new QMessageBox(this);
			message->setWindowTitle("ERROR");
			message->setText("متاسفانه اطلاعات شما ذخیره نشد");
			message->setIcon(QMessageBox::Critical);
			message->exec();

			this->reject();

		}
	}

	else {

		QMessageBox *message = new QMessageBox(this);
		message->setWindowTitle("Warning");
		message->setText("لطفا ورودی های خود را کنترل کنید");
		message->setIcon(QMessageBox::Warning);
		message->exec();
		delete message;
	}

}

void NewStudent::on_reset_btn_clicked()
{
	for (int i = 0; i < ledCount; ++i) {

		led[i]->clear();

	}

	ui->condition_combo->setCurrentIndex(0);
	ui->halfYear_combo->setCurrentIndex(0);
	ui->yearNum_spinBox->setValue(94);
	ui->termNum_spinBox->setValue(1);
	ui->unitNum_spinBox->setValue(0);
	ui->lessonNum_spinBox->setValue(0);
}

void NewStudent::on_cancel_btn_clicked()
{
	this->reject();
}

void NewStudent::on_lessonNum_spinBox_valueChanged(const int &arg1)
{
	QTableWidget *table = ui->lesson_table;

	if (arg1 == 0) {

		table->setVisible(false);

	} else {

		table->setVisible(true);
		table->setRowCount(arg1);

	}
}

void NewStudent::on_condition_combo_currentIndexChanged(const int &index)
{
	const short lastIndex =  ui->condition_combo->count() - 1;

	if (index == lastIndex) {

		ui->guestFrom_led->setVisible(true);
		ui->guestTo_led->setVisible(true);

	} else {

		ui->guestFrom_led->setVisible(false);
		ui->guestTo_led->setVisible(false);

	}
}

void NewStudent::on_guestFrom_led_textEdited(const QString &arg1)
{
	if (arg1 != "") {

		ui->guestTo_led->setEnabled(false);

	} else {

		ui->guestTo_led->setEnabled(true);

	}
}

void NewStudent::on_guestTo_led_textEdited(const QString &arg1)
{
	if (arg1 != "") {

		ui->guestFrom_led->setEnabled(false);

	} else {

		ui->guestFrom_led->setEnabled(true);

	}
}
