#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGame.h"
#include "GameWidget.h"



class QtGame : public QMainWindow
{
	Q_OBJECT

public:
	QtGame(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGameClass ui;
signals:
	void open_sub_widget();
	void close_sub_widget();
public slots:
	void do_it_pressed();
	void closegame();

};
