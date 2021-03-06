// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "CharNum.h"
#include "LineNum.h"
#include"WordNum.h"
#include "Word_Fre.h"
using namespace std;
//int argc, char *argv[]
int main(int argc, char *argv[])
{	
	int topn = 10;
	int word_m = 1;
	int word_w = 1;
	int i = 1;
	int infile=-1, outfile=-1;
	string in = "-i",o="-o",w="-w",m="-m",n="-n";
	while (argv[i])
	{
		if (argv[i] == in) infile = i + 1;												
		if (argv[i] == o) outfile = i + 1;												
		if (argv[i] == w) word_w= atoi(argv[i+1]);
		if (argv[i] == m) word_m = atoi(argv[i + 1]);									
		if (argv[i] == n) topn = atoi(argv[i + 1]);
		i++;
	}

	
	if (infile == -1)
	{

		printf("please input the infile!\n");
		return -1;

	}
	if (outfile == -1)
	{
		printf("please input the outfile");
		return -1;
	}

	if (word_w == -1)
	{
		printf("please input the word weight");
		return -1;
	}
	std::fstream file;
	file.open(argv[infile]);
	if (!file) {

		printf("the file cannot open or no exist!\n");
		return -1;
	}

	file.close();
	
	//char filename[100] = "D:\\demo.txt";
	//char outfilename[100] = "result.txt";
	FILE * stream;
	freopen_s(&stream, argv[outfile], "w", stderr);
	int Char_Number = CharNum(argv[infile]);
	int Lines_Number = LineNum(argv[infile]);
	int Words_Number = WordNum(argv[infile]);

	fprintf(stream, "characters: %d\n", Char_Number);
	fprintf(stream, "words: %d\n", Words_Number-Lines_Number);
	fprintf(stream, "lines: %d\n", Lines_Number);


	Word_Fre(argv[infile], argv[outfile], word_w,word_m, topn);			//Word frequency statistics

	
	

	return 0;
}
