#!/bin/bash

rm -rf data/output
mkdir data/output
benchmark=kmeans
for f in ./../common/img/*.rgb
do
	filename=$(basename "$f")
	extension="${filename##*.}"
	filename="${filename%.*}"
	
	echo -e "\e[95m------ ${filename} ------\e[0m"
	
	echo -e "\e[96m*** Float Version ***\e[0m"
	time ./bin/${benchmark}.out ${f} data/output/${filename}_${benchmark}.rgb
	
	echo -e "\e[96m*** Fix Version ***\e[0m"
	time ./bin/${benchmark}.out.fixp ${f} data/output/${filename}_${benchmark}.rgb.fixp
	
	echo -e "\e[32m### QoS ###\e[0m"
	
	python ./../common/scripts/png2rgb.py png data/output/${filename}_${benchmark}.rgb data/output/${filename}_${benchmark}.png > out1.tmp
	python ./../common/scripts/png2rgb.py png data/output/${filename}_${benchmark}.rgb.fixp data/output/${filename}_${benchmark}.png.fixp > out2.tmp
	
	compare -metric RMSE data/output/${filename}_${benchmark}.png data/output/${filename}_${benchmark}.png.fixp null > tmp.log 2> tmp.err
	awk '{ printf("*** Error: %0.2f%\n",substr($2, 2, length($2) - 2) * 100) }' tmp.err
	
done