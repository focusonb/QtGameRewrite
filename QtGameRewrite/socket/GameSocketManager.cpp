#include "GameSocketManager.h"
#include "../myfunction.h"
#include "../data_base/DataWuziqi.h"

#include <QtCore>

using std::string;

GameSocketManager::GameSocketManager(DataWuziqiSpecType* dataWuziqiSpecType):
	m_dataWuziqiSpecType(dataWuziqiSpecType)
{
}


void GameSocketManager::reactToMessage(std::string msg)
{
	QPointF point_chess;
	split_a(msg, point_chess);

	//m_dataWuziqiSpecType->insert(point_chess, m_BRequestConnection);
	bool anotherSideColor = !m_BRequestConnection;
	emit recievedData(point_chess, anotherSideColor);
}

void GameSocketManager::sendStrData(std::string msgStr)
{
	memset(msg, 0, sizeof(msg));
	msgStr.copy(msg, msgStr.size(), 0);
	sendData();
	memset(msg, 0, sizeof(msg));
}