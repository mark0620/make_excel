#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	const char* c = str.c_str();
	ifstream in(c);
	ofstream kernel_name("kernel_name.txt");
	ofstream gpu_sim_cycle("gpu_sim_cycle.txt");
	
	ofstream L1D_total_cache_accesses ("L1D_total_cache_accesses.txt");
	ofstream L1D_total_cache_misses ("L1D_total_cache_misses.txt");
	ofstream L1D_total_cache_pending_hits ("L1D_total_cache_pending_hits.txt");
	ofstream L1D_total_cache_reservation_fails ("L1D_total_cache_reservation_fails.txt");
	ofstream L1D_cache_data_port_util ("L1D_cache_data_port_util.txt");
	ofstream L1D_cache_fill_port_util ("L1D_cache_fill_port_util.txt");

	ofstream L2_total_cache_accesses ("L2_total_cache_accesses.txt");
	ofstream L2_total_cache_misses ("L2_total_cache_misses.txt");
	ofstream L2_total_cache_pending_hits ("L2_total_cache_pending_hits.txt");
	ofstream L2_total_cache_reservation_fails ("L2_total_cache_reservation_fails.txt");


	ofstream n_act_file ("n_act.txt");
	ofstream n_rd_file ("n_rd.txt");
	ofstream n_write_file ("n_write.txt");
	ofstream n_wr_bk_file ("n_wr_bk.txt");
	ofstream bw_util_file ("bw_util.txt");
	
	string line;
	int cnt = 1;

	while(getline(in, line))
	{
		if(in.is_open())
		{
			if(line.length()>11)
			{
				string str = line.substr(0,11);
				if(str == "kernel_name")
				{
					kernel_name << line << endl;
				}
			}

			if(line.length()>13)
			{
				string str = line.substr(0,13);
				if(str == "gpu_sim_cycle")
				{
					gpu_sim_cycle << line << endl;
				}
			}


			if(line.length()>24)
			{
				string str = line.substr(1,24);
				if(str == "L1D_total_cache_accesses")
				{
					L1D_total_cache_accesses << line << endl;
				}
			}

			if(line.length()>22)
			{
				string str = line.substr(1,22);
				if(str == "L1D_total_cache_misses")
				{
					L1D_total_cache_misses << line << endl;
				}
			}

			if(line.length()>28)
			{
				string str = line.substr(1,28);
				if(str == "L1D_total_cache_pending_hits")
				{
					L1D_total_cache_pending_hits << line << endl;
				}
			}

			if(line.length()>33)
			{
				string str = line.substr(1,33);
				if(str == "L1D_total_cache_reservation_fails")
				{
					 L1D_total_cache_reservation_fails<< line << endl;
				}
			}

			if(line.length()>23)
			{
				string str = line.substr(1,24);
				if(str == "L1D_cache_data_port_util")
				{
					 L1D_cache_data_port_util<< line << endl;
				}
			}

			if(line.length()>23)
			{
				string str = line.substr(1,24);
				if(str == "L1D_cache_fill_port_util")
				{
					 L1D_cache_fill_port_util<< line << endl;
				}
			}

			if(line.length()>24)
			{
				string str = line.substr(0,23);
				if(str == "L2_total_cache_accesses")
				{
					L2_total_cache_accesses << line << endl;
				}
			}

			if(line.length()>22)
			{
				string str = line.substr(0,21);
				if(str == "L2_total_cache_misses")
				{
					L2_total_cache_misses << line << endl;
				}
			}

			if(line.length()>28)
			{
				string str = line.substr(0,27);
				if(str == "L2_total_cache_pending_hits")
				{
					L2_total_cache_pending_hits << line << endl;
				}
			}

			if(line.length()>33)
			{
				string str = line.substr(0,32);
				if(str == "L2_total_cache_reservation_fails")
				{
					 L2_total_cache_reservation_fails<< line << endl;
				}
			}

			if(line.length()>30)
			{
				string str = line.substr(0,5);
				if(str == "n_cmd")
				{
					int n_act = line.find("n_act");
					int n_pre = line.find("n_pre");
					
					int n_rd = line.find("n_rd=");
					int n_rd_ = line.find("n_rd_");

					int n_write = line.find("n_write");
					int n_wr_bk = line.find("n_wr_bk");
					int bw_util = line.find("bw_util");


					str = line.substr(n_act,n_pre-n_act-1);
					n_act_file << str << endl;
					
					str = line.substr(n_rd,n_rd_-n_rd-1);
					n_rd_file << str << endl;

					str = line.substr(n_write,n_wr_bk-n_write-1);
					n_write_file << str << endl;

					str = line.substr(n_wr_bk,bw_util-n_wr_bk-1);
					n_wr_bk_file << str << endl;

					str = line.substr(bw_util,line.size()-bw_util-1);
					bw_util_file << str << endl;
				}
			}


		}
	}
	in.close();
}
