#ifndef NEWSTUDENT_H
#define NEWSTUDENT_H

#include <QDialog>
#include <QAbstractButton>
#include <QLineEdit>
#include <QStringList>

namespace Ui {
class NewStudent;
}

class NewStudent : public QDialog
{
	Q_OBJECT

public:
	explicit NewStudent(QWidget *parent = 0);
	~NewStudent();

	void initData();
	bool saveData();
	bool inputControl();
	QStringList storeInBuffer();

private slots:

	void on_save_btn_clicked();
	void on_reset_btn_clicked();
	void on_cancel_btn_clicked();
	void on_guestFrom_led_textEdited(const QString &arg1);
	void on_guestTo_led_textEdited(const QString &arg1);
	void on_lessonNum_spinBox_valueChanged(const int &arg1);
	void on_condition_combo_currentIndexChanged(const int &index);

private:
	Ui::NewStudent *ui;

	QLineEdit **led;
	const unsigned int ledCount;
	unsigned int lessonCount;
};

#endif // NEWSTUDENT_H
