#pragma once
#include <qmainwindow.h>
#include "ui_game_graphics_view.h"
#include <QtCore>
#include <QtGui>
#include <map>
//#include "SocketManager.h"
class SocketManager;
class GameSocketManager;
class std::thread;
using namespace std;
class GameWidget :
	public QMainWindow
{
	Q_OBJECT
		
public:
	GameWidget(GameSocketManager* gameSocketManager, QMainWindow* parent = nullptr);
	~GameWidget();
signals:
	void gameover();
	void  getaplayer();
public slots:
	virtual void show_window();
	virtual void matchplayer();
protected:
	void mousePressEvent(QMouseEvent*e)override;
	virtual void handleMousePress(QMouseEvent* e) {}

	Ui::MainWindow ui;
	QGraphicsScene* scene;
	GameSocketManager* m_gameSocketManager;
	std::thread* m_thread;
};


