#ifndef ARDUNO_TEMP_H
#define ARDUNO_TEMP_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class arduno_temp
{
public:
    arduno_temp();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();
private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_product_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // ARDUNO_TEMP_H

