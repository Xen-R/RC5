#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include<vector>
#include <random>
#include <ctime>
using namespace std;

//simple operations used while encoding
uint32_t cycle_shift_left(uint32_t to_be_shifted, int shift);

uint32_t cycle_shift_right(uint32_t to_be_shifted, int shift);

vector<uint32_t> cycle_shift_left(vector<uint32_t> data, int shift);

int get_bit(vector<uint32_t> data, int idx, int num);
int get_bit(uint32_t data, int num);

int max_ind(vector<int> arr1);

//key or initializing vector random generation
string random_key(int len);

//to convert
vector<uint32_t> string_to_words(string &key);//key or initializing vector

vector<uint32_t> char_to_words(vector<char> &data);

string words_to_string(vector<uint32_t> &data);//to get output in string-form

vector<char> words_to_char(vector<uint32_t> &data);

vector<uint32_t> txt_to_words(string &key);//to convert input to the vector of words

vector<uint32_t> expanded_keys(int r);//to create array of expanded keys which does not depends of the key

void mix_key(vector<uint32_t> &s, vector<uint32_t> &l);//to create key-based array of keys

void encode(vector<uint32_t> &data, string key, int r);//to encode if key is alredy exist


void sencode(vector<uint32_t> &data, int key_type, int r, vector<int>& bitchanges);//to encode if key is alredy exist


void full_encode(vector<uint32_t> &data, string key, int r, bool key_gen);//to generate key if needed and encode

void decode(vector<uint32_t>& data, string key, int r);//to decode

vector<uint32_t> ofb(vector<uint32_t> init, vector<uint32_t> &data, string key, int r, bool key_gen, bool encode);//ofb encoding&decoding

//tests
bool frequency_test(vector<uint32_t> data);

vector<int> autocorretation_test(vector<uint32_t> data);

vector<int> runs_test(vector<uint32_t> data);
