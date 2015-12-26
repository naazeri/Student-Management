#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "personinfo.h"
#include "studentinfo.h"
#include "terminfo.h"

class DataManager : public PersonInfo, public StudentInfo, public TermInfo

{
public:
	DataManager();
	~DataManager();

};

#endif // DATAMANAGER_H
