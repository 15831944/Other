Attribute VB_Name = "Vivod_rm_doc"
Dim i As Integer
Dim save_dialog_variable As Integer

Public Sub Save_RM()
'''''''''''''''''''''''''''''''''''''''''''''''''''
''' ������� ��������� ������ ���������� ������� '''
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
''' ������� ������ �������� ������ �� ������ ������������� � �������� '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'------------------------------------------
'-           �������� ������              -
'------------------------------------------
'���� ���������
    Selection.Font.Size = 14
    Selection.Font.Bold = wdToggle
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:= _
        "������ �������� ����� �� ��������� � ���������� �� ����������� �����������."
'���� ������ ������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=vbTab & _
        "�������� ������ ��� �������, ����� ��� ���� ������ (��������� �� ������ �������������):"
'�������� ������ ������
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
'��������� ����� � ������
'��������� tn1
    ListGalleries(wdBulletGallery).ListTemplates(7).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
            wdBulletGallery).ListTemplates(7), ContinuePreviousList:=False, ApplyTo:= _
            wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:="����������� ��������� ������� �������� �������� ���������� [2], t�1"
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
            Selection.TypeText Text:="�;"
    Selection.Font.Italic = wdToggle
'��������� tn2
    Selection.TypeParagraph
                Selection.TypeText Text:= _
                    "������� �������� ����������� �������� ��������� ������ ���� [2], t�2"
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
            Selection.TypeText Text:="�;"
            Selection.Font.Italic = wdToggle
'��������� tn3
    Selection.TypeParagraph
            Selection.TypeText Text:= _
                "������� ����������� �������, ������������� ������� [2], t�3"
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
            Selection.TypeText Text:="�;"
            Selection.Font.Italic = wdToggle
'��������� n_ot_per
    Selection.TypeParagraph
            Selection.TypeText Text:= _
                "����������������� ������������� ������� [2], n = "
            Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(n_ot_per, False) & " ���;"
            Selection.Font.Italic = wdToggle
'��������� k_vih_pr_dn
    Selection.TypeParagraph
            Selection.TypeText Text:= _
                "����� ���������� � ����������� ���� [2], k = "
            Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(k_vih_pr_dn, False) & " ���."
            Selection.Font.Italic = wdToggle
End Sub
Sub Vivod_ot_zd()
'������� ������ �������� ������ �� ������� � ��������
'
'���� ���������
    Selection.InsertBreak Type:=wdPageBreak
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.Font.Bold = wdToggle
    Selection.Font.Italic = wdToggle
            If Selection.Font.Underline = wdUnderlineNone Then
                Selection.Font.Underline = wdUnderlineSingle
            Else
                Selection.Font.Underline = wdUnderlineNone
            End If
    Selection.TypeText Text:="������ �"
                Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=txt(i)
                Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=" - " & Chr(34)
                    Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=n_zd(i) & " (��� ������ - " & zd_type(i) & ")"
                Selection.Font.Bold = wdToggle
                Selection.TypeText Text:=Chr(34) & ":"
                        If Selection.Font.Underline = wdUnderlineNone Then
                            Selection.Font.Underline = wdUnderlineSingle
                        Else
                            Selection.Font.Underline = wdUnderlineNone
                        End If
    Selection.TypeParagraph
    Selection.TypeText Text:=vbTab & _
        "�������� ������ ��� ������� (�� ������� ������):"
''''''������ ������''''''
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
'����� �������� ������
                    Selection.Font.Italic = wdToggle
            Selection.Font.Bold = wdToggle
            Selection.TypeParagraph
            Selection.TypeText Text:=vbTab
                    ListGalleries(wdBulletGallery).ListTemplates(7).Name = ""
                    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                    wdBulletGallery).ListTemplates(7), ContinuePreviousList:=False, ApplyTo:= _
                    wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
                    Selection.TypeText Text:="������� ������:"
                    Selection.TypeParagraph
'����� ������
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
            Selection.TypeText Text:="������, a = "
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=txt(a(i), False) & " �;"
                    Selection.Font.Italic = wdToggle
'����� �����
            Selection.TypeParagraph
            Selection.TypeText Text:="�����, b = "
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=txt(b(i), False) & " �;"
                    Selection.Font.Italic = wdToggle
'����� ������
            Selection.TypeParagraph
            Selection.TypeText Text:="������, h = "
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=txt(h(i), False) & " �."
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
'����� m(i)
    Selection.Range.ListFormat.ListOutdent
    Selection.TypeText Text:="���������� ����� ������ � �����, mc"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = "
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:=txt(m_hour_work_vent(i), False) & " �����;"
            Selection.Font.Italic = wdToggle
'����� tb
    Selection.TypeParagraph
    Selection.TypeText Text:="����������� ����������� �������, t��"
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
            Selection.TypeText Text:="�;"
    Selection.Font.Italic = wdToggle
'����� tpr
    Selection.TypeParagraph
    Selection.TypeText Text:="����������� ���������� �������, t��"
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
            Selection.TypeText Text:="�;"
    Selection.Font.Italic = wdToggle
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then ''''''������ ������''''''
'����� q(..., 1)
            Selection.TypeParagraph
            Selection.TypeText Text:="�������� ������������ �������������� ������ ��� t�.�."
                Selection.MoveLeft Unit:=wdCharacter, Count:=4, Extend:=wdExtend
                Selection.Font.Subscript = wdToggle
                Selection.MoveRight Unit:=wdCharacter, Count:=1
                Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = -30 0"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.TypeText Text:="�, q�"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 1), False) & " ����/�3"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                            True
                        Selection.TypeText Text:="�;"
                Selection.Font.Italic = wdToggle
'����� q(..., 2)
                Selection.TypeParagraph
                Selection.TypeText Text:="�������� �������� �������������� ������ ��� ����������, q�"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 2), False) & " ����/�3"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Superscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Superscript = wdToggle
                        Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                            True
                        Selection.TypeText Text:="�;"
                Selection.Font.Italic = wdToggle
Else
'����� q(...,4)
            Selection.TypeParagraph
            Selection.TypeText Text:="������������ ������� ������ ����� �� ��������� (��� t�1"
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
                        Selection.TypeText Text:="�), Q��"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                        Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=txt(tn1, False)
                Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 4), False) & " ����/�;"
                Selection.Font.Italic = wdToggle
'����� q(...,5)
                Selection.TypeParagraph
                Selection.TypeText Text:="������������ ������� ������ ����� �� ���������� (��� t�1"
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
                        Selection.TypeText Text:="�), Q�"
                        Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                        Selection.Font.Subscript = wdToggle
                        Selection.MoveRight Unit:=wdCharacter, Count:=1
                        Selection.Font.Subscript = wdToggle
                            Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=txt(tn1, False)
                Selection.Font.Superscript = wdToggle
                Selection.TypeText Text:=" = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(q(i, 5), False) & " ����/�;"
                Selection.Font.Italic = wdToggle
End If
'����� ��������� ������
'����� ���-�� ����� ��������� ������
    If z_y_n(i) = True Then
            Selection.TypeParagraph
                    Selection.TypeText Text:="������ ����� �� ��������� ������, Q��"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=txt(q(i, 3), False) & " ����/�3"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Superscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:="�;"
            Selection.Font.Italic = wdToggle
'����� ���-�� ����� ������ ��������� ������
                Selection.TypeParagraph
                Selection.TypeText Text:= _
                    "���������� ����� ������ ������ � �����, z = "
                Selection.Font.Italic = wdToggle
                Selection.TypeText Text:=txt(z(i), False)
                Select Case z(i)
                    Case 1, 21
                        Selection.TypeText Text:=" ���;"
                    Case 2 To 4, 22 To 24
                        Selection.TypeText Text:=" ����;"
                    Case 5 To 20
                        Selection.TypeText Text:=" �����;"
                End Select
                Selection.Font.Italic = wdToggle
    Else: Selection.TypeParagraph
        Selection.TypeText Text:="��������� ������ ���;"
    End If
'����� ��������� ���������
'����� ���-�� ����� ������ ��������� ���������
    If do_y_n(i) = True Then
            Selection.TypeParagraph
                    Selection.TypeText Text:="����������� ��������� ��������� t���"
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
            Selection.TypeText Text:="�."
                    Selection.Font.Italic = wdToggle
    Else: Selection.TypeParagraph
        Selection.TypeText Text:="��������� ��������� ��� (�.�. ��������� ������������� �������� � �������� ������)."
    End If
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.TypeParagraph
    Selection.Font.Bold = wdToggle
    Selection.Font.Italic = wdToggle
    Selection.TypeText Text:="������:"
    Selection.Font.Bold = wdToggle
    Selection.TypeParagraph
'''''''''''''''''''''''''''''''
''''''''''''�������''''''''''''
'''''''''''''''''''''''''''''''
'����� ������� ������
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
                & " �3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Italic = wdToggle
            Selection.TypeText Text:=" - ����� ������ �� ��������� ������."


'''''''''''''''''''''''''''''''''''''''''''
'              ���������                  '
'''''''''''''''''''''''''''''''''''''''''''
' ����� ������ �1 �������
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
                "������������ ������� ������ ����� �� ��������� (��� ����������� ��������� ������� t�1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�1
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�1"
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
                    Selection.TypeText Text:=" q�"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:="t��"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" - t�1"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=")/1000000, ����/�;"
            Selection.TypeParagraph
            Selection.TypeText Text:="Q��"
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
                    Selection.TypeText Text:=" ����/�"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=", ���"
                    Selection.TypeParagraph
                    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
                    Selection.TypeText Text:=vbTab
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:= _
                            " = " & txt(alfa(tn1)) & _
                            " ����������� �����������, ����������� ��������� ��������� �������� ����������� [1, ����.2.1]."
' ����� ������ �2 �������
            Selection.TypeParagraph
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "������� ������� ������ ����� �� ��������� �� �������� �������� ����� (������) (��� ����������� ��������� ������� t�2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�2
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�2"
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
                    Selection.TypeText Text:=" q�"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:="t��"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" - t�2"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=")/1000000, ����/�;"
            Selection.TypeParagraph
            Selection.TypeText Text:="Q��"
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
                    Selection.TypeText Text:=" ����/�"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=", ���"
                    Selection.TypeParagraph
                    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
                    Selection.TypeText Text:=vbTab
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:= _
                            " = " & txt(alfa(tn2)) & _
                            " ����������� �����������, ����������� ��������� ��������� �������� ����������� [1, ����.2.1]."
' ����� ������ �3 �������
            Selection.TypeParagraph
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "������� ������� ������ ����� �� ��������� �� ������������ ������ (��� ����������� ��������� ������� t�3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�3
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�3"
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
                    Selection.TypeText Text:=" q�"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" "
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                        True
                    Selection.TypeText Text:=" ("
                    Selection.TypeText Text:="t��"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=" - t�3"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Subscript = wdToggle
                    Selection.TypeText Text:=")/1000000, ����/�;"
            Selection.TypeParagraph
            Selection.TypeText Text:="Q��"
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
                    Selection.TypeText Text:=" ����/�"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=", ���"
                    Selection.TypeParagraph
                    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
                    Selection.TypeText Text:=vbTab
                    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3999, Unicode:= _
                        True
                    Selection.TypeText Text:= _
                            " = " & txt(alfa(tn3)) & _
                            " ����������� �����������, ����������� ��������� ��������� �������� ����������� [1, ����.2.1]."
Else   ''''�������� ������''''
' ����� ������ �1 �������
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
                "������������ ������� ������ ����� �� ��������� (��� ����������� ��������� ������� t�1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�1
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�1"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
            Selection.TypeText Text:="Q��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=txt(tn1, False)
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = " & txt(q(i, 4))
                    Selection.TypeText Text:=" ����/�"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=" (�������� ������)."
' ����� ������ �2 �������
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "������� ������� ������ ����� �� ��������� �� �������� �������� ����� (������) (��� ����������� ��������� ������� t�2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�2
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�2"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Q��"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="t�1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ����/�;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Q��"
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
                            Selection.TypeText Text:=" ����/�."
' ����� ������ �3 �������
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "������� ������� ������ ����� �� ��������� �� ������������ ������ (��� ����������� ��������� ������� t�3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�3
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�3"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Q��"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="t�1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ����/�;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Q��"
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
                            Selection.TypeText Text:=" ����/�."
                            Selection.Font.Italic = wdToggle
End If
' ����� ������ �4 �������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    Selection.Font.Italic = wdToggle
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "������� ������ ����� �� ��������� �� ������������ ������:"
' ����� ������� � �.�4
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Q��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
If do_y_n(i) = True Then
'���� ���� �������� ���������
    Selection.TypeText Text:="[Q��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="t�1"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" ((n - k) "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:="m�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (t��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - t�3"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=") + (n - k) "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (24 - m�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=") "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (t���"
    Selection.MoveLeft Unit:=wdCharacter, Count:=3, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - t�3"
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
    Selection.TypeText Text:=" (t���"
    Selection.MoveLeft Unit:=wdCharacter, Count:=3, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - t�3"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="))] /  "
    Selection.TypeText Text:=" (t��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" - t�1"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=") ,����/���;"
    '� �������
    Selection.TypeParagraph
    Selection.TypeText Text:="Q��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
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
        " (" & txt(td(i)) & " - " & txt(tn3) & "))] / (" & txt(tb(i)) & " - " & txt(tn1) & ") = " & txt(q(i, 13)) & " ����/���."
    Else
'���� ��� ��������� ���������
    Selection.TypeText Text:="Q��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="t�3"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" n "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" m�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=", ����/���;"
'� �������
    Selection.TypeParagraph
    Selection.TypeText Text:="Q��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 10)) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=txt(n_ot_per, False) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=txt(m_hour_work_ot(i)) & " = "
    Selection.TypeText Text:=txt(q(i, 13)) & " ����/���."
End If
End Sub
Sub Vivod_vnt_zd()
'''''''''''''''''''''''''''''''''''''''''''
'             ����������                  '
'''''''''''''''''''''''''''''''''''''''''''
'-----------------------------------------'
'-----------------------------------------'
'''''''''''''''''''''''''''''''
''''''''''''�������''''''''''''
'''''''''''''''''''''''''''''''
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then   ''''''������ ������''''''
' ����� ������ �5 �������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "������������ ������� ������ ����� �� ���������� (��� ����������� ��������� ������� t�1"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="�):"
' ����� ������� � �.�5
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Q�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="t�1"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = V "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" q�"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/1000000, ����/�;"
    Selection.TypeParagraph
    Selection.TypeText Text:="Q�"
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
            Selection.TypeText Text:=" ����/�."
' ����� ������ �6 �������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "������� ������� ������ ����� �� ���������� �� �������� �������� ����� (������) (��� ����������� ��������� ������� t�2"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="�):"
' ����� ������� � �.�6
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Q�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="t�2"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = V "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" q�"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/1000000, ����/�;"
    Selection.TypeParagraph
    Selection.TypeText Text:="Q�"
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
            Selection.TypeText Text:=" ����/�."
' ����� ������ �7 �������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "������� ������� ������ ����� �� ���������� �� ������������ ������ (��� ����������� ��������� ������� t�3"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="�):"
' ����� ������� � �.�7
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Q�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="t�3"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = V "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" q�"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/1000000, ����/�;"
    Selection.TypeParagraph
    Selection.TypeText Text:="Q�"
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
            Selection.TypeText Text:=" ����/�."
Else  ''''�������� ������''''
' ����� ������ �5 �������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "������������ ������� ������ ����� �� ���������� (��� ����������� ��������� ������� t�1"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Subscript = wdToggle
    Selection.TypeText Text:=" = " & txt(tn1, False) & " 0"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Superscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="�):"
' ����� ������� � �.�5
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q�"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�1"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
            Selection.TypeText Text:="Q�"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=txt(tn1, False)
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = " & txt(q(i, 5))
                    Selection.TypeText Text:=" ����/�"
                    Selection.Font.Italic = wdToggle
                    Selection.TypeText Text:=" (�������� ������)."
' ����� ������ �6 �������
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            Selection.Font.Italic = wdToggle
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "������� ������� ������ ����� �� ���������� �� �������� �������� ����� (������) (��� ����������� ��������� ������� t�2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn2, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�6
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q�"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�2"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Q�"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="t�1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�2"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ����/�;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Q�"
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
                            Selection.TypeText Text:=" ����/�."
' ����� ������ �7 �������
            Selection.TypeParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
            ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
            Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
                wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
                wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
            Selection.TypeText Text:= _
                "������� ������� ������ ����� �� ���������� �� ������������ ������ (��� ����������� ��������� ������� t�3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" = " & txt(tn3, False) & " 0"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Superscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="�):"
' ����� ������� � �.�7
            Selection.TypeParagraph
            Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
            Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
            Selection.TypeText Text:="Q�"
            Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Superscript = wdToggle
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:="t�3"
            Selection.Font.Superscript = wdToggle
            Selection.TypeText Text:=" = "
                    Selection.TypeText Text:="Q�"
                    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
                    Selection.Font.Subscript = wdToggle
                    Selection.MoveRight Unit:=wdCharacter, Count:=1
                    Selection.Font.Superscript = wdToggle
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:="t�1"
                    Selection.Font.Superscript = wdToggle
                    Selection.TypeText Text:=" "
            Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
                True
            Selection.TypeText Text:=" (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�3"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=")/ (t��"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:=" - t�1"
            Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
            Selection.Font.Subscript = wdToggle
            Selection.MoveRight Unit:=wdCharacter, Count:=1
            Selection.Font.Subscript = wdToggle
            Selection.TypeText Text:="), ����/�;"
            Selection.TypeParagraph
                    Selection.TypeText Text:="Q�"
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
                            Selection.TypeText Text:=" ����/�."
End If
' ����� ������ �8 �������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "������� ������ ����� �� ���������� �� ������������ ������:"
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Q�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:="Q�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="t�3"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (n - k) "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" m�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=", ����/���;"
'� �������
    Selection.TypeParagraph
    Selection.TypeText Text:="Q�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 11)) & " "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=" (" & txt(n_ot_per, False) & " - " & txt(k_vih_pr_dn) & ") "
    Selection.InsertSymbol Font:="Symbol", CharacterNumber:=-3881, Unicode:= _
        True
    Selection.TypeText Text:=txt(m_hour_work_vent(i)) & " = "
    Selection.TypeText Text:=txt(q(i, 14)) & " ����/���."
' ����� ������ �9 �������
If z_y_n(i) = True Then
        Selection.TypeParagraph
        Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
        ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
        Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
            wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
            wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
        Selection.TypeText Text:= _
            "������� ������ ����� �� ��������� ������:"
        Selection.TypeParagraph
        Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
        Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
        Selection.TypeText Text:="Q��"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Superscript = wdToggle
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:="���"
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:=" = "
        Selection.TypeText Text:="Q��"
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
        Selection.TypeText Text:=" z, ����/���;"
    '� �������
        Selection.TypeParagraph
        Selection.TypeText Text:="Q��"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Superscript = wdToggle
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:="���"
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
        Selection.TypeText Text:=txt(q(i, 15)) & " ����/���."
    Else: Selection.TypeParagraph
        Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
        ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
        Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
            wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
            wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
        Selection.TypeText Text _
            :="��������� ������ ���, ������� Q��"
        Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
        Selection.Font.Subscript = wdToggle
        Selection.MoveRight Unit:=wdCharacter, Count:=1
        Selection.Font.Superscript = wdToggle
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:="���"
        Selection.Font.Superscript = wdToggle
        Selection.TypeText Text:=" =0."
    End If
' ����� ������ �10 �������
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
    Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
        wdNumberGallery).ListTemplates(1), ContinuePreviousList:=True, ApplyTo:= _
        wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
    Selection.TypeText Text:= _
        "��������� ������� ������ ����� �� ������������ ������:"
    Selection.TypeParagraph
    Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.TypeText Text:="Q"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = Q��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" + Q�"
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" + Q��"
    Selection.MoveLeft Unit:=wdCharacter, Count:=2, Extend:=wdExtend
    Selection.Font.Subscript = wdToggle
    Selection.MoveRight Unit:=wdCharacter, Count:=1
    Selection.Font.Superscript = wdToggle
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=", ����/���;"
'� �������
    Selection.TypeParagraph
    Selection.TypeText Text:="Q"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:="���"
    Selection.Font.Superscript = wdToggle
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 13))
    Selection.TypeText Text:=" + "
    Selection.TypeText Text:=txt(q(i, 14))
    Selection.TypeText Text:=" + "
    Selection.TypeText Text:=txt(q(i, 15))
    Selection.TypeText Text:=" = "
    Selection.TypeText Text:=txt(q(i, 16))
    Selection.TypeText Text:=" ����/���."
'���������� ��� ��������� �������� ����������
    Selection.Font.Italic = wdToggle
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
End Sub
Public Sub vivod_literat()
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' ��������� ������ ������ ������������ ���������� ���������� ������� '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'����� ���������
    Selection.InsertBreak Type:=wdPageBreak
    Selection.TypeParagraph
    Selection.ParagraphFormat.Alignment = wdAlignParagraphJustify
    Selection.Font.Italic = wdToggle
    Selection.Font.Bold = wdToggle
    Selection.TypeText Text:=vbTab & _
        "����������� ���������, ������������ ��� �������:"
    Selection.Font.Italic = wdToggle
    Selection.Font.Bold = wdToggle
    Selection.TypeParagraph
ListGalleries(wdNumberGallery).ListTemplates(1).Name = ""
Selection.Range.ListFormat.ApplyListTemplate ListTemplate:=ListGalleries( _
    wdNumberGallery).ListTemplates(1), ContinuePreviousList:=False, ApplyTo:= _
    wdListApplyToWholeList, DefaultListBehavior:=wdWord9ListBehavior
Selection.TypeText Text:=Chr(34) & "������������ �������� �� ����������� " & _
    "�������� �������, �������������� � ���� �� ��������� ����� ������������� ���������� " & _
    "������������ ������������������� �����������" & Chr(34) & _
    ". �., ��� ��. ���������, 1994;"
Selection.TypeParagraph
Selection.TypeText Text:="���� 23-01-99. ������������ ������������ � ���������. �.," & _
    "����������, 1983;"
Selection.TypeParagraph
Selection.TypeText Text:="���� 2.04-05-91. ���������, ���������� � ����������������� " & _
    "�������. ����� ��������������. �., ����, 1992."
Selection.TypeParagraph
Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
Selection.TypeParagraph
End Sub


Public Function txt(perem As Variant, Optional x As Boolean = True)
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''                  ������� �������������� ��������� �������� � �����                        '''
'''                   � �������������� ���������� ����� ����� �������                         '''
'''                     �  ����������� �� 3-� ������ ����� �������                            '''
''' ���� ���������� �� ��������� x=false ����� ����� ���� ����� ������������ ����������� � () '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
If x = True Then
        If perem >= 0 Then
            txt = Trim(Format(Round(perem, 3)))
        Else: txt = "(" & Trim(Format(Round(perem, 3))) & ")"
        End If
Else: txt = Trim(Format(Round(perem, 3)))
End If
End Function



