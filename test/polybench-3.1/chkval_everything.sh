#!/bin/bash

export FORMAT='%15s%10s%10s%5$11s%6$11s%7$11s%8$13s\n'
./chkval_datamining.sh
export NOHEADER='yes'
./chkval_linear-algebra_kernels.sh
./chkval_linear-algebra_solvers.sh
./chkval_medley.sh
./chkval_stencils.sh

