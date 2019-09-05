import openpyxl

wb = openpyxl.Workbook()
sheet = wb.active

f = open("L1D_cache_data_port_util.txt",'r');

sheet['A1'] = 'kernel_name'
sheet['B1'] = 'gpu_sim_cycle'
sheet['C1'] = 'L1D_total_cache_accesses'
sheet['D1'] = 'L1D_total_cache_misses'
sheet['E1'] = 'L1D_total_cache_pending_hits'
sheet['F1'] = 'L1D_total_cache_reservation_fails'
sheet['G1'] = 'L1D_cache_data_port_util'
sheet['H1'] = 'L1D_cache_fill_port_util'
sheet['J1'] = 'L2_total_cache_accesses'
sheet['K1'] = 'L2_total_cache_misses'
sheet['L1'] = 'L2_total_cache_pending_hits'
sheet['M1'] = 'L2_total_cache_reservation_fails'

cnt =1;
while True:
	sheet.cell(row=1, column = cnt+12).value = 'n_act'
	cnt = cnt +1
	if cnt == 33:
		cnt =1
		break

while True:
	sheet.cell(row=1, column = cnt+12+33).value = 'n_rd'
	cnt = cnt +1
	if cnt == 33:
		cnt =1
		break

while True:
	
	sheet.cell(row=1, column = cnt+12+33+33).value = 'n_write'
	cnt = cnt +1
	if cnt == 33:
		cnt = 1
		break

while True:
	sheet.cell(row=1, column = cnt+12+33+33+33).value = 'n_wr_bk'
	cnt = cnt +1
	if cnt == 33:
		cnt =1
		break

while True:
	sheet.cell(row=1, column = cnt+12+33+33+33+33).value = 'bw_util'
	cnt = cnt +1
	if cnt == 33:
		cnt = 1
		break


f.close()
wb.save('test.xlsx')

