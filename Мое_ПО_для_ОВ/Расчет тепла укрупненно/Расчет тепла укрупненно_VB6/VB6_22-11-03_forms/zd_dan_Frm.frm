VERSION 5.00
Begin VB.Form zd_dan_Frm 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "�������������� ������ �"
   ClientHeight    =   7215
   ClientLeft      =   1125
   ClientTop       =   2370
   ClientWidth     =   13365
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   ForeColor       =   &H00000000&
   Icon            =   "zd_dan_Frm.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   7215
   ScaleWidth      =   13365
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton goto_CmdBtn 
      Caption         =   "������� � ..."
      Height          =   495
      Left            =   9120
      TabIndex        =   21
      ToolTipText     =   "������� � ������ � ��������� �������"
      Top             =   4560
      Width           =   1815
   End
   Begin VB.CheckBox vent_ChkBx 
      Caption         =   "���������� ���"
      Height          =   375
      Left            =   2520
      TabIndex        =   6
      Top             =   4440
      Width           =   1935
   End
   Begin VB.CheckBox ot_ChkBx 
      Caption         =   "��������� ���"
      Height          =   375
      Left            =   120
      TabIndex        =   5
      Top             =   4440
      Width           =   2055
   End
   Begin VB.ComboBox udelnie_CmbBx 
      Height          =   315
      ItemData        =   "zd_dan_Frm.frx":030A
      Left            =   120
      List            =   "zd_dan_Frm.frx":030C
      TabIndex        =   4
      Top             =   4080
      Width           =   4095
   End
   Begin VB.Frame zdFm 
      Caption         =   "������� ������, �:"
      Height          =   2775
      Left            =   120
      TabIndex        =   36
      ToolTipText     =   "�� ��������� ������"
      Top             =   840
      Width           =   4095
      Begin VB.TextBox Text3 
         Height          =   315
         Left            =   240
         TabIndex        =   3
         ToolTipText     =   "������ ������ �� ��������� ������"
         Top             =   2160
         Width           =   1815
      End
      Begin VB.TextBox Text2 
         Height          =   315
         Left            =   240
         TabIndex        =   2
         ToolTipText     =   "������ ������ �� ��������� ������"
         Top             =   1440
         Width           =   1815
      End
      Begin VB.TextBox Text1 
         Height          =   315
         Left            =   240
         TabIndex        =   1
         ToolTipText     =   "����� ������ �� ��������� ������"
         Top             =   600
         Width           =   1815
      End
      Begin VB.Label hLbl 
         AutoSize        =   -1  'True
         Caption         =   "������:"
         Height          =   195
         Left            =   240
         TabIndex        =   39
         ToolTipText     =   "������ ������ �� ��������� ������"
         Top             =   1920
         Width           =   735
      End
      Begin VB.Label bLbl 
         AutoSize        =   -1  'True
         Caption         =   "������:"
         Height          =   195
         Left            =   240
         TabIndex        =   38
         ToolTipText     =   "������ ������ �� ��������� ������"
         Top             =   1200
         Width           =   750
      End
      Begin VB.Label aLbl 
         AutoSize        =   -1  'True
         Caption         =   "�����:"
         Height          =   195
         Left            =   240
         TabIndex        =   37
         ToolTipText     =   "����� ������ �� ��������� ������"
         Top             =   360
         Width           =   645
      End
   End
   Begin VB.CommandButton Exit_CmdBtn 
      Caption         =   "�����"
      Height          =   495
      Left            =   11160
      TabIndex        =   22
      ToolTipText     =   "����� �� ���������"
      Top             =   4560
      Width           =   1815
   End
   Begin VB.CommandButton nazadCmdBtn 
      Caption         =   "< �����"
      Height          =   495
      Left            =   9120
      TabIndex        =   20
      ToolTipText     =   "������� � ����������� ���� �����"
      Top             =   3840
      Width           =   1815
   End
   Begin VB.TextBox tdotTxtBx 
      Height          =   315
      Left            =   4560
      TabIndex        =   14
      Text            =   "5"
      ToolTipText     =   "����������� ������� �������������� �������� ����������"
      Top             =   4080
      Width           =   1815
   End
   Begin VB.CommandButton okCmBtn 
      Caption         =   "����� >"
      Height          =   495
      Left            =   11160
      TabIndex        =   19
      ToolTipText     =   "������� � ���������� ���� �����"
      Top             =   3840
      Width           =   1815
   End
   Begin VB.Frame vz1Fm 
      Caption         =   "��������� ������:"
      Height          =   1935
      Left            =   8760
      TabIndex        =   32
      Top             =   1680
      Width           =   4455
      Begin VB.TextBox zTxtBx 
         Height          =   315
         Left            =   240
         MaxLength       =   2
         TabIndex        =   18
         Top             =   1320
         Width           =   1815
      End
      Begin VB.TextBox qvzTxtBx 
         Height          =   315
         Left            =   240
         MaxLength       =   7
         TabIndex        =   17
         Top             =   600
         Width           =   1815
      End
      Begin VB.Label zLbl 
         AutoSize        =   -1  'True
         Caption         =   "���������� ����� ������ ������ � �����:"
         Height          =   195
         Left            =   240
         TabIndex        =   34
         Top             =   1080
         Width           =   3825
      End
      Begin VB.Label qvzLbl 
         AutoSize        =   -1  'True
         Caption         =   "������ ����� �� ��������� ������, �����/�:"
         Height          =   195
         Left            =   240
         TabIndex        =   33
         Top             =   360
         Width           =   4080
      End
   End
   Begin VB.Frame vzFm 
      Caption         =   "��������� ������:"
      Height          =   1335
      Left            =   8760
      TabIndex        =   31
      Top             =   120
      Width           =   4455
      Begin VB.OptionButton yOptnBtn 
         Caption         =   "����"
         Height          =   255
         Left            =   240
         TabIndex        =   15
         Top             =   360
         Value           =   -1  'True
         Width           =   2655
      End
      Begin VB.OptionButton nOptnBtn 
         Caption         =   "���"
         Height          =   255
         Left            =   240
         TabIndex        =   16
         Top             =   840
         Width           =   2655
      End
   End
   Begin VB.Frame nagrFm 
      Caption         =   "�������� ��������  ������, ����/�3�:"
      Height          =   2055
      Left            =   120
      TabIndex        =   28
      Top             =   5040
      Width           =   4095
      Begin VB.TextBox qoTxtBx 
         Height          =   315
         Left            =   240
         TabIndex        =   7
         ToolTipText     =   "�������� ������������ �������������� ������ ��� t�=-30��"
         Top             =   600
         Width           =   1815
      End
      Begin VB.TextBox qbTxtBx 
         Height          =   315
         Left            =   240
         TabIndex        =   8
         ToolTipText     =   "�������� �������� �������������� ������ ��� ����������"
         Top             =   1440
         Width           =   1815
      End
      Begin VB.Label qoLbl 
         AutoSize        =   -1  'True
         Caption         =   "�� ���������:"
         Height          =   195
         Left            =   240
         TabIndex        =   30
         ToolTipText     =   "�������� ������������ �������������� ������ ��� t�=-30��"
         Top             =   360
         Width           =   1305
      End
      Begin VB.Label qbLbl 
         AutoSize        =   -1  'True
         Caption         =   "�� ����������:"
         Height          =   195
         Left            =   240
         TabIndex        =   29
         ToolTipText     =   "�������� �������� �������������� ������ ��� ����������"
         Top             =   1200
         Width           =   1440
      End
   End
   Begin VB.TextBox tprTxtBx 
      Height          =   315
      Left            =   4560
      TabIndex        =   11
      ToolTipText     =   "����������� ���������� �������"
      Top             =   1800
      Width           =   1815
   End
   Begin VB.TextBox tbTxtBx 
      Height          =   315
      Left            =   4560
      TabIndex        =   10
      ToolTipText     =   "������� ����������� ������� � ������"
      Top             =   1080
      Width           =   1815
   End
   Begin VB.Frame DotFm 
      Caption         =   "�������� ���������:"
      Height          =   1335
      Left            =   4560
      TabIndex        =   25
      Top             =   2280
      Width           =   3855
      Begin VB.OptionButton n_OptnBtn 
         Caption         =   "���"
         Height          =   255
         Left            =   240
         TabIndex        =   13
         ToolTipText     =   "��������� ������ �������� � �������� ������"
         Top             =   840
         Width           =   2655
      End
      Begin VB.OptionButton y_OptnBtn 
         Caption         =   "����"
         Height          =   255
         Left            =   240
         TabIndex        =   12
         ToolTipText     =   "������ ������ ��������� �����������"
         Top             =   440
         Value           =   -1  'True
         Width           =   2655
      End
   End
   Begin VB.TextBox mTxtBx 
      Height          =   315
      Left            =   4560
      MaxLength       =   2
      TabIndex        =   9
      ToolTipText     =   "�� ���������� ���� ������ �����"
      Top             =   360
      Width           =   1815
   End
   Begin VB.TextBox nzdTxtBx 
      Height          =   315
      Left            =   120
      MaxLength       =   7
      TabIndex        =   0
      ToolTipText     =   "����� �������� ������"
      Top             =   360
      Width           =   3615
   End
   Begin VB.Label ud_Lbl 
      AutoSize        =   -1  'True
      Caption         =   "��� ������:"
      Height          =   195
      Left            =   120
      TabIndex        =   40
      Top             =   3840
      Width           =   1095
   End
   Begin VB.Label tdotLbl 
      AutoSize        =   -1  'True
      Caption         =   "����������� ��������� ���������, oC:"
      Height          =   195
      Left            =   4560
      TabIndex        =   35
      ToolTipText     =   "����������� ������� �������������� �������� ����������"
      Top             =   3840
      Width           =   3585
   End
   Begin VB.Label tprLbl 
      AutoSize        =   -1  'True
      Caption         =   "����������� ���������� �������, oC:"
      Height          =   195
      Left            =   4560
      TabIndex        =   27
      ToolTipText     =   "����������� ���������� �������"
      Top             =   1560
      Width           =   3420
   End
   Begin VB.Label tbLbl 
      AutoSize        =   -1  'True
      Caption         =   "����������� ����������� �������, oC:"
      Height          =   195
      Left            =   4560
      TabIndex        =   26
      ToolTipText     =   "������� ����������� ������� � ������"
      Top             =   840
      Width           =   3525
   End
   Begin VB.Label mLbl 
      AutoSize        =   -1  'True
      Caption         =   "���������� ����� ������ ������ � �����:"
      Height          =   195
      Left            =   4560
      TabIndex        =   24
      ToolTipText     =   "�� ���������� ���� ������ �����"
      Top             =   120
      Width           =   3795
   End
   Begin VB.Label nzdLbl 
      AutoSize        =   -1  'True
      Caption         =   "������������ ������:"
      Height          =   195
      Left            =   120
      TabIndex        =   23
      ToolTipText     =   "�� ����� ��������"
      Top             =   120
      Width           =   2085
   End
End
Attribute VB_Name = "zd_dan_Frm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
