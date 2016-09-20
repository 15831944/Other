Attribute VB_Name = "Tabls_function"
Public Sub cells_merge_and_text_paste _
                (Tbl As Table, row_number, column_number, Optional MR_count = 0, Optional MD_count = 0, Optional Text = Empty)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''                         ����������� ������ ������ �������                                              '''
'''                       � ��������� ����� � ���������� ������                                            '''
''' ��������:                                                                                              '''
''' cells_merge_and_text_paste Tbl:= ___, row_number:=2, column_number:=2, [MR_count:=0], [MD_count:=0], _ '''
'''                             [Text:=Empty]                                                              '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Tbl.Cell(row_number, column_number).Select
    Selection.MoveRight Unit:=wdCharacter, Count:=MR_count, Extend:=wdExtend
'^^^�������� ������ ������ �� MR_count ����^^^
    Selection.MoveDown Unit:=wdLine, Count:=MD_count, Extend:=wdExtend
'^^^�������� ������ ������ �� MD_count ����^^^
    If MD_count <> 0 Or MR_count <> 0 Then Selection.Cells.Merge '���������� ���������� ������
    Selection.TypeText Text:=Text '��������� ����� � ���������� ������
End Sub
Public Sub cells_read_text(peremen_for_read, row_number, column_number, Optional numb_of_tbl = 1)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''          ������ ����� �� ��������� ������ ��������� ������� ��������� ���������      '''
''' ��������:                                                                            '''
''' cells_read_text peremen_for_read, row_number:=1, column_number:=1, [numb_of_tbl = 1] '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    ActiveDocument.Tables(numb_of_tbl).Cell(row_number, column_number).Select
'^^^�������� ������ (row_number, column_number)^^^
    Selection.MoveRight Unit:=wdCharacter, Count:=0, Extend:=wdExtend
'^^^�������� ��� ������ ���������^^^
    If IsNumeric(peremen_for_read) Then
        peremen_for_read = Str_conv_SngNmb(Left(Selection.Text, Len(Selection.Text) - 2))
    Else: peremen_for_read = Left(Selection.Text, Len(Selection.Text) - 2)
    End If
'^^^����������� peremen_for_read ��������, ��� ���� ���� peremen_for_read-�������� ����������
''''�� ��� �������� ����� ������������� � �����
End Sub


