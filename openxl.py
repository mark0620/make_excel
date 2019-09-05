import openpyxl

wb = openpyxl.Workbook()
sheet = wb.active

f = open("L1D_cache_data_port_util.txt",'r');

sheet['A1'] = 'kernel_name'
sheet['A2'] = 'gpu_sim_cycle'
sheet['A3'] = 'L1D_total_cache_accesses'
sheet['A4'] = 'L1D_total_cache_misses'
sheet['A5'] = 'L1D_total_cache_pending_hits'
sheet['A6'] = 'L1D_total_cache_reservation_fails'
sheet['A7'] = 'L1D_cache_data_port_util'
sheet['A8'] = 'L1D_cache_fill_port_util'
sheet['A9'] = 'L2_total_cache_accesses'
sheet['A10'] = 'L2_total_cache_misses'
sheet['A11'] = 'L2_total_cache_pending_hits'
sheet['A12'] = 'L2_total_cache_reservation_fails'

cnt =1;
while True:
	sheet.cell(row=cnt+12, column = 1).value = 'n_act'
	cnt = cnt +1
	if cnt == 33:
		cnt = 1
		break


#while True:
#	line = f.readline();
#	if not line: break
#	sheet.append([line[28:]])




f.close()
wb.save('test.xlsx')

