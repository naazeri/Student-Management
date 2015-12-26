#ifndef PERSONINFO_H
#define PERSONINFO_H

#include <QString>

class PersonInfo
{

public:
	PersonInfo();
	~PersonInfo();

	void setName(QString name);
	void setFamily();
	void setFutherName();
	void setMelliCode();
	void setShsh();

	QString getName();
	QString getFamily();
	QString getFutherName();
	QString getMelliCode();
	QString getShsh();

private:
	QString name, family, futherName, melliCode, shsh;

};

#endif // PERSONINFO_H
