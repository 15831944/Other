Attribute VB_Name = "VVod_Ud_Nagr"
Option Explicit
Option Base 1
Dim ud(Numb_of_cheh, 25) As String
Dim udeln1() As String
Dim udeln(Numb_of_cheh + 1) As String
Public Sub vvod_Ud_N_Frm()
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''     Открывает файл с удельными нагрузками и считывает оттуда значения       '''
''' и заполняет массив с удельными нагрузками и список городов формы zd_dan_Frm '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Dim i_ud_frm As Integer 'Для внутреннего цикла
Dim j_ud_frm As Integer 'Для внутреннего цикла
Open f_path_macros & f_ud_n_name For Input As #1
i_ud_frm = 1
    Do While Not EOF(1)
        Line Input #1, udeln(i_ud_frm)
        i_ud_frm = i_ud_frm + 1
    Loop
    Close #1
For i_ud_frm = 1 To Numb_of_cheh
    udeln1 = Split(udeln(i_ud_frm + 1), ";")
    For j_ud_frm = 1 To Val(udeln1(0)) * 3 + 3
        ud(i_ud_frm, j_ud_frm) = udeln1(j_ud_frm - 1)
    Next j_ud_frm
    zd_dan_Frm.udelnie_CmbBx.AddItem ud(i_ud_frm, 2)
Next i_ud_frm
zd_dan_Frm.udelnie_CmbBx.AddItem "Другое..."
End Sub
Public Sub vvod_Ud_N(i_ud_n As Integer)
Dim i_ud As Integer 'Для внутреннего цикла
Dim j_ud As Integer 'Для внутреннего цикла
txt_from_spisok = False
For i_ud = 1 To Numb_of_cheh
    If zd_dan_Frm.udelnie_CmbBx.Text = ud(i_ud, 2) Then
        txt_from_spisok = True
        For j_ud = 3 To Val(ud(i_ud, 1)) + 3
            If ((a(i_ud_n) * b(i_ud_n) * h(i_ud_n) / 1000) >= Val(ud(i_ud, j_ud))) _
                        And ((a(i_ud_n) * b(i_ud_n) * h(i_ud_n) / 1000) < Val(ud(i_ud, j_ud + 1))) Then
                q(i_ud_n, 1) = q_ot_S_c_N(Str_conv_SngNmb(ud(i_ud, ud(i_ud, 1) + j_ud + 1)))
                q(i_ud_n, 2) = q_v_S_c_N(Str_conv_SngNmb(ud(i_ud, ud(i_ud, 1) * 2 + j_ud + 1)))
            End If
        Next j_ud
        If (a(i_ud_n) * b(i_ud_n) * h(i_ud_n) / 1000) >= Val(ud(i_ud, ud(i_ud, 1) + 3)) Then
            q(i_ud_n, 1) = q_ot_S_c_N(Str_conv_SngNmb(ud(i_ud, ud(i_ud, 1) * 2 + 3)))
            q(i_ud_n, 2) = q_v_S_c_N(Str_conv_SngNmb(ud(i_ud, ud(i_ud, 1) * 3 + 3)))
        End If
        If (a(i_ud_n) * b(i_ud_n) * h(i_ud_n) / 1000) < Val(ud(i_ud, 3)) Then
            q(i_ud_n, 1) = q_ot_S_c_N(Str_conv_SngNmb(ud(i_ud, ud(i_ud, 1) + 4)))
            q(i_ud_n, 2) = q_v_S_c_N(Str_conv_SngNmb(ud(i_ud, ud(i_ud, 1) * 2 + 4)))
        End If
    End If
Next i_ud
If zd_dan_Frm.udelnie_CmbBx.Text = "Другое..." Then
    txt_from_spisok = True
    q(i_ud_n, 1) = q_ot_S_c_N(Str_conv_SngNmb(zd_dan_Frm.qoTxtBx.Text))
    q(i_ud_n, 2) = q_v_S_c_N(Str_conv_SngNmb(zd_dan_Frm.qbTxtBx.Text))
End If
End Sub


Public Function q_ot_S_c_N(virazenie)
If zd_dan_Frm.ot_ChkBx.Value = False Then q_ot_S_c_N = virazenie _
        Else: q_ot_S_c_N = 0
End Function
Public Function q_v_S_c_N(virazenie)
If zd_dan_Frm.vent_ChkBx.Value = False Then q_v_S_c_N = virazenie _
        Else: q_v_S_c_N = 0
End Function




