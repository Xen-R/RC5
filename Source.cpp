#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include<fstream>
int main() {
	//getting key or order to generate it automatically
	/*bool flag = false;
	string key;
	cout << "Type thekey below. If the key shoul be generated automatically, just press enter" << endl;
	cin >> key;
	if (key.length() == 0) {
		flag = true;
	}
	//ecb text
	ifstream file("in.txt"); 
	string s, stb;
	while (getline(file, s)) { 
	
		stb += s;
		stb += '\n';
	
	}
	file.close();
	vector<uint32_t> buf = txt_to_words(stb);
	string str = words_to_string(buf);
	full_encode(buf, key, 12, flag);
	std::ofstream out;         
	out.open("cipher.txt");
	str = words_to_string(buf);
	if (out.is_open())
	{
		out << str << std::endl;
	
	}
	out.close();
	decode(buf, key, 12);
	out.open("out.txt");
	str = words_to_string(buf);
	if (out.is_open())
	{
		out <<str << std::endl;
		
	}
	out.close();
	//ofb text
	vector<uint32_t> init;
	init = ofb(init, buf, key, 12, false, true);
	std::ofstream outofb;
	outofb.open("cipherofb.txt");
	str = words_to_string(buf);
	if (outofb.is_open())
	{
		outofb << str << std::endl;

	}
	outofb.close();
	ofb(init, buf, key, 12, false, false);
	outofb.open("outofb.txt");
	str = words_to_string(buf);
	if (outofb.is_open())
	{
		outofb << str << std::endl;

	}
	outofb.close();
	//bmp
	ifstream iFile;
	char ch;
	iFile.open("wh1.bmp", ios::binary);
	ofstream oFile, oFile2,oFile3, oFile4;
	oFile.open("lenacipher11.bmp", ios::binary);
	oFile2.open("lenaout11.bmp", ios::binary);
	oFile3.open("lenaofbcipher11.bmp", ios::binary);
	oFile4.open("lenaofbout11.bmp", ios::binary);
	//writing bmp header to all result files
	int fs[1079];
	for (int i = 0; i < 1079; i++)
	{
		iFile.get(ch);
		fs[i] = ch;
		char p;
		p = fs[i];
		oFile << p;
		oFile2 << p;
		oFile3 << p;
		oFile4 << p;
	}
	//getting data to encode from bmp
	stb = "";
	int c = 0;
	while (iFile.get(ch)) {//FIND PROBLEM WITH BMP
		stb += ch;
		if (c < 60) {
			cout << ch << " ";
			c++;
		}
	}

	//ecb bmp
	buf = txt_to_words(stb);
	encode(buf, key, 12);
	string smmth = words_to_string(buf);
	smmth.substr(stb.size());
	oFile << smmth;
	buf[0] = 0;
	//buf[1] = 0;;
	decode(buf, key, 12);

	smmth = words_to_string(buf);
	smmth.substr(stb.size());
	oFile2 << smmth;

	//ofbbmp
	buf = txt_to_words(stb);
	init = ofb(init, buf, key, 12, false, true);
	str = words_to_string(buf);
	str.substr(stb.size());
	oFile3 << str << std::endl;
	buf[0] = 0;
	//buf[1] = 0;
	ofb(init, buf, key, 12, false, false);
	str = words_to_string(buf);
	str.substr(stb.size());
	oFile4 << str << std::endl;

	
	oFile4.close();
	oFile3.close();
	oFile2.close();
	oFile.close();
	iFile.close();

	*/
	string data_for_tests = "AAAAAAAA";
	//string key_zeroes = "";
	//string key_strong = "ffdhdfhdvbvt";
	vector<uint32_t> buf1 = txt_to_words(data_for_tests);
	//cout << words_to_string(buf1) << endl;
	vector<uint32_t> buf2 = txt_to_words(data_for_tests);
	//cout << words_to_string(buf2) << endl;
	vector<uint32_t> buf3 = txt_to_words(data_for_tests);
	//cout << words_to_string(buf2) << endl;
	vector<uint32_t> buf4 = txt_to_words(data_for_tests);
	vector<int> bitchang0(buf1.size() * 32, 0), bitchang1(buf2.size() * 32, 0), bitchang2(buf2.size() * 32, 0), bitchang3(buf2.size() * 32, 0);
	cout << "zero key: \n";
	//sencode(buf1, 0, 11, bitchang0);
	//sencode(buf2, 1, 11, bitchang1);
	//sencode(buf3, 2, 11, bitchang2);
	sencode(buf4, 3, 11, bitchang3);
	//cout << words_to_string(buf1)<<endl;
	//cout << words_to_string(buf2)<<endl;
	cout << "Frequency test for the zero key\n";
	frequency_test(buf1);
	cout << "Frequency test for the ones key\n";
	frequency_test(buf2);
	cout << "Frequency test for the series key\n";
	frequency_test(buf3);	
	cout << "Frequency test for the random key\n";
	frequency_test(buf4);
	//decode(buf1, key_weak, 5);
	//decode(buf2, key_strong, 5);
	//cout << words_to_string(buf1) << endl;
	//cout << words_to_string(buf2) << endl;
	cout << "Autocorrelation test for the zero key:\n";
	vector<int> test = autocorretation_test(buf1);
	for(int i = 0; i<test.size(); i++)
	cout << test[i]<<" ";
	cout << "\nAutocorrelation test for the ones key:\n";
	test = autocorretation_test(buf2);
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << " ";
	cout << "\nAutocorrelation test for the series key:\n";
	test = autocorretation_test(buf3);
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << " ";
	cout << "\nAutocorrelation test for the random key:\n";
	test = autocorretation_test(buf4);
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << " ";
	cout << "\nRuns test for the zero key:\n";
	runs_test(buf1);
	cout << "\nRuns test for the ones key:\n";
	runs_test(buf2);
	cout << "\nRuns test for the series key:\n";
	runs_test(buf3);
	cout << "\nRuns test for the random key:\n";
	runs_test(buf4);

	cout << "\nBit changes for the zero key:\n";
	for (int i = 0; i < bitchang0.size(); i++)
		cout << bitchang0[i] << " ";
	cout << "\nBit changes for the ones key:\n";
	for (int i = 0; i < bitchang0.size(); i++)
		cout << bitchang1[i] << " ";
	cout << "\nBit changes for the series key:\n";
	for (int i = 0; i < bitchang0.size(); i++)
		cout << bitchang2[i] << " ";
	cout << "\nBit changes for the random key:\n";
	for (int i = 0; i < bitchang0.size(); i++)
		cout << bitchang3[i] << " ";
	//char hg = 1;
	//cout << hg;
	return 0;
}