#pragma once
#include "socketManager.h"
#include <QObject>

class DataWuziqiSpecType;
class GameSocketManager :
    public SocketManager
{
    Q_OBJECT
signals:
    void recievedData(QPointF point_chess, bool BRequestConnection);

public slots:
    void sendStrData(std::string msgStr);

public:
    GameSocketManager(DataWuziqiSpecType* dataWuziqiSpecType);
    void setBRequestConnection(bool BRequestConnection) { m_BRequestConnection = BRequestConnection; }
    bool getBRequestConnection() const { return m_BRequestConnection; }
    void reactToMessage(std::string msg) override;
private:
    DataWuziqiSpecType* m_dataWuziqiSpecType;
protected:
    void setRequestConnectionState() override { m_BRequestConnection = true; }
    void setWaitForConnectionState() override { m_BRequestConnection = false; }
};

