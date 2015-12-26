#ifndef ROOT_H
#define ROOT_H

#include <QMainWindow>

namespace Ui {
class Root;
}

class Root : public QMainWindow
{
	Q_OBJECT

public:
	explicit Root(QWidget *parent = 0);
	~Root();

private slots:

	void on_exit_btn_clicked();
	void on_newStudent_btn_clicked();
	void on_list_of_Student_btn_clicked();

private:
	Ui::Root *ui;

};

#endif // ROOT_H
