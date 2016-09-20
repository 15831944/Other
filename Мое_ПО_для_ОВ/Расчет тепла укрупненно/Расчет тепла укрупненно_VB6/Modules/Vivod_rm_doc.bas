Attribute VB_Name = "Vivod_rm_doc"
Dim i As Integer
Dim save_dialog_variable As Integer

Public Sub Save_RM()
'''''''''''''''''''''''''''''''''''''''''''''''''''
''' Главная процедура вывода подробного расчета '''
'''''''''''''''''''''''''''''''''''''''''''''''''''
Application.ScreenUpdating = False
newdoc f_name_rm
Vivod_cl
For i = 1 To x
    Vivod_ot_zd
    Vivod_vnt_zd
Next i
vivod_literat
Application.ScreenUpdating = True
    With Dialogs(wdDialogFileSaveAs)
        save_dialog_variable = .Show
    End With
If save_dialog_variable <> -1 Then
    Documents(f_name_rm).Close wdDoNotSaveChanges
Else
    f_name_rm = ActiveDocument.Name
End If
End Sub
Sub Vivod_cl()
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Функция вывода исходных данных по району строительства в документ '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'------------------------------------------
'-           ИСХОДНЫЕ ДАННЫЕ              -
'------------------------------------------
'Ввод заголовка
    Selection.Font.Size = 14
    Selection.Font.Bold = wdToggle
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:= _
        "Расчет расходов тепла на отопление и вентиляцию по укрупненным показателям."
'Ввод второй строки
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=vbTab & _
        "Исходные данные для расчета, общие для всех зданий (зависящие от района строительства):"
'Задается формат списка
    Selection.TypeParagraph
    Selection.Font.Bold = wdToggle
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=vbTab
    With ListGalleries(wdBulletGallery).ListTemplates(7).ListLevels(1)
        .NumberFormat = ChrW(61692)
        .TrailingCharacter = wdTrailingTab
        .NumberStyle = wdListNumberStyleBullet
        .NumberPosition = CentimetersToPoints(0.2)
        .Alignment = wdListLevelAlignLeft
        .TextPosition = CentimetersToPoints(1)
        .TabPosition = CentimetersToPoints(1)
        .ResetOnHigher = 0
        .StartAt = 1
        With .Font
            .Bold = wdUndefined
            .Italic = wdUndefined
            .Strikethrough = wdUndefined
            .Subscript = wdUndefined
            .Superscript = wdUndefined
            .Shadow = wdUndefined
            .Outline = wdUndefined
            .Emboss = wdUndefined
            .Engrave = wdUndefined
            .AllCaps = wdUndefined
            .Hidden = wdUndefined
            .Underline = wdUndefined
            .Color = wdUndefined
            .Size = wdUndefined
            .Animation = wdUndefined
            .DoubleStrikeThrough = wdUndefined
            .Name = "Wingdings"
        End With
        .LinkedStyle = ""
    End With
'Выводится текст в список
'Выводится tn1
    ListGalleries(wdBulletGallery).ListTemplates(7).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
            wdBulletGallery).ListTemplates(7), ContinuePreviousList:=False, ApplyTo:= _
            wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:="Температура наружного воздуха наиболее холодной пятидневки [2], tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = "
            Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(tn1, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С;"
    Selection.Font.Italic = wdToggle
'Выводится tn2
    Selection.TypeParagraph
                Selection.TypeText Text:= _
                    "Средняя месячная температура наиболее холодного месяца года [2], tн2"
                Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                Selection.MoveRight Unit:=wdCharacter, Count:=1
                Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                Selection.Font.Subscript = wdToggle
                Selection.MoveRight Unit:=wdCharacter, Count:=1
                Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(tn2, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С;"
            Selection.Font.Italic = wdToggle
'Выводится tn3
    Selection.TypeParagraph
            Selection.TypeText Text:= _
                "Средняя температура воздуха, отопительного периода [2], tн3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = "
            Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(tn3, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С;"
            Selection.Font.Italic = wdToggle
'Выводится n_ot_per
    Selection.TypeParagraph
            Selection.TypeText Text:= _
                "Продолжительность отопительного периода [2], n = "
            Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(n_ot_per, False) & " сут;"
            Selection.Font.Italic = wdToggle
'Выводится k_vih_pr_dn
    Selection.TypeParagraph
            Selection.TypeText Text:= _
                "Сумма воскресных и праздничных дней [2], k = "
            Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(k_vih_pr_dn, False) & " сут."
            Selection.Font.Italic = wdToggle
End Sub
Sub Vivod_ot_zd()
'Функция вывода исходных данных по зданиям в документ
'
'Ввод заголовка
    Selection.InsertBreak Type:=wdPageBreak
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.Font.Bold = wdToggle
    Selection.Font.Italic = wdToggle
            If Selection.Font.Underline = wdUnderlineNone Then
                Selection.Font.Underline = wdUnderlineSingle
            Else
                Selection.Font.Underline = wdUnderlineNone
            End If
    Selection.TypeText Text:="Здание №"
                Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=txt(i)
                Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=" - " & Chr(34)
                    Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=n_zd(i) & " (тип здания - " & zd_type(i) & ")"
                Selection.Font.Bold = wdToggle
                Selection.TypeText Text:=Chr(34) & ":"
                        If Selection.Font.Underline = wdUnderlineNone Then
                            Selection.Font.Underline = wdUnderlineSingle
                        Else
                            Selection.Font.Underline = wdUnderlineNone
                        End If
    Selection.TypeParagraph
    Selection.TypeText Text:=vbTab & _
        "Исходные данные для расчета (по данному зданию):"
''''''Полный расчет''''''
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
'Вывод размеров здания
                    Selection.Font.Italic = wdToggle
            Selection.Font.Bold = wdToggle
            Selection.TypeParagraph
            Selection.TypeText Text:=vbTab
                    ListGalleries(wdBulletGallery).ListTemplates(7).Name = ""
                    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                    wdBulletGallery).ListTemplates(7), ContinuePreviousList:=False, ApplyTo:= _
                    wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
                    Selection.TypeText Text:="Размеры здания:"
                    Selection.TypeParagraph
'Вывод ширины
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.TypeText Text:=vbTab
                    With ListGalleries(wdBulletGallery).ListTemplates(6).ListLevels(1)
                        .NumberFormat = ChrW(61485)
                        .TrailingCharacter = wdTrailingTab
                        .NumberStyle = wdListNumberStyleBullet
                        .NumberPosition = CentimetersToPoints(0.2)
                        .Alignment = wdListLevelAlignLeft
                        .TextPosition = CentimetersToPoints(0.7)
                        .TabPosition = CentimetersToPoints(0.7)
                        .ResetOnHigher = 0
                        .StartAt = 1
                        With .Font
                            .Bold = wdUndefined
                            .Italic = wdUndefined
                            .Strikethrough = wdUndefined
                            .Subscript = wdUndefined
                            .Superscript = wdUndefined
                            .Shadow = wdUndefined
                            .Outline = wdUndefined
                            .Emboss = wdUndefined
                            .Engrave = wdUndefined
                            .AllCaps = wdUndefined
                            .Hidden = wdUndefined
                            .Underline = wdUndefined
                            .Color = wdUndefined
                            .Size = wdUndefined
                            .Animation = wdUndefined
                            .DoubleStrikeThrough = wdUndefined
                            .Name = "Symbol"
                        End With
                        .LinkedStyle = ""
                    End With
            ListGalleries(wdBulletGallery).ListTemplates(6).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdBulletGallery).ListTemplates(6), ContinuePreviousList:=False, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:="ширина, a = "
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=txt(a(i), False) & " м;"
                    Selection.Font.Italic = wdToggle
'Вывод длины
            Selection.TypeParagraph
            Selection.TypeText Text:="длина, b = "
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=txt(b(i), False) & " м;"
                    Selection.Font.Italic = wdToggle
'Вывод высоты
            Selection.TypeParagraph
            Selection.TypeText Text:="высота, h = "
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=txt(h(i), False) & " м."
                    Selection.Font.Italic = wdToggle
                    Selection.TypeParagraph

Else:
    Selection.Font.Italic = wdToggle
    Selection.Font.Bold = wdToggle
    Selection.TypeParagraph
    Selection.TypeText Text:=vbTab
                    ListGalleries(wdBulletGallery).ListTemplates(7).Name = ""
                    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                    wdBulletGallery).ListTemplates(7), ContinuePreviousList:=False, ApplyTo:= _
                    wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
End If
'Вывод m(i)
    Selection.Range.ListFormat.ListOutdent
    Selection.TypeText Text:="Количество часов работы в сутки, mc"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = "
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(m_hour_work_vent(i), False) & " часов;"
            Selection.Font.Italic = wdToggle
'Вывод tb
    Selection.TypeParagraph
    Selection.TypeText Text:="Температура внутреннего воздуха, tвн"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Subscript = wdToggle
        Selection.TypeText Text:=" = "
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(tb(i), False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С;"
    Selection.Font.Italic = wdToggle
'Вывод tpr
    Selection.TypeParagraph
    Selection.TypeText Text:="Температура приточного воздуха, tпр"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Subscript = wdToggle
        Selection.TypeText Text:=" = "
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(tpr(i), False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С;"
    Selection.Font.Italic = wdToggle
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then ''''''Полный расчет''''''
'Вывод q(..., 1)
            Selection.TypeParagraph
            Selection.TypeText Text:="Удельная отопительная характеристика здания при tр.о."
                Selection.MoveLeft Unit:=wdCharacter, Count:=4, Extend:=wdExtend
                Selection.Font.Subscript = wdToggle
                Selection.MoveRight Unit:=wdCharacter, Count:=1
                Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = -30 0"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.TypeText Text:="С, qо"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 1), False) & " ккал/м3"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                            True
                        Selection.TypeText Text:="ч;"
                Selection.Font.Italic = wdToggle
'Вывод q(..., 2)
                Selection.TypeParagraph
                Selection.TypeText Text:="Удельная тепловая характеристика здания для вентиляции, qв"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 2), False) & " ккал/м3"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                            True
                        Selection.TypeText Text:="ч;"
                Selection.Font.Italic = wdToggle
Else
'Вывод q(...,4)
            Selection.TypeParagraph
            Selection.TypeText Text:="Максимальный часовой расход тепла на отопление (при tн1"
                Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                Selection.Font.Subscript = wdToggle
                Selection.MoveRight Unit:=wdCharacter, Count:=1
                Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.TypeText Text:=txt(tn1, False) & " 0"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.TypeText Text:="С), Qот"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                        Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=txt(tn1, False)
                Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 4), False) & " ккал/ч;"
                Selection.Font.Italic = wdToggle
'Вывод q(...,5)
                Selection.TypeParagraph
                Selection.TypeText Text:="Максимальный часовой расход тепла на вентиляцию (при tн1"
                Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                Selection.Font.Subscript = wdToggle
                Selection.MoveRight Unit:=wdCharacter, Count:=1
                Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.TypeText Text:=txt(tn1, False) & " 0"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.TypeText Text:="С), Qв"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                            Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=txt(tn1, False)
                Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 5), False) & " ккал/ч;"
                Selection.Font.Italic = wdToggle
End If
'Вывод воздушной завесы
'Вывод кол-ва тепла воздушной завесы
    If z_y_n(i) = True Then
            Selection.TypeParagraph
                    Selection.TypeText Text:="Расход тепла на воздушную завесу, Qвз"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=txt(q(i, 3), False) & " Гкал/м3"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Superscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:="ч;"
            Selection.Font.Italic = wdToggle
'Вывод кол-ва часов работы воздушной завесы
                Selection.TypeParagraph
                Selection.TypeText Text:= _
                    "Количество часов работы завесы в сутки, z = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(z(i), False)
                Select Case z(i)
                    Case 1, 21
                        Selection.TypeText Text:=" час;"
                    Case 2 To 4, 22 To 24
                        Selection.TypeText Text:=" часа;"
                    Case 5 To 20
                        Selection.TypeText Text:=" часов;"
                End Select
                Selection.Font.Italic = wdToggle
    Else: Selection.TypeParagraph
        Selection.TypeText Text:="Воздушной завесы нет;"
    End If
'Вывод дежурного отопления
'Вывод кол-ва часов работы дежурного отопления
    If do_y_n(i) = True Then
            Selection.TypeParagraph
                    Selection.TypeText Text:="Температура дежурного отопления tдеж"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=3, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=txt(td(i), False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С."
                    Selection.Font.Italic = wdToggle
    Else: Selection.TypeParagraph
        Selection.TypeText Text:="Дежурного отопления нет (т.е. отопление круглосуточно работает в основном режиме)."
    End If
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.TypeParagraph
    Selection.Font.Bold = wdToggle
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:="Расчет:"
    Selection.Font.Bold = wdToggle
    Selection.TypeParagraph
'''''''''''''''''''''''''''''''
''''''''''''Условие''''''''''''
'''''''''''''''''''''''''''''''
'Вывод формулы объема
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
            Selection.TypeText Text:=vbTab
            Selection.TypeText Text:="V = a "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" b "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" h = " & txt(a(i)) & " "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" " & txt(b(i)) & " "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" " & txt(h(i)) & " = " & txt(a(i) * b(i) * h(i), False) _
                & " м3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=" - объем здания по наружному обмеру."


'''''''''''''''''''''''''''''''''''''''''''
'              ОТОПЛЕНИЕ                  '
'''''''''''''''''''''''''''''''''''''''''''
' Вывод пункта №1 расчета
            Selection.TypeParagraph
            Selection.Font.Italic = wdToggle
            With ListGalleries(wdNumberGallery).ListTemplates(1).ListLevels(1)
                .NumberFormat = "%1."
                .TrailingCharacter = wdTrailingTab
                .NumberStyle = wdListNumberStyleArabic
                .NumberPosition = CentimetersToPoints(0.63)
                .Alignment = wdListLevelAlignLeft
                .TextPosition = CentimetersToPoints(1.27)
                .TabPosition = CentimetersToPoints(1.27)
                .ResetOnHigher = 0
                .StartAt = 1
                With .Font
                    .Bold = wdUndefined
                    .Italic = wdUndefined
                    .Strikethrough = wdUndefined
                    .Subscript = wdUndefined
                    .Superscript = wdUndefined
                    .Shadow = wdUndefined
                    .Outline = wdUndefined
                    .Emboss = wdUndefined
                    .Engrave = wdUndefined
                    .AllCaps = wdUndefined
                    .Hidden = wdUndefined
                    .Underline = wdUndefined
                    .Color = wdUndefined
                    .Size = wdUndefined
                    .Animation = wdUndefined
                    .DoubleStrikeThrough = wdUndefined
                    .Name = ""
                End With
                .LinkedStyle = ""
            End With
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=False, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Максимальный часовой расход тепла на отопление (при температуре наружного воздуха tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№1
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн1"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" V "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" qо"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:="tвн"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" - tн1"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=")/1000000, ккал/ч;"
            Selection.TypeParagraph
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=txt(tn1, False)
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = " & txt(alfa(tn1))
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.TypeText Text:=txt(a(i) * b(i) * h(i))
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.TypeText Text:=txt(q(i, 1), False)
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:=txt(tb(i), False)
                    Selection.TypeText Text:=" - "
                    Selection.TypeText Text:=txt(tn1)
                    Selection.TypeText Text:=")/1000000 = "
                    Selection.TypeText Text:=txt(q(i, 4), False)
                    Selection.TypeText Text:=" ккал/ч"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=", где"
                    Selection.TypeParagraph
                    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
                    Selection.TypeText Text:=vbTab
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:= _
                            " = " & txt(alfa(tn1)) & _
                            " поправочный коэффициент, учитывающий изменение расчетной наружной температуры [1, табл.2.1]."
' Вывод пункта №2 расчета
            Selection.TypeParagraph
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Средний часовой расход тепла на отопление за наиболее холодный месяц (январь) (при температуре наружного воздуха tн2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№2
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн2"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" V "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" qо"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:="tвн"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" - tн2"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=")/1000000, ккал/ч;"
            Selection.TypeParagraph
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=txt(tn2, False)
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = " & txt(alfa(tn2))
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.TypeText Text:=txt(a(i) * b(i) * h(i))
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.TypeText Text:=txt(q(i, 1), False)
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:=txt(tb(i), False)
                    Selection.TypeText Text:=" - "
                    Selection.TypeText Text:=txt(tn2)
                    Selection.TypeText Text:=")/1000000 = "
                    Selection.TypeText Text:=txt(q(i, 7), False)
                    Selection.TypeText Text:=" ккал/ч"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=", где"
                    Selection.TypeParagraph
                    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
                    Selection.TypeText Text:=vbTab
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:= _
                            " = " & txt(alfa(tn2)) & _
                            " поправочный коэффициент, учитывающий изменение расчетной наружной температуры [1, табл.2.1]."
' Вывод пункта №3 расчета
            Selection.TypeParagraph
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Средний часовой расход тепла на отопление за отопительный период (при температуре наружного воздуха tн3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№3
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн3"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" V "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" qо"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:="tвн"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" - tн3"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=")/1000000, ккал/ч;"
            Selection.TypeParagraph
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=txt(tn3, False)
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = " & txt(alfa(tn3))
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.TypeText Text:=txt(a(i) * b(i) * h(i))
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" "
                    Selection.TypeText Text:=txt(q(i, 1), False)
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:=txt(tb(i), False)
                    Selection.TypeText Text:=" - "
                    Selection.TypeText Text:=txt(tn3)
                    Selection.TypeText Text:=")/1000000 = "
                    Selection.TypeText Text:=txt(q(i, 10), False)
                    Selection.TypeText Text:=" ккал/ч"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=", где"
                    Selection.TypeParagraph
                    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
                    Selection.TypeText Text:=vbTab
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:= _
                            " = " & txt(alfa(tn3)) & _
                            " поправочный коэффициент, учитывающий изменение расчетной наружной температуры [1, табл.2.1]."
Else   ''''Короткий расчет''''
' Вывод пункта №1 расчета
            Selection.TypeParagraph
            With ListGalleries(wdNumberGallery).ListTemplates(1).ListLevels(1)
                .NumberFormat = "%1."
                .TrailingCharacter = wdTrailingTab
                .NumberStyle = wdListNumberStyleArabic
                .NumberPosition = CentimetersToPoints(0.63)
                .Alignment = wdListLevelAlignLeft
                .TextPosition = CentimetersToPoints(1.27)
                .TabPosition = CentimetersToPoints(1.27)
                .ResetOnHigher = 0
                .StartAt = 1
                With .Font
                    .Bold = wdUndefined
                    .Italic = wdUndefined
                    .Strikethrough = wdUndefined
                    .Subscript = wdUndefined
                    .Superscript = wdUndefined
                    .Shadow = wdUndefined
                    .Outline = wdUndefined
                    .Emboss = wdUndefined
                    .Engrave = wdUndefined
                    .AllCaps = wdUndefined
                    .Hidden = wdUndefined
                    .Underline = wdUndefined
                    .Color = wdUndefined
                    .Size = wdUndefined
                    .Animation = wdUndefined
                    .DoubleStrikeThrough = wdUndefined
                    .Name = ""
                End With
                .LinkedStyle = ""
            End With
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=False, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Максимальный часовой расход тепла на отопление (при температуре наружного воздуха tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№1
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн1"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=txt(tn1, False)
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = " & txt(q(i, 4))
                    Selection.TypeText Text:=" ккал/ч"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=" (исходные данные)."
' Вывод пункта №2 расчета
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Средний часовой расход тепла на отопление за наиболее холодный месяц (январь) (при температуре наружного воздуха tн2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№2
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн2"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Qот"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="tн1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (tвн"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (tвн"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ккал/ч;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Qот"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=txt(tn2, False)
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" = " & txt(q(i, 4))
                            Selection.TypeText Text:=" "
                            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                                True
                            Selection.TypeText Text:=" ("
                            Selection.TypeText Text:=txt(tb(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn2)
                            Selection.TypeText Text:=") / ("
                            Selection.TypeText Text:=txt(tb(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn1)
                            Selection.TypeText Text:=") = "
                            Selection.TypeText Text:=txt(q(i, 7), False)
                            Selection.TypeText Text:=" ккал/ч."
' Вывод пункта №3 расчета
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Средний часовой расход тепла на отопление за отопительный период (при температуре наружного воздуха tн3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№3
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qот"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн3"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Qот"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="tн1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (tвн"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (tвн"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ккал/ч;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Qот"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=txt(tn3, False)
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" = " & txt(q(i, 4))
                            Selection.TypeText Text:=" "
                            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                                True
                            Selection.TypeText Text:=" ("
                            Selection.TypeText Text:=txt(tb(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn3)
                            Selection.TypeText Text:=") / ("
                            Selection.TypeText Text:=txt(tb(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn1)
                            Selection.TypeText Text:=") = "
                            Selection.TypeText Text:=txt(q(i, 10), False)
                            Selection.TypeText Text:=" ккал/ч."
                            Selection.Font.Italic = wdToggle
End If
' Вывод пункта №4 расчета
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    Selection.Font.Italic = wdToggle
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "Годовой расход тепла на отопление за отопительный период:"
' Вывод формулы в п.№4
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Qот"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
If do_y_n(i) = True Then
'Если есть дежурное отопление
    Selection.TypeText Text:="[Qот"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="tн1"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" ((n - k) "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:="mс"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (tвн"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - tн3"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=") + (n - k) "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (24 - mс"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=") "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (tдеж"
    Selection.MoveLeft Unit:=wdCharacter, Count:=3, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - tн3"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=") + k "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" 24 "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (tдеж"
    Selection.MoveLeft Unit:=wdCharacter, Count:=3, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - tн3"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="))] /  "
    Selection.TypeText Text:=" (tвн"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - tн1"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=") ,Гкал/год;"
    'С числами
    Selection.TypeParagraph
    Selection.TypeText Text:="Qот"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = ["
    Selection.TypeText Text:=txt(q(i, 4)) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" ((" & txt(n_ot_per, False) & " - " & txt(k_vih_pr_dn, False) & ") "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=txt(m_hour_work_ot(i)) & " "
                Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:= _
        " (" & txt(tb(i)) & " - " & txt(tn3) & ") + (" & txt(n_ot_per) & " - " & txt(k_vih_pr_dn, False) & ") "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (24 - " & txt(m_hour_work_ot(i)) & ") "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:= _
        " (" & txt(td(i)) & " - " & txt(tn3) & ") + " & txt(k_vih_pr_dn) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" 24 "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:= _
        " (" & txt(td(i)) & " - " & txt(tn3) & "))] / (" & txt(tb(i)) & " - " & txt(tn1) & ") = " & txt(q(i, 13)) & " Гкал/год."
    Else
'Если нет дежурного отопления
    Selection.TypeText Text:="Qот"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="tн3"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" n "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" mс"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=", Гкал/год;"
'С числами
    Selection.TypeParagraph
    Selection.TypeText Text:="Qот"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 10)) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=txt(n_ot_per, False) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=txt(m_hour_work_ot(i)) & " = "
    Selection.TypeText Text:=txt(q(i, 13)) & " Гкал/год."
End If
End Sub
Sub Vivod_vnt_zd()
'''''''''''''''''''''''''''''''''''''''''''
'             ВЕНТИЛЯЦИЯ                  '
'''''''''''''''''''''''''''''''''''''''''''
'-----------------------------------------'
'-----------------------------------------'
'''''''''''''''''''''''''''''''
''''''''''''Условие''''''''''''
'''''''''''''''''''''''''''''''
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then   ''''''Полный расчет''''''
' Вывод пункта №5 расчета
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "Максимальный часовой расход тепла на вентиляцию (при температуре наружного воздуха tн1"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="С):"
' Вывод формулы в п.№5
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="tн1"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = V "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" qв"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (tпр"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/1000000, ккал/ч;"
    Selection.TypeParagraph
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=txt(tn1, False)
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = " & txt(a(i) * b(i) * h(i))
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" "
            Selection.TypeText Text:=txt(q(i, 2), False)
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" ("
            Selection.TypeText Text:=txt(tpr(i), False)
            Selection.TypeText Text:=" - "
            Selection.TypeText Text:=txt(tn1)
            Selection.TypeText Text:=")/1000000 = "
            Selection.TypeText Text:=txt(q(i, 5), False)
            Selection.TypeText Text:=" ккал/ч."
' Вывод пункта №6 расчета
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "Средний часовой расход тепла на вентиляцию за наиболее холодный месяц (январь) (при температуре наружного воздуха tн2"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="С):"
' Вывод формулы в п.№6
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="tн2"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = V "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" qв"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (tпр"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/1000000, ккал/ч;"
    Selection.TypeParagraph
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=txt(tn2, False)
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = " & txt(a(i) * b(i) * h(i))
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" "
            Selection.TypeText Text:=txt(q(i, 2), False)
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" ("
            Selection.TypeText Text:=txt(tpr(i), False)
            Selection.TypeText Text:=" - "
            Selection.TypeText Text:=txt(tn2)
            Selection.TypeText Text:=")/1000000 = "
            Selection.TypeText Text:=txt(q(i, 8), False)
            Selection.TypeText Text:=" ккал/ч."
' Вывод пункта №7 расчета
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "Средний часовой расход тепла на вентиляцию за отопительный период (при температуре наружного воздуха tн3"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="С):"
' Вывод формулы в п.№7
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="tн3"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = V "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" qв"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (tпр"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/1000000, ккал/ч;"
    Selection.TypeParagraph
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=txt(tn3, False)
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = " & txt(a(i) * b(i) * h(i))
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" "
            Selection.TypeText Text:=txt(q(i, 2), False)
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" ("
            Selection.TypeText Text:=txt(tpr(i), False)
            Selection.TypeText Text:=" - "
            Selection.TypeText Text:=txt(tn3)
            Selection.TypeText Text:=")/1000000 = "
            Selection.TypeText Text:=txt(q(i, 11), False)
            Selection.TypeText Text:=" ккал/ч."
Else  ''''Короткий расчет''''
' Вывод пункта №5 расчета
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "Максимальный часовой расход тепла на вентиляцию (при температуре наружного воздуха tн1"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="С):"
' Вывод формулы в п.№5
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qв"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн1"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
            Selection.TypeText Text:="Qв"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=txt(tn1, False)
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = " & txt(q(i, 5))
                    Selection.TypeText Text:=" ккал/ч"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=" (исходные данные)."
' Вывод пункта №6 расчета
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Средний часовой расход тепла на вентиляцию за наиболее холодный месяц (январь) (при температуре наружного воздуха tн2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№6
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qв"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн2"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Qв"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="tн1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (tпр"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (tвн"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ккал/ч;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Qв"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=txt(tn2, False)
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" = " & txt(q(i, 5))
                            Selection.TypeText Text:=" "
                            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                                True
                            Selection.TypeText Text:=" ("
                            Selection.TypeText Text:=txt(tpr(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn2)
                            Selection.TypeText Text:=") / ("
                            Selection.TypeText Text:=txt(tpr(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn1)
                            Selection.TypeText Text:=") = "
                            Selection.TypeText Text:=txt(q(i, 8), False)
                            Selection.TypeText Text:=" ккал/ч."
' Вывод пункта №7 расчета
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "Средний часовой расход тепла на вентиляцию за отопительный период (при температуре наружного воздуха tн3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="С):"
' Вывод формулы в п.№7
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Qв"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="tн3"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Qв"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="tн1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (tпр"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (tвн"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - tн1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ккал/ч;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Qв"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=txt(tn3, False)
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" = " & txt(q(i, 5))
                            Selection.TypeText Text:=" "
                            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                                True
                            Selection.TypeText Text:=" ("
                            Selection.TypeText Text:=txt(tpr(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn3)
                            Selection.TypeText Text:=") / ("
                            Selection.TypeText Text:=txt(tpr(i), False)
                            Selection.TypeText Text:=" - "
                            Selection.TypeText Text:=txt(tn1)
                            Selection.TypeText Text:=") = "
                            Selection.TypeText Text:=txt(q(i, 11), False)
                            Selection.TypeText Text:=" ккал/ч."
End If
' Вывод пункта №8 расчета
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "Годовой расход тепла на вентиляцию за отопительный период:"
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="tн3"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (n - k) "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" mс"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=", Гкал/год;"
'С числами
    Selection.TypeParagraph
    Selection.TypeText Text:="Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 11)) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (" & txt(n_ot_per, False) & " - " & txt(k_vih_pr_dn) & ") "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=txt(m_hour_work_vent(i)) & " = "
    Selection.TypeText Text:=txt(q(i, 14)) & " Гкал/год."
' Вывод пункта №9 расчета
If z_y_n(i) = True Then
        Selection.TypeParagraph
        Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
        ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
        Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
            wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
            wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
        Selection.TypeText Text:= _
            "Годовой расход тепла на воздушную завесу:"
        Selection.TypeParagraph
        Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
        Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
        Selection.TypeText Text:="Qвз"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Superscript = wdToggle
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:="год"
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:=" = "
        Selection.TypeText Text:="Qвз"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:=" "
        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
            True
        Selection.TypeText Text:=" (n - k) "
        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
            True
        Selection.TypeText Text:=" z, Гкал/год;"
    'С числами
        Selection.TypeParagraph
        Selection.TypeText Text:="Qвз"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Superscript = wdToggle
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:="год"
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:=" = "
        Selection.TypeText Text:=txt(q(i, 3)) & " "
        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
            True
        Selection.TypeText Text:=" (" & txt(n_ot_per, False) & " - " & txt(k_vih_pr_dn) & ") "
        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
            True
        Selection.TypeText Text:=" "
        Selection.TypeText Text:=txt(z(i)) & " = "
        Selection.TypeText Text:=txt(q(i, 15)) & " Гкал/год."
    Else: Selection.TypeParagraph
        Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
        ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
        Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
            wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
            wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
        Selection.TypeText Text _
            :="Воздушной завесы нет, поэтому Qвз"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Superscript = wdToggle
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:="год"
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:=" =0."
    End If
' Вывод пункта №10 расчета
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "Суммарный годовой расход тепла за отопительный период:"
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Q"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = Qот"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" + Qв"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" + Qвз"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=", Гкал/год;"
'С числами
    Selection.TypeParagraph
    Selection.TypeText Text:="Q"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="год"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 13))
    Selection.TypeText Text:=" + "
    Selection.TypeText Text:=txt(q(i, 14))
    Selection.TypeText Text:=" + "
    Selection.TypeText Text:=txt(q(i, 15))
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 16))
    Selection.TypeText Text:=" Гкал/год."
'Возвращает все настройки исходным параметрам
    Selection.Font.Italic = wdToggle
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
End Sub
Public Sub vivod_literat()
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Процедура вывода списка используемой литературы подробного расчета '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'Вывод заголовка
    Selection.InsertBreak Type:=wdPageBreak
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    Selection.Font.Italic = wdToggle
    Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=vbTab & _
        "Нормативные документы, используемые при расчете:"
    Selection.Font.Italic = wdToggle
    Selection.Font.Bold = wdToggle
    Selection.TypeParagraph
ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
    wdNumberGallery).ListTemplates(1), ContinuePreviousList:=False, ApplyTo:= _
    wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
Selection.TypeText Text:=Chr(34) & "Методические указания по определению " & _
    "расходов топлива, электроэнергии и воды на выработку тепла отопительными котельными " & _
    "коммунальных теплоэнергетических предприятий" & Chr(34) & _
    ". М., АКХ им. Памфилова, 1994;"
Selection.TypeParagraph
Selection.TypeText Text:="СНиП 23-01-99. Строительная климатология и геофизика. М.," & _
    "Стройиздат, 1983;"
Selection.TypeParagraph
Selection.TypeText Text:="СНиП 2.04-05-91. Отопление, вентиляция и кондиционирование " & _
    "воздуха. Нормы проектирования. М., ЦТНИ, 1992."
Selection.TypeParagraph
Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
Selection.TypeParagraph
End Sub


Public Function txt(perem As Variant, Optional x As Boolean = True)
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''                  Функция форматирования числового значения в текст                        '''
'''                   с представлением десятичной части через запятую                         '''
'''                     и  округлением до 3-х знаков после запятой                            '''
''' если переменная по умолчанию x=false тогда текст если число отрицательно заключается в () '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
If x = True Then
        If perem >= 0 Then
            txt = Trim(Format(Round(perem, 3)))
        Else: txt = "(" & Trim(Format(Round(perem, 3))) & ")"
        End If
Else: txt = Trim(Format(Round(perem, 3)))
End If
End Function



