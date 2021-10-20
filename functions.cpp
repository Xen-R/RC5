#include "Header.h"

uint32_t cycle_shift_right(uint32_t to_be_shifted, int shift)
{
	uint32_t tmp = to_be_shifted >> shift%32;
	uint32_t res = to_be_shifted << (32 - shift%32);
	uint32_t fulres = tmp | res;
	return fulres;
}

vector<uint32_t> cycle_shift_left(vector<uint32_t> data, int shift)
{
	vector<uint32_t> result = data;
	/*while (shift >= 32) {
		uint32_t tmp = result[data.size()-1];

		for (int i = 1; i < data.size() - 1; i++) {
			result[i] = result[i-1] >> shift;
		}
		result[0] = tmp;
		shift -= 32;
	}
	if (shift > 0) {
		vector<uint32_t> tmp = result;
		for (int i = 0; i < data.size() - 1; i++) {
			tmp[i] = tmp[i] << (32 - shift);
			result[i] = result[i] >> shift;
		}
		for (int i = 0; i < data.size() - 2; i++) {
			result[i] = result[i] | tmp[i + 1] >> shift;
		}
		result[data.size() - 1] = result[data.size() - 1] | tmp[0];
	}*/
	if (shift < 32 && shift !=0) {
		uint32_t tmp0 = data[0];
		uint32_t tmp1 = data[1];
		result[0] = result[0] << shift;
		tmp0 = tmp0 >> (32 - shift);
		result[1] = result[1] << shift;
		tmp1 = tmp1 >> (32 - shift);
		result[0] = result[0] | tmp1;
		result[1] = result[1] | tmp0;
	}
	if (shift == 32) {
		result[0] = data[1];
		result[1] = data[0];
	}
	if (shift > 32 && shift !=64) {
		result[0] = data[1];
		result[1] = data[0];
		uint32_t tmp0 = data[1];
		uint32_t tmp1 = data[0];
		result[0] = result[0] << (shift-32);
		tmp0 = tmp0 >> (32 - (shift - 32));
		result[1] = result[1] << (shift-32);
		tmp1 = tmp1 >> (32 - (shift-32));
		result[0] = result[0] | tmp1;
		result[1] = result[1] | tmp0;
	}
	return result;
}

int get_bit(vector<uint32_t> data, int idx, int num)
{
	uint32_t tmp = data[idx] >> (32 - num);
	tmp = tmp & 1;
	return tmp;
}

int get_bit(uint32_t data,  int num)
{
	uint32_t tmp = data >> (32 - num);
	tmp = tmp & 1;
	return tmp;
}

int max_ind(vector<int> arr1)
{
	int ind = 0;
	for (int i = 0; i < arr1.size(); i++) {
		if (arr1[i] > 0) {
			ind = i;
		}
	}
	return ind;
}

string random_key(int len)
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, len);
}

uint32_t cycle_shift_left(uint32_t to_be_shifted, int shift)
{
	uint32_t tmp = to_be_shifted << (shift%32);
	uint32_t res = to_be_shifted >> (32 - (shift%32));
	uint32_t fulres = tmp | res;
	return fulres;
}


vector<uint32_t> string_to_words(string &key)
{
	int len = key.length();
	if (len != 0) {
		vector<unsigned char> buffer;
		for (int i = 0; i < key.length(); i++) {
			buffer.push_back(key.at(i));
		}
		int words_number = len/4, tail = 4 - len % 4;
		if (tail != 4) {
			words_number++;
		}
		vector<uint32_t> key_words(words_number);

		for (int i = 0; i < words_number; i++) {
			for (int j = 0; j < 4; j++) {
				if (!(i == words_number - 1 && tail != 4 && j >= 4 - tail)) {
					key_words[i] = key_words[i] | (uint32_t)buffer[i*4 + j];
				}
				key_words[i] = key_words[i] << 8;
			}
		}
		return key_words;
	}
	vector<uint32_t> kk;
	kk.push_back(0);
	return kk;
}

vector<uint32_t> txt_to_words(string &key)
{
	int len = key.length();
	if (len != 0) {
		vector<unsigned char> buffer;
		for (int i = 0; i < key.length(); i++) {
			buffer.push_back(key.at(i));
		}
		int words_number = len / 4, tail = 4 - len % 4;
		if (tail != 4) {
			words_number++;
		}
		vector<uint32_t> key_words(words_number);

		for (int i = 0; i < words_number; i++) {
			for (int j = 0; j < 4; j++) {
				if (!(i == words_number - 1 && tail != 4 && j >= 4 - tail)) {
					uint32_t tmp = (uint32_t)buffer[i * 4 + j] << 8 * j;
					key_words[i] = key_words[i] | tmp;
				}
				
			}
		}
		return key_words;
	}
	vector<uint32_t> kk;
	return kk;
}

vector<uint32_t> char_to_words(vector<char>& data)
{
	int len = data.size();
	if (len != 0) {
		vector<unsigned char> buffer;
		for (int i = 0; i < data.size(); i++) {
			buffer.push_back(data[i]);
		}
		int words_number = len / 4, tail = 4 - len % 4;
		if (tail != 4) {
			words_number++;
		}
		vector<uint32_t> key_words(words_number);

		for (int i = 0; i < words_number; i++) {
			for (int j = 0; j < 4; j++) {
				if (!(i == words_number - 1 && tail != 0 && j >= 4 - tail)) {
					key_words[i] = key_words[i] | (uint32_t)buffer[i * 4 + j];
				}
				key_words[i] = key_words[i] << 8;
			}
		}
		return key_words;
	}
	return vector<uint32_t>();
}

string words_to_string(vector<uint32_t>& data)
{
	vector<char> buffer;
	for (int i = 0; i < data.size(); i++) {
		uint32_t tmp = data[i];
	
		for(int j = 0; j < 4; j++){
			
			char tmp2 = ((unsigned char *)(&data[i]))[j];
			buffer.push_back((char)tmp);
			tmp = tmp >> 8;
		}
	}
	string newstr;
	for (int i = 0; i < buffer.size(); i++) {
		//cout << buffer[i] << endl;
		newstr+=buffer[i];
	}


	return newstr;
}

vector<char> words_to_char(vector<uint32_t>& data)
{
	vector<char> buffer;
	for (int i = 0; i < data.size(); i++) {
		uint32_t tmp = data[i];

		for (int j = 0; j < 4; j++) {

			//char tmp2 = ((unsigned char *)(&data[i]))[j];
			buffer.push_back((char)tmp);
			tmp = tmp >> 8;
		}
	}

	return buffer;
}

vector<uint32_t> expanded_keys(int r)
{
	uint32_t p = 3084996963, q= 2654435769;
	vector<uint32_t> key_exp;
	key_exp.push_back(p);
	for (int i = 1; i < 2*(r + 1) - 1; i++) {
		uint32_t tmp = key_exp[i - 1] + q;
		key_exp.push_back(tmp);
	}
	return key_exp;
}

void mix_key(vector<uint32_t> &s, vector<uint32_t> &l)
{
	uint32_t a = 0, b = 0;
	int i = 0, j = 0;
	int c = l.size();
	int sr = s.size();
	int n = 3*c;
	if (sr > c) {
		n = 3*sr;
	}
	for (int k = 0; k < n; k++) {
		uint32_t tmp = s[i] + a + b, tmp2 = l[j] + a + b, ab = a+b;
		s[i] = cycle_shift_left(tmp, 3);
		a = s[i];
		ab = a + b;
		tmp2 = l[j] + a + b;
		l[j] = cycle_shift_left(tmp2, ab%32);
		b = l[j];
		i = (i + 1) % sr;
		j = (j + 1) % c;
	}
}

void encode(vector<uint32_t> &data, string key, int r) {
	vector<uint32_t> s = expanded_keys(r);
	vector<uint32_t> kw = string_to_words(key);
	//while (kw.size() % 4 != 0) {
	//	kw.push_back(0);
	//}

	//cout << words_to_string(kw) << endl;

	mix_key(s, kw);


	//cout << words_to_string(s) << endl;


	for (int j = 0; j <data.size()- 1;) {
		data[j] += s[0];//a+s0
		data[j+1] += s[1];//b+s1
		for (int i = 1; i < r; i++) {
			uint32_t tmp = data[j] ^ data[j + 1];//a xor b
			data[j] = cycle_shift_left(tmp, data[j + 1]) + s[2 * i];//a = a xor b <<< b + s2i
			tmp = data[j + 1] ^ data[j];//b xor a
			data[j + 1] = cycle_shift_left(tmp, data[j]) + s[2 * i + 1];//b = b xor a <<< a + s2i+1

		} 
		j += 2;
	}
}

void sencode(vector<uint32_t>& data, int key_type, int r, vector<int>& bitchanges)
{
	vector<uint32_t> kw;
	if (key_type == 0) {
		kw.push_back(0);
		kw.push_back(0);
		kw.push_back(0);
		kw.push_back(0);
	}
	if (key_type == 1) {
		kw.push_back(4294967295);
		kw.push_back(4294967295);
		kw.push_back(4294967295);
		kw.push_back(4294967295);
	}
	if (key_type == 2) {
		kw.push_back(4027576335);
		kw.push_back(4027576335);
		kw.push_back(4027576335);
		kw.push_back(4027576335);
	}
	if (key_type == 3) {
		string key = random_key(16);
		kw = string_to_words(key);
	}
	vector<uint32_t> s = expanded_keys(r);
	mix_key(s, kw);
	for (int l = 0; l < 2; l++) {
		uint32_t gf = data[l];
		for (int k = 0; k < 32; k++) {
			cout << (gf & 1) << " ";
			gf = gf >> 1;
		}
	}
	cout << '\n';
	for (int j = 0; j < data.size() - 1;) {
		uint32_t stat1 = data[j];
		uint32_t stat2 = data[j + 1];

		data[j] += s[0];//a+s0
		data[j + 1] += s[1];//b+s1
		for (int k = 0; k < 32; k++) {
			if (get_bit(data[j], k) != get_bit(stat1, k))
				bitchanges[j * 32 + k]++;
			if (get_bit(data[j + 1], k) != get_bit(stat2, k))
				bitchanges[(j + 1) * 32 + k]++;
		}
		stat1 = data[j];
		stat2 = data[j + 1];
		for (int l = 0; l < 2; l++) {
			uint32_t gf = data[l];
			for (int k = 0; k < 32; k++) {
				cout << (gf & 1)<< " ";
				gf = gf >> 1;
			}
		}
		cout << '\n';
		for (int i = 1; i < r; i++) {
			uint32_t tmp = data[j] ^ data[j + 1];//a xor b
			data[j] = cycle_shift_left(tmp, data[j + 1]) + s[2 * i];//a = a xor b <<< b + s2i
			tmp = data[j + 1] ^ data[j];//b xor a
			data[j + 1] = cycle_shift_left(tmp, data[j]) + s[2 * i + 1];//b = b xor a <<< a + s2i+1
			for (int k = 0; k < 32; k++) {
				if (get_bit(data[j], k) != get_bit(stat1, k))
					bitchanges[j * 32 + k]++;
				if (get_bit(data[j+1], k) != get_bit(stat2, k))
					bitchanges[(j+1) * 32 + k]++;
			}
			for (int l = 0; l < 2; l++) {
				uint32_t gf = data[l];
				for (int k = 0; k < 32; k++) {
					cout << (gf & 1) << " ";
					gf = gf >> 1;
				}
			}
			cout << '\n';
			stat1 = data[j];
			stat2 = data[j + 1];

		}
		j += 2;

	}


}

void full_encode(vector<uint32_t>& data, string key, int r, bool key_gen)
{
	if (key_gen) {
		srand(time(0));
		int len = 16 * rand();
		key = random_key(len);
	}
	encode(data, key, r);
}

void decode(vector<uint32_t> &data, string key, int r) {
	vector<uint32_t> s = expanded_keys(r);
	vector<uint32_t> kw = string_to_words(key);
	mix_key(s, kw);
	for (int j = 0; j < data.size() - 1;) {
		
		for (int i = r-1; i >= 1; i--) {
			uint32_t tmp = data[j+1] - s[2 * i + 1] ;//b-s2i+1
			data[j + 1] = cycle_shift_right(tmp, data[j])^ data[j];//b = b - s2i+1 >>> a xor a
			tmp = data[j] -s[2 * i];//a - s2i
			data[j] = cycle_shift_right(tmp, data[j + 1])^ data[j + 1];//a = a - s2i >>> b xor b

		}
		data[j + 1] -= s[1];//b - s1
		data[j] -= s[0];//a - s0
		j += 2;
	}
}

vector<uint32_t> ofb(vector<uint32_t> init, vector<uint32_t> &data, string key, int r, bool key_gen, bool encode)
{
	if (encode) {
		srand(time(0));
		int len = rand() % 127 + 129;
		string str = random_key(len);
		init = string_to_words(str);
	}
	vector<uint32_t>in = init;//to save initializing vector
	if (key_gen) {
		srand(time(0));
		int len =  rand() % 15 + 1;
		key = random_key(len);
	}
	vector<uint32_t> s = expanded_keys(r);
	vector<uint32_t> kw = string_to_words(key);
	mix_key(s, kw);
	for (int j = 0; j < data.size() - 1;) {
		init[0] += s[0];//a+s0
		init[1] += s[1];//b+s1
		for (int i = 1; i < r; i++) {
			uint32_t tmp = init[0] ^ init[ 1];//a xor b
			init[0] = cycle_shift_left(tmp, init[ 1]) + s[2 * i];//a = a xor b <<< b + s2i
			tmp = init[1] ^ init[0];//b xor a
			init[1] = cycle_shift_left(tmp, init[0]) + s[2 * i + 1];//b = b xor a <<< a + s2i+1
		}
		data[j] = data[j] ^ init[0];//first block of text xor a
		data[j + 1] = data[j + 1] ^ init[1];//second block of text xor b
		j += 2;
	}
	return in;//to save initializing vector
}

bool frequency_test(vector<uint32_t> data)
{
	double sum = 0;
	cout << "Frequency test started\n";
	for (int i = 0; i < data.size(); i++) {
		uint32_t tmp = data[i];
		for (int j = 0; j < 32; j++) {
			sum += tmp & 1;
			tmp = tmp >> 1;
		}
	}
	cout << "sum of x = " << sum << "\n";
	sum = sum - ((double)data.size()*32.0 )/ 2;
	sum = (double)(2 * sum )/ (sqrt((double)(data.size()*32.0)));
	cout << "f(x) = " << sum << "\n";
	if (abs(sum) < 3) {
		cout << "Frequency test has been succesfully passed\n";
		return true;
	}
	cout << "Frequency test has been failed\n";
	return false;
}

vector<int> autocorretation_test(vector<uint32_t> data)
{
	vector<int> result;
	
	for (int i = 0; i < data.size()*32; i++) {
		//vector<uint32_t> tmp = cycle_shift_left(data, i);
		vector<uint32_t> tmp(2);
		tmp[0] = data[0];
		tmp[1] = data[1];
		int shift = i;
	
		if (shift < 32 && shift != 0) {
			uint32_t tmp0 = data[0];
			uint32_t tmp1 = data[1];
			tmp[0] = tmp[0] << shift;
			tmp0 = tmp0 >> (32 - shift);
			tmp[1] = tmp[1] << shift;
			tmp1 = tmp1 >> (32 - shift);
			tmp[0] = tmp1 | tmp[0];
			tmp[1] = tmp0 | tmp[1];
		}
		if (shift == 32) {
			tmp[0] = data[1];
			tmp[1] = data[0];
		}
		if (shift > 32 && shift != 64) {
			tmp[0] = data[1];
			tmp[1] = data[0];
			uint32_t tmp0 = data[1];
			uint32_t tmp1 = data[0];
			tmp[0] = tmp[0] << (shift - 32);
			tmp0 = tmp0 >> (32 - (shift - 32));
			tmp[1] = tmp[1] << (shift - 32);
			tmp1 = tmp1 >> (32 - (shift - 32));
			tmp[0] =tmp1 |  tmp[0];
			tmp[1] =tmp0 | tmp[1] ;
		}



		
		int sum = 0, tmp1 = 0;
		for (int j = 0; j < data.size(); j++) {
			uint32_t cor1 = data[j], cor2 = tmp[j];
			
			for (int k = 0; k < 32; k++) {
				int last1 = cor1 & 1, last2 = cor2 & 1;
				if (last1 == last2) {
					sum++;
					
				}
				else {
					sum--;
				}
				//cout <<( cor2&1 );
				cor1 = cor1 >> 1;
				cor2 = cor2 >> 1;

			}
			
		}
		//cout <<'\n';
		result.push_back((sum));
	}
	return result;
}

vector<int> runs_test(vector<uint32_t> data)
{
	vector<int> zeroes(data.size()*32), ones(data.size()*32);
	for (int i = 0; i < data.size() * 32; i++) {
		zeroes[i] = 0;
		ones[i] = 0;
	}
	int curlen = 1, prev = 0, cur = 0;
	for (int i = 0; i < data.size() * 32; i++) {
		cur = get_bit(data, i / 32, 32 - i % 32);
	//	cout << cur;
		if ((cur == prev) || (i == 0)) {
			if (i != 0) {
				curlen++;
			}
			prev = cur;
		}
		if ((cur != prev) || (i == data.size() * 32 - 1)) {

			if (prev == 1) {
				ones[curlen]++;
				curlen = 1;
			}
			else {
				zeroes[curlen]++;
				curlen = 1;
			}
			if ((cur != prev) && (i == data.size() * 32 - 1)) {
				if (prev == 1) {
					zeroes[curlen]++;
				}
				else {
					ones[curlen]++;
				}

			}
		}
		prev = cur;
	}
	double sum1 = 0, sum2 = 0;
	/* cout << "\n";*/
	for (int i = 0; i < data.size() * 32; i++) {
	//	cout << ones[i] << " " << zeroes[i] << "\n";
//		sum2 += ones[i];
//		sum1 += zeroes[i];
	}
	//cout << "sum " << sum << endl;
	int l1 = max_ind(zeroes), l2 = max_ind(ones);
	
	
	for (int i = 0; i < l1; i++) {
		if (zeroes[i] != 0) {
		
			double del1 = (double)zeroes.size() / pow(2, i + 2);
			sum1 += double(pow((zeroes[i] - del1),2)) / del1;
		
		}
			
	}
	for (int i = 0; i < l2; i++) {
		if (ones[i] != 0) {

			double del2 = (double)zeroes.size() / pow(2, i + 2);
			sum2 += double(pow((zeroes[i] - del2),2)) / del2;

		}
	}
	sum1 += sum2;
	double x2[] = { 0, 3.8415, 	5.9915, 	7.8147, 9.4877, 11.0705, 12.5916, 14.0671, 15.5073, 16.9190, 18.3070, 19.6751, 21.0261, 22.3620, 23.6848 };
	//cout << "Enter x2 for k = " << max(l1,l2) << " and needed alpha\n";
	//double x2 = 0;
	//cin >> x2;
	if (x2[max(l1, l2)] < sum1) {
		cout << sum1 << " > " << x2[max(l1, l2)] << " =>\n";
		cout << "Runs test has been succefully passed\n";
	}
	else {
		cout << sum1 << " <= " << x2[max(l1, l2)] << " =>\n";
		cout << "Runs test has been failed\n";
	}



	return vector<int>();
}


