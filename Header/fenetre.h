#ifndef FENETRE_H
#define FENETRE_H
#include<citoyent.h>
#include<commerciale.h>
#include <QMediaPlayer>

#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>

#include <QWidget>

namespace Ui {
class fenetre;
}

class QSystemTrayIcon ;

class fenetre : public QWidget
{
    Q_OBJECT

public:
    explicit fenetre(QWidget *parent = nullptr);
    ~fenetre();
    QMediaPlayer* player= new QMediaPlayer;


private slots:


    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_chercherP_2_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_34_clicked();

    void on_afficher_commerciale_1_activated(const QModelIndex &index);

    void on_radioButton_11_clicked();

    void on_radioButton_13_clicked();


    void on_pushButton_22_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_tab_citoyent_activated(const QModelIndex &index);


    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_37_clicked();

private:
    Ui::fenetre *ui;
    citoyent temcitoyent;
    commerciale tempcommerciale;

    QSystemTrayIcon *mysystem;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QParallelAnimationGroup *animationGroup;
};

#endif // FENETRE_H
