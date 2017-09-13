#!/bin/bash

source common_compile.sh

ROOT='stencils'
compile "adi" $D_STANDARD_DATASET 8 32
compile "fdtd-2d" $D_STANDARD_DATASET 24 32
compile "fdtd-apml" $D_STANDARD_DATASET 12 32
compile "jacobi-1d-imper" $D_STANDARD_DATASET 24 32
compile "jacobi-2d-imper" $D_STANDARD_DATASET 18 32
compile "seidel-2d" $D_STANDARD_DATASET 16 32
