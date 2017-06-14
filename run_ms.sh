#!/bin/bash

	ls -1 ./input > input_file

	rm output*

while IFS='' read -r line || [[ -n "$line" ]]; do
	echo " " >> output1
	echo -n $line >> output1
	(time cat ./input/$line | ./bin/mergeSort o) &>> output1
	echo " " >> output2
	echo -n $line >> output2
	(time cat ./input/$line | ./bin/mergeSort a) &>> output2
done < ./input_file

	rm input_file
