#include "../socket/GameSocketManager.h"
#include "WuziqiGameWidget.h"
#include <QGraphicsEllipseItem>
#include <iostream>
#include <qmessagebox.h>
#include <thread>

#include "../../drawer/Drawer.h"
#include "../../myFunction.h"

WuziqiGameWidget::WuziqiGameWidget(GameSocketManager* gameSocketManager, DataWuziqiSpecType* dataWuziqiSpecType) :
	GameWidget(gameSocketManager), 
	m_dataWuziqi(dataWuziqiSpecType), 
	message_game_end {QMessageBox::Warning, "Information", "Game End", QMessageBox::Yes, this}
{
	QObject::connect(&m_controllerRuleWorker, SIGNAL(workFinished()), &message_game_end, SLOT(exec()));
	QObject::connect(this, &WuziqiGameWidget::ruleStart, &m_controllerRuleWorker, &ControllerRuleWorker::emitOperate);
}

void WuziqiGameWidget::drawOneChess(QPointF point_chess, bool BRequestConnection)
{
	m_dataWuziqi->insert(point_chess, BRequestConnection);
	map<QPointF, int, cmp>* ptr_m_chesses = m_dataWuziqi->get();
	Drawer drawer;
	drawer.drawOneChess(BRequestConnection, point_chess, scene, m_width_chess, ptr_m_chesses, gamegoingon);

	//emit m_controllerRuleWorker.operate(point_chess, ptr_m_chesses, m_width_chess, m_myCharacter);
	emit ruleStart(point_chess, ptr_m_chesses, m_width_chess, m_myCharacter);
}

void WuziqiGameWidget::mousePressEvent(QMouseEvent* e)
{
	handleMousePress(e);
}
void WuziqiGameWidget::handleMousePress(QMouseEvent* e)
{
	std::cout << "mouse press" << std::endl;

	//if (is_matched == false)
	//{
	//	QMessageBox message(QMessageBox::Warning, "Information", "Waiting for your opponent", QMessageBox::Yes, NULL);
	//	message.exec();
	//	return;
	//}
	//if (myturn != mypart)
	//{
	//	QMessageBox message(QMessageBox::Warning, "Information", "Its not your turn", QMessageBox::Yes, NULL);
	//	message.exec();
	//	return;
	//}
	QPoint mousePos = e->pos();
	QPoint pointcentre = ui.centralwidget->mapFromParent(mousePos);
	QPoint pointwidget = ui.widget->mapFromParent(pointcentre);
	QPoint pointview = ui.graphicsView->mapFromParent(pointwidget);
	achess = ui.graphicsView->mapToScene(pointview);

	std::string message_toopponent(std::to_string(achess.rx()) + 'a' + std::to_string(achess.ry()));
	//socketThread->sendachesss(message_toopponent, socketThread->getsocket());

	//map<QPointF, int, cmp> temp_chesses = m_dataWuziqi.get();
	//map<QPointF, int, cmp>* ptr_m_chesses = &temp_chesses;
	m_dataWuziqi->insert(achess, m_myCharacter);
	map<QPointF, int, cmp>* ptr_m_chesses = m_dataWuziqi->get();

	if (m_bRecieved == false) {
		return;
	}

	drawOneChess(achess, m_gameSocketManager->getBRequestConnection());

	//Drawer drawer;
	//try {
	//	drawer.drawOneChess(m_myCharacter, achess, scene, m_width_chess, ptr_m_chesses, gamegoingon);
	//	m_bRecieved = false;
	//}
	//catch (std::out_of_range& e) {
	//	std::cout << "std::out_of_range" << std::endl;
	//	return;
	//}
	//catch (...) {
	//	std::cout << "std::exception" << std::endl;
	//	return;
	//}

	emit sendAChessData(message_toopponent);
}

QPointF WuziqiGameWidget::getLastMousePoint()
{
	return m_mousePoint;
}

void WuziqiGameWidget::show_window()
{
	//chesses = new map<QPointF, int, cmp>();
	qreal height_chess;
	this->show();
	this->activateWindow();
	Drawer drawer;
	drawer.drawChessBoard(ui.graphicsView, scene, m_width_chess, height_chess, m_dataWuziqi);
}

void WuziqiGameWidget::matchplayer()
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