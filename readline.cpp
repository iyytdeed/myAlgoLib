#include <stdio.h>
#include <string.h>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
	
	int N;
	cin >> N;
	cin.ignore();
	vector<vector<string> > saved_strs;
	char line[100] = {0};
	const char *delim = " ,";
	while(cin.getline(line, 100)){
		vector<string> tmp_strvec;	
		// delim process begin
		char *p = strtok(line, delim);
		while(p != NULL){
			string tmp_str(p);
			tmp_strvec.push_back(tmp_str);
			p = strtok(NULL, delim);
		}
		// delim process end
		saved_strs.push_back(tmp_strvec);
		cout << "N = " << N << endl;
		N--;
		if( N <= 0 ) break; 
	}

	cout << "parse result :" << endl;
	for(int i = 0; i < saved_strs.size(); i++){
		for(int j = 0; j < saved_strs[i].size(); j++){
			cout << saved_strs[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;

	return 0;
}
