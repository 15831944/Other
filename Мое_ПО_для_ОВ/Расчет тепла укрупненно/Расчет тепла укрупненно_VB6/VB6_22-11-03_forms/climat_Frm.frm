VERSION 5.00
Begin VB.Form climat_Frm 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "������������� �������"
   ClientHeight    =   7725
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   5070
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "climat_Frm.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   7725
   ScaleWidth      =   5070
   StartUpPosition =   2  'CenterScreen
   WhatsThisHelp   =   -1  'True
   Begin VB.CommandButton Exit_CmdBtn 
      Caption         =   "�����"
      Height          =   495
      Left            =   3120
      TabIndex        =   10
      ToolTipText     =   "����� �� ���������"
      Top             =   2520
      Width           =   1815
   End
   Begin VB.PictureBox Picture1 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   204
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   4455
      Left            =   120
      ScaleHeight     =   4395
      ScaleWidth      =   4755
      TabIndex        =   13
      Top             =   3120
      Width           =   4815
      Begin VB.TextBox n_grd_TxtBx 
         Height          =   315
         Left            =   120
         TabIndex        =   4
         Top             =   360
         Width           =   1815
      End
      Begin VB.Frame tnFm 
         Caption         =   "����������� ��������� �������:"
         Height          =   2655
         Left            =   120
         TabIndex        =   15
         ToolTipText     =   "�� ���� 23-01-99  ""������������ ������������ � ���������"""
         Top             =   840
         Width           =   3495
         Begin VB.TextBox tn3TxtBx 
            Height          =   315
            Left            =   120
            TabIndex        =   7
            ToolTipText     =   "�������������� ����������� I (������ ���������) ������:"
            Top             =   2040
            Width           =   1815
         End
         Begin VB.TextBox tn2TxtBx 
            Height          =   315
            Left            =   120
            TabIndex        =   6
            ToolTipText     =   "������� ������� �� �������������� ������������ ������� ������ ��� ������ 8 ��"
            Top             =   1320
            Width           =   1815
         End
         Begin VB.TextBox tn1TxtBx 
            Height          =   315
            Left            =   120
            TabIndex        =   5
            ToolTipText     =   "(��������������� 0,92)"
            Top             =   600
            Width           =   1815
         End
         Begin VB.Label tn3Lbl 
            AutoSize        =   -1  'True
            Caption         =   "������� �� ������:"
            Height          =   195
            Left            =   120
            TabIndex        =   18
            ToolTipText     =   "�������������� ����������� I (������ ���������) ������:"
            Top             =   1800
            Width           =   1785
         End
         Begin VB.Label tn2Lbl 
            AutoSize        =   -1  'True
            Caption         =   "������� �� ������������ ������:"
            Height          =   195
            Left            =   120
            TabIndex        =   17
            ToolTipText     =   "������� ������� �� �������������� ������������ ������� ������ ��� ������ 8 ��"
            Top             =   1080
            Width           =   3105
         End
         Begin VB.Label tn1Lbl 
            AutoSize        =   -1  'True
            Caption         =   "�������� �������� ����������:"
            Height          =   195
            Left            =   120
            TabIndex        =   16
            ToolTipText     =   "(��������������� 0,92)"
            Top             =   360
            Width           =   2925
         End
      End
      Begin VB.TextBox nTxtBx 
         Height          =   315
         Left            =   120
         TabIndex        =   8
         ToolTipText     =   "�� ���� 23-01-99  ""������������ ������������ � ���������"""
         Top             =   3840
         Width           =   1815
      End
      Begin VB.Label n_grd_Lbl 
         AutoSize        =   -1  'True
         Caption         =   "�������� ������:"
         Height          =   195
         Left            =   120
         TabIndex        =   19
         Top             =   120
         Width           =   1620
      End
      Begin VB.Label nLbl 
         AutoSize        =   -1  'True
         Caption         =   "����������������� ������������� �������, ����:"
         Height          =   195
         Left            =   120
         TabIndex        =   14
         ToolTipText     =   "�� ���� 23-01-99  ""������������ ������������ � ���������"""
         Top             =   3600
         Width           =   4605
      End
   End
   Begin VB.ComboBox climat_CmbBx 
      Height          =   315
      Left            =   120
      Sorted          =   -1  'True
      TabIndex        =   2
      ToolTipText     =   "�������� ������ ����� �������������"
      Top             =   1080
      Width           =   4815
   End
   Begin VB.CommandButton okCmBtn 
      Caption         =   "����� >"
      Height          =   495
      Left            =   3120
      TabIndex        =   9
      ToolTipText     =   "������� � ���������� ���� �����"
      Top             =   1800
      Width           =   1815
   End
   Begin VB.TextBox kTxtBx 
      Height          =   315
      Left            =   120
      TabIndex        =   3
      ToolTipText     =   "�� ���� ���"
      Top             =   1800
      Width           =   1815
   End
   Begin VB.TextBox xTxtBx 
      Height          =   315
      Left            =   120
      MaxLength       =   2
      TabIndex        =   1
      ToolTipText     =   "�� ����� 40"
      Top             =   360
      Width           =   1815
   End
   Begin VB.Label clLbl 
      AutoSize        =   -1  'True
      Caption         =   "����� �������������:"
      Height          =   195
      Left            =   120
      TabIndex        =   12
      ToolTipText     =   "�������� ������ ����� �������������"
      Top             =   840
      Width           =   1980
   End
   Begin VB.Label kLbl 
      AutoSize        =   -1  'True
      Caption         =   "����� �������� � ����������� ����:"
      Height          =   195
      Left            =   120
      TabIndex        =   11
      ToolTipText     =   "�� ���� ���"
      Top             =   1560
      Width           =   3450
   End
   Begin VB.Label xLbl 
      AutoSize        =   -1  'True
      Caption         =   "���������� ������:"
      Height          =   195
      Left            =   120
      TabIndex        =   0
      ToolTipText     =   "�� ����� ������"
      Top             =   120
      Width           =   1800
   End
End
Attribute VB_Name = "climat_Frm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
