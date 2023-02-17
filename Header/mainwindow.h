#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <commerciale.h>
#include <citoyent.h>
#include "contrat.h"
#include "fourriere.h"
#include"vehicule.h"
#include"amende.h"
#include "certifdeces.h"
#include "permisconstr.h"
#include "employe.h"
#include "departement.h"

#include "server.h"
#include "client.h"

#include "temp.h"
#include "lumiere.h"

#include <QMediaPlayer>
#include <QSound>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon ;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int  getselectedEmploye();
    int getselectedDepartement();

private slots:
    void on_pushButton_commerciale_clicked();

    void on_pushButton_citoyen_clicked();

    void on_pushButton_clicked();

    void on_pushButton_certifdeces_clicked();

    void on_pushButton_permisconstr_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_lesamendes_clicked();

    void on_pushButton_lesvehicules_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_backdeces_clicked();

    void on_pushButton_backpermis_clicked();

    void on_pushButton_backcitoyen0_clicked();

    void on_pushButton_bkaf_clicked();

    void on_pushButton_bkaf2_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_ajouterciyoyenacceuil_clicked();

    void on_pushButton_affichercitoyenacceuil_clicked();

    void on_pushButton_backcitoyen1_clicked();

    void on_pushButton_backaffichagecitoyen_clicked();

    void on_pushButton_ajoutercitoyen_clicked();

    void on_pushButton_supprimercitoyen_clicked();

    void on_pushButton_chercherP_2_clicked();

    void on_pushButton_ajoutercommerciale_clicked();

    void on_pushButton_supprimercommerciale_clicked();

    void on_pushButton_modifiercommerciale_clicked();

    void on_imprimercommerciale_clicked();

    void on_pushButton_imprimercitoyen_clicked();

    void on_pushButton_pdfcitoyen_clicked();

    void on_pdfcommerciale_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_13_clicked();

    void on_pushButton_recherchecitoyen_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_tab_citoyent_activated(const QModelIndex &index);

    void on_afficher_commerciale_1_activated(const QModelIndex &index);

    void on_pushButton_recherchecomm_clicked();

    void on_pushButton_chercherP_6_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_chercherP_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_supp_clicked();

    void on_pushButton_modi_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_impr_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_chercherP_7_clicked();

    void on_pushButton_supp_2_clicked();

    void on_pushButton_chercherP_4_clicked();

    void on_pushButton_rech_2_clicked();

    void on_radioButton_mat_2_clicked();

    void on_radioButton_date_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_suppr_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_reche_clicked();



    void on_pushButton_imp_clicked();

    void on_radioButton_dat_clicked();

    void on_radioButton_nom_clicked();

    void on_pushButton_ajouterdeces_clicked();

    void on_pushButton_supprimerdeces_clicked();

    void on_pushButton_modifierdeces_clicked();

    void on_pushButton_imprimerdeces_clicked();

    void on_pushButton_rechdeces_clicked();

    void on_pushButton_pdfdeces_clicked();

    void on_pushButton_TriAZdeces_clicked();

    void on_pushButton_TriZAdeces_clicked();

    void on_tableView_deces_activated(const QModelIndex &index);

    void on_pushButton_ajouterpermis_clicked();

    void on_pushButton_supprimerpermis_clicked();

    void on_pushButton_modifierpermis_clicked();

    void on_pushButton_recherchepermis_clicked();

    void on_pushButton_lieuazpermis_clicked();

    void on_pushButton_lieuzapermis_clicked();

    void on_pushButton_tripostalecroipermis_clicked();

    void on_pushButton_tripostaledecpermis_clicked();

    void on_pushButton_pdfpermis_clicked();

    void on_pushButton_imprimerpermis_clicked();

    void on_pushButton_imagepermis_clicked();

    void on_tableView_permis_activated(const QModelIndex &index);

    void on_pushButton_ajouteremploye_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_35_clicked();

private:
    Ui::MainWindow *ui;
    citoyent temcitoyent;
    commerciale tempcommerciale;
    contrat tempcontrat;
    fourriere tempfourriere;
    vehicule tempVehicule;
    amende temAmende;
    Certifdeces tempcert;
    permisconstr temppermis;
    employe z;
    departement d;



    Server *serverdialog;
    Client *clientdialog;

    temp *tempe;
    lumiere *mouv;

   QSystemTrayIcon *mysystem;
   QSound *son;
   QMediaPlayer *click;
   QPropertyAnimation *animation;
   QPropertyAnimation *animation1;
   QPropertyAnimation *animation2;
   QParallelAnimationGroup *animationGroup;
};
#endif // MAINWINDOW_H
