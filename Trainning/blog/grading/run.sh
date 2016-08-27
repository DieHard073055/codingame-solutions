#!/bin/bash
echo starting test run
for i in `seq 1 100`
do
	echo $i
	python gen_test.py $i > testcase; ./s -f testcase
done
echo done
