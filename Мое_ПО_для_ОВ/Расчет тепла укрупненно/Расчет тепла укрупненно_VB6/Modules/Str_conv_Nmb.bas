Attribute VB_Name = "Str_conv_Nmb"
Public Function Str_conv_SngNmb(Strng As String)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''             Возвращает число не зависимо от того введено оно через "," или "."             '''
''' если число введено через ",", то функцией CSng после запятой оно округляется до 3-х знаков '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    If InStr(1, Strng, ",", vbTextCompare) <> 0 Then
        Str_conv_SngNmb = CSng(Strng)
    Else: Str_conv_SngNmb = Val(Strng)
    End If
End Function


