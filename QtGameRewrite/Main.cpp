
#include "socket\GameSocketManager.h"
#include <QApplication>
#include "QtGame.h"
#include "GameWidget.h"
#include <qmessagebox.h>

#include "Wuziqi\WuziqiGameWidget.h"

#include "data_base\DataWuziqi.h"
//#include "rule/RuleWiorker.h"


int main(int argc, char* argv[])
{
	//qRegisterMetaType<MapPoint>("MapPoint");
	QApplication a(argc, argv);
	QtGame game_main_window;
	
	DataWuziqiSpecType dataWuziqiSpecType;
	GameSocketManager gameSocketManager(&dataWuziqiSpecType);

	WuziqiGameWidget game_sub_window(&gameSocketManager, &dataWuziqiSpecType);

	QMessageBox message_1(QMessageBox::Warning, "Information", "accept a new connection request", QMessageBox::Yes, &game_sub_window);
	QMessageBox message_2(QMessageBox::Warning, "Information", "join a new connection", QMessageBox::Yes, &game_sub_window);

	QObject::connect(&game_main_window, SIGNAL(open_sub_widget()), &game_sub_window, SLOT(show_window()));
	
	
	QObject::connect(&gameSocketManager, SIGNAL(acceptConnection()), &message_1, SLOT(exec()));
	QObject::connect(&gameSocketManager, SIGNAL(joinConnection()), &message_2, SLOT(exec()));




	game_main_window.show();
	return a.exec();
}