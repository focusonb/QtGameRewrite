#include "../socket/GameSocketManager.h"
#include "GameWidget.h"
#include <qmessagebox.h>
#include <iostream>
#include <thread>


GameWidget::GameWidget(GameSocketManager* gameSocketManager, QMainWindow* parent) : m_gameSocketManager(gameSocketManager)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	/*QRectF rect = ui.graphicsView->rect();
	scene->setSceneRect(rect);*/
	ui.graphicsView->setScene(scene);
}

void GameWidget::matchplayer()
{
	std::cout << "sfdsfs" << std::endl;
	m_thread = new std::thread(&GameSocketManager::runRecieveLoop, m_gameSocketManager);

}

void GameWidget::mousePressEvent(QMouseEvent*e)
{
	handleMousePress(e);
}

void GameWidget::show_window() {
	this->show();
	this->activateWindow();
}

GameWidget::~GameWidget()
{
}
