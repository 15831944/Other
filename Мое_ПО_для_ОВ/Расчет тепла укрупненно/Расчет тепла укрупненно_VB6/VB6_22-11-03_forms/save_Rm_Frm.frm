VERSION 5.00
Begin VB.Form save_Rm_Frm 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "������ ����� ����������"
   ClientHeight    =   1215
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5535
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "save_Rm_Frm.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   1215
   ScaleWidth      =   5535
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton cCmBtn 
      Caption         =   "���"
      Height          =   495
      Left            =   3060
      TabIndex        =   1
      ToolTipText     =   "�� ��������� ��������� ������"
      Top             =   480
      Width           =   1815
   End
   Begin VB.CommandButton sCmBtn 
      Caption         =   "��"
      Height          =   495
      Left            =   660
      TabIndex        =   0
      ToolTipText     =   "��������� ��������� ������ � ��������� Word"
      Top             =   480
      Width           =   1815
   End
   Begin VB.Label Lbl 
      AutoSize        =   -1  'True
      Caption         =   "��������� ��������� ��������� � ����?"
      Height          =   255
      Left            =   840
      TabIndex        =   2
      Top             =   120
      Width           =   3855
   End
End
Attribute VB_Name = "save_Rm_Frm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
