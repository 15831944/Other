Attribute VB_Name = "Str_conv_Nmb"
Public Function Str_conv_SngNmb(Strng As String)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''             ���������� ����� �� �������� �� ���� ������� ��� ����� "," ��� "."             '''
''' ���� ����� ������� ����� ",", �� �������� CSng ����� ������� ��� ����������� �� 3-� ������ '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    If InStr(1, Strng, ",", vbTextCompare) <> 0 Then
        Str_conv_SngNmb = CSng(Strng)
    Else: Str_conv_SngNmb = Val(Strng)
    End If
End Function


