#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QString>

class StudentInfo
{

public:
	StudentInfo();
	~StudentInfo();

	void setID(QString id);
	void setUniName(QString uniName);
	void setDegree();
	void setMajor();
	void setArea();
	void setYear_of_entry();

	QString getID();
	QString getUniName();
	QString getDegree();
	QString getMajor();
	QString getArea();
	QString getYear_of_entry();

private:
	QString id, uniName, degree, major, area, year_of_entry;

};

#endif // STUDENTINFO_H
