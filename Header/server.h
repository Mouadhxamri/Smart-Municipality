#ifndef SERVER_H
#define SERVER_H
#include <QMainWindow>
#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTime>

namespace Ui { class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

protected:
    void initWindow();
    void initServer();
    void setConnFlag(bool);
    void setConnected();
    void showPeerInfo();
    void printCurTime();


protected slots:
    void slotSend();
    void slotNewConn();
    void slotRecv();
    void slotDisConn();
    void slotErr(QAbstractSocket::SocketError);

private:
    Ui::Server *ui;
    QTcpSocket *socket;
//    QTcpSocket *connectedSocket;
    QTcpServer *server;
    bool connFlag;  //show the connection status

};

#endif // SERVER_H
