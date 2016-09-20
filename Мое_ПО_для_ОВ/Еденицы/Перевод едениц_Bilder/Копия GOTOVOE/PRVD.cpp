//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <exception.h>
#include "PRVD.h"
#include "Perevod.h"
//---------------------------------------------------------------------------
void prvd(int N_ED,int *N_EDT,TEdit ***EDT_ARR,double **KOEF,int **PRISTAVKA)
{
TEdit * CurrEdt=(TEdit *)Frm_prvd->ActiveControl;

int curr_i,curr_j;
double base_curr_znach;
    if (CurrEdt->Text!="")
    {
        for(int i=0;i<N_ED;i++)
            for(int j=0;j<N_EDT[i];j++)
                if(CurrEdt==EDT_ARR[i][j])
                   {
                        curr_i=i;
                        curr_j=j;
                   }
        base_curr_znach=StrToFloat(CurrEdt->Text)*PRISTAVKA[curr_i][curr_j];

        for(int i=0;i<N_ED;i++)
            for(int j=0;j<N_EDT[i];j++)
                if (!(i==curr_i&&j==curr_j))
                    EDT_ARR[i][j]->Text=FloatToStr(base_curr_znach*KOEF[curr_i][i]/PRISTAVKA[i][j]);
    }else
    {   for(int i=0;i<N_ED;i++)
            for(int j=0;j<N_EDT[i];j++)
                if (!(i==curr_i&&j==curr_j))
                    EDT_ARR[i][j]->Text="";
    }
// Удаление массивов
    for (int i = 0; i < N_ED;  i++)
        delete[] EDT_ARR[i];
    delete[] EDT_ARR;
    for (int i = 0; i < N_ED;  i++)
        delete[] KOEF[i];
    delete[] KOEF;
    for (int i = 0; i < N_ED;  i++)
        delete[] PRISTAVKA[i];
    delete[] PRISTAVKA;
}
//---------------------------------------------------------------------------
void prvd_q()
{
int N_ED=2;         // кол-во едениц измерения
int N_EDT[]={4,4};  //кол-во Edit'ов в каждой еденице измерения
// Массив Edit'ов
TEdit ***EDT_ARR;
    EDT_ARR = new TEdit **[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            EDT_ARR[j] = new TEdit *[N_EDT[j]];
            // кол-во столбцов, Edit'ов в кажд.ед-це измерения
    EDT_ARR[0][0]=Frm_prvd->Edt_QGW;
    EDT_ARR[0][1]=Frm_prvd->Edt_QMW;
    EDT_ARR[0][2]=Frm_prvd->Edt_QkW;
    EDT_ARR[0][3]=Frm_prvd->Edt_QW;
        EDT_ARR[1][0]=Frm_prvd->Edt_QGkh;
        EDT_ARR[1][1]=Frm_prvd->Edt_QMkh;
        EDT_ARR[1][2]=Frm_prvd->Edt_Qkkh;
        EDT_ARR[1][3]=Frm_prvd->Edt_Qkh;
// Массив коэффициентов перевода из одних едениц в другие
double **KOEF;
    KOEF = new double*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            KOEF[j] = new double [N_ED];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    KOEF[0][0]=1;           KOEF[0][1]=860;
    KOEF[1][0]=1.163e-3;    KOEF[1][1]=1;
// Массив приставок
int **PRISTAVKA;
    PRISTAVKA = new int*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            PRISTAVKA[j] = new int [N_EDT[j]];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    PRISTAVKA[0][0]=GIGA;
    PRISTAVKA[0][1]=MEGA;
    PRISTAVKA[0][2]=KILO;
    PRISTAVKA[0][3]=1;
        PRISTAVKA[1][0]=GIGA;
        PRISTAVKA[1][1]=MEGA;
        PRISTAVKA[1][2]=KILO;
        PRISTAVKA[1][3]=1;
// Вызов функции перевода
    prvd(N_ED,N_EDT,EDT_ARR,KOEF,PRISTAVKA);
}
//---------------------------------------------------------------------------
void prvd_qq()
{
int N_ED=3;        // кол-во едениц измерения
int N_EDT[]={4,4,1}; //кол-во Edit'ов в каждой еденице измерения
// Массив Edit'ов
TEdit ***EDT_ARR;
    EDT_ARR = new TEdit **[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            EDT_ARR[j] = new TEdit *[N_EDT[j]];
            // кол-во столбцов, Edit'ов в кажд.ед-це измерения
    EDT_ARR[0][0]=Frm_prvd->Edt_QGJ;
    EDT_ARR[0][1]=Frm_prvd->Edt_QMJ;
    EDT_ARR[0][2]=Frm_prvd->Edt_QkJ;
    EDT_ARR[0][3]=Frm_prvd->Edt_QJ;
        EDT_ARR[1][0]=Frm_prvd->Edt_QGk;
        EDT_ARR[1][1]=Frm_prvd->Edt_QMk;
        EDT_ARR[1][2]=Frm_prvd->Edt_Qkk;
        EDT_ARR[1][3]=Frm_prvd->Edt_Qk;
    EDT_ARR[2][0]=Frm_prvd->Edt_Qtut;
// Массив коэффициентов перевода из одних едениц в другие
double **KOEF;
    KOEF = new double*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            KOEF[j] = new double [N_ED];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    KOEF[0][0]=1;           KOEF[0][1]=0.239;   KOEF[0][2]=0.341e-10;
    KOEF[1][0]=4.187;       KOEF[1][1]=1;       KOEF[1][2]=0.143e-9;
    KOEF[2][0]=2.931e10;    KOEF[2][1]=7e9;     KOEF[2][2]=1;
// Массив приставок
int **PRISTAVKA;
    PRISTAVKA = new int*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            PRISTAVKA[j] = new int [N_EDT[j]];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    PRISTAVKA[0][0]=GIGA;
    PRISTAVKA[0][1]=MEGA;
    PRISTAVKA[0][2]=KILO;
    PRISTAVKA[0][3]=1;
        PRISTAVKA[1][0]=GIGA;
        PRISTAVKA[1][1]=MEGA;
        PRISTAVKA[1][2]=KILO;
        PRISTAVKA[1][3]=1;
    PRISTAVKA[2][0]=1;
// Вызов функции перевода
    prvd(N_ED,N_EDT,EDT_ARR,KOEF,PRISTAVKA);
}
//---------------------------------------------------------------------------
void prvd_c()
{
int N_ED=2;         // кол-во едениц измерения
int N_EDT[]={4,4};  //кол-во Edit'ов в каждой еденице измерения
// Массив Edit'ов
TEdit ***EDT_ARR;
    EDT_ARR = new TEdit **[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            EDT_ARR[j] = new TEdit *[N_EDT[j]];
            // кол-во столбцов, Edit'ов в кажд.ед-це измерения
    EDT_ARR[0][0]=Frm_prvd->Edt_QGJ_k;
    EDT_ARR[0][1]=Frm_prvd->Edt_QMJ_k;
    EDT_ARR[0][2]=Frm_prvd->Edt_QkJ_k;
    EDT_ARR[0][3]=Frm_prvd->Edt_QJ_k;
        EDT_ARR[1][0]=Frm_prvd->Edt_QGk_k;
        EDT_ARR[1][1]=Frm_prvd->Edt_QMk_k;
        EDT_ARR[1][2]=Frm_prvd->Edt_Qkk_k;
        EDT_ARR[1][3]=Frm_prvd->Edt_Qk_k;
// Массив коэффициентов перевода из одних едениц в другие
double **KOEF;
    KOEF = new double*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            KOEF[j] = new double [N_ED];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    KOEF[0][0]=1;           KOEF[0][1]=0.239;
    KOEF[1][0]=4.187;       KOEF[1][1]=1;
// Массив приставок
int **PRISTAVKA;
    PRISTAVKA = new int*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            PRISTAVKA[j] = new int [N_EDT[j]];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    PRISTAVKA[0][0]=GIGA;
    PRISTAVKA[0][1]=MEGA;
    PRISTAVKA[0][2]=KILO;
    PRISTAVKA[0][3]=1;
        PRISTAVKA[1][0]=GIGA;
        PRISTAVKA[1][1]=MEGA;
        PRISTAVKA[1][2]=KILO;
        PRISTAVKA[1][3]=1;
// Вызов функции перевода
    prvd(N_ED,N_EDT,EDT_ARR,KOEF,PRISTAVKA);
}
//---------------------------------------------------------------------------
void prvd_P()
{
int N_ED=7;               // кол-во едениц измерения
int N_EDT[]={4,2,2,3,1,1,1};  //кол-во Edit'ов в каждой еденице измерения
// Массив Edit'ов
TEdit ***EDT_ARR;
    EDT_ARR = new TEdit **[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            EDT_ARR[j] = new TEdit *[N_EDT[j]];
            // кол-во столбцов, Edit'ов в кажд.ед-це измерения
    EDT_ARR[0][0]=Frm_prvd->Edt_PGPa;
    EDT_ARR[0][1]=Frm_prvd->Edt_PMPa;
    EDT_ARR[0][2]=Frm_prvd->Edt_PkPa;
    EDT_ARR[0][3]=Frm_prvd->Edt_PPa;
        EDT_ARR[1][0]=Frm_prvd->Edt_Pmvst;
        EDT_ARR[1][1]=Frm_prvd->Edt_Pmmvst;
    EDT_ARR[2][0]=Frm_prvd->Edt_Pmrtst;
    EDT_ARR[2][1]=Frm_prvd->Edt_Pmmrtst;
        EDT_ARR[3][0]=Frm_prvd->Edt_Pkg_mm;
        EDT_ARR[3][1]=Frm_prvd->Edt_Pkg_cm;
        EDT_ARR[3][2]=Frm_prvd->Edt_Pkg_m;
    EDT_ARR[4][0]=Frm_prvd->Edt_Pbar;
        EDT_ARR[5][0]=Frm_prvd->Edt_Patm;
    EDT_ARR[6][0]=Frm_prvd->Edt_Pat;
// Массив коэффициентов перевода из одних едениц в другие
double **KOEF;
    KOEF = new double*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            KOEF[j] = new double [N_ED];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    KOEF[0][0]=1;
    KOEF[0][1]=0.102;
    KOEF[0][2]=0.008;
    KOEF[0][3]=0.102;
    KOEF[0][4]=1e-6;
    KOEF[0][5]=9.869e-6;
    KOEF[0][6]=1.020e-5;
        KOEF[1][0]=9.807;
        KOEF[1][1]=1;
        KOEF[1][2]=0.074;
        KOEF[1][3]=1;
        KOEF[1][4]=9.807e-6;
        KOEF[1][5]=9.678e-5;
        KOEF[1][6]=0.0001;
    KOEF[2][0]=133.322;
    KOEF[2][1]=13.595;
    KOEF[2][2]=1;
    KOEF[2][3]=13.595;
    KOEF[2][4]=1.333e-4;
    KOEF[2][5]=0.001;
    KOEF[2][6]=0.001;
        KOEF[3][0]=9.807;
        KOEF[3][1]=1;
        KOEF[3][2]=0.074;
        KOEF[3][3]=1;
        KOEF[3][4]=9.807e-6;
        KOEF[3][5]=9.678e-5;
        KOEF[3][6]=0.0001;
    KOEF[4][0]=1e6;
    KOEF[4][1]=1.02e5;
    KOEF[4][2]=7.501e3;
    KOEF[4][3]=1.02e5;
    KOEF[4][4]=1;
    KOEF[4][5]=9.869;
    KOEF[4][6]=10.197;
        KOEF[5][0]=1.013e5;
        KOEF[5][1]=1.033e4;
        KOEF[5][2]=7.6e2;
        KOEF[5][3]=1.033e4;
        KOEF[5][4]=1.013e-1;
        KOEF[5][5]=1;
        KOEF[5][6]=1.033;
    KOEF[6][0]=9.81e4;
    KOEF[6][1]=10000;
    KOEF[6][2]=735.561;
    KOEF[6][3]=10000;
    KOEF[6][4]=9.807e-2;
    KOEF[6][5]=9.678e-1;
    KOEF[6][6]=1;
// Массив приставок
int **PRISTAVKA;
    PRISTAVKA = new int*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            PRISTAVKA[j] = new int [N_EDT[j]];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    PRISTAVKA[0][0]=GIGA;
    PRISTAVKA[0][1]=MEGA;
    PRISTAVKA[0][2]=KILO;
    PRISTAVKA[0][3]=1;
        PRISTAVKA[1][0]=MILI;
        PRISTAVKA[1][1]=1;
    PRISTAVKA[2][0]=MILI;
    PRISTAVKA[2][1]=1;
        PRISTAVKA[3][0]=MILI*MILI;
        PRISTAVKA[3][1]=SANTI*SANTI;
        PRISTAVKA[3][2]=1;
    PRISTAVKA[4][0]=1;
    PRISTAVKA[5][0]=1;
    PRISTAVKA[6][0]=1;
// Вызов функции перевода
    prvd(N_ED,N_EDT,EDT_ARR,KOEF,PRISTAVKA);
}
//---------------------------------------------------------------------------
void prvd_G()
{
int N_ED=3;         // кол-во едениц измерения
int N_EDT[]={2,2,2};  //кол-во Edit'ов в каждой еденице измерения
// Массив Edit'ов
TEdit ***EDT_ARR;
    EDT_ARR = new TEdit **[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            EDT_ARR[j] = new TEdit *[N_EDT[j]];
            // кол-во столбцов, Edit'ов в кажд.ед-це измерения
    EDT_ARR[0][0]=Frm_prvd->Edt_Gm_h;
    EDT_ARR[0][1]=Frm_prvd->Edt_Gl_h;
        EDT_ARR[1][0]=Frm_prvd->Edt_Gm_m;
        EDT_ARR[1][1]=Frm_prvd->Edt_Gl_m;
    EDT_ARR[2][0]=Frm_prvd->Edt_Gm_c;
    EDT_ARR[2][1]=Frm_prvd->Edt_Gl_c;
// Массив коэффициентов перевода из одних едениц в другие
double **KOEF;
    KOEF = new double*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            KOEF[j] = new double [N_ED];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    KOEF[0][0]=1;       KOEF[0][1]=0.017;      KOEF[0][2]=0.278e-3;
    KOEF[1][0]=60;      KOEF[1][1]=1;          KOEF[1][2]=0.017;
    KOEF[2][0]=3600;    KOEF[2][1]=60;         KOEF[2][2]=1;
// Массив приставок
int **PRISTAVKA;
    PRISTAVKA = new int*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            PRISTAVKA[j] = new int [N_EDT[j]];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    PRISTAVKA[0][0]=LITR_FROM_M;
    PRISTAVKA[0][1]=1;
        PRISTAVKA[1][0]=LITR_FROM_M ;
        PRISTAVKA[1][1]=1;
    PRISTAVKA[2][0]=LITR_FROM_M;
    PRISTAVKA[2][1]=1;
// Вызов функции перевода
    prvd(N_ED,N_EDT,EDT_ARR,KOEF,PRISTAVKA);
}
//---------------------------------------------------------------------------
void prvd_Gm()
{
int N_ED=3;         // кол-во едениц измерения
int N_EDT[]={2,2,2};  //кол-во Edit'ов в каждой еденице измерения
// Массив Edit'ов
TEdit ***EDT_ARR;
    EDT_ARR = new TEdit **[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            EDT_ARR[j] = new TEdit *[N_EDT[j]];
            // кол-во столбцов, Edit'ов в кажд.ед-це измерения
    EDT_ARR[0][0]=Frm_prvd->Edt_Gkg_h;
    EDT_ARR[0][1]=Frm_prvd->Edt_Gt_h;
        EDT_ARR[1][0]=Frm_prvd->Edt_Gkg_m;
        EDT_ARR[1][1]=Frm_prvd->Edt_Gt_m;
    EDT_ARR[2][0]=Frm_prvd->Edt_Gkg_c;
    EDT_ARR[2][1]=Frm_prvd->Edt_Gt_c;
// Массив коэффициентов перевода из одних едениц в другие
double **KOEF;
    KOEF = new double*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            KOEF[j] = new double [N_ED];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    KOEF[0][0]=1;       KOEF[0][1]=0.017;      KOEF[0][2]=0.278e-3;
    KOEF[1][0]=60;      KOEF[1][1]=1;          KOEF[1][2]=0.017;
    KOEF[2][0]=3600;    KOEF[2][1]=60;         KOEF[2][2]=1;
// Массив приставок
int **PRISTAVKA;
    PRISTAVKA = new int*[N_ED];        // кол-во строк, едениц измерения
        for (int j = 0; j < N_ED; j++)
            PRISTAVKA[j] = new int [N_EDT[j]];
               // кол-во столбцов, коэф-тов в кажд.ед-це измерения
    PRISTAVKA[0][0]=1;
    PRISTAVKA[0][1]=KG_FROM_T;
        PRISTAVKA[1][0]=1 ;
        PRISTAVKA[1][1]=KG_FROM_T;
    PRISTAVKA[2][0]=1;
    PRISTAVKA[2][1]=KG_FROM_T;
// Вызов функции перевода
    prvd(N_ED,N_EDT,EDT_ARR,KOEF,PRISTAVKA);
}
//---------------------------------------------------------------------------
