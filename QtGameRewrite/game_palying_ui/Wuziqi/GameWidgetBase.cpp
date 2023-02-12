#include "../socket/GameSocketManager.h"
#include "GameWidgetBase.h"
#include <QObject>
#include <QGraphicsEllipseItem>
#include <iostream>
#include <qmessagebox.h>
#include <thread>

#include "../../drawer/Drawer.h"
//#include "../../myFunction.h"

GameWidgetBase::GameWidgetBase(GameSocketManager* gameSocketManager, DataWuziqiSpecType* dataWuziqiSpecType) :
	GameWidget(gameSocketManager),
	m_dataWuziqi(dataWuziqiSpecType),
	message_game_end{ QMessageBox::Warning, "Information", "Game End", QMessageBox::Yes, this }
{
	//QObject::connect(gameSocketManager, &GameSocketManager::recievedData, this, &GameWidgetBase::setBRecieved);
	QObject::connect(gameSocketManager, SIGNAL(recievedData(QPointF, bool)), this, SLOT(setBRecieved()));
	QObject::connect(gameSocketManager, SIGNAL(recievedData(QPointF, bool)), this, SLOT(drawOneChess(QPointF, bool)));
}

void GameWidgetBase::drawOneChess(QPointF point_chess, bool myCharacter)
{
	m_dataWuziqi->insert(point_chess, myCharacter);
	map<QPointF, int, cmp>* ptr_m_chesses = m_dataWuziqi->get();
	Drawer drawer;
	drawer.drawOneChess(myCharacter, point_chess, scene, m_width_chess, ptr_m_chesses, gamegoingon);

	emit ruleStart(point_chess, ptr_m_chesses, m_width_chess, m_myCharacter);
}

void GameWidgetBase::mousePressEvent(QMouseEvent* e)
{
	handleMousePress(e);
}
void GameWidgetBase::handleMousePress(QMouseEvent* e)
{
	std::cout << "mouse press" << std::endl;

	QPoint mousePos = e->pos();
	QPoint pointcentre = ui.centralwidget->mapFromParent(mousePos);
	QPoint pointwidget = ui.widget->mapFromParent(pointcentre);
	QPoint pointview = ui.graphicsView->mapFromParent(pointwidget);
	achess = ui.graphicsView->mapToScene(pointview);
	std::string message_toopponent(std::to_string(achess.rx()) + 'a' + std::to_string(achess.ry()));

	if (m_bRecieved == false) {
		return;
	}
	
	drawOneChess(achess, m_gameSocketManager->getBRequestConnection());
	m_bRecieved = false;

	emit sendAChessData(message_toopponent);
}

QPointF GameWidgetBase::getLastMousePoint()
{
	return m_mousePoint;
}

void GameWidgetBase::show_window()
{
	qreal height_chess;
	this->show();
	this->activateWindow();
	Drawer drawer;
	drawer.drawChessBoard(ui.graphicsView, scene, m_width_chess, height_chess, m_dataWuziqi);
}

void GameWidgetBase::matchplayer()
{
	std::cout << "sfdsfs1111" << std::endl;
	if (m_gameSocketManager->getBEventMaked() == true) {
		return;
	}
	m_gameSocketManager->prepareForWaitLoop();
	m_thread = new std::thread(&GameSocketManager::looprecvsend, m_gameSocketManager);

	//there may be a problem, that is when function getBRequestConnection() execute, the task of setting value has
	// not been done.
	m_myCharacter = m_gameSocketManager->getBRequestConnection();
	if (m_myCharacter == true) {
		//show message box telling seccess of matching a existting player.
	}
	else {

	}
}

