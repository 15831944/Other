VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form opn_f_ish_dan_Frm 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Выбор файла исходных данных"
   ClientHeight    =   1470
   ClientLeft      =   5310
   ClientTop       =   5070
   ClientWidth     =   6135
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "opn_f_ish_dan_Frm.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   1470
   ScaleWidth      =   6135
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton oCmBtn 
      Caption         =   "Открыть"
      Height          =   495
      Left            =   1020
      TabIndex        =   0
      ToolTipText     =   "открытие сущетвующего файла с исходными данными"
      Top             =   480
      Width           =   1815
   End
   Begin VB.CommandButton nCmBtn 
      Caption         =   "Новый"
      Height          =   495
      Left            =   3300
      TabIndex        =   1
      ToolTipText     =   "ввод исходных данных вручную"
      Top             =   480
      Width           =   1815
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   5520
      Top             =   840
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.CheckBox Fast_CkBx 
      Caption         =   "Короткий расчет"
      Height          =   255
      Left            =   2100
      TabIndex        =   2
      ToolTipText     =   "расчет с уже известными максимальными часовыми расходами"
      Top             =   1080
      Width           =   1935
   End
   Begin VB.Label Lbl 
      AutoSize        =   -1  'True
      Caption         =   "Выберите файл исходных данных для расчета"
      Height          =   195
      Left            =   990
      TabIndex        =   3
      ToolTipText     =   "выбор способа ввода исходных данных"
      Top             =   120
      Width           =   4140
   End
End
Attribute VB_Name = "opn_f_ish_dan_Frm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
