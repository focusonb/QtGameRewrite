#include "QtGame.h"

QtGame::QtGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
void QtGame::closegame()
{
	close();
	emit close_sub_widget();
	//this->game_widget->close();
}
void QtGame::do_it_pressed()
{
	//game_widget->show();
	//game_widget->activateWindow();
	//game_widget->raise();
	emit open_sub_widget();
}