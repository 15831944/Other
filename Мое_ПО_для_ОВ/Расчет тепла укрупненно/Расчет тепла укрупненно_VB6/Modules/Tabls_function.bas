Attribute VB_Name = "Tabls_function"
Public Sub cells_merge_and_text_paste _
                (Tbl As Table, row_number, column_number, Optional MR_count = 0, Optional MD_count = 0, Optional Text = Empty)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''                         Объеденияет нужные ячейки таблицы                                              '''
'''                       и вставляет текст в полученную ячейку                                            '''
''' Вызывать:                                                                                              '''
''' cells_merge_and_text_paste Tbl:= ___, row_number:=2, column_number:=2, [MR_count:=0], [MD_count:=0], _ '''
'''                             [Text:=Empty]                                                              '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Tbl.Cell(row_number, column_number).Select
    Selection.MoveRight Unit:=wdCharacter, Count:=MR_count, Extend:=wdExtend
'^^^Выделяет ячейки вправо на MR_count штук^^^
    Selection.MoveDown Unit:=wdLine, Count:=MD_count, Extend:=wdExtend
'^^^Выделяет ячейки вправо на MD_count штук^^^
    If MD_count <> 0 Or MR_count <> 0 Then Selection.Cells.Merge 'Объеденяет выделенные ячейки
    Selection.TypeText Text:=Text 'Вставляет текст в полученную ячейку
End Sub
Public Sub cells_read_text(peremen_for_read, row_number, column_number, Optional numb_of_tbl = 1)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''          Читает текст из указанной ячейки указанной таблицы активного документа      '''
''' Вызывать:                                                                            '''
''' cells_read_text peremen_for_read, row_number:=1, column_number:=1, [numb_of_tbl = 1] '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    ActiveDocument.Tables(numb_of_tbl).Cell(row_number, column_number).Select
'^^^Выбирает ячейку (row_number, column_number)^^^
    Selection.MoveRight Unit:=wdCharacter, Count:=0, Extend:=wdExtend
'^^^Выделяет эту ячейку полностью^^^
    If IsNumeric(peremen_for_read) Then
        peremen_for_read = Str_conv_SngNmb(Left(Selection.Text, Len(Selection.Text) - 2))
    Else: peremen_for_read = Left(Selection.Text, Len(Selection.Text) - 2)
    End If
'^^^Присваивает peremen_for_read значение, при этом если peremen_for_read-числовая переменная
''''то это значение сразу преобразуется в число
End Sub


