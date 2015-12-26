#ifndef TERMINFO_H
#define TERMINFO_H

#include <QString>

class TermInfo
{

public:
	TermInfo();
	~TermInfo();

	void setCondition();
	void setGuestFrom();
	void setGuestTo();
	void setHalfYear();
	void setYearNum();
	void setTermNum();
	void setUnitNum();
	void setLessonNum();
	void setLessonName();
	void setLessonScore();
	void setLessonUnit();

	QString getCondition();
	QString getGuestFrom();
	QString getGuestTo();
	QString getHalfYear();
	QString getYearNum();
	QString getTermNum();
	QString getUnitNum();
	QString getLessonNum();
	QString getLessonName();
	QString getLessonScore();
	QString getLessonUnit();

private:

	QString condition, guestFrom, guestTo, halfYear, yearNum, termNum,
	unitNum, lessonNum, lessonName, lessonScore, lessonUnit;

};

#endif // TERMINFO_H
