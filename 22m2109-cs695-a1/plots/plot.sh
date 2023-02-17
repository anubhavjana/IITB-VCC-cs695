#!/bin/bash

for concurrency_count in 5 10 15 20 30 50 100
do
    ab -n 100000 -c $concurrency_count http://localhost:8080/arithmetic/fibonacci?num=5 | grep "Requests per second:" | cut -d ' ' -f 7 >> load33.csv

done
