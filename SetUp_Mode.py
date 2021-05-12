import openpyxl
import subprocess


# read value from a cell in excel file


def get_value_excel(filename, cellname):
    wb = openpyxl.load_workbook(filename)
    Sheet1 = wb['Sheet1']
    wb.close()
    return Sheet1[cellname].value

# write value to a specific cell


def update_value_excel(filename, cellname, value):
    wb = openpyxl.load_workbook(filename)
    Sheet1 = wb['Sheet1']
    Sheet1[cellname].value = value
    wb.close()
    wb.save(filename)

# Force kill Excel if running to avoid conflict


s = subprocess.check_output('tasklist', shell=False)
if b"EXCEL.EXE" in s:
    subprocess.call(['taskkill', '/F', '/IM', 'excel.exe'])

# Choose window state match cases


for index in range(8):

    filename = 'SetUp_Mode.xlsx'

    Window_cell = 'D' + str(index + 2)
    Mode_cell = 'G' + str(index + 2)

    Light_cell_value = get_value_excel(filename, 'A' + str(index + 2))
    Rain_cell_value = get_value_excel(filename, 'B' + str(index + 2))
    Sound_cell_value = get_value_excel(filename, 'C' + str(index + 2))

    print(str(index + 1) + '. ' + Light_cell_value + ' + ' + Rain_cell_value + ' + ' +
          Sound_cell_value + ', đóng hay mở cửa?(1: đóng, 2:mở):')

    # Process cases
    Choose_Window_State = input()
    if Choose_Window_State == '1':
        update_value_excel(filename, Window_cell, 'đóng cửa')
        update_value_excel(filename, Mode_cell, 'gạt XUỐNG')
        continue

    if Choose_Window_State == '2':
        update_value_excel(filename, Window_cell, 'mở cửa')
        update_value_excel(filename, Mode_cell, 'gạt LÊN')

print('Mở excel file lên nào!')

# Open excel file
subprocess.Popen(['start', filename], shell=True)
