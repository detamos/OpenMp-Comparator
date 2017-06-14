#!/bin/bash

	rm output*

for (( i = 1; i <= 100; i++ )); do
	(time ./bin/fibonacci a $i) &>> output1
	(time ./bin/fibonacci o $i) &>> output2
done