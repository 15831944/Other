VERSION 5.00
Begin VB.Form zd_dan_Frm_fast 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "�������������� ������ �"
   ClientHeight    =   5295
   ClientLeft      =   1125
   ClientTop       =   2370
   ClientWidth     =   13590
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "zd_dan_Frm_fast.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   5295
   ScaleWidth      =   13590
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton okCmBtn 
      Caption         =   "����� >"
      Height          =   495
      Left            =   11280
      TabIndex        =   29
      ToolTipText     =   "������� � ���������� ���� �����"
      Top             =   3960
      Width           =   1815
   End
   Begin VB.CommandButton nazadCmdBtn 
      Caption         =   "< �����"
      Height          =   495
      Left            =   9240
      TabIndex        =   28
      ToolTipText     =   "������� � ����������� ���� �����"
      Top             =   3960
      Width           =   1815
   End
   Begin VB.CommandButton Exit_CmdBtn 
      Caption         =   "�����"
      Height          =   495
      Left            =   11280
      TabIndex        =   27
      ToolTipText     =   "����� �� ���������"
      Top             =   4680
      Width           =   1815
   End
   Begin VB.CommandButton goto_CmdBtn 
      Caption         =   "������� � ..."
      Height          =   495
      Left            =   9240
      TabIndex        =   26
      ToolTipText     =   "������� � ������ � ��������� �������"
      Top             =   4680
      Width           =   1815
   End
   Begin VB.TextBox tdotTxtBx 
      Height          =   315
      Left            =   5040
      TabIndex        =   24
      Text            =   "5"
      ToolTipText     =   "����������� ������� �������������� �������� ����������"
      Top             =   1920
      Width           =   1815
   End
   Begin VB.Frame vz1Fm 
      Caption         =   "��������� ������:"
      Height          =   2055
      Left            =   9000
      TabIndex        =   19
      Top             =   1680
      Width           =   4455
      Begin VB.TextBox zTxtBx 
         Height          =   315
         Left            =   240
         MaxLength       =   2
         TabIndex        =   21
         Top             =   1320
         Width           =   1815
      End
      Begin VB.TextBox qvzTxtBx 
         Height          =   315
         Left            =   240
         MaxLength       =   7
         TabIndex        =   20
         Top             =   600
         Width           =   1815
      End
      Begin VB.Label zLbl 
         AutoSize        =   -1  'True
         Caption         =   "���������� ����� ������ ������ � �����:"
         Height          =   195
         Left            =   240
         TabIndex        =   23
         Top             =   1080
         Width           =   3825
      End
      Begin VB.Label qvzLbl 
         AutoSize        =   -1  'True
         Caption         =   "������ ����� �� ��������� ������, �����/�:"
         Height          =   195
         Left            =   240
         TabIndex        =   22
         Top             =   360
         Width           =   4080
      End
   End
   Begin VB.Frame vzFm 
      Caption         =   "��������� ������:"
      Height          =   1335
      Left            =   9000
      TabIndex        =   16
      Top             =   120
      Width           =   4455
      Begin VB.OptionButton yOptnBtn 
         Caption         =   "����"
         Height          =   255
         Left            =   240
         TabIndex        =   18
         Top             =   360
         Value           =   -1  'True
         Width           =   2655
      End
      Begin VB.OptionButton nOptnBtn 
         Caption         =   "���"
         Height          =   255
         Left            =   240
         TabIndex        =   17
         Top             =   840
         Width           =   2655
      End
   End
   Begin VB.Frame nagrFm 
      Caption         =   "������������ ������� ������� �����, ����/�"
      Height          =   2055
      Left            =   120
      TabIndex        =   11
      Top             =   840
      Width           =   4575
      Begin VB.TextBox qoTxtBx 
         Height          =   315
         Left            =   240
         TabIndex        =   13
         ToolTipText     =   "������������ ������� ������ �� ���������"
         Top             =   600
         Width           =   1815
      End
      Begin VB.TextBox qbTxtBx 
         Height          =   315
         Left            =   240
         TabIndex        =   12
         ToolTipText     =   "������������ ������� ������ �� ����������"
         Top             =   1440
         Width           =   1815
      End
      Begin VB.Label qoLbl 
         AutoSize        =   -1  'True
         Caption         =   "�� ���������:"
         Height          =   195
         Left            =   240
         TabIndex        =   15
         ToolTipText     =   "������������ ������� ������ �� ���������"
         Top             =   360
         Width           =   1305
      End
      Begin VB.Label qbLbl 
         AutoSize        =   -1  'True
         Caption         =   "�� ����������:"
         Height          =   195
         Left            =   240
         TabIndex        =   14
         ToolTipText     =   "������������ ������� ������ �� ����������"
         Top             =   1200
         Width           =   1440
      End
   End
   Begin VB.TextBox tprTxtBx 
      Height          =   315
      Left            =   120
      TabIndex        =   9
      ToolTipText     =   "����������� ���������� �������"
      Top             =   4800
      Width           =   1815
   End
   Begin VB.TextBox tbTxtBx 
      Height          =   315
      Left            =   120
      TabIndex        =   7
      ToolTipText     =   "������� ����������� ������� � ������"
      Top             =   4080
      Width           =   1815
   End
   Begin VB.Frame DotFm 
      Caption         =   "�������� ���������:"
      Height          =   1335
      Left            =   5040
      TabIndex        =   4
      Top             =   120
      Width           =   3615
      Begin VB.OptionButton n_OptnBtn 
         Caption         =   "���"
         Height          =   255
         Left            =   240
         TabIndex        =   6
         ToolTipText     =   "��������� ������ �������� � �������� ������"
         Top             =   840
         Width           =   2655
      End
      Begin VB.OptionButton y_OptnBtn 
         Caption         =   "����"
         Height          =   255
         Left            =   240
         TabIndex        =   5
         ToolTipText     =   "������ ������ ��������� �����������"
         Top             =   440
         Value           =   -1  'True
         Width           =   2655
      End
   End
   Begin VB.TextBox mTxtBx 
      Height          =   315
      Left            =   120
      MaxLength       =   2
      TabIndex        =   2
      ToolTipText     =   "�� ���������� ���� ������ �����"
      Top             =   3360
      Width           =   1815
   End
   Begin VB.TextBox nzdTxtBx 
      Height          =   315
      Left            =   120
      MaxLength       =   7
      MousePointer    =   3  'I-Beam
      TabIndex        =   0
      ToolTipText     =   "����� �������� ������"
      Top             =   360
      Width           =   3615
   End
   Begin VB.Label tdotLbl 
      AutoSize        =   -1  'True
      Caption         =   "����������� ��������� ���������, oC:"
      Height          =   195
      Left            =   5040
      TabIndex        =   25
      ToolTipText     =   "����������� ������� �������������� �������� ����������"
      Top             =   1680
      Width           =   3585
   End
   Begin VB.Label tprLbl 
      AutoSize        =   -1  'True
      Caption         =   "����������� ���������� �������, oC:"
      Height          =   195
      Left            =   120
      TabIndex        =   10
      ToolTipText     =   "����������� ���������� �������"
      Top             =   4560
      Width           =   3420
   End
   Begin VB.Label tbLbl 
      AutoSize        =   -1  'True
      Caption         =   "����������� ����������� �������, oC:"
      Height          =   195
      Left            =   120
      TabIndex        =   8
      ToolTipText     =   "������� ����������� ������� � ������"
      Top             =   3840
      Width           =   3525
   End
   Begin VB.Label mLbl 
      AutoSize        =   -1  'True
      Caption         =   "���������� ����� ������ ������ � �����:"
      Height          =   195
      Left            =   120
      TabIndex        =   3
      ToolTipText     =   "�� ���������� ���� ������ �����"
      Top             =   3120
      Width           =   3795
   End
   Begin VB.Label nzdLbl 
      AutoSize        =   -1  'True
      Caption         =   "������������ ������:"
      Height          =   195
      Left            =   120
      TabIndex        =   1
      ToolTipText     =   "�� ����� ��������"
      Top             =   120
      Width           =   2085
   End
End
Attribute VB_Name = "zd_dan_Frm_fast"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
