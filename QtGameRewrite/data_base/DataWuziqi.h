#pragma once
#include <QtCore>
#include <map>

//#include "../drawer/Drawer.h"
#include "../comStruct.h"

class OneChessData
{
public:

};

//extern struct cmp;

class DataWuziqi
{
public:
	using widthNum = int;
	using heightNum = int;
	using pointSeq = QPointF;
	using chessState = int;
	using chessesData = std::map<QPointF, int, cmp>;
public:
	virtual void insert(pointSeq seq, chessState oneChessState) = 0;
	virtual chessesData* get() = 0;
};

class DataWuziqiSpecType : public DataWuziqi
{
public:
	using pointSeq = DataWuziqi::pointSeq;
	using chessState = DataWuziqi::chessState;
	using chessesData = DataWuziqi::chessesData;
private:
	chessesData chessDataBase;
public:
	virtual void insert(QPointF qPointF, chessState oneChessState) override;
	chessesData* get() override;
};