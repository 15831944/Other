VERSION 5.00
Begin VB.Form save_ish_dan_Frm 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "–асчет тепла укрупненно"
   ClientHeight    =   1170
   ClientLeft      =   6285
   ClientTop       =   3480
   ClientWidth     =   5280
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "save_ish_dan_Frm.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   1170
   ScaleWidth      =   5280
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cCmBtn 
      Caption         =   "Ќет"
      Height          =   495
      Left            =   2933
      TabIndex        =   2
      ToolTipText     =   "не сохран€ть исходные данные дл€ расчета"
      Top             =   480
      Width           =   1815
   End
   Begin VB.CommandButton sCmBtn 
      Caption         =   "ƒа"
      Height          =   495
      Left            =   533
      TabIndex        =   1
      ToolTipText     =   "сохранить исходные данные дл€ расчета в документе Word"
      Top             =   480
      Width           =   1815
   End
   Begin VB.Label Lbl 
      AutoSize        =   -1  'True
      Caption         =   "—охранить исходные данные?"
      Height          =   195
      Left            =   1298
      TabIndex        =   0
      Top             =   120
      Width           =   2685
   End
End
Attribute VB_Name = "save_ish_dan_Frm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
