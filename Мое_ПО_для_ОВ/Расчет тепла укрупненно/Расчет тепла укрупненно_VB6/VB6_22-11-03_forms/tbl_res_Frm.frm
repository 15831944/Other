VERSION 5.00
Begin VB.Form tbl_res_Frm 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "–асчет тепла укрупненно"
   ClientHeight    =   1485
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6840
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "tbl_res_Frm.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   1485
   ScaleWidth      =   6840
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton ok_CmBtn 
      Caption         =   "√отово"
      Height          =   495
      Left            =   2513
      TabIndex        =   1
      ToolTipText     =   "выход из пограммы и вставка таблицы с результатами расчета в выбранный документ"
      Top             =   840
      Width           =   1815
   End
   Begin VB.ComboBox doc_CmBx 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   204
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   315
      Left            =   113
      TabIndex        =   0
      ToolTipText     =   "указаны только открытые в данный момент документы"
      Top             =   360
      Width           =   6615
   End
   Begin VB.Label Lbl 
      AutoSize        =   -1  'True
      Caption         =   "¬ыберите документ дл€ вставки результатов расчета"
      Height          =   195
      Left            =   120
      TabIndex        =   2
      ToolTipText     =   "указаны только открытые в данный момент документы"
      Top             =   120
      Width           =   4875
   End
End
Attribute VB_Name = "tbl_res_Frm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
