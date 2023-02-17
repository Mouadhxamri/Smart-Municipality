#include "arduno_temp.h"

#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
arduno_temp::arduno_temp()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}
QString arduno_temp::getarduino_port_name()
{
    return arduino_port_name;
}
QSerialPort *arduno_temp::getserial()
{
    return serial;
}
int arduno_temp::connect_arduino()
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()
                    == arduino_uno_product_id)
            {
              arduino_is_available=true;
              arduino_port_name=serial_port_info.portName();
            }
        }
    }
    qDebug() << "arduino_port_name is :" << arduino_port_name;
    if(arduino_is_available){
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return  1;
    }
    return -1;
}
int arduno_temp::close_arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}
int arduno_temp::write_to_arduino(QByteArray d)
{
    if(serial->isWritable())
    {
        serial->write(d);
    }
    else
        qDebug()<<"error en ecriture";
}
QByteArray arduno_temp::read_from_arduino()
{
    if(serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }
}

