#include "GameSocketManager.h"
#include "../myfunction.h"
#include "../data_base/DataWuziqi.h"

#include <QtCore>

using std::string;

GameSocketManager::GameSocketManager(DataWuziqiSpecType* dataWuziqiSpecType):
	m_dataWuziqiSpecType(dataWuziqiSpecType)
{
}


void GameSocketManager::reactToMessage(const char* msg)
{
	string recstr(msg);
	QPointF point_chess;
	split_a(recstr, point_chess);

	//m_dataWuziqiSpecType->insert(point_chess, m_BRequestConnection);
	emit recievedData(point_chess, m_BRequestConnection);
}
