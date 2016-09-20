Attribute VB_Name = "Rash_tep_ukr"
Option Explicit
Option Base 1
'''''''''''''''''''''''''
''' Описание констант '''
'''''''''''''''''''''''''
    Const x_ar = 40 '<--Количество элементов массивов (предельное количество зданий)
    Const font_size = 8 '<--Размер шрифта таблицы результатов
    Public Const f_clmt_name = "\Вспомогательные\Russian.txt"
    '^^^ Имя файла с климатическими данными по СНиП 23-01-99 ^^^'
    Public Const number_of_gorod = 425
    '^^^ Максимальное количество городов в файле с климатическими данными ^^^'
    Public Const f_ud_n_name = "\Вспомогательные\Udelnie.txt"
    '^^^ Имя файла с удельными нагрузками по зданиям ^^^'
    Public Const Numb_of_cheh = 35 'Максимальное количество типов производств в файле с удельными
'''''''''''''''''''''''''''
''' Описание переменных '''
'''''''''''''''''''''''''''
    Public Doc As Document '<--Используется для работы с документами (for each doc in documents)
        Public f_path_macros As String '<--Путь  файла с макросом
        Public f_name_macros As String '<--Имя файла с результатами
        Public f_name_ish_dan As String '<--Имя файла с исх. данными
        Public f_name_rm As String '<--Имя файла с исх. данными
        Public f_name_tbl_rez As String '<--Имя файла для вставки таблицы разультатов
    Dim tbl_res As Table '<--Таблица с результатами
    Dim tbl_ish As Table '<--Таблица с исходными данными
        Public open_dialog_variable As Integer '<--Указатель выбора окна диалога "Открыть документ"
        Public save_dialog_variable As Integer '<--Указатель выбора окна диалога "Сохранить документ"
    Dim Errorlb As Label '<--Метка для ошибки
    Dim drygoy_gorod As Boolean '<--Город "Другой..." "да"-"нет"
    Public nazadbtn As Boolean '<--True если нажата кнопка "Назад" на zd_dan_Frm при x=1
    Public txt_from_spisok As Boolean
    '<--Проверяет не введен ли текст, которого нет в списке
    Public text_soobcen As String '<--Текст сообщения при проверки введенных данных формы
'Общие данные для всех зданий
    Public gorod As String '<--Город строительства
    Public tn1 As Single '<--Температура наружного воздуха наиб.хол. пятидневки для данной местности
    Public tn3 As Single '<--Температура наружного воздуха ср. за от.п-д для данной местности
    Public tn2 As Single '<--Температура наружного воздуха ср. за I месяц для данной местности
        Public n_ot_per As Integer '<--Продолжительность отопительного периода
        Public k_vih_pr_dn As Integer '<--Сумма воскресных и празднечных дней за от.п-д
    Public x As Integer '<--Количество зданий
    Public i As Integer '<--Для счетчика
    Public j As Integer '<--Для счетчика
    Public o_ish_dan_f As Boolean '<--Фаил с исх.дан. открыть (да)-новый(нет)
'Данные по каждому зданию
    Public n_zd(x_ar) As String '<-- Название здания
        Public a(x_ar) As Single '<-- Длина здания
        Public b(x_ar) As Single '<-- Ширина здания
        Public h(x_ar) As Single '<-- Высота здания
        Public z_y_n(x_ar) As Boolean '<-- Завеса есть-нет
        Public do_y_n(x_ar) As Boolean '<-- Дежурное отопление есть-нет
    Public tb(x_ar) As Single '<-- Температура внутреннего воздуха
    Public td(x_ar) As Single '<-- Температура дежурного отопления
    Public tpr(x_ar) As Single '<-- Температура приточного воздуха
        Public m_hour_work_ot(x_ar) As Single '<-- Количество часов работы основного отопления
        Public m_hour_work_vent(x_ar) As Single '<-- Количество часов работы здания в сутки (от количества смен)(для вентиляции)
        Public z(x_ar) As Single '<-- Количество часов работы завесы в сутки
    Public zd_type(x_ar) As String  ' <--Тип здания
    Public ot_v_CkBk As Boolean '<--Для ot_ChkBx v_ChkBx формы zd_dan_Frm
    Public x_nzd As Integer '<--Номер здания на котором была нажата кнопка "Назад"
' Массив расходов тепла по зданию
    Public q(x_ar, 16) As Single
'q(x_ar,1) '<-- Удельные нагрузки тепла на отопление здания
'q(x_ar,2) '<-- Удельные нагрузки тепла на вентиляцию здания
'q(x_ar,3) '<-- Расход тепла на завесу
    'q(x_ar,4) '<-- Расход тепла на отопление при tn1
    'q(x_ar,5) '<-- Расход тепла на вентиляцию при tn1
    'q(x_ar,6) '<-- Суммарный расход тепла при tn1
'q(x_ar,7) '<-- Расход тепла на отопление при tn2
'q(x_ar,8) '<-- Расход тепла на вентиляцию при tn2
'q(x_ar,9) '<-- Суммарный расход тепла при tn2
    'q(x_ar,10) '<-- Расход тепла на отопление при tn3
    'q(x_ar,11) '<-- Расход тепла на вентиляцию при tn3
    'q(x_ar,12) '<-- Суммарный расход тепла при tn3
'q(x_ar,13) '<-- Годовой расход тепла на отопление
'q(x_ar,14) '<-- Годовой расход тепла на вентиляцию
'q(x_ar,15) '<-- Годовой расход тепла на завесу
    'q(x_ar,16) '<-- Суммарный годовой расход тепла
Public q_sum(13) As Single '<--Суммарные расходы по столбцам
Public Sub Main()
'''''''''''''''''''''''''''''''''''
''' Главная процедура программы '''
'''''''''''''''''''''''''''''''''''.
On Error GoTo Errorlb
f_path_macros = ActiveDocument.Path
ot_v_CkBk = False
For i = 1 To 13 ' Обнуляются значения сумм по столбцам талицы разультатов
    q_sum(i) = 0
Next i
nazadbtn = False ' Кнопка "Назад" не была нажата при x=1
    opn_f_ish_dan_Frm.Show
Errorlb:
    close_all_usen_files
    If f_name_tbl_rez <> "" And f_name_tbl_rez <> f_name_rm Then
        Application.WindowState = wdWindowStateMinimize
        Windows(f_name_tbl_rez).Activate
    End If
    End
End Sub
Public Sub q_each_zd(i_q As Integer)
Dim ij As Integer
''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Процедура расчета тепла укрупненно одного здания '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
'-----------------
'- Полный расчет -
'-----------------
For ij = 4 To 10 Step 3
    q(i_q, ij) = q_o_v_from_tn(q(i_q, 1), tn1, alfa(tn1), tb(i_q))
        q(i_q, ij + 1) = q_o_v_from_tn(q(i_q, 2), tn1, 1, tpr(i_q))
    q(i_q, ij + 2) = Round(q(i_q, ij), 3) + Round(q(i_q, ij + 1), 3)
Next ij
Else
'-------------------
'- Короткий расчет -
'-------------------
For ij = 4 To 10 Step 3
    If ij = 4 Then
        q(i_q, ij + 2) = Round(q(i_q, ij), 3) + Round(q(i_q, ij + 1), 3)
    Else
        q(i_q, ij) = q_o_v_from_tn_fast(q(i_q, 4), tn2, tb(i_q))
        q(i_q, ij + 1) = q_o_v_from_tn_fast(q(i_q, 5), tn2, tpr(i_q))
        q(i_q, ij + 2) = Round(q(i_q, ij), 3) + Round(q(i_q, ij + 1), 3)
    End If
Next ij
End If
'---------
'- Общее -
'---------
'Отопление годовая
    If tb(i_q) <> tn1 Then
        If do_y_n(i_q) = True Then
            q(i_q, 13) = (q(i_q, 4) * ((n_ot_per - k_vih_pr_dn) * (m_hour_work_ot(i_q) * (tb(i_q) - tn3) _
                    + (24 - m_hour_work_ot(i_q)) * (td(i_q) - tn3)) + k_vih_pr_dn * 24 * (td(i_q) - tn3))) / (tb(i_q) - tn1)
        Else: q(i_q, 13) = q(i_q, 4) * n_ot_per * m_hour_work_ot(i_q) * (tb(i_q) - tn3) / (tb(i_q) - tn1)
        End If
    Else: MsgBox "Температура внутреннего воздуха не может быть равна температуре наружного возуха", _
                vbCritical, "Ошибка"
            close_all_usen_files
            End
    End If
'Вентиляция годовая
    If tpr(i_q) <> tn1 Then
        q(i_q, 14) = ((n_ot_per - k_vih_pr_dn) * m_hour_work_vent(i_q) * (tpr(i_q) - tn3) * q(i_q, 5)) / (tpr(i_q) - tn1)
    Else: MsgBox "Температура приточного воздуха не может быть равна температуре наружного возуха", _
               vbCritical, "Ошибка"
            close_all_usen_files
            End
    End If
'Завеса годовая
        q(i_q, 15) = q(i_q, 3) * z(i_q) * (n_ot_per - k_vih_pr_dn)
'Годовая суммарная
        q(i_q, 16) = Round(q(i_q, 13), 3) + Round(q(i_q, 14), 3) + Round(q(i_q, 15), 3)
End Sub
Function q_o_v_from_tn(q_udelnaya As Single, tn As Single, alf As Single, t_vnytren As Single)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''      Расчет расхода тепла на отопление и вентиляцию        '''
''' в зависимости от удельных нагрузок тепла  при различных tn '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    If t_vnytren = tn Then
        MsgBox "Температура внутреннего воздуха не может быть равна температуре наружного возуха", _
                vbCritical, "Ошибка"
        close_all_usen_files
        End
    End If
         q_o_v_from_tn = (a(i) * b(i) * h(i) * q_udelnaya * alf * (t_vnytren - tn)) / 1000000
End Function
Function q_o_v_from_tn_fast(q As Single, tn As Single, t_vnytren As Single)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''      Расчет расхода тепла на отопление и вентиляцию        '''
''' в зависимости от удельных нагрузок тепла  при различных tn '''
'''                  при коротком расчете                      '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    If t_vnytren = tn Then
        MsgBox "Температура внутреннего воздуха не может быть равна температуре наружного возуха", _
                vbCritical, "Ошибка"
        Documents(f_name_ish_dan).Activate
        ActiveDocument.Close (wdDoNotSaveChanges)
        End
    End If
        q_o_v_from_tn_fast = q * (t_vnytren - tn) / (t_vnytren - tn1)
End Function
Public Sub vvod_znach_from_climat()
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Процедура ввода данных по району строительства из формы climat_Frm '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    x = Str_conv_SngNmb(climat_Frm.xTxtBx.Text)
        vvod_climat gorod, tn1, tn2, tn3, n_ot_per
    k_vih_pr_dn = Str_conv_SngNmb(climat_Frm.kTxtBx.Text)
End Sub
Public Sub vvod_znach_for_each_zd_from_zd_dan_Frms(i_zd As Integer)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Процедура ввода данных по зданиям из форм zd_dan_Frm и zd_dan_Frm_fast '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
'------------------------
'- Для формы zd_dan_Frm -
'------------------------
    n_zd(i_zd) = zd_dan_Frm.nzdTxtBx.Text
    a(i_zd) = Str_conv_SngNmb(zd_dan_Frm.aTxtBx.Text)
    b(i_zd) = Str_conv_SngNmb(zd_dan_Frm.bTxtBx.Text)
    h(i_zd) = Str_conv_SngNmb(zd_dan_Frm.hTxtBx.Text)
    m_hour_work_vent(i_zd) = Str_conv_SngNmb(zd_dan_Frm.mTxtBx.Text)
If zd_dan_Frm.yOptnBtn.Value = True Then
    z_y_n(i_zd) = True
Else: z_y_n(i_zd) = False
End If
    If z_y_n(i_zd) = True Then
        q(i_zd, 3) = Str_conv_SngNmb(zd_dan_Frm.qvzTxtBx.Text)
        z(i_zd) = Str_conv_SngNmb(zd_dan_Frm.zTxtBx.Text)
    Else: q(i_zd, 3) = 0 And z(i_zd) = 0
    End If
If zd_dan_Frm.y_OptnBtn.Value = True Then
    do_y_n(i_zd) = True
Else: do_y_n(i_zd) = False
End If
    If do_y_n(i_zd) = True Then
        m_hour_work_ot(i_zd) = m_hour_work_vent(i_zd)
        td(i_zd) = Str_conv_SngNmb(zd_dan_Frm.tdotTxtBx.Text)
    Else: m_hour_work_ot(i_zd) = 24
        td(i_zd) = 0
    End If
zd_type(i_zd) = zd_dan_Frm.udelnie_CmbBx.Text
vvod_Ud_N (i_zd)
    tb(i_zd) = Str_conv_SngNmb(zd_dan_Frm.tbTxtBx.Text)
    tpr(i_zd) = Str_conv_SngNmb(zd_dan_Frm.tprTxtBx.Text)
Else
'-----------------------------
'- Для формы zd_dan_Frm_fast -
'-----------------------------
    n_zd(i_zd) = zd_dan_Frm_fast.nzdTxtBx.Text
    m_hour_work_vent(i_zd) = Str_conv_SngNmb(zd_dan_Frm_fast.mTxtBx.Text)
If zd_dan_Frm_fast.yOptnBtn.Value = True Then z_y_n(i_zd) = True _
Else: z_y_n(i_zd) = False
    If z_y_n(i_zd) = True Then
        q(i_zd, 3) = Str_conv_SngNmb(zd_dan_Frm_fast.qvzTxtBx.Text)
        z(i_zd) = Str_conv_SngNmb(zd_dan_Frm_fast.zTxtBx.Text)
    Else: q(i_zd, 3) = 0 And z(i_zd) = 0
    End If
If zd_dan_Frm_fast.y_OptnBtn.Value = True Then
    do_y_n(i_zd) = True
Else: do_y_n(i_zd) = False
End If
    If do_y_n(i_zd) = True Then
        m_hour_work_ot(i_zd) = m_hour_work_vent(i_zd)
        td(i_zd) = Str_conv_SngNmb(zd_dan_Frm_fast.tdotTxtBx.Text)
    Else: m_hour_work_ot(i_zd) = 24
        td(i_zd) = 0
    End If
q(i_zd, 4) = Str_conv_SngNmb(zd_dan_Frm_fast.qoTxtBx.Text)
q(i_zd, 5) = Str_conv_SngNmb(zd_dan_Frm_fast.qbTxtBx.Text)
    tb(i_zd) = Str_conv_SngNmb(zd_dan_Frm_fast.tbTxtBx.Text)
    tpr(i_zd) = Str_conv_SngNmb(zd_dan_Frm_fast.tprTxtBx.Text)
End If
End Sub
Public Sub tbl_rez_shapka()
Dim i_tbl_rez_shapka As Integer 'Для внутреннего цикла
''''''''''''''''''''''''''''''''''''''''''''''''''
''' Создание шапки таблицы результатов расчета '''
''''''''''''''''''''''''''''''''''''''''''''''''''
    Documents(f_name_macros).Activate
'Формируется таблица и задаются параметры таблицы
    Selection.WholeStory                          ' Удаляется все что есть в
    Selection.Delete Unit:=wdCharacter, Count:=1  'документе с макросом
    Selection.Font.Size = font_size
        Set tbl_res = ActiveDocument.Tables.Add(Selection.Range, x * 2 + 5, 14)
    Selection.Tables(1).Select
    Selection.SelectCell
    Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
    Selection.Cells.VerticalAlignment = wdCellAlignVerticalCenter
'Заполняются ячейки заголовка таблицы
cells_merge_and_text_paste Tbl:=tbl_res, row_number:=1, column_number:=2, MR_count:=8, _
                            Text:="Расходы тепла, Гкал/ч/МВт"
cells_merge_and_text_paste Tbl:=tbl_res, row_number:=1, column_number:=3, MR_count:=3, MD_count:=1, _
                            Text:="Годовые нагрузки, Гкал/год/МДж"
cells_merge_and_text_paste Tbl:=tbl_res, row_number:=2, column_number:=2, MR_count:=2, _
                            Text:="Tp =" & Trim(Format(tn1))
cells_merge_and_text_paste Tbl:=tbl_res, row_number:=2, column_number:=3, MR_count:=2, _
                            Text:="Tp =" & Trim(Format(tn2))
cells_merge_and_text_paste Tbl:=tbl_res, row_number:=2, column_number:=4, MR_count:=2, _
                            Text:="Tp =" & Trim(Format(tn3))
For i_tbl_rez_shapka = 2 To 11 Step 3
        cells_merge_and_text_paste Tbl:=tbl_res, row_number:=3, column_number:=i_tbl_rez_shapka, _
                                Text:="отоп- ление"
        cells_merge_and_text_paste Tbl:=tbl_res, row_number:=3, column_number:=i_tbl_rez_shapka + 1, _
                                    Text:="венти- ляция"
    If i_tbl_rez_shapka <> 11 Then
        cells_merge_and_text_paste Tbl:=tbl_res, row_number:=3, column_number:=i_tbl_rez_shapka + 2, _
                                    Text:="всего"
    Else: cells_merge_and_text_paste Tbl:=tbl_res, row_number:=3, column_number:=i_tbl_rez_shapka + 2, _
                                    Text:="воздуш- ная завеса"
        cells_merge_and_text_paste Tbl:=tbl_res, row_number:=3, column_number:=i_tbl_rez_shapka + 3, _
                                    Text:="всего"
    End If
Next i_tbl_rez_shapka
cells_merge_and_text_paste Tbl:=tbl_res, row_number:=1, column_number:=1, MD_count:=2, _
                            Text:="Наименование здания"

'Задается авторазмер ячеек таблицы по содержимому,
    Selection.Tables(1).AutoFitBehavior (wdAutoFitContent)
'Задается двойное подчеркивание шапки таблицы
    tbl_res.Cell(1, 1).Select
    Selection.MoveRight Unit:=wdWord, Count:=13, Extend:=wdExtend
        With Options
            .DefaultBorderLineStyle = wdLineStyleDouble
            .DefaultBorderLineWidth = wdLineWidth050pt
            .DefaultBorderColor = wdColorAutomatic
        End With
        With Selection.Borders(wdBorderBottom)
            .LineStyle = Options.DefaultBorderLineStyle
            .LineWidth = Options.DefaultBorderLineWidth
            .Color = Options.DefaultBorderColor
        End With
    Selection.Rows.HeadingFormat = wdToggle 'Шапке таблицы присваевается свойство заголовка таблицы
End Sub
Public Sub tbl_rez(i_tbl_rez)
Dim ij As Integer
'''''''''''''''''''''''''''''''''''''''''''''''
''' Создание таблицы с результатами расчета '''
'''''''''''''''''''''''''''''''''''''''''''''''
tbl_res.Cell(i_tbl_rez + 3, 1).Range.InsertAfter n_zd(i_tbl_rez)
For ij = 4 To 16 'Заполнение таблицы значениями количеств тепла
    If q(i_tbl_rez, ij) <> 0 Then
        tbl_res.Cell(i_tbl_rez + 3, ij - 2).Range.InsertAfter _
            Trim(Format(Round(q(i_tbl_rez, ij), 3)))
        If ij < 13 Then
            tbl_res.Cell(i_tbl_rez + 4, ij - 2).Range.InsertAfter _
                Trim(Format(Round(q(i_tbl_rez, ij) * 1.163, 3)))
        Else: tbl_res.Cell(i_tbl_rez + 4, ij - 2).Range. _
                InsertAfter Trim(Format(Round(q(i_tbl_rez, ij) * 4.186, 3)))
        End If
    Else: tbl_res.Cell(i_tbl_rez + 4, ij - 2).Range.InsertAfter "—"
    End If
Next ij
    tbl_res.Cell(i_tbl_rez + 3, 2).Select
    Selection.MoveRight Unit:=wdCharacter, Count:=12, Extend:=wdExtend
    Selection.Font.Underline = wdUnderlineSingle
        For j = 1 To 14
            If i_tbl_rez <= x Then
                cells_merge_and_text_paste Tbl:=ActiveDocument.Tables(1), _
                    row_number:=i_tbl_rez + 3, column_number:=j, MD_count:=1
            End If
        Next j
End Sub
Public Sub newdoc(fi As String)
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Создание нового документа для таблицы исходных данных '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Documents.Add DocumentType:=wdNewBlankDocument
    fi = ActiveDocument.Name
End Sub
Public Sub tbl_ish_dan()
Dim i_tbl_ish As Integer 'Для внутреннего цикла
''''''''''''''''''''''''''''''''''''''''
''' Создание таблицы исходных данных '''
''''''''''''''''''''''''''''''''''''''''
    Set tbl_ish = ActiveDocument.Tables.Add(Selection.Range, x + 8, 15)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=1, column_number:=1, _
                                    Text:="Кол-во зданий"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=1, column_number:=2, _
                                    Text:=Str(x)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=2, column_number:=1, _
                                    Text:="Город"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=2, column_number:=2, _
                                    Text:=gorod
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=3, column_number:=1, _
                                    Text:="Макс.т-ра нар.в-ха"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=3, column_number:=2, _
                                    Text:=Str(tn1)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=4, column_number:=1, _
                                    Text:="Ср.т-ра нар.в-ха за от.п-д"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=4, column_number:=2, _
                                    Text:=Str(tn2)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=5, column_number:=1, _
                                    Text:="Ср.т-ра за январь"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=5, column_number:=2, _
                                    Text:=Str(tn3)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=6, column_number:=1, _
                                    Text:="Пр-ть от.п-да"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=6, column_number:=2, _
                                    Text:=Str(n_ot_per)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=7, column_number:=1, _
                                    Text:="Сум.воск. и пр. дней за от.п-д"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=7, column_number:=2, _
                                    Text:=Str(k_vih_pr_dn)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=1, _
                                    Text:="Наимен.зд-я"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=2, _
                                    Text:="Длина зд-я"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=3, _
                                    Text:="Ширина зд-я"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=4, _
                                    Text:="Высота зд-я"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=5, _
                                    Text:="Кол-во ч.работы зд-я в сутки"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=6, _
                                    Text:="Т-ра вн.в-ха"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=7, _
                                    Text:="Уд.нагр-ка от-я"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=8, _
                                    Text:="Уд.нагр-ка в-ции"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=9, _
                                    Text:="Т-ра пр.в-ха"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=10, _
                                    Text:="Завеса (есть-нет)"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=11, _
                                    Text:="Нагр-ка на завесу"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=12, _
                                    Text:="Кол-во ч.работы завесы в сутки"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=13, _
                                    Text:="Деж.от-е (есть-нет)"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=14, _
                                    Text:="Т-ра деж.от-я"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=15, _
                                    Text:="Тип здания"
    For i_tbl_ish = 1 To x
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=1, _
                                    Text:=n_zd(i_tbl_ish)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=2, _
                                    Text:=Str(a(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=3, _
                                    Text:=Str(b(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=4, _
                                    Text:=Str(h(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=5, _
                                    Text:=Str(m_hour_work_vent(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=6, _
                                    Text:=Str(tb(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=7, _
                                    Text:=Str(q(i_tbl_ish, 1))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=8, _
                                    Text:=Str(q(i_tbl_ish, 2))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=9, _
                                    Text:=Str(tpr(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=10, _
                                    Text:=z_y_n(i_tbl_ish)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=11, _
                                    Text:=Str(q(i_tbl_ish, 3))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=12, _
                                    Text:=Str(z(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=13, _
                                    Text:=do_y_n(i_tbl_ish)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=14, _
                                    Text:=Str(td(i_tbl_ish))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish + 8, column_number:=15, _
                                    Text:=zd_type(i_tbl_ish)
    Next i_tbl_ish
End Sub
Public Sub tbl_ish_dan_fast()
Dim i_tbl_ish_fast As Integer 'Для внутреннего цикла
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Создание таблицы исходных данных при коротком расчете '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    Set tbl_ish = ActiveDocument.Tables.Add(Selection.Range, x + 8, 11)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=1, column_number:=1, _
                                    Text:="Кол-во зданий"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=1, column_number:=2, _
                                    Text:=Str(x)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=2, column_number:=1, _
                                    Text:="Город"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=2, column_number:=2, _
                                    Text:=gorod
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=3, column_number:=1, _
                                    Text:="Макс.т-ра нар.в-ха"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=3, column_number:=2, _
                                    Text:=Str(tn1)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=4, column_number:=1, _
                                    Text:="Ср.т-ра нар.в-ха за от.п-д"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=4, column_number:=2, _
                                    Text:=Str(tn2)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=5, column_number:=1, _
                                    Text:="Ср.т-ра за январь"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=5, column_number:=2, _
                                    Text:=Str(tn3)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=6, column_number:=1, _
                                    Text:="Пр-ть от.п-да"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=6, column_number:=2, _
                                    Text:=Str(n_ot_per)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=7, column_number:=1, _
                                    Text:="Сум.воск. и пр. дней за от.п-д"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=7, column_number:=2, _
                                    Text:=Str(k_vih_pr_dn)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=1, _
                                    Text:="Наимен.зд-я"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=2, _
                                    Text:="Кол-во ч.работы зд-я в сутки"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=3, _
                                    Text:="Т-ра вн.в-ха"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=4, _
                                    Text:="Макс.часов.р-д на от-е"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=5, _
                                    Text:="Макс.часов.р-д на вен-ю"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=6, _
                                    Text:="Т-ра пр.в-ха"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=7, _
                                    Text:="Завеса (есть-нет)"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=8, _
                                    Text:="Нагр-ка на завесу"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=9, _
                                    Text:="Кол-во ч.работы завесы в сутки"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=10, _
                                    Text:="Деж.от-е (есть-нет)"
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=8, column_number:=11, _
                                    Text:="Т-ра деж.от-я"
    For i_tbl_ish_fast = 1 To x
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=1, _
                                    Text:=n_zd(i_tbl_ish_fast)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=2, _
                                    Text:=Str(m_hour_work_vent(i_tbl_ish_fast))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=3, _
                                    Text:=Str(tb(i_tbl_ish_fast))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=4, _
                                    Text:=Str(q(i_tbl_ish_fast, 4))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=5, _
                                    Text:=Str(q(i_tbl_ish_fast, 5))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=6, _
                                    Text:=Str(tpr(i_tbl_ish_fast))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=7, _
                                    Text:=z_y_n(i_tbl_ish_fast)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=8, _
                                    Text:=Str(q(i_tbl_ish_fast, 3))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=9, _
                                    Text:=Str(z(i_tbl_ish_fast))
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=10, _
                                    Text:=do_y_n(i_tbl_ish_fast)
        cells_merge_and_text_paste Tbl:=tbl_ish, row_number:=i_tbl_ish_fast + 8, column_number:=11, _
                                    Text:=Str(td(i_tbl_ish_fast))
     Next i_tbl_ish_fast
End Sub
Function alfa(t As Single)
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Функия нахождения коэффициента альфа в зависимости от теипературы '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Dim i_alfa As Integer
Dim al(2, 12) As Single
    al(1, 1) = 0:           al(2, 1) = 2.05
    al(1, 2) = -5:          al(2, 2) = 1.67
    al(1, 3) = -10:         al(2, 3) = 1.45
    al(1, 4) = -15:         al(2, 4) = 1.29
    al(1, 5) = -20:         al(2, 5) = 1.17
    al(1, 6) = -25:         al(2, 6) = 1.08
    al(1, 7) = -30:         al(2, 7) = 1
    al(1, 8) = -35:         al(2, 8) = 0.95
    al(1, 9) = -40:         al(2, 9) = 0.9
    al(1, 10) = -45:        al(2, 10) = 0.85
    al(1, 11) = -50:        al(2, 11) = 0.82
    al(1, 12) = -55:        al(2, 12) = 0.8
For i_alfa = 1 To 12
If al(1, i_alfa) = t Then alfa = al(2, i_alfa)
If i_alfa < 12 Then
    If Abs(t) > Abs(al(1, i_alfa)) And Abs(t) < Abs(al(1, i_alfa + 1)) Then
        alfa = interpol(t, al(1, i_alfa), al(1, i_alfa + 1), al(2, i_alfa), al(2, i_alfa + 1))
    End If
End If
If Abs(t) < Abs(al(1, 1)) Then alfa = exterpol_min(t, al(1, 1), al(1, 2), al(2, 1), al(2, 2))
If Abs(t) > Abs(al(1, 12)) Then alfa = exterpol_max(t, al(1, 11), al(1, 12), al(2, 11), al(2, 12))
Next i_alfa
End Function
Public Function interpol(x_znachenie_y, x, y, f_x, f_y)
'''''''''''''''''''''''''''''''''''''''''''''''''''
''' Функция интерполяции мужду двумя значениями '''
'''''''''''''''''''''''''''''''''''''''''''''''''''
    interpol = (((f_y - f_x) / (y - x)) * (x_znachenie_y - x)) + f_x
End Function
Public Function exterpol_min(znachenie_x, x, y, f_x, f_y)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Функция эксртерполяции если надо найти значение меньше наименьшего '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    exterpol_min = f_x - (((f_y - f_x) / (y - x)) * (x - znachenie_x))
End Function
Public Function exterpol_max(y_znachenie, x, y, f_x, f_y)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Функция эксртерполяции если надо найти значение больше наибольшего '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    exterpol_max = (((f_y - f_x) / (y - x)) * (y_znachenie - y)) + f_y
End Function
Public Sub read_opendoc_climat()
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''             Открыват файл с исходными данными и                     '''
''' считывает климатические данные из файла в программу по всем зданиям '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    With Dialogs(wdDialogFileOpen)
        If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
            .Name = "*_rtu"
        Else: .Name = "*_rtu1"
        End If
        open_dialog_variable = .Show
    End With
If open_dialog_variable = -1 Then
    Application.ScreenUpdating = False
    f_name_ish_dan = ActiveDocument.Name
'Считывание данных
    cells_read_text x, row_number:=1, column_number:=2
    cells_read_text gorod, row_number:=2, column_number:=2
    drygoy_gorod = True
    For j = 1 To number_of_gorod
        If gorod = clmt(j, 1) Then drygoy_gorod = False
    Next j
        If drygoy_gorod = True Then
            cells_read_text tn1, row_number:=3, column_number:=2
            cells_read_text tn2, row_number:=4, column_number:=2
            cells_read_text tn3, row_number:=5, column_number:=2
            cells_read_text n_ot_per, row_number:=6, column_number:=2
        End If
    cells_read_text k_vih_pr_dn, row_number:=7, column_number:=2
    Documents(f_name_macros).Activate
    Application.ScreenUpdating = True
End If
End Sub
Public Sub read_opendoc_zd_dan(i_zd)
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Считывает данные из файла в программу по каждому зданию zd_dan  '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Dim IsTr As String
    Documents(f_name_ish_dan).Activate
    cells_read_text n_zd(i_zd), row_number:=i_zd + 8, column_number:=1
        cells_read_text a(i_zd), row_number:=i_zd + 8, column_number:=2
        cells_read_text b(i_zd), row_number:=i_zd + 8, column_number:=3
        cells_read_text h(i_zd), row_number:=i_zd + 8, column_number:=4
    cells_read_text m_hour_work_vent(i_zd), row_number:=i_zd + 8, column_number:=5
    cells_read_text tb(i_zd), row_number:=i_zd + 8, column_number:=6
        cells_read_text q(i_zd, 1), row_number:=i_zd + 8, column_number:=7
        cells_read_text q(i_zd, 2), row_number:=i_zd + 8, column_number:=8
        cells_read_text tpr(i_zd), row_number:=i_zd + 8, column_number:=9
    cells_read_text IsTr, row_number:=i_zd + 8, column_number:=10
        If IsTr = "True" Then
            z_y_n(i_zd) = True
            cells_read_text q(i_zd, 3), row_number:=i_zd + 8, column_number:=11
            cells_read_text z(i_zd), row_number:=i_zd + 8, column_number:=12
        Else: z_y_n(i_zd) = False
            q(i_zd, 3) = 0
            z(i_zd) = 0
        End If
    cells_read_text IsTr, row_number:=i_zd + 8, column_number:=13
        If IsTr = "True" Then
            do_y_n(i_zd) = True
            cells_read_text td(i_zd), row_number:=i_zd + 8, column_number:=14
        Else: do_y_n(i_zd) = False
            td(i_zd) = "5"
        End If
    cells_read_text zd_type(i_zd), row_number:=i_zd + 8, column_number:=15
End Sub
Public Sub read_opendoc_zd_dan_fast(i_zd_f)
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Считывает данные из файла в программу по каждому зданию zd_dan_fast '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Dim IsTr As String
    Documents(f_name_ish_dan).Activate
    cells_read_text n_zd(i_zd_f), row_number:=i_zd_f + 8, column_number:=1
        cells_read_text m_hour_work_vent(i_zd_f), row_number:=i_zd_f + 8, column_number:=2
        cells_read_text tb(i_zd_f), row_number:=i_zd_f + 8, column_number:=3
    cells_read_text q(i_zd_f, 4), row_number:=i_zd_f + 8, column_number:=4
    cells_read_text q(i_zd_f, 5), row_number:=i_zd_f + 8, column_number:=5
    cells_read_text tpr(i_zd_f), row_number:=i_zd_f + 8, column_number:=6
        cells_read_text IsTr, row_number:=i_zd_f + 8, column_number:=7
            If IsTr = "True" Then
                z_y_n(i_zd_f) = True
                cells_read_text q(i_zd_f, 3), row_number:=i_zd_f + 8, column_number:=8
                cells_read_text z(i_zd_f), row_number:=i_zd_f + 8, column_number:=9
            Else: z_y_n(i_zd_f) = False
                q(i_zd_f, 3) = 0
                z(i_zd_f) = 0
            End If
        cells_read_text IsTr, row_number:=i_zd_f + 8, column_number:=10
            If IsTr = "True" Then
                do_y_n(i_zd_f) = True
                cells_read_text td(i_zd_f), row_number:=i_zd_f + 8, column_number:=11
            Else: do_y_n(i_zd_f) = False
                td(i_zd_f) = "5"
            End If
End Sub
Public Sub save_ish_dan_doc()
'''''''''''''''''''''''''''''''''''''''''
''' Сохраняет исходные данные в файле '''
'''''''''''''''''''''''''''''''''''''''''
    If o_ish_dan_f = True Then
        Documents(f_name_ish_dan).Activate
        ActiveDocument.Tables(1).Select
        Selection.Tables(1).Delete
    Else: newdoc f_name_ish_dan 'Создает новый документ под исходные данные и запоминает его имя
    End If
        Documents(f_name_ish_dan).Activate
        Selection.Font.Size = 6
        If opn_f_ish_dan_Frm.Fast_CkBx.Value = True Then
            tbl_ish_dan_fast
        Else: tbl_ish_dan
        End If
    With Dialogs(wdDialogFileSaveAs)
        If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
            .Name = "*_rtu"
        Else: .Name = "*_rtu1"
        End If
        save_dialog_variable = .Show
    End With
    If save_dialog_variable <> -1 Then
        If o_ish_dan_f = True Then
            Documents.Open FileName:=f_name_ish_dan, ConfirmConversions:=False, ReadOnly:= _
            False, AddToRecentFiles:=False, PasswordDocument:="", PasswordTemplate:= _
            "", Revert:=True, WritePasswordDocument:="", WritePasswordTemplate:="", _
            Format:=wdOpenFormatAuto
        Else
            close_all_usen_files
        End If
    Else: ActiveDocument.Close wdDoNotSaveChanges
    End If
End Sub
Public Sub vvod_znach_for_each_zd_to_zd_dan_Frms(i_to_zd_Frm As Integer)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Вводит значения в формы при их открытии (для zd_dan_Frm и zd_dan_Frm_fast) '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
If opn_f_ish_dan_Frm.Fast_CkBx.Value = False Then
'------------------------
'- Для формы zd_dan_Frm -
'------------------------
zd_dan_Frm.nzdTxtBx.Text = n_zd(i_to_zd_Frm)
Number_to_TxtBx zd_dan_Frm.aTxtBx, a(i_to_zd_Frm)
Number_to_TxtBx zd_dan_Frm.bTxtBx, b(i_to_zd_Frm)
Number_to_TxtBx zd_dan_Frm.hTxtBx, h(i_to_zd_Frm)
Number_to_TxtBx zd_dan_Frm.mTxtBx, m_hour_work_vent(i_to_zd_Frm)
Number_to_TxtBx zd_dan_Frm.tbTxtBx, tb(i_to_zd_Frm)
Number_to_TxtBx zd_dan_Frm.tprTxtBx, tpr(i_to_zd_Frm)
zd_dan_Frm.udelnie_CmbBx.Text = zd_type(i_to_zd_Frm)
    If zd_type(i_to_zd_Frm) = "Другое..." Then
        Number_to_TxtBx zd_dan_Frm.qoTxtBx, q(i_to_zd_Frm, 1)
        Number_to_TxtBx zd_dan_Frm.qbTxtBx, q(i_to_zd_Frm, 2)
    Else:
        zd_dan_Frm.Height = 290
        zd_dan_Frm.nagrFm.Visible = False
    End If
If q(i_to_zd_Frm, 1) = 0 And ot_v_CkBk = True And open_dialog_variable = -1 Then _
    zd_dan_Frm.ot_ChkBx.Value = True _
Else: zd_dan_Frm.ot_ChkBx.Value = False
If q(i_to_zd_Frm, 2) = 0 And ot_v_CkBk = True And open_dialog_variable = -1 Then _
    zd_dan_Frm.vent_ChkBx.Value = True _
Else zd_dan_Frm.vent_ChkBx.Value = False
        If do_y_n(i_to_zd_Frm) = True Then
            zd_dan_Frm.y_OptnBtn.Value = True
            Number_to_TxtBx zd_dan_Frm.tdotTxtBx, td(i_to_zd_Frm)
        Else
            zd_dan_Frm.n_OptnBtn.Value = True
            zd_dan_Frm.tdotTxtBx.Text = "5"
        End If
    If z_y_n(i_to_zd_Frm) = True Then zd_dan_Frm.yOptnBtn.Value = True _
                                    Else zd_dan_Frm.nOptnBtn.Value = True
        Number_to_TxtBx zd_dan_Frm.qvzTxtBx, q(i_to_zd_Frm, 3)
        Number_to_TxtBx zd_dan_Frm.zTxtBx, z(i_to_zd_Frm)
zd_dan_Frm.Caption = "Характеристики здания №" + Str(i_to_zd_Frm)
zd_dan_Frm.Show
Else:
'-----------------------------
'- Для формы zd_dan_Frm_fast -
'-----------------------------
    zd_dan_Frm_fast.nzdTxtBx.Text = n_zd(i_to_zd_Frm)
    Number_to_TxtBx zd_dan_Frm_fast.mTxtBx, m_hour_work_vent(i_to_zd_Frm)
    Number_to_TxtBx zd_dan_Frm_fast.tbTxtBx, tb(i_to_zd_Frm)
    Number_to_TxtBx zd_dan_Frm_fast.tprTxtBx, tpr(i_to_zd_Frm)
    Number_to_TxtBx zd_dan_Frm_fast.qoTxtBx, q(i_to_zd_Frm, 4)
    Number_to_TxtBx zd_dan_Frm_fast.qbTxtBx, q(i_to_zd_Frm, 5)
    If do_y_n(i_to_zd_Frm) = True Then
        zd_dan_Frm_fast.y_OptnBtn.Value = True
        Number_to_TxtBx zd_dan_Frm_fast.tdotTxtBx, td(i_to_zd_Frm)
    Else
        zd_dan_Frm_fast.n_OptnBtn.Value = True
        zd_dan_Frm_fast.tdotTxtBx.Text = "5"
    End If
    If z_y_n(i_to_zd_Frm) = True Then zd_dan_Frm_fast.yOptnBtn.Value = True _
                                Else: zd_dan_Frm_fast.nOptnBtn.Value = True
        Number_to_TxtBx zd_dan_Frm_fast.qvzTxtBx, q(i_to_zd_Frm, 3)
        Number_to_TxtBx zd_dan_Frm_fast.zTxtBx, z(i_to_zd_Frm)
zd_dan_Frm_fast.Caption = "Характеристики здания №" + Str(i_to_zd_Frm)
zd_dan_Frm_fast.Show
End If
End Sub
Public Sub close_all_usen_files _
                (Optional f_name_ish_dan_sv = wdDoNotSaveChanges, _
                    Optional f_name_rm_sv = wdSaveChanges)
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Закрывает все открытые программой документы (расчетными материалами и с исходными данными) '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
For Each Doc In Documents
    Select Case Doc.Name
    Case f_name_rm
        Documents(Doc.Name).Close (f_name_rm_sv)
    Case f_name_ish_dan
        Documents(Doc.Name).Close (f_name_ish_dan_sv)
    End Select
Next Doc
End Sub
Public Sub vvod_znach_to_climat_frm()
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Вводит значений переменных в текстовые поля по climat_frm '''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Number_to_TxtBx climat_Frm.xTxtBx, x
Number_to_TxtBx climat_Frm.kTxtBx, k_vih_pr_dn
drygoy_gorod = True
For j = 1 To number_of_gorod
    If gorod = clmt(j, 1) Then drygoy_gorod = False
Next j
If drygoy_gorod = True Then
    climat_Frm.climat_CmbBx.Text = "Другой..."
    climat_Frm.n_grd_TxtBx = gorod
    Number_to_TxtBx climat_Frm.tn1TxtBx, tn1
    Number_to_TxtBx climat_Frm.tn2TxtBx, tn2
    Number_to_TxtBx climat_Frm.tn3TxtBx, tn3
    Number_to_TxtBx climat_Frm.nTxtBx, n_ot_per
Else:
climat_Frm.Height = 185
climat_Frm.n_grd_TxtBx.Enabled = False
climat_Frm.tnFm.Enabled = False
climat_Frm.nTxtBx.Enabled = False
climat_Frm.climat_CmbBx.Text = gorod
End If
End Sub
Public Sub tbl_res_raschet_and_vivod_sum_q_all_zd()
Dim i_sum_q As Integer 'Для внутреннего цикла
Dim j_sum_q As Integer 'Для внутреннего цикла
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''' Расчитывает и выводит сумму количеств тепла по зданиям в таблицу результатов '''
'''                  (находит сумму по столбцам таблицы результатов)             '''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'Расчет
For i_sum_q = 1 To 13
    For j_sum_q = 1 To x
        q_sum(i_sum_q) = q_sum(i_sum_q) + q(j_sum_q, i_sum_q + 3)
    Next j_sum_q
Next i_sum_q
' Вывод
tbl_res.Cell(x + 4, 1).Range.InsertAfter "Итого:"
For i_sum_q = 2 To 14 'Заполнение таблицы значениями количеств тепла
    If q_sum(i_sum_q - 1) <> 0 Then
        tbl_res.Cell(x + 4, i_sum_q).Range.InsertAfter Trim(Format(Round(q_sum(i_sum_q - 1), 3)))
        If i_sum_q < 11 Then
            tbl_res.Cell(x + 5, i_sum_q).Range.InsertAfter _
                Trim(Format(Round(q_sum(i_sum_q - 1) * 1.163, 3)))
        Else: tbl_res.Cell(x + 5, i_sum_q).Range.InsertAfter _
                Trim(Format(Round(q_sum(i_sum_q - 1) * 4.186, 3)))
        End If
    Else: tbl_res.Cell(x + 5, i_sum_q).Range.InsertAfter "—"
    End If
Next i_sum_q
tbl_res.Cell(x + 4, 2).Select
Selection.MoveRight Unit:=wdCharacter, Count:=12, Extend:=wdExtend
Selection.Font.Underline = wdUnderlineSingle
    For j_sum_q = 1 To 14
        cells_merge_and_text_paste Tbl:=ActiveDocument.Tables(1), _
            row_number:=x + 4, column_number:=j_sum_q, MD_count:=1
    Next j_sum_q
End Sub


