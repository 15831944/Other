Attribute VB_Name = "Vvod_climat_Frm"
Option Explicit
Public clmt(number_of_gorod, 5) As String
Dim cl1() As String
Dim cl(number_of_gorod + 1) As String
Dim i_clmt As Integer, j_clmt As Integer
Sub Vvod_climat_CmbBx()
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''     ќткрывает файл с климатическими данными и считывает оттуда значени€       '''
''' и заполн€ет массив с климатическими данными и список городов формы climat_Frm '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Open f_path_macros & f_clmt_name For Input As #1
i_clmt = 1
Do While Not EOF(1)
    Line Input #1, cl(i_clmt)
    i_clmt = i_clmt + 1
Loop
Close #1
For i_clmt = 1 To number_of_gorod
    cl1 = Split(cl(i_clmt + 1), ";")
    For j_clmt = 1 To 5
        clmt(i_clmt, j_clmt) = cl1(j_clmt - 1)
    Next j_clmt
climat_Frm.climat_CmbBx.AddItem clmt(i_clmt, 1), (i_clmt - 1)
Next i_clmt
climat_Frm.climat_CmbBx.AddItem "ƒругой..."
End Sub

Public Sub vvod_climat(g As String, t1 As Single, t2 As Single, t3 As Single, n_ot As Integer)
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' ¬ зависимости от выбранного города заполн€ет климатические переменные '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
If climat_Frm.climat_CmbBx.ListIndex <> -1 And _
    climat_Frm.climat_CmbBx.ListIndex <> climat_Frm.climat_CmbBx.ListCount - 1 Then
    g = clmt(climat_Frm.climat_CmbBx.ListIndex + 1, 1)
    t1 = Str_conv_SngNmb(clmt(climat_Frm.climat_CmbBx.ListIndex + 1, 2))
    t2 = Str_conv_SngNmb(clmt(climat_Frm.climat_CmbBx.ListIndex + 1, 3))
    t3 = Str_conv_SngNmb(clmt(climat_Frm.climat_CmbBx.ListIndex + 1, 4))
    n_ot = Str_conv_SngNmb(clmt(climat_Frm.climat_CmbBx.ListIndex + 1, 5))
ElseIf climat_Frm.climat_CmbBx.ListIndex <> -1 And _
    climat_Frm.climat_CmbBx.ListIndex = climat_Frm.climat_CmbBx.ListCount - 1 Then
'значит climat_Frm.climat_CmbBx.Text = "ƒругой..."
    g = climat_Frm.n_grd_TxtBx.Text
    t1 = Str_conv_SngNmb(climat_Frm.tn1TxtBx.Text)
    t2 = Str_conv_SngNmb(climat_Frm.tn2TxtBx.Text)
    t3 = Str_conv_SngNmb(climat_Frm.tn3TxtBx.Text)
    n_ot = Str_conv_SngNmb(climat_Frm.nTxtBx.Text)
End If
End Sub


