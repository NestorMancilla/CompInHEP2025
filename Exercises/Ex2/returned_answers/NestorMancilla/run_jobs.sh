#!/bin/bash

N=10  # Number of jobs
for i in $(seq 1 $N); do
    ./HW $i &
done

wait  # Wait for all jobs to finish

